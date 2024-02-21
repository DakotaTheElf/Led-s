// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Led_Control.h"


Led_Control::Led_Control() = default;

// This method will be called once per scheduler run
void Led_Control::Periodic() {
    // True = Green
    // False = Defult
    P_state = C_state;
    if(Switch.Get()){
        C_state = true;
    }
    else
    {
        C_state = false;
    }

    if(P_state != C_state)
    {
        if(!C_state)
        {
            candle.SetLEDs(0, 255, 0);
        }

        if(C_state)
        {
            candle.SetLEDs(0, 0, 255);
        }
    }

}

void Led_Control::HandleIntakeState() {
    switch (m_intakeState)
    {
    case NO_NOTE:
        candle.SetLEDs(255, 0, 0);
        break;
    
    case NOTE:
        candle.SetLEDs(0, 255, 0);
        break;

    default:
        candle.SetLEDs(255, 255, 255);
        break;
    }
}

void Led_Control::HandleShooterState(){
    switch (m_shooterState)
    {
    case NO_SHOT:
        candle.SetLEDs(255, 0, 0);
        break;
    
    case SPIN_UP:
        candle.SetLEDs(255, 255, 0);
        break;

    case SHOOTING:
        candle.SetLEDs(0, 255, 0);
        break;
        
    case BAD:
        candle.SetLEDs(0, 255, 255);
        break;
    default:
        candle.SetLEDs(255, 255, 255);
        break;
    }
}