#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "speck.h"


int main()
{
    WORD gold_plaintxt0;
    WORD gold_plaintxt1;
    WORD gold_key[4];
    WORD gold_cyphertxt0;
    WORD gold_cyphertxt1;
    WORD test_cyphertxt0;
    WORD test_cyphertxt1;

    WORD* pointer0 = &test_cyphertxt0;
    WORD* pointer1 = &test_cyphertxt1;

    gold_plaintxt1 = 0x6574;
    gold_plaintxt0 = 0x694c;

    gold_key[3] = 0x1918;
    gold_key[2] = 0x1110;
    gold_key[1] = 0x0908;
    gold_key[0] = 0x0100;

    gold_cyphertxt1 = 0xa868;
    gold_cyphertxt0 = 0x42f2;
    
    speck32s64_encrypt( gold_plaintxt1, gold_plaintxt0, gold_key, pointer1, pointer0);
   
    if (gold_cyphertxt1 != test_cyphertxt1 || gold_cyphertxt0 != test_cyphertxt0) {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
        fprintf(stdout, "Test Pt: %04x, %04x\n", test_cyphertxt1, test_cyphertxt0);
        fprintf(stdout, "Gold Pt: %04x, %04x\n", gold_cyphertxt1, gold_cyphertxt0);
        fprintf(stdout, "*******************************************\n");
        return 1;
    } else {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "Test Pt: %04x, %04x\n", test_cyphertxt1, test_cyphertxt0);
        fprintf(stdout, "Gold Pt: %04x, %04x\n", gold_cyphertxt1, gold_cyphertxt0);
        fprintf(stdout, "*******************************************\n");
         
    }
        
    fprintf(stdout, "*********************************************************\n");
    fprintf(stdout, "PASS: The 16bit Block output matches the golden output!\n");
    fprintf(stdout, "*********************************************************\n");
   
    WORD64 gold_plaintxt0_64;
    WORD64 gold_plaintxt1_64;
    WORD64 gold_key_64[4];
    WORD64 gold_cyphertxt0_64;
    WORD64 gold_cyphertxt1_64;
    WORD64 test_cyphertxt0_64;
    WORD64 test_cyphertxt1_64;

    gold_plaintxt1_64 = 0x65736f6874206e49;
    gold_plaintxt0_64 = 0x202e72656e6f6f70;

    gold_key_64[3] = 0x1f1e1d1c1b1a1918;
    gold_key_64[2] = 0x1716151413121110;
    gold_key_64[1] = 0x0f0e0d0c0b0a0908;
    gold_key_64[0] = 0x0706050403020100;

    gold_cyphertxt1_64 = 0x4109010405c0f53e;
    gold_cyphertxt0_64 = 0x4eeeb48d9c188f43;

    speck128s256_encrypt( gold_plaintxt1_64, gold_plaintxt0_64, gold_key_64, &test_cyphertxt1_64, &test_cyphertxt0_64);
   
    if (gold_cyphertxt1_64 != test_cyphertxt1_64 || gold_cyphertxt0_64 != test_cyphertxt0_64) {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
        fprintf(stdout, "Test Pt: %012x, %012x\n", test_cyphertxt1_64, test_cyphertxt0_64);
        fprintf(stdout, "Gold Pt: %012x, %012x\n", gold_cyphertxt1_64, gold_cyphertxt0_64);
        fprintf(stdout, "*******************************************\n");
        return 1;
    } else {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "Test Pt: %012x, %012x\n", test_cyphertxt1_64, test_cyphertxt0_64);
        fprintf(stdout, "Gold Pt: %012x, %012x\n", gold_cyphertxt1_64, gold_cyphertxt0_64);
        fprintf(stdout, "*******************************************\n");
         
    }
        
    fprintf(stdout, "*********************************************************\n");
    fprintf(stdout, "PASS: The 64-bit Block output matches the golden output!\n");
    fprintf(stdout, "*********************************************************\n");
    return 0;
    

}
