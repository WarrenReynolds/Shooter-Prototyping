// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DisableBottomMotor.h"

DisableBottomMotor::DisableBottomMotor(ShooterSubsystem * subsystem)
  :m_subsystem{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_subsystem});
}

// Called when the command is initially scheduled.
void DisableBottomMotor::Initialize() {
  m_subsystem->SetBottomMotorState(false);
}

// Called repeatedly when this Command is scheduled to run
void DisableBottomMotor::Execute() {}

// Called once the command ends or is interrupted.
void DisableBottomMotor::End(bool interrupted) {}

// Returns true when the command should end.
bool DisableBottomMotor::IsFinished() {
  return true;
}
