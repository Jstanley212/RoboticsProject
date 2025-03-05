#pragma config(Sensor, S1,     touchLeft,      sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro)
#pragma config(Sensor, S3,     colourSensor,   sensorEV3_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

/*
Program: The robot drives in an equilateral triangular of side length set by a button press at the start of the program.
Authors: Joshua Stanley, Jack McCarthy
Date:20/03/2024
*/

#define CIRCUM 17.27

// Function signatures
void get_distance();
void reset();
void drive(long nMotorRatio, long dist, long power);

void gyroturn90(int Length);

task main()
{

    ///function to input the size of the triangle
    get_distance();

}



// Function to reset
void reset()
{
    resetMotorEncoder(leftMotor);
    resetMotorEncoder(rightMotor);
}

// Function to set amount of distance for robot to travel
void drive(long nMotorRatio, long dist, long power)
{
    float turns = 360 * (dist / CIRCUM);
    reset();
    setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, turns, power);
    waitUntilMotorStop(leftMotor);
}






// Function to get distance when button pressed, and run the triangle
void get_distance()
{

    ///lengths to choose from
    int upLength = 50;
    int downLength = 20;
    int rightLength = 30;
    int leftLength = 40;
           
    ///while loop that allows user to choose a distance      
    while (getButtonPress(buttonEnter) == 0)
    {
        if (getButtonPress(buttonUp))
        {
            ///entering length chosen into function
            for(int i = 0; i <=2; i++)
            {
            gyroturn90(upLength);
            }
        }

        if (getButtonPress(buttonDown))
        {
            ///entering length chosen into function
            for(int i = 0; i <=2; i++)
            {
            gyroturn90(downLength);
            }
        }

        if (getButtonPress(buttonLeft))
        {
            //entering length chosen into function
            for(int i = 0; i <=2; i++)
            {
            gyroturn90(leftLength);
            }
        }

        if (getButtonPress(buttonRight))
        {
            ///entering length chosen into function
            for(int i = 0; i <=2; i++)
            {
            gyroturn90(rightLength);
            }
        }
    }
}


///function to move forward and turn while the gyro is less than 115 degrees
void gyroturn90(int Length){
      resetGyro(gyroSensor);
     
      int Angle =0;
     
      ///moving forward
      drive(0, Length, 25);
      sleep(1500);
     
      while (abs(getGyroDegrees(S2))<115)
        {
            sleep(1);
           
            ///turning
            reset();
            setMotorSync(leftMotor, rightMotor, 100, 10);
        
            ///displaying the angle
            Angle=getGyroDegrees(S2);
            displayCenteredTextLine(5,"current angle %4d", Angle);
            
        }

    setMotorSync(motorB, motorC, 0, 0);
}