// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LED_Groups.h"
#include <ctre/phoenix/led/Animation.h>
#include <ctre/phoenix/led/LarsonAnimation.h>

void LED_Group::SetColor(int _r, int _g, int _b)
{
    for(int i: _group)
    {
        _candle->SetLEDs(_r, _g, _b, 0, i, 1);
    }
}

void LED_Group::SetLarson(int _r, int _g, int _b, int Length)
{
    SetColor(0, 0, 0);
    _candle->SetLEDs(_r, _g, _b, 0, _group[LarsonFront], Length);
    LarsonFront += 1;
    if(LarsonFront >= _group.size() - Length)
    {
        LarsonFront = 0;
    }
}
// This method will be called once per scheduler run

void LED_Group::SetDisco(int _r, int _g, int _b)
{
    for(int i: _group)
    {
     _candle->SetLEDs(_r, _g, _b, 0, i, 1);
     _candle->SetLEDs(0, 0, 0, 0, i - 1, 1);
    }
}

void LED_Group::SetFlash(int _r, int _g, int _b, int r, int g, int b, units::time::second_t Period)
{    
    _timer.Start();

    if(_timer.HasElapsed(Period))
    {
        if(_status)
        {
            SetColor(_r, _g, _b);
            _status = false;
        }
        else
        {
            SetColor(r, g, b);
            _status = true;
        }

        _timer.Reset();
    }
}

void LED_Group::SetScrollingGradient(int _r, int _g, int _b, int LedNum)
{
    int b = _b;
        int r = _r;
        int i = 0;
        for(i = 0; i <= 104; i++)
        {
            _candle->SetLEDs(r, _g, b, 0, i, 1);
            r -= 2;
            b += 2;
        }
    
    // int R = _r;
    // int G = _g;
    // int B = _b;
    // int i = 0;

    // StepR = _r / LedNum;
    // StepG = _g / LedNum;
    // StepB = _b / LedNum;
    
    //     for(i = 0; i <= 104; i++)
    //     {
    //         _candle->SetLEDs(R, G, B, 0, i, 1);



    //         r -= StepR;
    //         g -= StepG;
    //         b += StepB;
    //     }
}