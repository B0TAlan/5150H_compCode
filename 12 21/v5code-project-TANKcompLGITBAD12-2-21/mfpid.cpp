#include"main.cpp"

void drivf(double inches){
   //PID variables
   timer Timer;
   float threshold = 10; //exit loop while robot is within 10 ticks of target
   float error = 0.0, prevError; //proportional terms
   float integral = 0; //ditto
   float derivative = 1; //ditto 
   float kP = 1, kI = .01, kD = 1; //change in time
   float dT = Timer, prevTime = 0; //set delta time to current time
   float output;
   float targetTicks = (360*inches) / (4.0 * M_PI);//conversion from inches to ticks 
   int currentTime = Brain.timer(msec);
   int delta_time = currentTime - prevTime;
  prevTime = currentTime;
  //PID Loop
   while(fabs(error) > threshold){
     Controller1.Screen.clearScreen();
     Controller1.Screen.print("%f %f, speed, integral");
     printf("%f %f, speed, integral");
     float currentPosition = (leftDrive.position(rotationUnits::raw) + rightDrive.position(rotationUnits::raw))/2.0;
     
     error = targetTicks - currentPosition; //distance between robot and target position
       if(dT > 0){ //prevent divide by 0 error
       integral += error * dT;
       derivative = (error - prevError) * dT;
       }
       prevError = error;
       dT = Timer - prevTime;
 
       output = error*kP + integral*kI + derivative*kD;
      
       leftDrive.spin(reverse, output, volt);
       rightDrive.spin(reverse, output, volt);
      
       wait(20, msec);
     }
       rightDrive.stop(brake); //stop robot at target
       leftDrive.stop(brake);
 }
 