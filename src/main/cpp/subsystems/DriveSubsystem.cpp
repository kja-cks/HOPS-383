#include "subsystems/DriveSubsystem.h"
#include <iostream>

DriveSubsystem::DriveSubsystem() {
  // Invert the right side motors so that positive voltages
  // result in both sides moving forward.
  //m_right.SetInverted(true); 
  //m_robotDrive.SetSafetyEnabled(true);
  //m_robotDrive.SetExpiration(0.1_s);
  
}

void DriveSubsystem::Periodic() {
  // This method will be called once per scheduler run
}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  // Use the DifferentialDrive class's ArcadeDrive method.
  //this->m_robotDrive.ArcadeDrive(fwd, rot);
}
