#ifndef AES_H_
#define AES_H_

#include <ap_cint.h>
#include <math.h>

#define NUM_DATA_BYTES 16
#define NUM_KEY_BYTES 32
// #define NUM_KEY_BYTES 24
// #define NUM_KEY_BYTES 16
typedef uint8 BITE;
typedef int INTTYPE;




void mix_cols( BITE OutData[NUM_DATA_BYTES], BITE inData[NUM_DATA_BYTES] );

void shift_rows( BITE outText[NUM_DATA_BYTES], BITE inText[NUM_DATA_BYTES]);

void byte_sub(BITE input_byte, BITE* output_byte); /* ********* */
void sub_bytes( BITE outText[NUM_DATA_BYTES], BITE inText[NUM_DATA_BYTES]);

void add_rnd_key(BITE OutData[NUM_DATA_BYTES], BITE inData[NUM_DATA_BYTES], BITE SubKey[NUM_KEY_BYTES] );
void aes_round( BITE Pt[NUM_DATA_BYTES], int rnd_Num, BITE SubKey[NUM_KEY_BYTES], BITE StgOut[NUM_DATA_BYTES] );
void subkey_gen( 
				BITE origKey[NUM_KEY_BYTES],
				BITE subKey0[NUM_DATA_BYTES],  BITE subKey1[NUM_DATA_BYTES],
				BITE subKey2[NUM_DATA_BYTES],  BITE subKey3[NUM_DATA_BYTES],
				BITE subKey4[NUM_DATA_BYTES],  BITE subKey5[NUM_DATA_BYTES],
				BITE subKey6[NUM_DATA_BYTES],  BITE subKey7[NUM_DATA_BYTES],
				BITE subKey8[NUM_DATA_BYTES],  BITE subKey9[NUM_DATA_BYTES],
				BITE subKey10[NUM_DATA_BYTES], BITE subKey11[NUM_DATA_BYTES],
				BITE subKey12[NUM_DATA_BYTES], BITE subKey13[NUM_DATA_BYTES],
				BITE subKey14[NUM_DATA_BYTES], BITE subKey15[NUM_DATA_BYTES]
				);

void createTwo256Keys( BITE outKey0[NUM_DATA_BYTES], BITE outKey1[NUM_DATA_BYTES], BITE inKey0[NUM_DATA_BYTES], BITE inKey1[NUM_DATA_BYTES], BITE RC);
void pre_round_transform( BITE input[NUM_DATA_BYTES], BITE SubKey[NUM_DATA_BYTES], BITE output[NUM_DATA_BYTES]); /* ******** */

void aes( BITE Pt[NUM_DATA_BYTES], BITE Key[NUM_KEY_BYTES], BITE Ct[NUM_DATA_BYTES] );


#endif
