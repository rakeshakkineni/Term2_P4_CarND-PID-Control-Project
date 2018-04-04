## **CarNDPID Control Project**

The goals / steps of this project are the following:
* Modify the code to make the car in the simulator to drive autonomously without crossing the road limits for atleast one lap.


[//]: # (Image References)

[image1]: ./Output/CTE_Vs_Time.png
[image2]: ./Output/Steer_Value_Vs_Time.png 
[image3]: ./Output/Angle_Vs_TIme.png
[video1]: ./Output/Term2_P4_Output.mp4
---
### Writeup / README
In this project vehicle in the simulator is controlled using PID Controller, the main task is to tune the Kp,Ki,Kd parameters of PID Controller such that the vehcile does not cross the road limits. Source code provided by "UDACITY CarND PID Control Project" was used as base for this project. 

### Modifications
main.cpp , pid.cpp are modified to implement PID controller. PID,Init , UpdateError , TotalError, main() functions were modified to implement the controller . Modified code can be found [here] ("./Src")

### Code Flow
Following is brief description of the flow of the code.
- Initialize the PID parameters Kp,Kd,Ki. 
- Establish the connection with simulator.
- Get the data from the simulator for one scan.
- Update the p_error,d_error,i_error using the new CTE value.
- Calculate the Total Erorr i.e steer_value.
- Send the steer_value to the simulator. 

### Tuning Process
After modifying PID.cpp and main.cpp to implement PID controller i have started working on parameter tuning. I have followed the following methods.
- Twiddling: I have tried to use the twiddling method mentioned in the lecturers but i was not successful in implementing a proper code to perform twiddle. After spending a day on implementing the twiddle algorithm i have switched to manual tuning process. 

- Manual Tuning: 
    - Method 1: I have tried to manually tune the controller ,for almost 2 days, by using random values. But i was not successful to even make the car cross the first bridge. I have executed following steps.
        - Change manually Kp,Kd,Ki with random values 
        - Compile the code and run the simulator
    - Method 2: After spending 2 days on method 1 without any success i started searching online to understand more about the PID controllers and what methods are generally followed to tune the PID controllers. I have come across the following article. https://robotics.stackexchange.com/questions/167/what-are-good-strategies-for-tuning-pid-loop . I followed the method mentioned in the first answer. 
    
     To make tuning process simple i have modified my "main()" funtion to "int main(int argc, char* argv[])" , such that it can accept command line arguments and passed the command line arguments to pid.init() function after converting the parameters to floating point. The following code shows my implementation. 
     "pid.Init(atof(argv[1]),atof(argv[2]),atof(argv[3]));"
     
      As mentioned in the article i followed following steps to tune. 
        - Set all gains to zero.
        - Increase the P gain until the response to a disturbance is steady oscillation.
        - Increase the D gain until the the oscillations go away (i.e. it's critically damped).
        - Repeat above 2 steps until increasing the D gain does not stop the oscillations.
        - Set P and D to the last stable values.
        - Increase the I gain until it brings you to the setpoint with the number of oscillations desired (normally zero but a quicker response can be had if you don't mind a couple oscillations of overshoot)

    After following the above steps i was able to make the car drive one lap without crossing the road limits. 
    
    I have modified the main function to remove command line arguments and final parameters were passed to pid.Init function directly. I was able to finish the project by using Kp: 0.1 , Ki: 0.005 , Kd: 0.6 values. 
      

### Output
Following picutres the trend of Angle , Steering Value and CTE over time. 

- CTE Vs Time 

![alt text][image1]

- Steering Value Vs Time

![alt text][image2]

- Angle Vs Time 

![alt text][image3]

- Simulator and Command Prompt Recording.

![alt text][video1]

## Result:
Kp: 0.1 , Ki: 0.005 , Kd: 0.6. I have recorded the video it can be found in output folder.
