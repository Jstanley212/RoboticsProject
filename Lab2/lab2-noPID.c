#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, openLoop, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, openLoop, driveRight, encoder)
#pragma config(Motor,  motorD,           ,             tmotorEV3_Large, openLoop, encoder)

	//function for robot to turn 90 degrees left
	void turn90degreesLeft(long time, long motorpower)
	{
		setMotorSpeed(motorB, motorpower);
		setMotorSpeed(motorC, -motorpower);
		sleep(time);
	}

	//function for robot to turn 90 degrees right
	void turn90degreesRight(long time, long motorpower)
	{
		setMotorSpeed(motorB, -motorpower);
		setMotorSpeed(motorC, motorpower);
		sleep(time);
	}

	//function for robot to go forward 1 second
	void goForward1second(long time, long motorpower)
	{
		setMotorSpeed(motorB, motorpower);
		setMotorSpeed(motorC, motorpower);
		sleep(time);
	}

	//function for robot to go backwards for 1 second
	void reverse1second(long time, long motorpower)
	{
		setMotorSpeed(motorB, -motorpower);
		setMotorSpeed(motorC, -motorpower);
		sleep(time);
	}

	//function for robot to swing right 90 degrees
		void swingRight90degrees(long time, long motorpower)
	{
		setMotorSpeed(motorB, 0);
		setMotorSpeed(motorC, motorpower);
		sleep(time);
	}

	//function for robot to swing left 90 degrees
	void swingLeft90degrees(long time, long motorpower)
	{
		setMotorSpeed(motorB, motorpower);
		setMotorSpeed(motorC, 0);
		sleep(time);
	}

task main()
{
	//go forward
	goForward1second(1000, 50);
	setMotorSpeed(MotorB, 0);	
	setMotorSpeed(MotorC, 0); 
	sleep(1500);

	//turn right
	turn90degreesRight(430, 50);
	setMotorSpeed(MotorB, 0);	
	setMotorSpeed(MotorC, 0); 
	sleep(1500);

	//turn left
	turn90degreesLeft(430, 50);
	setMotorSpeed(MotorB, 0);	
	setMotorSpeed(MotorC, 0); 
	sleep(1500);

	//reverse
	reverse1second(1000,50);
	setMotorSpeed(MotorB, 0);	
	setMotorSpeed(MotorC, 0); 
	sleep(1500);

	//swing right
	swingRight90degrees(750,50);
	setMotorSpeed(MotorB, 0);	
	setMotorSpeed(MotorC, 0); 
	sleep(1500);

	//swing left
	swingLeft90degrees(750,50);
	setMotorSpeed(MotorB, 0);	
	setMotorSpeed(MotorC, 0); 
	sleep(1500);
}
