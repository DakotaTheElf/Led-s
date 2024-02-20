// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/led/CANdle.h>
#include <frc/DigitalInput.h>
#include <frc2/command/button/Trigger.h>

enum LightState
{
  DEFAULT,
  INTAKE,
  SHOOTING
};

enum IntakeState
{
  //Only while intake button pressed
  NO_NOTE,  //Red
  NOTE  //Green
};

enum ShooterState
{
  NO_SHOT,  // Orange
  SPIN_UP,  // Yellow
  SHOOTING,  //Green
  NO_NOTE  //Blinking Red
};

class Led_Control : public frc2::SubsystemBase {
 public:
  Led_Control();

  ctre::phoenix::led::CANdle candle {9};


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
 frc::DigitalInput Switch {4};

 bool P_state;
 bool C_state;

 void HandleIntakeState();

 LightState m_lightState = LightState::DEFAULT;
 IntakeState m_intakeState = IntakeState::NO_NOTE;
 ShooterState m_shooterState = ShooterState::NO_NOTE;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};