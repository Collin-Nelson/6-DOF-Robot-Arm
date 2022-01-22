void printParams(){
  Serial.println("Current parameters are: ");
  
 Serial.println("Current Acccelerations are: ");
      Serial.print("Accel 1: "); Serial.println(accel1);
      Serial.print("Accel 2: "); Serial.println(accel2);
      Serial.print("Accel 3: "); Serial.println(accel3);
      Serial.print("Accel 4: "); Serial.println(accel4);
      Serial.print("Accel 5: "); Serial.println(accel5);
      Serial.print("Accel 6: "); Serial.println(accel6);

  Serial.println("Current Velocities are: ");
      Serial.print("Vel 1: "); Serial.println(vel1);
      Serial.print("Vel 2: "); Serial.println(vel2);
      Serial.print("Vel 3: "); Serial.println(vel3);
      Serial.print("Vel 4: "); Serial.println(vel4);
      Serial.print("Vel 5: "); Serial.println(vel5);
      Serial.print("Vel 6: "); Serial.println(vel6);

  Serial.println("Current Min Angles are: ");
      Serial.print("Min 1: "); Serial.println(minAngle1);
      Serial.print("Min 2: "); Serial.println(minAngle2);
      Serial.print("Min 3: "); Serial.println(minAngle3);
      Serial.print("Min 4: "); Serial.println(minAngle4);
      Serial.print("Min 5: "); Serial.println(minAngle5);
      Serial.print("Min 6: "); Serial.println(minAngle6);

  Serial.println("Current Max Angles are: ");
      Serial.print("Max 1: "); Serial.println(maxAngle1);
      Serial.print("Max 2: "); Serial.println(maxAngle2);
      Serial.print("Max 3: "); Serial.println(maxAngle3);
      Serial.print("Max 4: "); Serial.println(maxAngle4);
      Serial.print("Max 5: "); Serial.println(maxAngle5);
      Serial.print("Max 6: "); Serial.println(maxAngle6);

}
