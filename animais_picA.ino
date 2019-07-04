#include <LiquidCrystal.h>   
#include <Stepper.h> 
 
LiquidCrystal lcd(12,11,10,9,8,7); 
const int stepsPerRevolution = 500; 
Stepper myStepper1(stepsPerRevolution, 26,28,27,29);
Stepper myStepper2(stepsPerRevolution, 40,44,42,46);

int controle = 0;
int hora_atual[3];
int h[6][3];
int i = 0;
int delay_inic = 150;
int delay_pisca = 250;
const int botao1 = 52;
const int botao2 = 53;
int estado1 = 0;
int estado2 = 0;
int vezes = 1;
int gramas = 50;
int aux = 1;
float aux2 = 0;
int d = 166;
char caractere;

void setup() {
  
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);

  for(i=0;i<3;i++){
    hora_atual[i] = 0;
  }
  for(i=0;i<6;i++){
    h[i][0] = 0;
    h[i][1] = 0;
    h[i][2] = 0;
  }
  lcd.begin(16, 2);
  //Inicializar();
  Hora_atual();
  Qtd_vezes();
  Qtd_comida();
  Hora();
  
}

void loop() {

  for(i=1;i<=vezes;i++){
    if((hora_atual[0] == h[i][0]) && (hora_atual[1] == h[i][1]) && (hora_atual[2] == h[i][2])){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Oba!");
      lcd.setCursor(0,1);
      lcd.print("Hora de comer!");
      motorAgua();
      motorComida();
      lcd.clear();
    }
  }

  if((millis() - aux2) > 1000){
    if(hora_atual[2]==59){
      hora_atual[2] = 0;
      hora_atual[1]++;
    }

    else{
      hora_atual[2]++;
    }

    if(hora_atual[1]==60){
      hora_atual[1] = 0;
      hora_atual[0]++;
    }

    if(hora_atual[0]==24){
      hora_atual[0] = 0;
    }

    aux2 = millis();
  }

  lcd.setCursor(0,1);
  lcd.print("Hora: ");
  if(hora_atual[0]<10){
      lcd.setCursor(6,1);
      lcd.print("0");
      lcd.setCursor(7,1);
      lcd.print(hora_atual[0]);
      lcd.setCursor(8,1);
      lcd.print(":");
      
    }

    else{
      lcd.setCursor(6,1);
      lcd.print(hora_atual[0]);
      lcd.setCursor(8,1);
      lcd.print(":");
    }

    if(hora_atual[1]<10){
      lcd.setCursor(9,1);
      lcd.print("0");
      lcd.setCursor(10,1);
      lcd.print(hora_atual[1]);
      lcd.setCursor(11,1);
      lcd.print(":");
    }

    else{
      lcd.setCursor(9,1);
      lcd.print(hora_atual[1]);
      lcd.setCursor(11,1);
      lcd.print(":");
    }

    if(hora_atual[2]<10){
      lcd.setCursor(12,1);
      lcd.print("0");
      lcd.setCursor(13,1);
      lcd.print(hora_atual[2]);
    }

    else{
      lcd.setCursor(12,1);
      lcd.print(hora_atual[2]);
    }

    lcd.setCursor(0,0);
    lcd.print("Funcionando");
    lcd.setCursor(11,0);
    lcd.print(".");
    delay(d);
    lcd.setCursor(12,0);
    lcd.print(".");
    delay(d);
    lcd.setCursor(13,0);
    lcd.print(".");
    delay(d);
    lcd.setCursor(13,0);
    lcd.print(" ");
    delay(d);
    lcd.setCursor(12,0);
    lcd.print(" ");
    delay(d);
    lcd.setCursor(11,0);
    lcd.print(" ");
    delay(d);
   
    
  
  
}

