void setAccel(int id, double accel){
  if (id == 1){ accel1 = accel; stepper1.setAcceleration(accel1*gear1); }
  else if (id == 2){ accel2 = accel; stepper2.setAcceleration(accel2*gear2); }
  else if (id == 3){ accel3 = accel; stepper3.setAcceleration(accel3*gear3); }
  else if (id == 4){ accel4 = accel; stepper4.setAcceleration(accel4*gear4); }
  else if (id == 5){ accel5 = accel; stepper5.setAcceleration(accel5*gear5); }
  else if (id == 6){ accel6 = accel; stepper6.setAcceleration(accel6*gear6); }
}
void setVel(int id, double vel){
  if (id == 1){ vel1 = vel; stepper1.setSpeed(vel1*gear1); }
  else if (id == 2){ vel2 = vel; stepper2.setSpeed(vel2*gear2); }
  else if (id == 3){ vel3 = vel; stepper3.setSpeed(vel3*gear3); }
  else if (id == 4){ vel4 = vel; stepper4.setSpeed(vel4*gear4); }
  else if (id == 5){ vel5 = vel; stepper5.setSpeed(vel5*gear5); }
  else if (id == 6){ vel6 = vel; stepper6.setSpeed(vel6*gear6); }
}
void setMin(int id, double lim){
  if (id == 1){ minAngle1 = lim; }
  else if (id == 2){ minAngle2 = lim; }
  else if (id == 3){ minAngle3 = lim; }
  else if (id == 4){ minAngle4 = lim; }
  else if (id == 5){ minAngle5 = lim; }
  else if (id == 6){ minAngle6 = lim; }
}
void setMax(int id, double lim){
  if (id == 1){ maxAngle1 = lim; }
  else if (id == 2){ maxAngle2 = lim; }
  else if (id == 3){ maxAngle3 = lim; }
  else if (id == 4){ maxAngle4 = lim; }
  else if (id == 5){ maxAngle5 = lim; }
  else if (id == 6){ maxAngle6 = lim; }
}
