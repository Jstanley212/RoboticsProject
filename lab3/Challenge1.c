/*
Program: Robot goes until it detects obstacle, and turns left 3 times. Then travels for 30cm.
Authors: Jan Varbe, Joshua Stanley, Jack McCarthy
Date: 14/02/2024
*/
#pragma config(Sensor, S1,     touchLeft,      sensorEV3_Touch)
#pragma config(Sensor, S3,     touchRight,     sensorEV3_Touch)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor, motorA, armMotor, tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor, motorB, leftMotor, tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor, motorC, rightMotor, tmotorEV3_Large, PIDControl, driveRight, encoder)

#define circum 17.27

//function signatures
void drive(long nMotorRatio, long dist, long power);
void reset();
void turn90(long nMotorRatio, long power);


task main(){

	//robot goes forward until it bumps into obstacle
	while (SensorValue(touchLeft) == 0 )
	{
		setMotorSpeed(motorB, 50);
		setMotorSpeed(motorC, 50);
	}

	//reverses from obstacle
	setMotorSpeed(motorB, -25);
	setMotorSpeed(motorC, -25);
	sleep(750);

	//turns left
	turn90(-100, 25);

	//goes forward until it detects obstacle
	while (SensorValue(sonarSensor) >15)
	{
		setMotorSpeed(motorB, 50);
		setMotorSpeed(motorC, 50);
	}

	//turns left
	turn90(-100, 25);

	//goes forward until hits obstacle
	while (SensorValue(touchLeft) == 0 )
	{
		setMotorSpeed(motorB, 50);
		setMotorSpeed(motorC, 50);
	}

	//reverses from obstacle
	setMotorSpeed(motorB, -25);
	setMotorSpeed(motorC, -25);
	sleep(750);

	//turns left
	turn90(-100, 25);

	//moves for 30cm
	drive(0, 30, 50);
	reset();

}


//function to reset
void reset()
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);

}

//function to turn 90 degrees
void turn90(long nMotorRatio, long power)
{
	reset();

	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, 180, power);
	waitUntilMotorStop(leftMotor);

}

//function to drive on
void drive(long nMotorRatio, long dist, long power)
{
	float turns = 360 * (dist/ circum);


	reset();

	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, turns, power);
	waitUntilMotorStop(leftMotor);
}