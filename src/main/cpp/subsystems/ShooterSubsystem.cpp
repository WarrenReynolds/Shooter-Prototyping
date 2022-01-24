// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSubsystem.h"
#include <frc/smartdashboard/SmartDashboard.h>

ShooterSubsystem::ShooterSubsystem()
{
  // Implementation of subsystem constructor goes here.
  m_bottomMotorMirror.Follow(m_bottomMotor);
  m_bottomMotorMirror.SetInverted(true);
}

void ShooterSubsystem::Periodic()
{
  // Implementation of subsystem periodic method goes here.
  if (m_bottomMotorEnabled)
  {
    m_bottomMotor.Set(ControlMode::PercentOutput, m_bottomPercentagePower);
  }
  else
  {
    m_bottomMotor.Set(ControlMode::PercentOutput, 0.0);
  }

  if (m_topMotorEnabled)
  {
    m_topMotor.Set(ControlMode::PercentOutput, m_topPercentagePower);
  }
  else
  {
    m_topMotor.Set(ControlMode::PercentOutput, 0.0);
  }

  m_feedMotor.Set(ControlMode::PercentOutput, m_feedPercentagePower);

  frc::SmartDashboard::PutNumber("Top Motor Speed", m_topPercentagePower);
  frc::SmartDashboard::PutNumber("Bottom Motor Speed", m_bottomPercentagePower);
}

void ShooterSubsystem::SetTopMotorState(bool MotorState)
{
  m_topMotorEnabled = MotorState;
  frc::SmartDashboard::PutBoolean("Top Motor State", m_topMotorEnabled);
}

void ShooterSubsystem::SetBottomMotorState(bool MotorState)
{
  m_bottomMotorEnabled = MotorState;
  frc::SmartDashboard::PutBoolean("Bottom Motor State", m_bottomMotorEnabled);
}

void ShooterSubsystem::SimulationPeriodic()
{
  // Implementation of subsystem simulation periodic method goes here.
}

void ShooterSubsystem::SetTopMotorPower(double TopSpeed)
{
  //Set the power to the top Motor
  m_topPercentagePower = TopSpeed;
}

void ShooterSubsystem::SetBottomMotorPower(double BottomSpeed)
{
  //Set the power to the Bottom Motor
  m_bottomPercentagePower = BottomSpeed;
}

void ShooterSubsystem::StepTopMotorSpeed(int Direction)
{
  m_topPercentagePower += Direction * 0.05;
  if (m_topPercentagePower > 1.0)
    m_topPercentagePower = 1.0;
  if (m_topPercentagePower < -1.0)
    m_topPercentagePower = -1.0;
}

void ShooterSubsystem::StepBottomMotorSpeed(int Direction)
{
  m_bottomPercentagePower += Direction * 0.05;
  if (m_bottomPercentagePower < -1.0)
    m_bottomPercentagePower = -1.0;
  if (m_bottomPercentagePower > 0)
    m_bottomPercentagePower = 0;
}

void ShooterSubsystem::SetFeedMotorPower(double FeedSpeed)
{
  m_feedPercentagePower = FeedSpeed;
}