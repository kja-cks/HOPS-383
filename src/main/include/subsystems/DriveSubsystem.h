#pragma once


#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/Joystick.h>
#include <rev/SparkMax.h>
using namespace rev::spark;

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

  //SparkMax m_tool1 = SparkMax(1, SparkLowLevel::MotorType::kBrushless);
  //SparkMax m_tool2 = SparkMax(2, SparkLowLevel::MotorType::kBrushless);

  //SparkMax m_left = SparkMax(3, SparkLowLevel::MotorType::kBrushed);
  //SparkMax m_right = SparkMax(4, SparkLowLevel::MotorType::kBrushed);
  //frc::MotorControllerGroup m_driveMotors = frc::MotorControllerGroup(m_leftDrive, m_rightDrive);

  //frc::DifferentialDrive m_robotDrive = frc::DifferentialDrive(m_tool1, m_tool2);
};