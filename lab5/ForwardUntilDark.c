/*
	Program: The robot runs until it hits a black line, but the program does not stop.
	Author: Joshua Stanley, Jack McCarthy
	Date: 28/02/2024
*/

#pragma config(Sensor, S1,     touchLeft,      sensorEV3_Touch)
#pragma config(Sensor, S3,     colourSensor,   sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

#define circum 17.27
#define THRESHOLD 40




task main()
{


              int light_value = -1;
              int dark_value = -1;
              int average=0;

              //instructions for the user
              displayBigTextLine(3, "Up for light");
              sleep(1000);
              displayBigTextLine(3, "Down for dark");
              sleep(1000);

              while (getButtonPress(buttonEnter)==0)
                  {
                //reads in and displays light value
                  if (getButtonPress(buttonUp))
                        {
                        light_value = SensorValue[colourSensor];
                        displayBigTextLine(4, "light value: %d", light_value);
                        sleep(2000);

                              }

                //reads in and displays dark value
                  else if (getButtonPress(buttonDown))
                        {
                        dark_value = SensorValue[colourSensor];
                        displayBigTextLine(4, "dark value: %d", dark_value);
                        sleep(2000);
                              }

                //calculates
                  else if (light_value >= 0 && dark_value >= 0)
                        {
                        average = (light_value + dark_value) / 2;
                        displayBigTextLine(4, "Threshold %d", average);


                              }

                              }

      while (true)
      {
            if(SensorValue[colourSensor] > average)
            {
                setMotorSync(leftMotor, rightMotor, 0, 50);

            }

            else if (SensorValue[colourSensor] < average)
            {
                setMotorSync(leftMotor, rightMotor, 0, 0);
            }

      }


}
