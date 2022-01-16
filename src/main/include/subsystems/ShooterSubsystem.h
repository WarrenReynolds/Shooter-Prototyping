// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once



#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix.h>

class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

  /**
   * Sets top motor percentage power.
   */
  void SetTopMotorPower(double TopSpeed);

  /**
   * Sets Bottom motor percentage power.
   */
  void SetBottomMotorPower(double BottomSpeed);

    /**
   * Sets top motor enabled state.
   */
  void SetTopMotorState(bool MotorState);

      /**
   * Sets bottom motor enabled state.
   */
  void SetBottomMotorState(bool MotorState);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
TalonFX m_bottomMotor{1};
TalonFX m_topMotor{2};
double m_bottomPercentagePower=0.0;
double m_topPercentagePower=0.0;

bool m_bottomMotorEnabled=false;
bool m_topMotorEnabled=false;

};
