#include QMK_KEYBOARD_H

static const pin_t row_pins[MATRIX_ROWS] = ROW_PINS;

static matrix_row_t read_row(uint8_t row_index) {
    matrix_row_t next_row = 0; 

    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        // Set the shift register data to 1 for the first column, and shift it all the way through subsequent columns
	if (col_index == 0) {
            writePinHigh(SR_DATA_PIN);
	} else {
            writePinLow(SR_DATA_PIN);
	}

        writePinHigh(SR_CLK_PIN);
        wait_ms(1);

	uint8_t key_state = readPin(row_pins[row_index]);

	next_row |= (key_state ? 0 : (MATRIX_ROW_SHIFTER << col_index));

	writePinLow(SR_CLK_PIN);
    }

    return next_row;
}

void matrix_init_custom(void) {
    // Set rows as input pins with pull-up resistors
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        setPinInputHigh(row_pins[row_index]);
    }

    // Set shift register clock and data pins as outputs
    setPinOutput(SR_CLK_PIN);
    setPinOutput(SR_DATA_PIN);

    // Initialize output pin values
    writePinLow(SR_CLK_PIN);
    writePinLow(SR_DATA_PIN);
}

uint8_t matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;

    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        matrix_row_t next_row = read_row(row_index);
	matrix_has_changed |= (current_matrix[row_index] != next_row);
	current_matrix[row_index] = next_row;
    }

    return matrix_has_changed;
}
