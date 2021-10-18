#include QMK_KEYBOARD_H

static const pin_t matrix_pins[MATRIX_PIN_COUNT] = MATRIX_PINS;

static matrix_row_t read_row(uint8_t row_index) {
    matrix_row_t next_row = 0;

    for (uint8_t col_index = 0; col_index < 8; col_index++) {

        // Shift a 1 into the beginning of the shift register data chain, then shift 0s throughout the rest
        writePin(SR_DATA_PIN, row_index == 0 && col_index == 0 ? 1 : 0);
        writePinLow(SR_CLK_PIN);
        writePinHigh(SR_CLK_PIN);

        // Small delay to allow shift register to finish shifting
        wait_us(5);

        // Read matrix input pins B1, B2, B3, B4 and bit-shift them into position
        next_row |= (((matrix_row_t)(0b00011110 & PINB) >> 1) << (col_index * 4));

    }

    return next_row;
}

void matrix_init_custom(void) {
    // Set matrix pins as input pins
    for (uint8_t matrix_pin_index = 0; matrix_pin_index < MATRIX_PIN_COUNT; matrix_pin_index++) {
        setPinInput(matrix_pins[matrix_pin_index]);
    }

    // Set shift register clock and data pins as outputs
    setPinOutput(SR_CLK_PIN);
    setPinOutput(SR_DATA_PIN);
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
