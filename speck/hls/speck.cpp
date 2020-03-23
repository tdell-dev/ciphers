#include "speck.h"

void speck32s64_encrypt( WORD pt_0, WORD pt_1, WORD key[4], WORD *ct_0, WORD *ct_1 ){

	WORD x_ar[22];
	WORD y_ar[22];

	//x_ar[0] = pt_0;
	//y_ar[0] = pt_1;

	WORD subkeyAr[22];

	gen_subkeys( key, subkeyAr );
	
	x_ar[0] = pt_0;
	y_ar[0] = pt_1;

	for (int i=0; i<22; i++) {
		if( i==0 ) {
			speck_enc_round( pt_0, pt_1, subkeyAr[0], x_ar, y_ar);
		}
		else {
			speck_enc_round(x_ar[i-1], y_ar[i-1], subkeyAr[i], x_ar + i , y_ar + i );
		}
	}

	*ct_0 = x_ar[21];
	*ct_1 = y_ar[21];

}

void speck32s64_decrypt( WORD ct_0, WORD ct_1, WORD key[4], WORD* pt_0, WORD* pt_1 ){
	WORD x_ar[22];
	WORD y_ar[22];



	WORD subkeyAr[22];

	gen_subkeys( key, subkeyAr );
	


	for (int i=0; i<22; i++) {
		if( i==0 ) {
			speck_dec_round( ct_0, ct_1, subkeyAr[21], x_ar, y_ar);
		}
		else {
			speck_dec_round(x_ar[i-1], y_ar[i-1], subkeyAr[21-i], x_ar + i , y_ar + i );
		}
	}

	*pt_0 = x_ar[21];
	*pt_1 = y_ar[21];

}




void speck128s256_encrypt( WORD64 pt_0, WORD64 pt_1, WORD64 key[4], WORD64 *ct_0, WORD64 *ct_1 ){
		WORD64 x_ar[34];
		WORD64 y_ar[34];

		//x_ar[0] = pt_0;
		//y_ar[0] = pt_1;

		WORD64 subkeyAr[34];

		gen_subkeys( key, subkeyAr );

		//x_ar[0] = pt_0;
		//y_ar[0] = pt_1;

		for (int i=0; i<34; i++) {
			if( i==0 ) {
				speck_enc_round( pt_0, pt_1, subkeyAr[0], x_ar, y_ar);
			}
			else {
				speck_enc_round(x_ar[i-1], y_ar[i-1], subkeyAr[i], x_ar + i , y_ar + i );
			}
		}

		*ct_0 = x_ar[33];
		*ct_1 = y_ar[33];

}


void speck128s256_decrypt( WORD64 ct_0, WORD64 ct_1, WORD64 key[4], WORD64* pt_0, WORD64* pt_1 ){
		WORD64 x_ar[34];
		WORD64 y_ar[34];

		//x_ar[0] = pt_0;
		//y_ar[0] = pt_1;

		WORD64 subkeyAr[34];

		gen_subkeys( key, subkeyAr );

		//x_ar[0] = pt_0;
		//y_ar[0] = pt_1;

		for (int i=0; i<34; i++) {
			if( i==0 ) {
				speck_dec_round( ct_0, ct_1, subkeyAr[33], x_ar, y_ar);
			}
			else {
				speck_dec_round(x_ar[i-1], y_ar[i-1], subkeyAr[33-i], x_ar + i , y_ar + i );
			}
		}

		*pt_0 = x_ar[33];
		*pt_1 = y_ar[33];

}
