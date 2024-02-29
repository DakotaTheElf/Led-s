// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LED_Groups.h"
#include <ctre/phoenix/led/Animation.h>
#include <ctre/phoenix/led/LarsonAnimation.h>
#include <frc/smartdashboard/SmartDashboard.h>


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

void LED_Group::SetGradient(int _r, int _g, int _b, int _R, int _G, int _B, int LedNum)
{
    int r = _r;
    int g = _g;
    int b = _b;
    int R = _R;
    int G = _G;
    int B = _B;

    int _rStep;
    int _gStep;
    int _bStep;

    int RStep;
    int GStep;
    int BStep;

    int i = 0;

    _rStep = r - R;
    _gStep = g - G;
    _bStep = b - B;

    RStep = _rStep/LedNum;
    GStep = _gStep/LedNum;
    BStep = _bStep/LedNum;

    for(i = 0; i <= LedNum; i++)
    {
        _candle->SetLEDs(r, g, b, 0, i + 8, 1);
        
        r -= RStep;
        g -= GStep;
        b -= BStep;
    }
}

void LED_Group::SetScrollingGradient(int _r, int _g, int _b, int _R, int _G, int _B, int LedNum)
{
    int a;
    for(a = 0; a <= LedNum; a++)
    {
        int r = _r;
        int g = _g;
        int b = _b;
        int R = _R;
        int G = _G;
        int B = _B;

        int _rStep;
        int _gStep;
        int _bStep;

        int RStep;
        int GStep;
        int BStep;

        int i;

        _rStep = r - R;
        _gStep = g - G;
        _bStep = b - B;

        RStep = _rStep/LedNum;
        GStep = _gStep/LedNum;
        BStep = _bStep/LedNum;

        if(i >= LedNum)
        {
            Offset += 1;
            r = (RStep * Offset) + r;
            frc::SmartDashboard::PutBoolean("TEST", true);
        }

        for(i = 0; i <= LedNum; i++)
        {
            _candle->SetLEDs(r, g, b, 0, i + 8, 1);
        
            r -= RStep;
            g -= GStep;
            b -= BStep;
        }
    }
}