// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ShooterSubsystem.h"
#include "frc/Joystick.h"
#include "commands/SetBottomMotorSpeed.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...

  frc::Joystick m_controllerTop{0};
  frc::Joystick m_controllerBottom{1};

  ShooterSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;
  //SetBottomMotorSpeed m_bottomSpeedCommand;


  void ConfigureButtonBindings();
};