#include "aes.h"

void aes_round(	BITE StgIn[NUM_DATA_BYTES], int rnd_Num, BITE SubKey[NUM_KEY_BYTES], BITE StgOut[NUM_DATA_BYTES] ){



if( rnd_Num == 14) {
	BITE temp0[NUM_DATA_BYTES];
	BITE temp1[NUM_DATA_BYTES];
	
	sub_bytes(   temp0,  StgIn );
	shift_rows(  temp1,  temp0 );
	add_rnd_key( StgOut, temp1, SubKey );
}
else {
	BITE temp0[NUM_DATA_BYTES];
	BITE temp1[NUM_DATA_BYTES];
	BITE temp2[NUM_DATA_BYTES];
	sub_bytes	( temp0,  StgIn );
	shift_rows	( temp1,  temp0 );
	mix_cols	( temp2,  temp1 );
	add_rnd_key	( StgOut, temp2, SubKey );
}



}