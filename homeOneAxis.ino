

void homeAxis(int axis){
  Serial.print("Homeing Axis: ");
  Serial.println(axis);

  switch (axis){
    case 1:
      stepper1.moveTo(-(upperLim1-lowerLim1)*stepCount*gear1);
      int val = digitalRead(LS1);   //Check if limit swithc is pressed
      while(val == 0){              //run until limit switch is pressed
        stepper1.run();
        val = digitalRead(LS1);     //Check if limit switch is pressed
      }
      Serial.println("Stepper 1 is zeroed!");
      
      Serial.println("\nMoving axis 1 to home\n");
      delay(250);
      
      moveCommand(1, -lowerLim1);

      //move until home
      while(stepper1.currentPosition() != stepper1.targetPosition()){
        stepper1.run();
      }

      //Set the homed position as zero
      stepper1.setCurrentPosition(0);
  
      break;
      
    case 2:
      stepper2.moveTo(-(upperLim2-lowerLim2)*stepCount*gear2);
      val = digitalRead(LS2);
      while(val == 0){
        stepper2.run();
        val = digitalRead(LS2);
      }
      Serial.println("Stepper 2 is zeroed!");
      
      Serial.println("\nMoving axis 2 to home\n");
      delay(250);
      
      moveCommand(2, -lowerLim2);

      //move until home
      while(stepper2.currentPosition() != stepper2.targetPosition()){
        stepper2.run();
      }

      //Set the homed position as zero
      stepper2.setCurrentPosition(0);
  
      break;
      
    case 3:
      stepper3.moveTo(-(upperLim3-lowerLim3)*stepCount*gear3);
      val = digitalRead(LS3);
      while(val == 0){
        stepper3.run();
        val = digitalRead(LS3);
      }
      Serial.println("Stepper 3 is zeroed!");
      
      Serial.println("\nMoving axis 3 to home\n");
      delay(250);
      
      moveCommand(3, -lowerLim3);

      //move until home
      while(stepper3.currentPosition() != stepper3.targetPosition()){
        stepper3.run();
      }

      //Set the homed position as zero
      stepper3.setCurrentPosition(0);
  
      break;
      
    case 4:
      stepper4.moveTo(-(upperLim4-lowerLim4)*stepCount*gear4);
      val = digitalRead(LS4);
      while(val == 0){
        stepper4.run();
        val = digitalRead(LS4);
      }
      Serial.println("Stepper 4 is zeroed!");
      
      Serial.println("\nMoving axis 4 to home\n");
      delay(250);

      moveCommand(4, -lowerLim4);

      //move until home
      while(stepper4.currentPosition() != stepper4.targetPosition()){
        stepper4.run();
      }

      //Set the homed position as zero
      stepper4.setCurrentPosition(0);
  
      break;
      
    case 5:
      stepper5.moveTo(-(upperLim5-lowerLim5)*stepCount*gear5);
      val = digitalRead(LS5);
      while(val == 0){
        stepper5.run();
        val = digitalRead(LS5);
      }
      Serial.println("Stepper 5 is zeroed!");
      
      Serial.println("\nMoving axis 5 to home\n");
      delay(250);

      moveCommand(5, -lowerLim5);

      //move until home
      while(stepper5.currentPosition() != stepper5.targetPosition()){
        stepper5.run();
      }

      //Set the homed position as zero
      stepper5.setCurrentPosition(0);
  
      break;
      
    case 6:
      stepper6.moveTo(-(upperLim6-lowerLim6)*stepCount*gear6);
      val = digitalRead(LS6);
      while(val == 0){
        stepper6.run();
        val = digitalRead(LS6);
      }
      Serial.println("Stepper 6 is zeroed!");
      
      Serial.println("\nMoving axis 6 to home\n");
      delay(250);

      moveCommand(6, -lowerLim6);

      //move until home
      while(stepper6.currentPosition() != stepper6.targetPosition()){
        stepper6.run();
      }

      //Set the homed position as zero
      stepper6.setCurrentPosition(0);
  
      break;
      
  }
  

  Serial.println("Axis is Home!");
}
