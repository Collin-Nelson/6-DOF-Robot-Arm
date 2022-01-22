
//Takes an int 0-255 as a position to move to and sets the PWM output appropriately
void gripperCommand(int degrees){
  if(degrees == 0){
    digitalWrite(25, LOW);
    gripperPos = 0;
  } else {
    digitalWrite(25, HIGH);
    gripperPos = 180;
  }
  
}
