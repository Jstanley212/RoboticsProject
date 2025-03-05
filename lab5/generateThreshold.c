/* Program: This program reads a light value, a dark value, and generates the threshold.
Authors: Joshua Stanley, Jack McCarthy,Jan Varbe
Date: 21/02/2024
*/
#pragma config(Sensor, S1,     touchLeft,      sensorEV3_Touch)
#pragma config(Sensor, S3,     colourSensor,   sensorEV3_Color, modeEV3Color_Reflected)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)


task main()
{
    int light_value = -1;
    int dark_value = -1;

    int average = 0;

    //instructions for the user
    displayBigTextLine(3, "Up for light");
    sleep(1000);
    displayBigTextLine(3, "Down for dark");
    sleep(1000);


    while (true)
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

        //calculates and displays threshold value
        else if (light_value >= 0 && dark_value >= 0)
        {
                average = (light_value + dark_value) / 2;
                displayBigTextLine(4, "Threshold %d", average);
        }
    }

}
