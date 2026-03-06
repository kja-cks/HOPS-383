#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubsystem.h"
#include <functional>
#include <frc/Errors.h>

/**
 * An example command that uses an arcade drive method.
 */
class DriveWithJoystick
    : public frc2::CommandHelper<frc2::Command, DriveWithJoystick> {
 public:
  DriveWithJoystick(DriveSubsystem* subsystem, frc::Joystick* joystick)
      : m_drive{subsystem}, m_joystick{joystick}{
    AddRequirements({subsystem});
  }

  void Execute() override {
    FRC_ReportError(frc::warn::Warning, "We are actually in the execute on the drive train");
    FRC_ReportError(frc::warn::Warning,  "This is x: {}", m_joystick->GetX());
    m_drive->ArcadeDrive(-1, 1);//m_joystick->GetX(), m_joystick->GetY());
  }

  void End(bool interrupted) override {
    m_drive->ArcadeDrive(0, 0); // Stop motors when command ends.
  }
  bool IsFinished()
  {
    return false;
  }

 private:
  DriveSubsystem* m_drive;
  frc::Joystick* m_joystick;
  };