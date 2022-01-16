// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc2/command/button/JoystickButton.h>
#include "commands/SetBottomMotorSpeed.h"
#include "commands/SetTopMotorSpeed.h"
#include "commands/DisableTopMotor.h"
#include "commands/DisableBottomMotor.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
frc2::JoystickButton(&m_controllerBottom,1).WhenPressed(new SetBottomMotorSpeed(&m_subsystem,[this] {return m_controllerBottom.GetThrottle();}));
frc2::JoystickButton(&m_controllerBottom,2).WhenPressed(new DisableBottomMotor(&m_subsystem));

frc2::JoystickButton(&m_controllerTop,1).WhenPressed(new SetTopMotorSpeed(&m_subsystem, [this] {return m_controllerTop.GetThrottle();}));
frc2::JoystickButton(&m_controllerTop,2).WhenPressed(new DisableTopMotor(&m_subsystem));

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}


void RobotContainer::StopAllMotors(){
  m_subsystem.SetBottomMotorState(false);
  m_subsystem.SetTopMotorState(false);
}