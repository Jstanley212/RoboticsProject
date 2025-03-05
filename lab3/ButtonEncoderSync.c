/*
Program: User presses buttons to select the distance the robot will travel.
Authors: Jan Varbe, Joshua Stanley, Jack McCarthy
Date: 21/02/2024
*/

#pragma config(Sensor, S1,     touchLeft,      sensorEV3_Touch)
#pragma config(Sensor, S3,     touchRight,     sensorEV3_Touch)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor, motorA, armMotor, tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor, motorB, leftMotor, tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor, motorC, rightMotor, tmotorEV3_Large, PIDControl, driveRight, encoder)

#define circum 17.27

//function signatures
void get_distance();
void reset();
void drive(long nMotorRatio, long dist, long power);


task main()
{
	get_distance();
}

void reset()
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
}


//function to set a distance for when a button is pressed on the robot
void get_distance() {

	// Loop until button pressed
	while (getButtonPress(buttonEnter) == 0 )  // this will fail once the button is enter pressed.
	{

		if (getButtonPress(buttonUp)) 
		{
			drive(0, 10, 50);
		}

		else if (getButtonPress(buttonDown))
		{
			drive(0, 40, 50);
		}

		else if (getButtonPress(buttonLeft))
		{
			drive(0, 60, 50);
		}

		else if (getButtonPress(buttonRight))
		{
			drive(0, 80, 50);
		}

		// Wait 20 ms, this gives us 50 readings per second
		sleep(20);
	}


}
