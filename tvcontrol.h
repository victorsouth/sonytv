
#ifndef __TV_CONTROL_H__
#define __TV_CONTROL_H__


#define bit_time 600 // us

#define sequence_12pulses_length 13 // start bit + 12 bits data


typedef struct {
	unsigned char length;
	char bits[];
} ir_pulse;

typedef unsigned char* sequence_12bits;
typedef unsigned char* sequence_raw;


extern unsigned char mute_sound[];
extern const ir_pulse* ir_pulses[];
extern const ir_pulse zero_pulse;
extern const ir_pulse one_pulse;
extern const ir_pulse start_pulse;


char invert_bit(char value, char bit_mask);
unsigned char get_sequence12_raw_length(sequence_12bits sequence);



#endif
