

#include "tvcontrol.h"

unsigned char mute_sound[] = {2, 
							  0, 0, 1, 0, 1, 0, 0,  // cmd : mute
							  1, 0, 0, 0, 0};		// addr: TV


const ir_pulse zero_pulse  = {2, {1, 0}};
const ir_pulse one_pulse   = {3, {1, 1, 0}};
const ir_pulse start_pulse = {5, {1, 1, 1, 1, 0}};
const ir_pulse* ir_pulses[] = 
	{&zero_pulse, &one_pulse, &start_pulse};


char invert_bit(char value, char bit_mask) {
	return (value & ~bit_mask) | (~value & bit_mask);
}


unsigned char get_sequence12_raw_length(sequence_12bits sequence) {
	/*unsigned char result = 0;
	for (unsigned char index = 0; index < sequence_12bits_length; ++index) {
		unsigned char bit_index = sequence[index];
		ir_protocol_bit* bit = & ir_bits[bit_index];
		result += bit->length;
	}

	return result;*/
	return 0;
}
