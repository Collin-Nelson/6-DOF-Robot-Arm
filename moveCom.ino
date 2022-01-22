

//Does the math and checks for a command to move (Axis 1-6 and servo gripper (7))
void moveCommand(String servoId, double degrees){
  if(servoId == "1"){
    if(minAngle1 <= degrees && degrees <= maxAngle1){   //checks if the move is valid
      int position = degrees*gear1*stepCount;           //converts degrees into steps based on steps per rev and grea ratio
      stepper1.moveTo(position);                        //commands stepper to move
      Serial.print("Moving servo 1 to: ");
      Serial.println(position);
    } else {
      Serial.println("Servo 1 position out of range");
    }
  }
  if(servoId == "2"){
    if(minAngle2 <= degrees && degrees <= maxAngle2){
      int position = degrees*gear2*stepCount;
      stepper2.moveTo(-1*position);
      Serial.print("Moving servo 2 to: ");
      Serial.println(position);
    } else {
      Serial.println("Servo 2 position out of range");
    }
  }
  if(servoId == "3"){
    if(minAngle3 <= degrees && degrees <= maxAngle3){
      int position = degrees*gear3*stepCount;
      stepper3.moveTo(position);
      Serial.print("Moving servo 3 to: ");
      Serial.println(position);
    } else {
      Serial.println("Servo 3 position out of range");
    }
  }
  if(servoId == "4"){
    if(minAngle4 <= degrees && degrees <= maxAngle4){
      int position = degrees*gear4*stepCount;
      stepper4.moveTo(position);
      Serial.print("Moving servo 4 to: ");
      Serial.println(position);
    } else {
      Serial.println("Servo 4 position out of range");
    }
  }
  if(servoId == "5"){
    if(minAngle5 <= degrees && degrees <= maxAngle5){
      int position = degrees*gear5*stepCount;
      stepper5.moveTo(position);
      Serial.print("Moving servo 5 to: ");
      Serial.println(position);
    } else {
      Serial.println("Servo 5 position out of range");
    }
  }
  if(servoId == "6"){
    if(minAngle6 <= degrees && degrees <= maxAngle6){
      int position = degrees*gear6*stepCount;
      stepper6.moveTo(position);
      Serial.print("Moving servo 6 to: ");
      Serial.println(position);
    } else {
      Serial.println("Servo 6 position out of range");
    }
  }
  if(servoId == "7"){
    if(degrees == 0 || degrees == 180){
      gripperCommand((int) degrees);
      Serial.print("Moving gripper to: ");
      Serial.println(degrees);
    } else {
      Serial.println("Gripper position out of range");
    }
  }
}
