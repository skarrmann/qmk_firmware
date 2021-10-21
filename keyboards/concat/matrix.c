#include QMK_KEYBOARD_H

static const pin_t matrix_pins[MATRIX_PIN_COUNT] = MATRIX_PINS;

static matrix_row_t read_row(uint8_t row_index) {
    matrix_row_t next_row = 0;

    for (uint8_t col_index = 0; col_index < 8; col_index++) {

        // Write a 0 into the beginning of the shift register data chain, then shift 1 throughout the rest
        writePin(SR_DATA_PIN, row_index == 0 && col_index == 0 ? 0 : 1);
        
        // Advance the shift register
        writePinLow(SR_LATCH_PIN);
        writePinLow(SR_CLOCK_PIN);
        writePinHigh(SR_CLOCK_PIN);
        writePinHigh(SR_LATCH_PIN);

        // Wait for data to show on shift register output (Should be less than 300ns under typical conditions)
        wait_us(1);
        
        // Read matrix input pins B1, B2 and bit-shift them into position
        next_row |= (((matrix_row_t)(0b00000110 & ~PINB) >> 1) << (col_index * MATRIX_PIN_COUNT));

    }

    return next_row;
}

void matrix_init_custom(void) {
    // Set matrix pins as input pins
    for (uint8_t matrix_pin_index = 0; matrix_pin_index < MATRIX_PIN_COUNT; matrix_pin_index++) {
        setPinInputHigh(matrix_pins[matrix_pin_index]);
    }

    // Set shift register clock and data pins as outputs
    setPinOutput(SR_DATA_PIN);
    setPinOutput(SR_LATCH_PIN);
    setPinOutput(SR_CLOCK_PIN);
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
