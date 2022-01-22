#include <AccelStepper.h>

#define homeFunc
#define moveCom
#define serial
#define gripperCom
#define printPosition
#define printParameters
#define homeOneAxis
#define printLimitSwitchStatus
#define setParameters

#define LS1_PIN 26
#define LS2_PIN 27
#define LS3_PIN 28
#define LS4_PIN 29
#define LS5_PIN 30
#define LS6_PIN 31

#define inputSize 48            //Maximum size of the gcode serial input string
#define stepsPerRev 6400.0      //Number of mictosteps per revolution
#define minPulseWidth 25        //Set the minimum width of the step pulse in microseconds


double stepCount = stepsPerRev/360.0;    //Look at this later - this math might cause accumulating error over time

//Define gearbox ratios
#define gear1 15.3
#define gear2 30.6 //15.3*2
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

//Define 6 stepper motors and gripper position double
AccelStepper stepper1;
AccelStepper stepper2;
AccelStepper stepper3;
AccelStepper stepper4;
AccelStepper stepper5;
AccelStepper stepper6;
double gripperPos = 0;

char input[inputSize+1];

//Define  motion parameters
double accel1 = 750;
double accel2 = 750;
double accel3 = 750;
double accel4 = 750;
double accel5 = 750;
double accel6 = 750;
double vel1 = 100;
double vel2 = 100;
double vel3 = 100;
double vel4 = 100;
double vel5 = 100;
double vel6 = 100;

//Define rotation limis for each joint
double minAngle1 = -90.0;
double maxAngle1 = 90.0;
double minAngle2 = -10.0;
double maxAngle2 = 90.0;
double minAngle3 = 0.0;
double maxAngle3 = 135.0;
double minAngle4 = -90.0;
double maxAngle4 = 90.0;
double minAngle5 = -90.0;
double maxAngle5 = 90.0;
double minAngle6 = -180.0;
double maxAngle6 = 180.0;

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
  

  Serial.begin(57600);
  delay(2000);

  //print the current parameters
  printParams();
      
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
