#include "RobotContainer.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/DriveSubsystem.h"

RobotContainer::RobotContainer() {
  // Configure button bindings
  ConfigureButtonBindings();
  //m_tool1 = SparkMax(1, SparkLowLevel::MotorType::kBrushless);
  //m_tool2 = SparkMax(2, SparkLowLevel::MotorType::kBrushless);
  // Set the default command for the DriveSubsystem.
  //m_drive.SetDefaultCommand(DriveWithJoystick(&m_drive, &m_driverJoystick));
  //frc::DifferentialDrive m_robotDrive = frc::DifferentialDrive(m_tool1, m_tool2);

}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here, for example:;
  // frc2::JoystickButton(&m_driverJoystick, 1).WhenPressed(...);
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example autonomous command
  return  frc2::InstantCommand([] {}, {}).ToPtr();
}
