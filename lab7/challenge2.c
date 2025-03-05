#pragma config(Sensor, S1,     touchLeft,      sensorEV3_Touch)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     gyroSensor,    sensorEV3_Gyro)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

/*
Program: The robot drives on until it encounters obstacles, and turns left each time. Then it runs for 30cm.
Authors: Jan Varbe, Jack McCarthy, Joshua Stanley
Date: 20/03/2024
*/

// circumference
#define CIRCUM 17.27

// function signatures
void gyroturn90(int power);
void reset();
void bump(int power);
void ultrason(int power);
void drive(int nMotorRatio, float dist, int power);
void reverse();

task main()
{
      // Drive until robot hits obstacle
      bump(40);

      // Turn 90 degrees
      gyroturn90(10);

      // Drive until ultrasonic detects obstacle
      ultrason(40);

      // Turn 90 degrees
      gyroturn90(10);

      // Drive until robot hits obstacle
      bump(40);

      // Turn 90 degrees
      gyroturn90(10);


      // Drive 30cm
      drive(0, 30, 20);
}


// Reset motor encoders
void reset()
{
      resetMotorEncoder(leftMotor);
      resetMotorEncoder(rightMotor);
}


// function for robot to drive until bump detected
void bump(int power)
{
      //robot drives while bump not detected
      while (SensorValue(touchLeft) == 0)
      {
            setMotorSpeed(leftMotor, power);
            setMotorSpeed(rightMotor, power);
      }

      // reverse
      reverse();
}


// function to make robot turn 90
void gyroturn90(int power)
{
      // Reset gyro
      resetGyro(gyroSensor);

      // Turn 90 degrees
      while(getGyroDegrees(gyroSensor) > -83)
      {
            setMotorSync(leftMotor, rightMotor, -100, power);
      }
}


// function to drive until obstacle sensed using ultrasonic
void ultrason(int power)
{
      while(getUSDistance(sonarSensor) > 10)
      {
            setMotorSync(leftMotor, rightMotor, 0, power);
      }
}


// function to make robot drive on
void drive(int nMotorRatio, float dist, int power)
{
      //wheel rotations needed for distance
      float rotations = 360 * (dist / CIRCUM);

      // reset encoders
      reset();

      //drives
      setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, rotations, power);
      waitUntilMotorStop(leftMotor);
}

// function to reverse
void reverse() {
      setMotorSpeed(leftMotor, -25);
      setMotorSpeed(rightMotor, -25);
      sleep(500);
}