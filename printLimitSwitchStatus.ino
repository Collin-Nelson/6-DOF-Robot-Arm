void printLimStatus(){
  Serial.println("Current LS statuses are: ");
  
  Serial.print("Stepper 1 LS: ");
  Serial.println(digitalRead(LS1_PIN));

  Serial.print("Stepper 2 LS: ");
  Serial.println(digitalRead(LS2_PIN));

  Serial.print("Stepper 3 LS: ");
  Serial.println(digitalRead(LS3_PIN));

  Serial.print("Stepper 4 LS: ");
  Serial.println(digitalRead(LS4_PIN));

  Serial.print("Stepper 5 LS: ");
  Serial.println(digitalRead(LS5_PIN));

  Serial.print("Stepper 6 LS: ");
  Serial.println(digitalRead(LS6_PIN));
}
