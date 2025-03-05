//function to move the robot
void moveRobot(long nMotorRatio, long time, long power)
{
	
	setMotorSyncTime(motorB, motorC, nMotorRatio, time, power);	
	
	sleep(time);						
}

//function to generate and return a random number (0 or 1)
int randomDirection()
{
	
	return random(1);
}


task main()
{
	
	//shows that move robot functions correctly
	moveRobot(0,2000,50);
	moveRobot(100,2000,50);
	moveRobot(-100,2000,50);	
	moveRobot(50,1000,50);
	moveRobot(-50,750,50);

	//robot randomly turns left or right 90 degrees
	if (randomDirection()==1)
	{
		moveRobot(100,410,50);
	}
	else
	{
		moveRobot(-100,410,50);
	}
	
	//robot goes in square, returns to original position
	moveRobot(0,3000,50);
	moveRobot(100,410,50);
	moveRobot(0,3000,50);
	moveRobot(100,410,50);
	moveRobot(0,3000,50);
	moveRobot(100,410,50);
	moveRobot(0,3000,50);
	moveRobot(100,410,50);
	
	//robot goes forward for 2 seconds at full speed, then does 180degree spin and at half speed travels back to the original starting position.
	moveRobot(0,2000,100);
	moveRobot(100,820,50);
	moveRobot(0,4000,50);
}