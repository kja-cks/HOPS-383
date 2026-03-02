#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubsystem.h"
#include <functional>

/**
 * An example command that uses an arcade drive method.
 */
class DriveWithJoystick
    : public frc2::CommandHelper<frc2::Command, DriveWithJoystick> {
 public:
  DriveWithJoystick(DriveSubsystem* subsystem, std::function<double()> fwd,
                    std::function<double()> rot)
      : m_drive{subsystem}, m_fwd{fwd}, m_rot{rot} {
    AddRequirements({subsystem});
  }

  void Execute() override {
    m_drive->ArcadeDrive(m_fwd(), m_rot());
  }

  void End(bool interrupted) override {
    m_drive->ArcadeDrive(0, 0); // Stop motors when command ends.
  }

 private:
  DriveSubsystem* m_drive;
  std::function<double()> m_fwd;
  std::function<double()> m_rot;
};
