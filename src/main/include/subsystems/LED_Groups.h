// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// #include "Led_Control.h"
#include <vector>
#include <ctre/phoenix/led/CANdle.h>
#include <frc2/command/WaitCommand.h>

class LED_Group{
 public:
  LED_Group(ctre::phoenix::led::CANdle* candle, std::vector<int> group) :
         _candle(candle),
         _group(group) {}
  
  void SetColor(int _r, int _g, int _b);
  void SetLarson(int _r, int _g, int _b, int Length);
  void SetDisco(int _r, int _g, int _b);
  void SetFlash(int _r, int _g, int _b, int r, int g, int b, units::time::second_t Period);
  void SetScrollingGradient(int _r, int _g, int _b, int LedNum);
    /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
 private:
  // Led_Control leds;

  // int _r = 255;
  // int _g = 0;
  // int _b = 0;
  int random;
  int LarsonFront = 0;
  int StepR;
  int StepG;
  int StepB;

  bool _status = false;

  frc::Timer _timer;

  ctre::phoenix::led::CANdle* _candle;
  std::vector<int> _group;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
