//Deals with serial I/O
void getSerial(){
  //Flag if the arm position changed as a result of a commanad
  bool moved = false;

  //Read in serial data
  byte size = Serial.readBytes(input, inputSize);   //in format: 1:10.2:20.3:30.4:40.5:50.6:60 (J1 to 10, J2 to 20, etc)
  input[size] = 0;

  //split serial data by axis
  char* command = strtok(input, ".");
  
  //if recieve "help" with or without newline char, run the homing function
  if (strcmp(command, "help\n") == 0 || strcmp(command, "help") == 0){
    Serial.println("Commands are:");
    Serial.println("print pos");
    Serial.println("primt params");
    Serial.println("print lim status");
    Serial.println("home [optional axis number]");
    Serial.println("zero [optional axis number]");
    Serial.println("move commands: 'axis number':'angle commanded'");
  }
  //if recieve "print pos" with or without newline char, print the current joint angles
  if (strcmp(command, "print pos\n") == 0 || strcmp(command, "print pos") == 0){
    printPos();
  }
  //if recieve "print params" with or without newline char, print the velocity, acceleration, and min and max angles
  if (strcmp(command, "print params\n") == 0 || strcmp(command, "print params") == 0){
    printParams();
  }
  //if recieve "print lim status" with or without newline char, print the currnet limit switch statuses
  if (strcmp(command, "print lim status\n") == 0 || strcmp(command, "print lim status") == 0){
    printLimStatus();
  }
  //if recieve "zero" with or without newline char, move each joint to zero
  if (strcmp(command, "zero\n") == 0 || strcmp(command, "zero") == 0){
    moveCommand(1, 0);
    moveCommand(2, 0);
    moveCommand(3, 0);
    moveCommand(4, 0);
    moveCommand(5, 0);
    moveCommand(6, 0);
    moved = true;
  }
  //if recieve "zero [axis number]" with or without newline char, move joint to zero
  if (strcmp(command, "zero 1\n") == 0 || strcmp(command, "zero 1") == 0){ moveCommand(1, 0); moved = true; }
  if (strcmp(command, "zero 2\n") == 0 || strcmp(command, "zero 2") == 0){ moveCommand(2, 0); moved = true; }
  if (strcmp(command, "zero 3\n") == 0 || strcmp(command, "zero 3") == 0){ moveCommand(3, 0); moved = true; }
  if (strcmp(command, "zero 4\n") == 0 || strcmp(command, "zero 4") == 0){ moveCommand(4, 0); moved = true; }
  if (strcmp(command, "zero 5\n") == 0 || strcmp(command, "zero 5") == 0){ moveCommand(5, 0); moved = true; }
  if (strcmp(command, "zero 6\n") == 0 || strcmp(command, "zero 6") == 0){ moveCommand(6, 0); moved = true; }
  
  //if recieve "home" with or without newline char, run the homing function
  if (strcmp(command, "home\n") == 0 || strcmp(command, "home") == 0){
    home();
    moved = true;
  }
  //if recieve "home [axis number]" with or without newline char, run the homing function
  if (strcmp(command, "home 1\n") == 0 || strcmp(command, "home 1") == 0){ homeAxis(1); moved = true; }
  if (strcmp(command, "home 2\n") == 0 || strcmp(command, "home 2") == 0){ homeAxis(2); moved = true; }
  if (strcmp(command, "home 3\n") == 0 || strcmp(command, "home 3") == 0){ homeAxis(3); moved = true; }
  if (strcmp(command, "home 4\n") == 0 || strcmp(command, "home 4") == 0){ homeAxis(4); moved = true; }
  if (strcmp(command, "home 5\n") == 0 || strcmp(command, "home 5") == 0){ homeAxis(5); moved = true; }
  if (strcmp(command, "home 6\n") == 0 || strcmp(command, "home 6") == 0){ homeAxis(6); moved = true; }

  //loop through the command to each axis
  while (command != 0){
    
      // Split the command into the axis number and position commanded
      char* separator = strchr(command, ':');

      if (separator != 0){
        
          // Actually split the string in 2: replace ':' with 0
          *separator = 0;
          String servoId = command;
          ++separator;
          int position = atoi(separator);
          
          // Print out what was commanded with servoId and position
          Serial.print("\nServo ID: ");
          Serial.println(servoId);      
          Serial.print("Target Position (deg): ");
          Serial.println(position);

          // check if updating parameters
          if (servoId == "A1"){ setAccel(1, position); Serial.print("Accel 1: "); Serial.println(accel1); }
          else if (servoId == "A2"){ setAccel(2, position); Serial.print("Accel 2: "); Serial.println(accel2); }
          else if (servoId == "A3"){ setAccel(3, position); Serial.print("Accel 3: "); Serial.println(accel3); }
          else if (servoId == "A4"){ setAccel(4, position); Serial.print("Accel 4: "); Serial.println(accel4); }
          else if (servoId == "A5"){ setAccel(5, position); Serial.print("Accel 5: "); Serial.println(accel5); }
          else if (servoId == "A6"){ setAccel(6, position); Serial.print("Accel 6: "); Serial.println(accel6); }
          else if (servoId == "V1"){ setVel(1, position); Serial.print("Vel 1: "); Serial.println(vel1); }
          else if (servoId == "V2"){ setVel(2, position); Serial.print("Vel 2: "); Serial.println(vel2); }
          else if (servoId == "V3"){ setVel(3, position); Serial.print("Vel 3: "); Serial.println(vel3); }
          else if (servoId == "V4"){ setVel(4, position); Serial.print("Vel 4: "); Serial.println(vel4); }
          else if (servoId == "V5"){ setVel(5, position); Serial.print("Vel 5: "); Serial.println(vel5); }
          else if (servoId == "V6"){ setVel(6, position); Serial.print("Vel 6: "); Serial.println(vel6); }
          else if (servoId == "m1"){ setMin(1, position); Serial.print("Min 1: "); Serial.println(minAngle1); }
          else if (servoId == "m2"){ setMin(2, position); Serial.print("Min 2: "); Serial.println(minAngle2); }
          else if (servoId == "m3"){ setMin(3, position); Serial.print("Min 3: "); Serial.println(minAngle3); }
          else if (servoId == "m4"){ setMin(4, position); Serial.print("Min 4: "); Serial.println(minAngle4); }
          else if (servoId == "m5"){ setMin(5, position); Serial.print("Min 5: "); Serial.println(minAngle5); }
          else if (servoId == "m6"){ setMin(6, position); Serial.print("Min 6: "); Serial.println(minAngle6); }
          else if (servoId == "M1"){ setMax(1, position); Serial.print("Max 1: "); Serial.println(maxAngle1); }
          else if (servoId == "M2"){ setMax(2, position); Serial.print("Max 2: "); Serial.println(maxAngle2); }
          else if (servoId == "M3"){ setMax(3, position); Serial.print("Max 3: "); Serial.println(maxAngle3); }
          else if (servoId == "M4"){ setMax(4, position); Serial.print("Max 4: "); Serial.println(maxAngle4); }
          else if (servoId == "M5"){ setMax(5, position); Serial.print("Max 5: "); Serial.println(maxAngle5); }
          else if (servoId == "M6"){ setMax(6, position); Serial.print("Max 6: "); Serial.println(maxAngle6); }
          
          else {
            // Call function to check that positions are valid and set the position to move to
            moveCommand(servoId, position);
            moved = true;
          }
          
      }
      // Find the next command in input string
      command = strtok(0, ".");
  }
  if(moved){ printPos(); moved = false; }
}
