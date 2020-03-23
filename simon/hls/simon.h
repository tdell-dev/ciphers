#include <stdio.h>
typedef unsigned short WORD;
typedef unsigned long long WORD64;

#define NUM_ARRAY 32

//For WORD size of 16bits
void simon32s64_encrypt( WORD input_block0, WORD input_block1, WORD key[4], WORD *output_block0, WORD *output_block1 );
void simon32s64_decrypt( WORD pt_0, WORD pt_1, WORD key[4], WORD* ct_0, WORD* ct_1 );
void simon_dec_round( WORD x_i, WORD y_i, WORD subkey, WORD* x_n, WORD* y_n );
void simon_enc_round( WORD x_i, WORD y_i, WORD subkey, WORD* x_n, WORD* y_n );
void gen_subkeys( WORD subkeyAr[NUM_ARRAY], WORD key[4]);
void simon_round( WORD in0, WORD in1, WORD subkey, WORD* out0, WORD* out1 );
void circ_shift1( WORD in0, WORD* shifted);
void circ_shift2( WORD in0, WORD* shifted);
void circ_shift8( WORD in0, WORD* shifted);
void circ_shift_right1( WORD in0, WORD* shifted);
void circ_shift_right2( WORD in0, WORD* shifted);
void circ_shift_right3( WORD in0, WORD* shifted);
void circ_shift_right8( WORD in0, WORD* shifted);

//for WORD64 size of 64bits
void simon128s256_encrypt( WORD64 input_block0, WORD64 input_block1, WORD64 key[4], WORD64 *output_block0, WORD64 *output_block1 );
void simon128s256_decrypt( WORD64 pt_0, WORD64 pt_1, WORD64 key[4], WORD64* ct_0, WORD64* ct_1 );
void simon_dec_round( WORD64 x_i, WORD64 y_i, WORD64 subkey, WORD64* x_n, WORD64* y_n );
void simon_enc_round( WORD64 x_i, WORD64 y_i, WORD64 subkey, WORD64* x_n, WORD64* y_n );
void gen_subkeys( WORD64 subkeyAr[NUM_ARRAY] );
void simon_round( WORD64 in0, WORD64 in1, WORD64 subkey, WORD64* out0, WORD64* out1 );
void circ_shift1( WORD64 in0, WORD64* shifted);
void circ_shift2( WORD64 in0, WORD64* shifted);
void circ_shift8( WORD64 in0, WORD64* shifted);
void circ_shift_right1( WORD64 in0, WORD64* shifted);
void circ_shift_right2( WORD64 in0, WORD64* shifted);
void circ_shift_right3( WORD64 in0, WORD64* shifted);
void circ_shift_right8( WORD64 in0, WORD64* shifted);
