
//The limit switch pins
#define LS1 26
#define LS2 27
#define LS3 28
#define LS4 29
#define LS5 30
#define LS6 31


void home(){
  
  Serial.println("Homing all axes");

  //Command motion of the full motion range in the negative direction, but don't move (call run) ) yet
  stepper1.moveTo(-(maxAngle1-minAngle1)*stepCount*gear1);
  stepper2.moveTo(-(maxAngle2-minAngle2)*stepCount*gear2);
  stepper3.moveTo(-(maxAngle3-minAngle3)*stepCount*gear3);
  stepper4.moveTo(-(maxAngle4-minAngle4)*stepCount*gear4);
  stepper5.moveTo(-(maxAngle5-minAngle5)*stepCount*gear5);
  stepper6.moveTo(-(maxAngle6-minAngle6)*stepCount*gear6);

  //Stepper 1
  int val = digitalRead(LS1);   //Check if limit swithc is pressed
  while(val == 0){              //run until limit switch is pressed
    stepper1.run();
    val = digitalRead(LS1);     //Check if limit switch is pressed
  }
  Serial.println("Stepper 1 is zeroed!");
  
  //Stepper 2
  val = digitalRead(LS2);
  while(val == 0){
    stepper2.run();
    val = digitalRead(LS2);
  }
  Serial.println("Stepper 2 is zeroed!");
  
  //Stepper 3
  val = digitalRead(LS3);
  while(val == 0){
    stepper3.run();
    val = digitalRead(LS3);
  }
  Serial.println("Stepper 3 is zeroed!");

  //Stepper 4
  val = digitalRead(LS4);
  while(val == 0){
    stepper4.run();
    val = digitalRead(LS4);
  }
  Serial.println("Stepper 4 is zeroed!");

  //Stepper 5
  val = digitalRead(LS5);
  while(val == 0){
    stepper5.run();
    val = digitalRead(LS5);
  }
  Serial.println("Stepper 5 is zeroed!");

  //Stepper 6
  val = digitalRead(LS6);
  while(val == 0){
    stepper6.run();
    val = digitalRead(LS6);
  }
  Serial.println("Stepper 6 is zeroed!");

  Serial.println("\nMoving to home\n");
  delay(250);

  //Move all axis to the home position (0, center of travel right now)
  moveCommand("1", -minAngle1);
  moveCommand("2", -minAngle2);
  moveCommand("3", -minAngle3);
  moveCommand("4", -minAngle4);
  moveCommand("5", -minAngle5);
  moveCommand("6", -minAngle6);

  //While axes are not in the commanded position, keep calling run
  while(stepper1.currentPosition() != stepper1.targetPosition() || stepper2.currentPosition() != stepper2.targetPosition() || stepper3.currentPosition() != stepper3.targetPosition() || 
        stepper4.currentPosition() != stepper4.targetPosition() || stepper5.currentPosition() != stepper5.targetPosition() || stepper6.currentPosition() != stepper6.targetPosition()){
    
    stepper1.run();
    stepper2.run();
    stepper3.run();
    stepper4.run();
    stepper5.run();
    stepper6.run();
    
  }

  //Set the homed position as zero
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
  stepper4.setCurrentPosition(0);
  stepper5.setCurrentPosition(0);
  stepper6.setCurrentPosition(0);
  

  Serial.println("All axes are Home!");
}
