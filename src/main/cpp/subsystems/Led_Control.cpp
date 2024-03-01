// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Led_Control.h"


Led_Control::Led_Control() 
{
    candle.ConfigLEDType(ctre::phoenix::led::LEDStripType::GRB);
    candle.SetLEDs(0, 0, 0);

}


// This method will be called once per scheduler run
void Led_Control::Periodic() {
    // True = Green
    // False = Defult
    
    // P_state = C_state;
    // if(Switch.Get()){
    //     C_state = true;
    // }
    // else
    // {
    //     C_state = false;
    // }

    // if(P_state != C_state)
    // {
    //     if(!C_state)
    //     {
            
    //     }

    //     if(C_state)
    //     {

    //     }
    // }

    m_shooterState = SHOOTING;
    HandleShooterState();
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
        candle.SetLEDs(255, 0, 0); //Red
        break;
    
    case SPIN_UP:
        candle.SetLEDs(255, 255, 0); //Yellow
        break;

    case SHOOTING:
        ledGroup1.SetLarson(255, 30, 0, 4);
        ledGroup2.SetLarson(255, 30, 0, 3);
        // ledGroup3.SetLarson(255, 30, 0, 3);
        ledGroup4.SetLarson(255, 30, 0, 3);
        ledGroup5.SetLarson(255, 30, 0, 3);
        ledGroup3.SetFlash(255,255,255,0,0,0,Time);
        // ledGroup1.SetScrollingGradient(0, 255, 0, 0, 0, 255);
        // ledGroup2.SetScrollingGradient(0, 255, 0, 0, 0, 255);
        // ledGroup3.SetScrollingGradient(0, 255, 0, 0, 0, 255);
        // ledGroup4.SetScrollingGradient(0, 255, 0, 0, 0, 255);
        // ledGroup5.SetScrollingGradient(0, 255, 0, 0, 0, 255);
        break;
    case BAD:
        AllLEDs.SetFlash(255, 0, 0, 255, 30, 0, Time);
        break;
    default:
        candle.SetLEDs(255, 255, 255);
        break;
    }
}



//Gradient Code: