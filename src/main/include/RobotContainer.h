#pragma once

#include <frc/Joystick.h>
#include <frc2/command/Command.h>
#include <frc2/command/button/JoystickButton.h>
#include "subsystems/DriveSubsystem.h"
#include "commands/DriveWithJoystick.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

 private:
  // Subsystems
  DriveSubsystem m_drive;
  //SparkMax m_tool1;
  //SparkMax m_tool2;

  // Joysticks
  //frc::Joystick m_driverJoystick{0};

  // Commands
  //DriveWithJoystick m_driveWithJoystickCmd{ &m_drive, &m_driverJoystick };

  void ConfigureButtonBindings();
};
