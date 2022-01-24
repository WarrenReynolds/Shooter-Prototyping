// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SetBottomMotorSpeed.h"
#include <frc/smartdashboard/SmartDashboard.h>

SetBottomMotorSpeed::SetBottomMotorSpeed(ShooterSubsystem *subsystem, std::function<double()> MotorSpeed)
    : m_subsystem{subsystem},
      m_motorSpeedFunction{std::move(MotorSpeed)} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void SetBottomMotorSpeed::Initialize()
{
  m_subsystem->SetBottomMotorState(true);
}

// Called repeatedly when this Command is scheduled to run
void SetBottomMotorSpeed::Execute()
{
  m_subsystem->SetBottomMotorPower(m_motorSpeedFunction());

}

// Called once the command ends or is interrupted.
void SetBottomMotorSpeed::End(bool interrupted) {}

// Returns true when the command should end.
bool SetBottomMotorSpeed::IsFinished()
{
  return true;
}
