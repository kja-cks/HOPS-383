#include "subsystems/DriveSubsystem.h"
#include <iostream>

DriveSubsystem::DriveSubsystem() {
  // Invert the right side motors so that positive voltages
  // result in both sides moving forward.
  m_rightMotors.SetInverted(true); 
}

void DriveSubsystem::Periodic() {
  // This method will be called once per scheduler run
}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  // Use the DifferentialDrive class's ArcadeDrive method.
  m_robotDrive.ArcadeDrive(fwd, rot);
}
