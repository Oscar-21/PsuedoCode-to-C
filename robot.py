
# Filename:  robot.py
# Description: Program for a robot that
 
# Version:  1.0
# Created:  02/27/2017 04:49:20 PM
# Revision:  none
# Compiler:  Mr Roboto

# Author:  Austin Conder (), austin.conder@outlook.com
# Organization:  Mr. Solo Dolo


# declare and define variables that will be called
# by the main function.

declare sit
   if ( robot is standing
        and facing direction exactly opposite 
	the seat of the chair
	and seat of chair is directly behind
	robot )

      starting from the top rotate legs
      45 degress downward

declare stand 
   if robot is sitting
      extend legs and upper body 45 degrees
   else
      output "stand can only"
   	     "be implemented if"
	     " robot is in the" 
	     " sitting position."  

declare step 
   if robots is standing
      step one foot forward
   else
      output "step can only be implemented"
             " if robot is in standing"
	     " position."

declare raiseArms
   if robot's arms point to floor
      raise arms
   else
      output "arms are already raised"

declare lowerArms
   if robot's arms are parralell to floor
      lower arms
   else
      output "arms are already lowered."

declare sense
   if arms are lowered
      output "arms must be raised to sense"  
      
   do
      check for obstructions
         if there are obstructions 
	    return True
	 else
            return False	 
   while arms are raised.

declare turn
   if robot is standing
      using right foot, 
      take one 90 degree step to the right
      using left foot,
      take one 90 degree step to the right.

   else 
      output "robot can only turn if"
             " in the standing position."   

# main function will operate on a sitting robot
# have it walk to the wall and back, sit back down
# and it will return the number of steps.
start main function

   initialize stepCounter to zero. # this will count number
                                   # of steps until the robot
                                   # sits down again 
   stand  
   
   raise_arms

   sense
   
   # conditional to check if
   # robot's starting position is
   #at the wall
   if sense is true  
      lower_arms
      sit
      output stepCounter
      stop program

   # conditional that will have
   # robot walk until it senses wall
   while sense is false
      step
      increment stepCounter

   turn
   turn
  
   # conditional the will check if robot
   # is back at chair.
   while sense is false
      step
      increment stepCounter

      # loop closes out when sense is true
      # so we are now back at chair and
      # can sit down
      turn     
      turn
      lower_arms
      sit

      # return the number of steps taken
      output stepCounter

      # this will end the main function
      stop 
 
   


      
      
   
