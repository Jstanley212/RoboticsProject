/*
	Program: The robot goes over black lines and counts them
	Date: 28/02/2024
	Authors: Joshua Stanley, Jack McCarthy
*/

#pragma config(Sensor, S1,     touchLeft,      sensorEV3_Touch)
#pragma config(Sensor, S3,     colourSensor,   sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

#define threshold 40
#define circum 17.27

///void reset();
///void drive(long nMotorRatio, long dist, long power);
///void line_counter(long line_count);

task main()
{

      int line_count = 0;
      while (true){
            setMotorSync(rightMotor, leftMotor, 0, 50);

            while (SensorValue[colourSensor] < threshold){
                  line_count+=1;
                  displayBigTextLine(4, "%d", line_count);
                  setMotorSync(rightMotor, leftMotor, 0, 0);
                  sleep(500);
                  setMotorSync(rightMotor, leftMotor, 0, 5);

            }

      }

      ///int line_count = 0;
      ///line_counter(line_count);






}


/*void reset()
{
      resetMotorEncoder(leftMotor);
      resetMotorEncoder(rightMotor);
}

//function to set an amount of distance for the robot to travel
void drive(long nMotorRatio, long dist, long power)

{
      float turns = 360 * (dist/ circum);


      reset();

      setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, turns, power);
      waitUntilMotorStop(leftMotor);
}*/


/*void line_counter(long line_count){




      if (SensorValue[colourSensor] > threshold) {
            setMotorSync(rightMotor, leftMotor, 0, 50);

      }

      else ///(SensorValue[colourSensor] < threshold)
            {
            line_count+=1;
            displayBigTextLine(4, "%d", line_count);
            setMotorSync(rightMotor, leftMotor, 0, 0);
            sleep(500);
            setMotorSync(rightMotor, leftMotor, 0, 20);
            sleep(500);


            }

      line_counter(line_count);
}*/
