

//Does the math and checks for a command to move (Axis 1-6 and servo gripper (7))
void moveCommand(int servoId, double degrees){
  switch(servoId){
    case 1:
      if(lowerLim1 <= degrees && degrees <= upperLim1){   //checks if the move is valid
        int position = degrees*gear1*stepCount;           //converts degrees into steps based on steps per rev and grea ratio
        stepper1.moveTo(position);                        //commands stepper to move
        Serial.print("Moving servo 1 to: ");
        Serial.println(position);
      } else {
        Serial.println("Servo 1 position out of range");
      }
      break;
    case 2:
      if(lowerLim2 <= degrees && degrees <= upperLim2){
        int position = degrees*gear2*stepCount;
        stepper2.moveTo(-1*position);
        Serial.print("Moving servo 2 to: ");
        Serial.println(position);
      } else {
        Serial.println("Servo 2 position out of range");
      }
      break;
    case 3:
      if(lowerLim3 <= degrees && degrees <= upperLim3){
        int position = degrees*gear3*stepCount;
        stepper3.moveTo(position);
        Serial.print("Moving servo 3 to: ");
        Serial.println(position);
      } else {
        Serial.println("Servo 3 position out of range");
      }
      break;
    case 4:
      if(lowerLim4 <= degrees && degrees <= upperLim4){
        int position = degrees*gear4*stepCount;
        stepper4.moveTo(position);
        Serial.print("Moving servo 4 to: ");
        Serial.println(position);
      } else {
        Serial.println("Servo 4 position out of range");
      }
      break;
    case 5:
      if(lowerLim5 <= degrees && degrees <= upperLim5){
        int position = degrees*gear5*stepCount;
        stepper5.moveTo(position);
        Serial.print("Moving servo 5 to: ");
        Serial.println(position);
      } else {
        Serial.println("Servo 5 position out of range");
      }
      break;
    case 6:
      if(lowerLim6 <= degrees && degrees <= upperLim6){
        int position = degrees*gear6*stepCount;
        stepper6.moveTo(position);
        Serial.print("Moving servo 6 to: ");
        Serial.println(position);
      } else {
        Serial.println("Servo 6 position out of range");
      }
      break;
    case 7:
      if(degrees == 0 || degrees == 180){
        gripperCommand((int) degrees);
        Serial.print("Moving gripper to: ");
        Serial.println(degrees);
      } else {
        Serial.println("Gripper position out of range");
      }
      break;
      
  }
}
