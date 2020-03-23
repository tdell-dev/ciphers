#include "simon.h"

void simon32s64_encrypt( WORD pt_0, WORD pt_1, WORD key[4], WORD* ct_0, WORD* ct_1 ){

	WORD x_ar[32];
	WORD y_ar[32];

	//x_ar[0] = pt_0;
	//y_ar[0] = pt_1;

	WORD subkeyAr[32];
	subkeyAr[0] = key[3];
	subkeyAr[1] = key[2];
	subkeyAr[2] = key[1];
	subkeyAr[3] = key[0];

	gen_subkeys( subkeyAr, key );
	

	for (int i=0; i<32; i++) {
		if( i==0 ){
			simon_enc_round(pt_0, pt_1, subkeyAr[0], x_ar, y_ar );
		}
		else{
			simon_enc_round(x_ar[i-1], y_ar[i-1], subkeyAr[i], x_ar + i, y_ar + i);
		}
	}

	*ct_0 = x_ar[31];
	*ct_1 = y_ar[31];
}

void simon32s64_decrypt( WORD pt_0, WORD pt_1, WORD key[4], WORD* ct_0, WORD* ct_1 ){

	WORD x_ar[32];
	WORD y_ar[32];

	//x_ar[0] = pt_0;
	//y_ar[0] = pt_1;

	WORD subkeyAr[32];
	subkeyAr[0] = key[3];
	subkeyAr[1] = key[2];
	subkeyAr[2] = key[1];
	subkeyAr[3] = key[0];

	gen_subkeys( subkeyAr, key );
	

	for (int i=0; i<32; i++) {
		if( i==0 ){
			simon_dec_round(pt_0, pt_1, subkeyAr[31], x_ar, y_ar );
		}
		else{
			simon_dec_round(x_ar[i-1], y_ar[i-1], subkeyAr[31-i], x_ar + i, y_ar + i);
		}
	}

	*ct_0 = x_ar[31];
	*ct_1 = y_ar[31];
}

/*
void simon48s72_encrypt(  ){
	int num_rounds = 36;
	int num_block_bits = 24;
}



void simon48s72_decrypt(  ){
	int num_rounds = 36;
	int num_block_bits = 24;
}



void simon48s96_encrypt(  ){
	int num_rounds = 36;
	int num_block_bits = 24;

}
void simon48s96_decrypt(  ){
	int num_rounds = 36;
	int num_block_bits = 24;

}



void simon64s96_encrypt(  ){
	int num_rounds = 42;
	int num_block_bits = 32;
}


void simon64s96_encrypt(  ){
	int num_rounds = 42;
	int num_block_bits = 32;
}



void simon64s128_encrypt( ){
	int num_rounds = 44;
	int num_block_bits = 32;
}

void simon64s128_encrypt( ){
	int num_rounds = 44;
	int num_block_bits = 32;
}



void simon96s96_encrypt(  ){
	int num_rounds = 52;
	int num_block_bits = 48;
}

void simon96s144_encrypt( ){
	int num_rounds = 54;
	int num_block_bits = 48;
}

void simon128s128_encrypt(){
	int num_rounds = 68;
	int num_block_bits = 64;
}

void simon128s192_encrypt(){
	int num_rounds = 69;
	int num_block_bits = 64;
} */

void simon128s256_encrypt(WORD64 pt_0, WORD64 pt_1, WORD64 key[4], WORD64* ct_0, WORD64* ct_1){
	int num_rounds = 72;
	int num_block_bits = 64;

	WORD64 x_ar[72];
	WORD64 y_ar[72];

	//x_ar[0] = pt_0;
	//y_ar[0] = pt_1;

	WORD64 subkeyAr[72];
	subkeyAr[0] = key[3];
	subkeyAr[1] = key[2];
	subkeyAr[2] = key[1];
	subkeyAr[3] = key[0];
	
	gen_subkeys( subkeyAr );
	

	for (int i=0; i<72; i++) {
		if( i==0 ){
			simon_enc_round(pt_0, pt_1, subkeyAr[0], x_ar, y_ar );
		}
		else{
			simon_enc_round(x_ar[i-1], y_ar[i-1], subkeyAr[i], x_ar + i, y_ar + i);
		}
	}

	*ct_0 = x_ar[71];
	*ct_1 = y_ar[71];
}



void simon128s256_decrypt(WORD64 ct_0, WORD64 ct_1, WORD64 key[4], WORD64* pt_0, WORD64* pt_1 ){

	WORD64 x_ar[72];
	WORD64 y_ar[72];

	//x_ar[0] = pt_0;
	//y_ar[0] = pt_1;

	WORD64 subkeyAr[72];
	subkeyAr[0] = key[3];
	subkeyAr[1] = key[2];
	subkeyAr[2] = key[1];
	subkeyAr[3] = key[0];

	gen_subkeys( subkeyAr );
	

	for (int i=0; i<72; i++) {
		if( i==0 ){
			simon_dec_round(ct_0, ct_1, subkeyAr[71], x_ar, y_ar );
		}
		else{
			simon_dec_round(x_ar[i-1], y_ar[i-1], subkeyAr[71-i], x_ar + i, y_ar + i);
		}
	}

	*pt_0 = x_ar[71];
	*pt_1 = y_ar[71];
}
