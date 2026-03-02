#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/Joystick.h>

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the robot is enabled.
   */
  void Periodic() override;

  /**
   * Drives the robot using arcade drive.
   *
   * @param fwd The forward direction value [-1.0..1.0].
   * @param rot The rotation direction value [-1.0..1.0].
   */
  void ArcadeDrive(double fwd, double rot);

 private:
  // Components (e.g. motors, speed controllers, etc) should generally be
  // created here, rather than in the constructor.
  frc::PWMSparkMax m_leftFront{1};
  frc::PWMSparkMax m_leftRear{2};
  frc::MotorControllerGroup m_leftMotors{m_leftFront, m_leftRear};

  frc::PWMSparkMax m_rightFront{3};
  frc::PWMSparkMax m_rightRear{4};
  frc::MotorControllerGroup m_rightMotors{m_rightFront, m_rightRear};
};