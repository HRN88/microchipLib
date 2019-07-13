
#include "pin18F4550.h"

#define VR_INTERNAL 0
#define VR_EXTERNAL 1


void configADC(int n_channels, int vref){
    //n_channels will be max 8
    int nch;
    if(vref == 0){
        //-Vref = VSS
        ADCON1bits.VCFG1 = 0;
        //+Vref = VDD
        ADCON1bits.VCFG0 = 0;
    }else if(vref == 1){
         //-Vref = AN2
        ADCON1bits.VCFG1 = 1;
        //+Vref = AN3
        ADCON1bits.VCFG0 = 1;
    }
    
    nch = ~n_channels & 0x0F;
    ADCON0 = 0x01; 
    ADCON1 |= nch;
    ADCON2 = 0b10010010; 
    TRISA = 0b1100000;
    
}

int readADC(int channel){
    ADCON0 = 0x01;
    ADCON0 |= (channel << 2);
    ADCON0bits.GODONE = 1;
    while(ADCON0bits.GODONE);
    return ((ADRESH << 8) + ADRESL);
    
}