void Inicializar(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A");
  delay(delay_inic);

  lcd.setCursor(1,0);
  lcd.print("l");
  delay(delay_inic);

  lcd.setCursor(2,0);
  lcd.print("i");
  delay(delay_inic);

  lcd.setCursor(3,0);
  lcd.print("m");
  delay(delay_inic);

  lcd.setCursor(4,0);
  lcd.print("e");
  delay(delay_inic);

  lcd.setCursor(5,0);
  lcd.print("n");
  delay(delay_inic);

  lcd.setCursor(6,0);
  lcd.print("t");
  delay(delay_inic);

  lcd.setCursor(7,0);
  lcd.print("a");
  delay(delay_inic);

  lcd.setCursor(8,0);
  lcd.print("d");
  delay(delay_inic);

  lcd.setCursor(9,0);
  lcd.print("o");
  delay(delay_inic);

  lcd.setCursor(10,0);
  lcd.print("r");
  delay(delay_inic);

  lcd.setCursor(12,0);
  lcd.print("p");
  delay(delay_inic);

  lcd.setCursor(13,0);
  lcd.print("a");
  delay(delay_inic);

  lcd.setCursor(14,0);
  lcd.print("r");
  delay(delay_inic);

  lcd.setCursor(15,0);
  lcd.print("a");
  delay(delay_inic);

  lcd.setCursor(4,1);
  lcd.print("A");
  delay(delay_inic);

  lcd.setCursor(5,1);
  lcd.print("n");
  delay(delay_inic);

  lcd.setCursor(6,1);
  lcd.print("i");
  delay(delay_inic);

  lcd.setCursor(7,1);
  lcd.print("m");
  delay(delay_inic);

  lcd.setCursor(8,1);
  lcd.print("a");
  delay(delay_inic);

  lcd.setCursor(9,1);
  lcd.print("i");
  delay(delay_inic);

  lcd.setCursor(10,1);
  lcd.print("s");
  delay(delay_inic);

  lcd.clear();
  delay(delay_pisca);
  lcd.setCursor(0,0);
  lcd.print("Alimentador para");
  lcd.setCursor(4,1);
  lcd.print("Animais");
  delay(delay_pisca);

  lcd.clear();
  delay(delay_pisca);
  lcd.setCursor(0,0);
  lcd.print("Alimentador para");
  lcd.setCursor(4,1);
  lcd.print("Animais");
  delay(2000);

  lcd.clear();
  
}

void Hora_atual(){

  lcd.setCursor(0,0);
  lcd.print("Que horas sao?");
  lcd.setCursor(0,1);
  lcd.print("Hora: 00:00:00");
  controle=0;

  //horas
  while(controle==0){
    setHora_atual();
    if(hora_atual[0]<10){
      lcd.setCursor(6,1);
      lcd.print("0");
      lcd.setCursor(7,1);
      lcd.print(hora_atual[0]);
      lcd.setCursor(8,1);
      lcd.print(":");
      lcd.setCursor(8,1);
      lcd.print(" ");
      //delay(100);
      lcd.setCursor(8,1);
      lcd.print(":");
      //delay(100);
      
    }

    else{
      lcd.setCursor(6,1);
      lcd.print(hora_atual[0]);
      lcd.setCursor(8,1);
      lcd.print(":");
      lcd.setCursor(8,1);
      lcd.print(" ");
      //delay(100);
      lcd.setCursor(8,1);
      lcd.print(":");
      //delay(100);
    }
  }
  controle=0;

  //minutos
  while(controle==0){
    setMinuto_atual();
    if(hora_atual[1]<10){
      lcd.setCursor(9,1);
      lcd.print("0");
      lcd.setCursor(10,1);
      lcd.print(hora_atual[1]);
      lcd.setCursor(11,1);
      lcd.print(":");
      lcd.setCursor(11,1);
      lcd.print(" ");
      //delay(100);
      lcd.setCursor(11,1);
      lcd.print(":");
      //delay(100);
    }

    else{
      lcd.setCursor(9,1);
      lcd.print(hora_atual[1]);
      lcd.setCursor(11,1);
      lcd.print(":");
      lcd.setCursor(11,1);
      lcd.print(" ");
      //delay(100);
      lcd.setCursor(11,1);
      lcd.print(":");
      //delay(100);
    }
  }
  controle = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Horario atual");
  lcd.setCursor(0,1);
  lcd.print("ajustado");
  delay(2000);
  lcd.clear();
}

void setHora_atual(){
  //estado1 = digitalRead(botao1);
  //estado2 = digitalRead(botao2);
  if (Serial1.available()) { // Verificar se há caracteres disponíveis
       caractere = Serial1.read(); // Armazena caracter lido.
       Serial.print("Char Received =");
       Serial.println(caractere); 
  }

  if(caractere == 'A') {
         estado1=1;
         estado2=0;
  }

  else if(caractere == 'B') {
         estado1=0;
         estado2=1;
  }
  
  else if(caractere == 'X'){
        estado1=0;
        estado2=0;
  }

  if((estado1==1) && (estado2==0)){
    if(hora_atual[0]==23){
      hora_atual[0] = 0;
    }

    else{
      hora_atual[0]++;
    }
  }

  else if((estado1==0) && (estado2==1)){
    controle = 1;
  }
}

