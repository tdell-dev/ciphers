#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "present.h"


int main()
{
   
    WORD64 gold_plaintxt0_64;
    KEYWORD gold_key_80;
    WORD64 gold_cyphertxt0_64;
    WORD64 test_cyphertxt0_64;

    gold_plaintxt0_64 = 0x0000000000000000;
    gold_key_80 = 0x00000000000000000000;
    gold_cyphertxt0_64 = 0x5579c1387b228445;

    present80_encrypt( gold_plaintxt0_64, gold_key_80, &test_cyphertxt0_64);
   
    if ( gold_cyphertxt0_64 != test_cyphertxt0_64 ) {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
        fprintf(stdout, "Test Pt: %012x\n", test_cyphertxt0_64);
        fprintf(stdout, "Gold Pt: %012x\n", gold_cyphertxt0_64);
        fprintf(stdout, "*******************************************\n");
        return 1;
    } else {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "Test Pt: %012x\n", test_cyphertxt0_64);
        fprintf(stdout, "Gold Pt: %012x\n", gold_cyphertxt0_64);
        fprintf(stdout, "*******************************************\n");
         
    }
        
    fprintf(stdout, "*********************************************************\n");
    fprintf(stdout, "PASS: The 64-bit Block output matches the golden output!\n");
    fprintf(stdout, "*********************************************************\n");
    return 0;
    

}
