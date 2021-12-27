//Deals with serial I/O
void getSerial(){
  //Read in serial data
  byte size = Serial.readBytes(input, inputSize);   //in format: 1:10.2:20.3:30.4:40.5:50.6:60 (J1 to 10, J2 to 20, etc)
  input[size] = 0;

  //split serial data by axis
  char* command = strtok(input, ".");

  //if recieve "home" with or without newline char, run the homing function
  if (strcmp(command, "home\n") == 0 || strcmp(command, "home") == 0){
    home();
  }
  //if recieve "print pos" with or without newline char, run the homing function
  if (strcmp(command, "print pos\n") == 0 || strcmp(command, "print pos") == 0){
    printPos();
  }
    //if recieve "zero" with or without newline char, move each joint to zero
  if (strcmp(command, "zero\n") == 0 || strcmp(command, "zero") == 0){
    moveCommand(1, 0);
    moveCommand(2, 0);
    moveCommand(3, 0);
    moveCommand(4, 0);
    moveCommand(5, 0);
    moveCommand(6, 0);
  }
  //if recieve "help" with or without newline char, run the homing function
  if (strcmp(command, "help\n") == 0 || strcmp(command, "help") == 0){
    Serial.println("Commands are:");
    Serial.println("home");
    Serial.println("zero");
    Serial.println("print pos");
    Serial.println("stack");
    Serial.println("home [axis number]");    
  }
  //if recieve "home [axis number]" with or without newline char, run the homing function
  if (strcmp(command, "home 1\n") == 0 || strcmp(command, "home 1") == 0){
    homeAxis(1);
  }
  //if recieve "home [axis number]" with or without newline char, run the homing function
  if (strcmp(command, "home 2\n") == 0 || strcmp(command, "home 2") == 0){
    homeAxis(2);
  }
  //if recieve "home [axis number]" with or without newline char, run the homing function
  if (strcmp(command, "home 3\n") == 0 || strcmp(command, "home 3") == 0){
    homeAxis(3);
  }
  //if recieve "home [axis number]" with or without newline char, run the homing function
  if (strcmp(command, "home 4\n") == 0 || strcmp(command, "home 4") == 0){
    homeAxis(4);
  }
  //if recieve "home [axis number]" with or without newline char, run the homing function
  if (strcmp(command, "home 5\n") == 0 || strcmp(command, "home 5") == 0){
    homeAxis(5);
  }
  //if recieve "home [axis number]" with or without newline char, run the homing function
  if (strcmp(command, "home 6\n") == 0 || strcmp(command, "home 6") == 0){
    homeAxis(6);
  }

  //loop through the command to each axis
  while (command != 0){
    
      // Split the command into the axis number and position commanded
      char* separator = strchr(command, ':');

      if (separator != 0){
        
          // Actually split the string in 2: replace ':' with 0
          *separator = 0;
          int servoId = command;
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
          else if (servoId == "m1"){ setMin(1, position); Serial.print("Min 1: "); Serial.println(lowerLim1); }
          else if (servoId == "m2"){ setMin(2, position); Serial.print("Min 2: "); Serial.println(lowerLim2); }
          else if (servoId == "m3"){ setMin(3, position); Serial.print("Min 3: "); Serial.println(lowerLim3); }
          else if (servoId == "m4"){ setMin(4, position); Serial.print("Min 4: "); Serial.println(lowerLim4); }
          else if (servoId == "m5"){ setMin(5, position); Serial.print("Min 5: "); Serial.println(lowerLim5); }
          else if (servoId == "m6"){ setMin(6, position); Serial.print("Min 6: "); Serial.println(lowerLim6); }
          else if (servoId == "M1"){ setMax(1, position); Serial.print("Max 1: "); Serial.println(upperLim1); }
          else if (servoId == "M2"){ setMax(2, position); Serial.print("Max 2: "); Serial.println(upperLim2); }
          else if (servoId == "M3"){ setMax(3, position); Serial.print("Max 3: "); Serial.println(upperLim3); }
          else if (servoId == "M4"){ setMax(4, position); Serial.print("Max 4: "); Serial.println(upperLim4); }
          else if (servoId == "M5"){ setMax(5, position); Serial.print("Max 5: "); Serial.println(upperLim5); }
          else if (servoId == "M6"){ setMax(6, position); Serial.print("Max 6: "); Serial.println(upperLim6); }
          
          else {
            // Call function to check that positions are valid and set the position to move to
            moveCommand(servoId, position);
          }
          
      }
      // Find the next command in input string
      command = strtok(0, ".");
  }
}
