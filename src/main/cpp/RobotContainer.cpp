#include "RobotContainer.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/DriveSubsystem.h"

RobotContainer::RobotContainer() {
  // Configure button bindings
  ConfigureButtonBindings();

  // Set the default command for the DriveSubsystem.
  m_drive.SetDefaultCommand(std::move(m_driveWithJoystickCmd));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here, for example:
  // frc2::JoystickButton(&m_driverJoystick, 1).WhenPressed(...);
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example autonomous command
  return  frc2::InstantCommand([] {}, {}).ToPtr();
}
