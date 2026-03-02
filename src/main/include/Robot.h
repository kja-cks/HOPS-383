// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#pragma once


#include <optional>


#include <frc2/command/CommandPtr.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/TimedRobot.h>
#include <frc/Timer.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/DataLogManager.h>


#include "RobotContainer.h"


class Robot : public frc::TimedRobot {
 public:
  Robot();
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;


 private:
  // Have it empty by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  std::optional<frc2::CommandPtr> m_autonomousCommand;
  std::optional<frc2::CommandPtr> m_teleopCommand;
// Robot drive system
  frc::Spark m_left{1};
  frc::Spark m_right{2};
  frc::PWMSparkMax m_tool1{3};
  frc::PWMSparkMax m_tool2{4};
  frc::PWMSparkMax m_tool3{5};
  frc::DifferentialDrive m_robotDrive{
      [&](double output) { m_left.Set(output); },
      [&](double output) { m_right.Set(output); },    
      };


  frc::XboxController m_controller{0};
  frc::Timer m_timer;
  RobotContainer m_container;
};