#include "speck.h"


void circ_shift_left2(WORD in0, WORD* shifted)	  {
	*shifted = (in0 << 2) | (in0 >> 14);
}

void circ_shift_left3(WORD64 in0, WORD64* shifted) {
	*shifted = (in0 << 3) | (in0 >> 61);
}

void circ_shift_left7(WORD in0, WORD* shifted)	  {
	*shifted = (in0 << 7) | (in0 >> 9);
}

void circ_shift_left8(WORD64 in0, WORD64* shifted) {
	*shifted = (in0 << 8) | (in0 >> 56);
}


void circ_shift_right2(WORD in0, WORD* shifted)	  {
	*shifted = (in0 << 14) | (in0 >> 2);
}

void circ_shift_right3(WORD64 in0, WORD64* shifted){
	*shifted = (in0 << 61) | (in0 >> 3);
}

void circ_shift_right7(WORD in0, WORD* shifted)	  {
	*shifted = (in0 << 9) | (in0 >> 7);
}

void circ_shift_right8(WORD64 in0, WORD64* shifted){
	*shifted = (in0 << 56) | (in0 >> 8);
}


void mod_sub( WORD in0, WORD in1, WORD* out0){
	//if( in0 < in1) {
		*out0 = (in0 - in1);// %(65536);
		//*out0 = (in0 + 65536) - in1; 
	//}
	//else {

		//*out0 = in0 - in1;
	//}
}


void mod_sub( WORD64 in0, WORD64 in1, WORD64* out0){
	//if( in0 < in1) {
		*out0 = (in0 - in1);// % (18446744073709551616);
		//*out0 = (in0 + 1<<64) - in1; 
	//}
	//else {
	//	*out0 = in0 - in1;
	//}
}

void mod_add_prep( WORD in0, WORD* out0){
	*out0 = in0;//(unsigned int) (65536) - in0;
	
}

void mod_add_prep( WORD64 in0, WORD64* out0 ) {
		*out0 = in0;// (18446744073709551616) - in0;
}



void speck_enc_round( WORD x_i, WORD y_i, WORD subkey, WORD* x_n, WORD* y_n ){
	//alpha = 7;
	//beta  = 2;

	WORD shifted7;
	circ_shift_right7( x_i, &shifted7);

	WORD shifted2;
	circ_shift_left2( y_i, &shifted2);

	WORD sum = (shifted7 + y_i);//%(65536);
	*x_n = sum ^ subkey;
	*y_n = shifted2 ^ sum ^ subkey; 
}


void speck_dec_round( WORD x_i, WORD y_i, WORD subkey, WORD* x_n, WORD* y_n ){
	//alpha = 7;
	//beta = 2;

	WORD shifted2;
	circ_shift_right2(x_i^y_i, &shifted2);

	WORD subOut;
	mod_sub(x_i^subkey, shifted2, &subOut);
	
	WORD shifted7;
	circ_shift_left7( subOut, &shifted7 );

	*x_n = shifted7;
	*y_n = shifted2;
}

void speck_enc_round( WORD64 x_i, WORD64 y_i, WORD64 subkey, WORD64* x_n, WORD64* y_n ){
	//alpha = 8;
	//beta  = 3;

	WORD64 shifted8;
	circ_shift_right8( x_i, &shifted8);

	WORD64 shifted3;
	circ_shift_left3( y_i, &shifted3);

	WORD64 sum = (shifted8 + y_i);//%(65536);
	*x_n = sum ^ subkey;
	*y_n = shifted3 ^ sum ^ subkey; 

}

void speck_dec_round( WORD64 x_i, WORD64 y_i, WORD64 subkey, WORD64* x_n, WORD64* y_n ){
	//alpha = 8;
	//beta = 3;

	WORD64 shifted3;
	circ_shift_right3(x_i^y_i, &shifted3);

	WORD64 subOut;
	mod_sub(x_i^subkey, shifted3, &subOut);
	
	WORD64 shifted8;
	circ_shift_left8( subOut, &shifted8 );

	*x_n = shifted8;
	*y_n = shifted3;
}

void gen_subkeys( WORD key[], WORD subKeyAr[] ){
	WORD l[24];
	l[2] = key[3];
	l[1] = key[2];
	l[0] = key[1];
	subKeyAr[0] = key[0];

	WORD temp;
	WORD prep1, prep2;
	
	for(int i=0; i<21; i++){
		circ_shift_right7(l[i], &temp);
		prep1 = temp + subKeyAr[i];
		l[i+3] = prep1 ^ i;
		circ_shift_left2( subKeyAr[i], &temp);
		subKeyAr[i+1] = temp ^ prep1 ^ i;
	}

}

void gen_subkeys( WORD64 key[], WORD64 subKeyAr[] ) {
	WORD64 l[36];
	l[2] = key[3];
	l[1] = key[2];
	l[0] = key[1];
	subKeyAr[0] = key[0];
	WORD64 temp;
	WORD64 prep1, prep2;
	
	for(int i=0; i<34; i++){
		circ_shift_right8(l[i], &temp);
		prep1 = temp + subKeyAr[i];
		l[i+3] = prep1 ^ i;
		circ_shift_left3( subKeyAr[i], &temp);
		subKeyAr[i+1] = temp ^ prep1 ^ i;
	}
}
