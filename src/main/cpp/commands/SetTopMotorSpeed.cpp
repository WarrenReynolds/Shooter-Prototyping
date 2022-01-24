// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SetTopMotorSpeed.h"
#include <frc/smartdashboard/SmartDashboard.h>

SetTopMotorSpeed::SetTopMotorSpeed(ShooterSubsystem *subsystem, std::function<double()> MotorSpeed)
    : m_subsystem{subsystem},
      m_motorSpeedFunction{std::move(MotorSpeed)} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void SetTopMotorSpeed::Initialize()
{
  m_subsystem->SetTopMotorState(true);
}

// Called repeatedly when this Command is scheduled to run
void SetTopMotorSpeed::Execute()
{
  m_subsystem->SetTopMotorPower(m_motorSpeedFunction());

}

// Called once the command ends or is interrupted.
void SetTopMotorSpeed::End(bool interrupted) {}

// Returns true when the command should end.
bool SetTopMotorSpeed::IsFinished()
{
  return true;
}
