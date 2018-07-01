void config_PWM1HW( ){
    PR2 = 255;                  //By default 6490kHz about whit 20MHz Crystal
    CCPR2L = 0b01111111;        //By default DC = %50
    CCP2CON = 0b00111100;       //CCP2 as PWM
    TRISC = 0;
    LATC = 0;
    T2CON |= 0b01;          //Set 4 bit prescaler for T2CON
    T2CONbits.TMR2ON = 1;   //Turn on TMR2      ‭
}

void dc_PWM1HW(long n){
    long dc = 0;
    dc = (long)n*1023/100;
    CCPR2L = dc >> 2;
    CCP2CONbits.DC2B = ((dc & 0x03));
    
    
}