// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/StepBottomMotorSpeed.h"

StepBottomMotorSpeed::StepBottomMotorSpeed(ShooterSubsystem *subsystem, int direction) 
  : m_subsystem{subsystem},
  m_direction{direction} {
    AddRequirements({subsystem});
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void StepBottomMotorSpeed::Initialize() {
    m_subsystem->SetBottomMotorState(true);
m_subsystem->StepBottomMotorSpeed(m_direction);
}

// Called repeatedly when this Command is scheduled to run
void StepBottomMotorSpeed::Execute() {}

// Called once the command ends or is interrupted.
void StepBottomMotorSpeed::End(bool interrupted) {}

// Returns true when the command should end.
bool StepBottomMotorSpeed::IsFinished() {
  return true;
}