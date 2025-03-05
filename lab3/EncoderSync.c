/*
Program: Robot goes in a square of 240cm perimeter in a random direction, then goes forward at 100 power, does a random 180 turn, and goes forward at 25 power.
Authors: Jan Varbe, Joshua Stanley, Jack McCarthy
Date: 14/02/2024
*/
#pragma config(Sensor, S1, touchSensor, sensorEV3_Touch)
#pragma config(Sensor, S2, gyroSensor, sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3, colorSensor, sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4, sonarSensor, sensorEV3_Ultrasonic)
#pragma config(Motor, motorA, armMotor, tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor, motorB, leftMotor, tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor, motorC, rightMotor, tmotorEV3_Large, PIDControl, driveRight, encoder)

#define circum 17.27

//function signatures
void gosquare(long dist, long power);
void turn90(long nMotorRatio, long power);
void drive(long nMotorRatio, long dist, long power);
void reset();

int randomDirection();

task main()
{
	//decides which direction the robot will go
	if (randomDirection()==1){

		turn90(100, 25);

		int x;

		//completes the square
		for (x = 4; x > 0; x--){
			gosquare(60, 50);
		}

	}
	else{
		turn90(-100, 25);

		int x;

		//completes the square
		for (x = 4; x > 0; x--){
			gosquare(60, 50);
		}

	}

    //goes forward
    drive(0, 100, 25);
	sleep(3000);

	///right
	turn90(100, 25);
	sleep(2000);

	///left
    turn90(-100, 25);
    sleep(2000);


}

//function to generate 1 or 0
int randomDirection()
{

	return random(1);
}


//function to reset
void reset(){
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

//function to go in a square
void gosquare(long dist, long power){
	reset();

	drive(0, dist, power);
	turn90(100, 25);


}