void setMinuto_atual(){
  //estado1 = digitalRead(botao1);
  //estado2 = digitalRead(botao2);

  if (Serial1.available()) { // Verificar se há caracteres disponíveis
       caractere = Serial1.read(); // Armazena caracter lido.
       Serial.print("Char Received =");
       Serial.println(caractere); 
  }

  if(caractere == 'A') {
         estado1=1;
         estado2=0;
  }

  if(caractere == 'B') {
         estado1=0;
         estado2=1;
  }
  
  else if(caractere == 'X'){
        estado1=0;
        estado2=0;
  }

  if((estado1==1) && (estado2==0)){
    if(hora_atual[1]==59){
      hora_atual[1] = 0;
    }

    else{
      hora_atual[1]++;
    }
  }

  else if((estado1==0) && (estado2==1)){
    controle = 1;
  }
}

//quantidade de vezes

void Qtd_vezes(){

  lcd.setCursor(0,0);
  lcd.print("Quantas vezes?");
  lcd.setCursor(0,1);
  lcd.print("1 vezes ao dia");
  controle=0;

  while(controle==0){
    setVezes();
    lcd.setCursor(0,1);
    lcd.print(vezes);
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Voce escolheu:");
  lcd.setCursor(0,1);
  lcd.print(vezes);
  lcd.setCursor(2,1);
  lcd.print("vezes ao dia");

  delay(2500);
  lcd.clear();
}

void setVezes(){
  //estado1 = digitalRead(botao1);
  //estado2 = digitalRead(botao2);
  //delay(200);

  if (Serial1.available()) { // Verificar se há caracteres disponíveis
       caractere = Serial1.read(); // Armazena caracter lido. 
       Serial.print("Char Received =");
       Serial.println(caractere);
  }

  if(caractere == 'A') {
         estado1=1;
         estado2=0;
  }

  if(caractere == 'B') {
         estado1=0;
         estado2=1;
  }
  
  else if(caractere == 'X'){
        estado1=0;
        estado2=0;
  }

  if((estado1==1) && (estado2==0)){
    if(vezes==5){
      vezes = 1;
    }

    else{
      vezes++;
    }
  }

  else if((estado1==0) && (estado2==1)){
    controle = 1;
  }
}

//quantidade de comida

void Qtd_comida(){

  lcd.setCursor(0,0);
  lcd.print("Quantas gramas?");
  lcd.setCursor(0,1);
  lcd.print("50 g");
  controle=0;

  while(controle==0){
    setGramas();
    lcd.setCursor(0,1);
    lcd.print(gramas);

    if(gramas<100){
      lcd.setCursor(2,1);
      lcd.print(" g ");
    }
    else if(gramas>=100){
      lcd.setCursor(3,1);
      lcd.print(" g");
    }
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Voce escolheu:");
  lcd.setCursor(0,1);
  lcd.print(gramas);
  lcd.setCursor(4,1);
  lcd.print("gramas");

  delay(2500);
  lcd.clear();
}

void setGramas(){
  //estado1 = digitalRead(botao1);
  //estado2 = digitalRead(botao2);
  //delay(200);

  if (Serial1.available()) { // Verificar se há caracteres disponíveis
       caractere = Serial1.read(); // Armazena caracter lido. 
       Serial.print("Char Received =");
       Serial.println(caractere);
  }

  if(caractere == 'A') {
         estado1=1;
         estado2=0;
  }

  if(caractere == 'B') {
         estado1=0;
         estado2=1;
  }
  
  else if(caractere == 'X'){
        estado1=0;
        estado2=0;
  }

  if((estado1==1) && (estado2==0)){
    if(gramas==150){
      gramas = 50;
    }

    else{
      gramas = gramas + 25;
    }
  }

  else if((estado1==0) && (estado2==1)){
    controle = 1;
  }
}

void Hora(){

  lcd.setCursor(0,0);
  lcd.print("Defina as horas:");
  controle=0;

  //horas
  while(aux<=vezes){
  while(controle==0){
    setHora();
    if(h[aux][0]<10){
      lcd.setCursor(0,1);
      lcd.print("Hora");
      lcd.setCursor(5,1);
      lcd.print(aux);
      lcd.setCursor(6,1);
      lcd.print(": 00:00:00");
      
      lcd.setCursor(8,1);
      lcd.print("0");
      lcd.setCursor(9,1);
      lcd.print(h[aux][0]);
      lcd.setCursor(10,1);
      lcd.print(":");
      lcd.setCursor(10,1);
      lcd.print(" ");
      //delay(100);
      lcd.setCursor(10,1);
      lcd.print(":");
      //delay(100);
      
    }

    else{
      lcd.setCursor(8,1);
      lcd.print(h[aux][0]);
      lcd.setCursor(10,1);
      lcd.print(":");
      lcd.setCursor(10,1);
      lcd.print(" ");
      //delay(100);
      lcd.setCursor(10,1);
      lcd.print(":");
      //delay(100);
    }
  }
  controle=0;

  //minutos
  while(controle==0){
    setMinuto();
    if(h[aux][1]<10){
      lcd.setCursor(11,1);
      lcd.print("0");
      lcd.setCursor(12,1);
      lcd.print(h[aux][1]);
      lcd.setCursor(13,1);
      lcd.print(":");
      lcd.setCursor(13,1);
      lcd.print(" ");
      //delay(100);
      lcd.setCursor(13,1);
      lcd.print(":");
      //delay(100);
    }

    else{
      lcd.setCursor(11,1);
      lcd.print(h[aux][1]);
      lcd.setCursor(13,1);
      lcd.print(":");
      lcd.setCursor(13,1);
      lcd.print(" ");
      //delay(100);
      lcd.setCursor(13,1);
      lcd.print(":");
      //delay(100);
    }
  }
  controle=0;
  aux++;
  }
  controle = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Horas definidas");
  delay(2000);
  lcd.clear();

  Serial1.write('A');
}

void setHora(){
  //estado1 = digitalRead(botao1);
  //estado2 = digitalRead(botao2);

  if (Serial1.available()) { // Verificar se há caracteres disponíveis
        caractere = Serial1.read(); // Armazena caracter lido. 
        Serial.print("Char Received =");
       Serial.println(caractere);
  }

  if(caractere == 'A') {
         estado1=1;
         estado2=0;
  }

  if(caractere == 'B') {
         estado1=0;
         estado2=1;
  }
  
  else if(caractere == 'X'){
        estado1=0;
        estado2=0;
  }
 

  if((estado1==1) && (estado2==0)){
    if(h[aux][0]==23){
      h[aux][0] = 0;
    }

    else{
      h[aux][0]++;
    }
  }

  else if((estado1==0) && (estado2==1)){
    controle = 1;
  }
}

void setMinuto(){
  //estado1 = digitalRead(botao1);
  //estado2 = digitalRead(botao2);

  if (Serial1.available()) { // Verificar se há caracteres disponíveis
       caractere = Serial1.read(); // Armazena caracter lido. 
       Serial.print("Char Received =");
       Serial.println(caractere);
  }

  if(caractere == 'A') {
         estado1=1;
         estado2=0;
  }

  if(caractere == 'B') {
         estado1=0;
         estado2=1;
  }
  
 else if(caractere == 'X'){
        estado1=0;
        estado2=0;
  }

  if((estado1==1) && (estado2==0)){
    if(h[aux][1]==59){
      h[aux][1] = 0;
    }

    else{
      h[aux][1]++;
    }
  }

  else if((estado1==0) && (estado2==1)){
    controle = 1;
  }
}

void motorComida(){

  if(gramas==50){
    myStepper1.step(-500);
    delay(500);
    myStepper1.step(500);
  }

  else if(gramas==75){
    myStepper1.step(200);
    delay(500);
    myStepper1.step(-200);
  }

  else if(gramas==100){
    myStepper1.step(200);
    delay(500);
    myStepper1.step(-200);
  }

  else if(gramas==125){
    myStepper1.step(200);
    delay(500);
    myStepper1.step(-200);
  }

  else if(gramas==150){
    myStepper1.step(200);
    delay(500);
    myStepper1.step(-200);
  }
  
}

void motorAgua(){
  for ( i = 0; i<=3; i++)
 {
 myStepper2.step(-600); 
 }

 delay(3500);

 for ( i = 0; i<=3; i++)
 {
 myStepper2.step(600); 
 }
}






