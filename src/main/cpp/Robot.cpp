// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include "Robot.h"



Robot::Robot() : m_container() {


   wpi::SendableRegistry::AddChild(&m_robotDrive, &m_left);
    wpi::SendableRegistry::AddChild(&m_robotDrive, &m_right);


    // We need to invert one side of the drivetrain so that positive voltages
    // result in both sides moving forward. Depending on how your robot's
    // gearbox is constructed, you might have to invert the left side instead.
    m_right.SetInverted(true);
    m_robotDrive.SetExpiration(100_ms);
    m_timer.Start();
}


/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
}


/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}


void Robot::DisabledPeriodic() {}


/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();


  if (m_autonomousCommand) {
    m_autonomousCommand->Schedule();
   
  }
}


void Robot::AutonomousPeriodic() {
 /* if(float(m_timer.Get()) < 1.0){
    m_robotDrive.ArcadeDrive(0.0,1.0);
  }
  else{
    m_robotDrive.ArcadeDrive(0.0, 0.0);
  }*/
}
//credit to wpilib
void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand) {
    m_autonomousCommand->Cancel();
   
  }
}


/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
// Drive with arcade style (use right stick to steer)
    m_robotDrive.ArcadeDrive(-m_controller.GetLeftY(),
                             ((m_controller.GetRightX())*-1));
   
   if(m_controller.GetYButtonPressed())
   {
   
    m_tool1.Set(1);
   }
   else if(m_controller.GetYButtonReleased()){
    m_tool1.Set(0);
   }
   else if (m_controller.GetXButtonPressed())
   {
   
    m_tool1.Set(-1);


    /* code */
   }
   else if(m_controller.GetXButtonReleased()){
    m_tool1.Set(0);
   }
   else if(m_controller.GetBButtonPressed())
   {
   
    m_tool2.Set(1);
   }
   else if(m_controller.GetBButtonReleased())
   {
   
    m_tool2.Set(0);
   }
   else if(m_controller.GetAButtonPressed())
   {
   
    m_tool2.Set(-1);
   }
   else if(m_controller.GetAButtonReleased())
   {
    m_tool2.Set(0);
   }
    else if(m_controller.GetRightBumperButtonPressed()){
   
    m_tool3.Set(1);
   }
   else if(m_controller.GetRightBumperButtonReleased())
   {
    m_tool3.Set(0);
   }
   else if(m_controller.GetRightBumperPressed()){
   
    m_tool3.Set(-1);
   }
   else if(m_controller.GetRightBumperReleased()){
    m_tool3.Set(0);
   }
   
   
   


}


/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}


/**
 * This function is called once when the robot is first started up.
 */
void Robot::SimulationInit() {}


/**
 * This function is called periodically whilst in simulation.
 */
void Robot::SimulationPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif