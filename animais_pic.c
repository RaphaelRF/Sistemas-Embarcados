// CHAVES DE FUNÇÃO:
//  --------CHAVE1--------  --------CHAVE2---------
// |GLCD\LCD ( 1) = OFF   |DIS1    ( 1) = OFF   |
// |RX       ( 2) = ON    |DIS2    ( 2) = OFF   |
// |TX       ( 3) = ON    |DIS3    ( 3) = OFF   |
// |REL1     ( 4) = OFF   |DIS4    ( 4) = OFF   |
// |REL2     ( 5) = OFF   |INFR    ( 5) = OFF   |
// |SCK      ( 6) = OFF   |RESIS   ( 6) = OFF   |
// |SDA      ( 7) = OFF   |TEMP    ( 7) = OFF   |
// |RTC      ( 8) = OFF   |VENT    ( 8) = OFF   |
// |LED1     ( 9) = OFF   |AN0     ( 9) = OFF   |
// |LED2     (10) = OFF   |AN1     (10) = OFF   |
//  --------------------- ----------------------

// --- Ligações entre PIC e LCD ---
sbit LCD_RS at RE2_bit;   // PINO 2 DO PORTD INTERLIGADO AO RS DO DISPLAY
sbit LCD_EN at RE1_bit;   // PINO 3 DO PORTD INTERLIGADO AO EN DO DISPLAY
sbit LCD_D7 at RD7_bit;  // PINO 7 DO PORTD INTERLIGADO AO D7 DO DISPLAY
sbit LCD_D6 at RD6_bit;  // PINO 6 DO PORTD INTERLIGADO AO D6 DO DISPLAY
sbit LCD_D5 at RD5_bit;  // PINO 5 DO PORTD INTERLIGADO AO D5 DO DISPLAY
sbit LCD_D4 at RD4_bit;  // PINO 4 DO PORTD INTERLIGADO AO D4 DO DISPLAY

// Selecionando direção de fluxo de dados dos pinos utilizados para a comunicação com display LCD
sbit LCD_RS_Direction at TRISE2_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 2 DO PORTD
sbit LCD_EN_Direction at TRISE1_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 3 DO PORTD
sbit LCD_D7_Direction at TRISD7_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 7 DO PORTD
sbit LCD_D6_Direction at TRISD6_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 6 DO PORTD
sbit LCD_D5_Direction at TRISD5_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 5 DO PORTD
sbit LCD_D4_Direction at TRISD4_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 4 DO PORTD

int controle=0;

int Verifica() {

TRISB0_bit = 1;                                // set RB0 pin as input
TRISB1_bit = 1;                                // set RB0 pin as input
TRISB2_bit = 1;                                // set RB0 pin as input

  do {
    if (Button(&PORTB, 0, 1, 0)) {               // Detect logical one      ENTER
      return 1;                              // Update flag
    }

    //----------------------------------------------------------------------------------------
    if (Button(&PORTB, 1, 1, 0)) {               // Detect logical one      Cima
      return 2;                              // Update flag
    }

     else{
     return 0;
     }
    //----------------------------------------------------------------------------------------

  } while(1);                                    // Endless loop

}

void main(){

   char ucRead;        // Variavel para armazenar o dado lido.
   unsigned int Control = 1;  // +++++++ VARIAVEL DE CONTROLE DA COMUNICAÇÃO ++++++++
                              // LEMBRE DE ALTERAR ESSA VARIAVE TAMBEM NO ARDUINO

   ADCON1  = 0x0E;                           //Configura os pinos do PORTB como digitais, e RA0 (PORTA) como analógico

   Lcd_Init();                               //Inicializa módulo LCD
   Lcd_Cmd(_LCD_CURSOR_OFF);                 //Apaga cursor
   Lcd_Cmd(_LCD_CLEAR);                      //Limpa display

   UART1_Init(9600);  // Utiliza bibliotecas do compilador para configuração o Baud rate.


   while(ucRead!='A'){  // SELECIONE A VARIAVEL DE CONTROLE (CONTROL) DECLARADA ACIMA.
   
     controle=Verifica();
     if (controle==1){
       Lcd_Cmd(_LCD_CLEAR);
       UART1_Write('A');
       lcd_out(1,1,"Send = A");
       Delay_ms(200);
       Lcd_Cmd(_LCD_CLEAR);
     }

     else if (controle==2){
       Lcd_Cmd(_LCD_CLEAR);
       UART1_Write('B');
       lcd_out(1,1,"Send = B");
       Delay_ms(200);
       Lcd_Cmd(_LCD_CLEAR);
     }

     else if (controle==0){
       UART1_Write('X');
       lcd_out(1,1,"Botoes");
       lcd_out(2,1,"disponiveis");
     }
     
         ucRead = UART1_Read(); // Lê o dado da serial.

   }
   Lcd_Cmd(_LCD_CLEAR);
   lcd_out(1,1,"Funcionando..");
   
}