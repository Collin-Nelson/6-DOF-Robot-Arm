void printPos(){
  Serial.println("Current motor positions are: ");
  
  Serial.print("Stepper 1: ");
  Serial.println(stepper1.currentPosition()/gear1/stepCount);

  Serial.print("Stepper 2: ");
  Serial.println(-stepper2.currentPosition()/gear2/stepCount);

  Serial.print("Stepper 3: ");
  Serial.println(stepper3.currentPosition()/gear3/stepCount);

  Serial.print("Stepper 4: ");
  Serial.println(stepper4.currentPosition()/gear4/stepCount);

  Serial.print("Stepper 5: ");
  Serial.println(stepper5.currentPosition()/gear5/stepCount);

  Serial.print("Stepper 6: ");
  Serial.println(stepper6.currentPosition()/gear6/stepCount);

  Serial.print("Gripper 7: ");
  Serial.println(gripperPos);
}
