// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc2/command/button/JoystickButton.h>
#include "commands/SetBottomMotorSpeed.h"
#include "commands/SetTopMotorSpeed.h"
#include "commands/DisableTopMotor.h"
#include "commands/DisableBottomMotor.h"
#include "commands/StepTopMotorSpeed.h"
#include "commands/StepBottomMotorSpeed.h"
#include "commands/SetFeedMotorSpeed.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
frc2::JoystickButton(&m_controllerBottom,1).WhileHeld (new SetBottomMotorSpeed(&m_subsystem,[this] {return m_controllerBottom.GetThrottle();}));
frc2::JoystickButton(&m_controllerBottom,2).WhenPressed(new DisableBottomMotor(&m_subsystem));

frc2::JoystickButton(&m_controllerTop,1).WhileHeld(new SetTopMotorSpeed(&m_subsystem, [this] {return m_controllerTop.GetThrottle();}));
frc2::JoystickButton(&m_controllerTop,2).WhenPressed(new DisableTopMotor(&m_subsystem));

frc2::JoystickButton(&m_controllerBottom,7).WhenPressed(new StepBottomMotorSpeed(&m_subsystem,1));
frc2::JoystickButton(&m_controllerBottom,8).WhenPressed(new StepBottomMotorSpeed(&m_subsystem,-1));


frc2::JoystickButton(&m_controllerTop,7).WhenPressed(new StepTopMotorSpeed(&m_subsystem,-1));
frc2::JoystickButton(&m_controllerTop,8).WhenPressed(new StepTopMotorSpeed(&m_subsystem,1));

frc2::JoystickButton(&m_controllerTop,11).WhenPressed(new SetFeedMotorSpeed(&m_subsystem,0.0));
frc2::JoystickButton(&m_controllerTop,12).WhenPressed(new SetFeedMotorSpeed(&m_subsystem,0.2));

frc2::JoystickButton(&m_controllerBottom,11).WhenPressed(new SetFeedMotorSpeed(&m_subsystem,0.0));
frc2::JoystickButton(&m_controllerBottom,12).WhenPressed(new SetFeedMotorSpeed(&m_subsystem,0.2));

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}


void RobotContainer::StopAllMotors(){
  m_subsystem.SetBottomMotorState(false);
  m_subsystem.SetTopMotorState(false);
}