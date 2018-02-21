# alpfinder
Android Lock Pattern Finder for Arduino
2018 - Sebastian Gomez - Gabinete de Pericias Informaticas - Neuquen - Argentina
Quick reference:
1) Define a new mobile device profile using the templates included in this script. Copy and paste a template and add the main parameters x1,y1,c,h and h1 for the new device model.
  Note: The h1 parameter is used when the long diagonal is bigger than 90, because relative mouse steps are limited to this scope by the Mouse.h library. The step h is done in an iterative loop until the pointer reaches h1 distance.
2) Look the loop() procedure, enable the validate() and test() procedures and use them to calibrate the pointer within the dots. 
3) Compile and upload the code to Arduino Leonardo. Start using them, connecting a mobile device to Arduino Leonardo with OTG cable while the mobile device shows the lock pattern display.
   Note: To start the loop() procedure in Arduino Leonardo, attach a cable between Digital GND pinout (Ground) and Digital PWM pinout number 2. GND <--cable connection--> DigitalPWM-2
4) Modify the parameters x1,y1,c, h and h1 until they are well conditioned. Repeat 3) until they are well conditioned.
5) Look the loop() procedure and disable validate() and test() procedures. Enable the bruteforce() and/or dictionaryattack() procedures.
6) Compile and upload the code to Arduino Leonardo. Start using them, connecting a mobile device to Arduino Leonardo with OTG cable while the mobile device shows the lock pattern display.
   Note: To start the loop() procedure in Arduino Leonardo, attach a cable between Digital GND pinout (Ground) and Digital PWM pinout number 2. GND <--cable connection--> DigitalPWM-2
