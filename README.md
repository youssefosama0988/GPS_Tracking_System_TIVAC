# GPS-Tracking-System
## Project Description
The goal of this project is to develop an embedded system using C programming that 
gathers real-time positional coordinates while a microcontroller is in motion (GPS tracking 
system using TM4C123G LaunchPad) after power-on until a destination point is reached. 
The collected data will then be efficiently transferred to a personal computer (PC) and 
visualized on a map application.
There are three possible options for the definition of the destination point:
1. Once the moved distance exceeds 100m, stop adding new points to the trajectory 
and the last point added to the trajectory is the target destination.
2. Stop adding new points when a push button is pressed, and the last point added 
to the trajectory is the last destination.
3. Predefine the destination point in your code and when the system reaches this 
point, stop adding new points to the trajectory.

**Other functions required by the system**:
1. When the destination point is reached the build-in LED of the launchpad should be 
turned on.
2. The system should check for UART commands from the PC and if the PC sends
the command ‘U’ then the system should send the stored trajectory to the PC.
