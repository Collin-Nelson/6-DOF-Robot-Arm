

void homeAxis(String axis){
  Serial.print("Homeing Axis: ");
  Serial.println(axis);

  if(axis == "1"){
    stepper1.moveTo(-(maxAngle1-minAngle1)*stepCount*gear1);
    int val = digitalRead(LS1);   //Check if limit swithc is pressed
    while(val == 0){              //run until limit switch is pressed
      stepper1.run();
      val = digitalRead(LS1);     //Check if limit switch is pressed
    }
    Serial.println("Stepper 1 is zeroed!");
    
    Serial.println("\nMoving axis 1 to home\n");
    delay(250);
    
    moveCommand(1, -minAngle1);

    //move until home
    while(stepper1.currentPosition() != stepper1.targetPosition()){
      stepper1.run();
    }

    //Set the homed position as zero
    stepper1.setCurrentPosition(0);
  }
  if(axis == "2"){
    stepper2.moveTo(-(maxAngle2-minAngle2)*stepCount*gear2);
    int val = digitalRead(LS2);
    while(val == 0){
      stepper2.run();
      val = digitalRead(LS2);
    }
    Serial.println("Stepper 2 is zeroed!");
    
    Serial.println("\nMoving axis 2 to home\n");
    delay(250);
    
    moveCommand(2, -minAngle2);

    //move until home
    while(stepper2.currentPosition() != stepper2.targetPosition()){
      stepper2.run();
    }

    //Set the homed position as zero
    stepper2.setCurrentPosition(0);
  }
  if(axis == "3"){
    stepper3.moveTo(-(maxAngle3-minAngle3)*stepCount*gear3);
    int val = digitalRead(LS3);
    while(val == 0){
      stepper3.run();
      val = digitalRead(LS3);
    }
    Serial.println("Stepper 3 is zeroed!");
    
    Serial.println("\nMoving axis 3 to home\n");
    delay(250);
    
    moveCommand(3, -minAngle3);

    //move until home
    while(stepper3.currentPosition() != stepper3.targetPosition()){
      stepper3.run();
    }

    //Set the homed position as zero
    stepper3.setCurrentPosition(0);
  }
  if(axis == "4"){
    stepper4.moveTo(-(maxAngle4-minAngle4)*stepCount*gear4);
    int val = digitalRead(LS4);
    while(val == 0){
      stepper4.run();
      val = digitalRead(LS4);
    }
    Serial.println("Stepper 4 is zeroed!");
    
    Serial.println("\nMoving axis 4 to home\n");
    delay(250);

    moveCommand(4, -minAngle4);

    //move until home
    while(stepper4.currentPosition() != stepper4.targetPosition()){
      stepper4.run();
    }

    //Set the homed position as zero
    stepper4.setCurrentPosition(0);
  }
  if(axis == "5"){
    stepper5.moveTo(-(maxAngle5-minAngle5)*stepCount*gear5);
    int val = digitalRead(LS5);
    while(val == 0){
      stepper5.run();
      val = digitalRead(LS5);
    }
    Serial.println("Stepper 5 is zeroed!");
    
    Serial.println("\nMoving axis 5 to home\n");
    delay(250);

    moveCommand(5, -minAngle5);

    //move until home
    while(stepper5.currentPosition() != stepper5.targetPosition()){
      stepper5.run();
    }

    //Set the homed position as zero
    stepper5.setCurrentPosition(0);
  }
  if(axis == "6"){
    stepper6.moveTo(-(maxAngle6-minAngle6)*stepCount*gear6);
    int val = digitalRead(LS6);
    while(val == 0){
      stepper6.run();
      val = digitalRead(LS6);
    }
    Serial.println("Stepper 6 is zeroed!");
    
    Serial.println("\nMoving axis 6 to home\n");
    delay(250);

    moveCommand(6, -minAngle6);

    //move until home
    while(stepper6.currentPosition() != stepper6.targetPosition()){
      stepper6.run();
    }

    //Set the homed position as zero
    stepper6.setCurrentPosition(0);
  }
  

  Serial.println("Axis is Home!");
}
