/*
This is traditional AES implementation.
INPUT:
	In_R, In_I[]: Real and Imag parts of Complex signal

OUTPUT:
	Out_R, Out_I[]: Real and Imag parts of Complex signal
*/
#include "aes.h"


void aes( BITE Pt[NUM_DATA_BYTES], BITE Key[NUM_KEY_BYTES], BITE aes_out[NUM_DATA_BYTES] ){

	BITE SubKeyStg0  [NUM_DATA_BYTES]; BITE SubKeyStg1  [NUM_DATA_BYTES];
	BITE SubKeyStg2  [NUM_DATA_BYTES]; BITE SubKeyStg3  [NUM_DATA_BYTES];
	BITE SubKeyStg4  [NUM_DATA_BYTES]; BITE SubKeyStg5  [NUM_DATA_BYTES];
	BITE SubKeyStg6  [NUM_DATA_BYTES]; BITE SubKeyStg7  [NUM_DATA_BYTES];
	BITE SubKeyStg8  [NUM_DATA_BYTES]; BITE SubKeyStg9  [NUM_DATA_BYTES];
	BITE SubKeyStg10 [NUM_DATA_BYTES]; BITE SubKeyStg11 [NUM_DATA_BYTES];
	BITE SubKeyStg12 [NUM_DATA_BYTES]; BITE SubKeyStg13 [NUM_DATA_BYTES];
	BITE SubKeyStg14 [NUM_DATA_BYTES]; BITE SubKeyStg15 [NUM_DATA_BYTES];

	BITE round_out1	 [NUM_DATA_BYTES]; BITE round_out2  [NUM_DATA_BYTES];
	BITE round_out3	 [NUM_DATA_BYTES]; BITE round_out4  [NUM_DATA_BYTES];
	BITE round_out5	 [NUM_DATA_BYTES]; BITE round_out6  [NUM_DATA_BYTES];
	BITE round_out7	 [NUM_DATA_BYTES]; BITE round_out8  [NUM_DATA_BYTES];
	BITE round_out9	 [NUM_DATA_BYTES]; BITE round_out10 [NUM_DATA_BYTES];
	BITE round_out11 [NUM_DATA_BYTES]; BITE round_out12 [NUM_DATA_BYTES];
	BITE round_out13 [NUM_DATA_BYTES]; BITE round_out14	[NUM_DATA_BYTES];
	BITE start_rounds[NUM_DATA_BYTES];
	
	subkey_gen(
		Key,        
		SubKeyStg0,  SubKeyStg1,  
		SubKeyStg2,  SubKeyStg3,
		SubKeyStg4,  SubKeyStg5,
		SubKeyStg6,  SubKeyStg7,
		SubKeyStg8,  SubKeyStg9,
		SubKeyStg10, SubKeyStg11,
		SubKeyStg12, SubKeyStg13,
		SubKeyStg14, SubKeyStg15
		);

	pre_round_transform( Pt, SubKeyStg0, start_rounds);

	aes_round( start_rounds, 1, SubKeyStg1,  round_out1  );
	aes_round( round_out1,   2, SubKeyStg2,  round_out2  );
	aes_round( round_out2,   3, SubKeyStg3,  round_out3  );
	aes_round( round_out3,   4, SubKeyStg4,  round_out4  );
	aes_round( round_out4,   5, SubKeyStg5,  round_out5  );
	aes_round( round_out5,   6, SubKeyStg6,  round_out6  );
	aes_round( round_out6,   7, SubKeyStg7,  round_out7  );
	aes_round( round_out7,   8, SubKeyStg8,  round_out8  );
	aes_round( round_out8,   9, SubKeyStg9,  round_out9  );
	aes_round( round_out9,  10, SubKeyStg10, round_out10 );
	aes_round( round_out10, 11, SubKeyStg11, round_out11 );
	aes_round( round_out11, 12, SubKeyStg12, round_out12 );
	aes_round( round_out12, 13, SubKeyStg13, round_out13 );
	aes_round( round_out13, 14, SubKeyStg14, aes_out );

} 
