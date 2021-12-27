#include <AccelStepper.h>

#define homeFunc
#define moveCom
#define serial
#define gripperCom
#define printPosition
#define homeOneAxis
#define StackQueue

#define inputSize 48            //Maximum size of the gcode serial input string
#define stepsPerRev 6400.0      //Number of mictosteps per revolution
#define accel1 750
#define accel2 750
#define accel3 750
#define accel4 750
#define accel5 750
#define accel6 750          
#define vel1 100
#define vel2 100
#define vel3 100
#define vel4 100
#define vel5 100
#define vel6 100
#define minPulseWidth 25        //Set the minimum width of the step pulse in microseconds


double stepCount = stepsPerRev/360.0;    //Look at this later - this math might cause accumulating error over time

//Define gearbox ratios
#define gear1 15.3
#define gear2 15.3*2
#define gear3 13.73
#define gear4 26.85
#define gear5 26.85
#define gear6 5.18
    
//Define "home" position for all axes
#define home1 0.0
#define home2 0.0
#define home3 0.0
#define home4 0.0
#define home5 0.0
#define home6 0.0

//Define 6 stepper motors
AccelStepper stepper1;
AccelStepper stepper2;
AccelStepper stepper3;
AccelStepper stepper4;
AccelStepper stepper5;
AccelStepper stepper6;

char input[inputSize+1];

//Define rotation limis for each joint
double lowerLim1= -90.0;
double upperLim1= 90.0;
double lowerLim2= -10.0;
double upperLim2= 90.0;
double lowerLim3= 0.0;
double upperLim3= 135.0;
double lowerLim4= -90.0;
double upperLim4= 90.0;
double lowerLim5= -90.0;
double upperLim5= 90.0;
double lowerLim6= -180.0;
double upperLim6= 180.0;

void setup(){
 
  //Set pins for digital output to control stepper drivers
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);  //output to arduino Uno to control gripper
  
  //Set pins for limit switches
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);

  
  //initialize 6 stepper motors and set speed/acceleration limits
  stepper1 = AccelStepper(AccelStepper::DRIVER, 12, 24);
  stepper1.setSpeed(vel1*gear1);
  stepper1.setAcceleration(accel1*gear1);
  stepper1.setMinPulseWidth(minPulseWidth);

  stepper2 = AccelStepper(AccelStepper::DRIVER, 10, 11);
  stepper2.setSpeed(vel2*gear2);
  stepper2.setAcceleration(accel2*gear2);
  stepper2.setMinPulseWidth(minPulseWidth);

  stepper3 = AccelStepper(AccelStepper::DRIVER, 8, 9);
  stepper3.setSpeed(vel3*gear3);
  stepper3.setAcceleration(accel3*gear3);
  stepper3.setMinPulseWidth(minPulseWidth);

  stepper4 = AccelStepper(AccelStepper::DRIVER, 6, 7);
  stepper4.setSpeed(vel4*gear4);
  stepper4.setAcceleration(accel4*gear4);
  stepper4.setMinPulseWidth(minPulseWidth);

  stepper5 = AccelStepper(AccelStepper::DRIVER, 4, 5);
  stepper5.setSpeed(vel5*gear5);
  stepper5.setAcceleration(accel5*gear5);
  stepper5.setMinPulseWidth(minPulseWidth);

  stepper6 = AccelStepper(AccelStepper::DRIVER, 2, 3);
  stepper6.setSpeed(vel6*gear6);
  stepper6.setAcceleration(accel6*gear6);
  stepper6.setMinPulseWidth(minPulseWidth);
  

  Serial.begin(9600);
  delay(2000);

  //Ask to home all axes
  Serial.println("Position is lost. Please type 'home' to home");

  //Ask user for move input
  Serial.println("Move?");
  
}

void loop(){

  //If serial data is availible and the motors are not running, call the getSerial() function to read in serial data
  if(Serial.available() && !stepper1.isRunning() && !stepper2.isRunning() && !stepper3.isRunning() && !stepper4.isRunning() && !stepper5.isRunning() && !stepper6.isRunning()){
    getSerial();
    
    //Ask user for move input
    Serial.println("\nMove?");
  }
  
  //Run motors if a step is due
  stepper1.run();
  stepper2.run();
  stepper3.run();
  stepper4.run();
  stepper5.run();
  stepper6.run();
  delayMicroseconds(10);
  
}

void setAccel(int id, double accel){
  if (id == 1){ stepper1.setAcceleration(accel*gear1); }
  else if (id == 2){ stepper2.setAcceleration(accel*gear2); }
  else if (id == 3){ stepper3.setAcceleration(accel*gear3); }
  else if (id == 4){ stepper4.setAcceleration(accel*gear4); }
  else if (id == 5){ stepper5.setAcceleration(accel*gear5); }
  else if (id == 6){ stepper6.setAcceleration(accel*gear6); }
}
void setVel(int id, double vel){
  if (id == 1){ stepper1.setSpeed(vel*gear1); }
  else if (id == 2){ stepper2.setSpeed(vel*gear2); }
  else if (id == 3){ stepper3.setSpeed(vel*gear3); }
  else if (id == 4){ stepper4.setSpeed(vel*gear4); }
  else if (id == 5){ stepper5.setSpeed(vel*gear5); }
  else if (id == 6){ stepper6.setSpeed(vel*gear6); }
}
void setMin(int id, double lim){
  if (id == 1){ lowerLim1 = lim; }
  else if (id == 2){ lowerLim2 = lim; }
  else if (id == 3){ lowerLim3 = lim; }
  else if (id == 4){ lowerLim4 = lim; }
  else if (id == 5){ lowerLim5 = lim; }
  else if (id == 6){ lowerLim6 = lim; }
}
void setMax(int id, double lim){
  if (id == 1){ upperLim1 = lim; }
  else if (id == 2){ upperLim2 = lim; }
  else if (id == 3){ upperLim3 = lim; }
  else if (id == 4){ upperLim4 = lim; }
  else if (id == 5){ upperLim5 = lim; }
  else if (id == 6){ upperLim6 = lim; }
}
