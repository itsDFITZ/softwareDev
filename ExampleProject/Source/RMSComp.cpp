//
//  RMSComp.cpp
//  ExampleProject - VST3
//
//  Created by Dylan Page on 3/23/21.
//  Copyright © 2021 DFITZ SP. All rights reserved.
//

#include <stdio.h>
#include "RMSComp.h"

using namespace std;

RMSComp::RMSComp(){};

void RMSComp::rmsComp(float * signal, const int numSamples, const int c){};
float RMSComp::processSample(float x, int c){
    return 1.f;
};

void RMSComp::processSignal(float * signal, const int numSamples, const int c) {
    
    newThreshold = -6.f; // I aim to make this variable based on RMS of input with a potential lookahead feature
    setAttack = 3.f;
    setRelease = 3.f;
    setRatio = 20.f;
    gainSmoothPrev = 0.f;
    
    alphaA = exp(-log(9)/(Fs * setAttack));
    alphaR = exp(-log(9)/(Fs * setRelease));
    
    for (int n = 0; n < numSamples; n++){
        float x = signal[n];
        x_dB = 20.f * log10(abs(x[n]));
        if (x_dB < -96.f)
            x_dB = -96.f;
        
        
        if (x_dB > newThreshold)
            gainSC = newThreshold + (x_dB - newThreshold)/setRatio;
        else
            gainSC = x_dB;
      
        gainChange_dB = gainSC - x_dB;
        
        if (gainChange_dB < gainSmoothPrev)
                gainSmooth = -sqrt(((1-alphaA)*gainChange_dB^2)+(alphaA*gainSmoothPrev^2));
            else
                gainSmooth = -sqrt(((1-alphaR)*gainChange_dB^2)+(alphaR*gainSmoothPrev^2));
           
            
            lin_A[n] = 10^(gainChange_dB/20);
            
            x[n] = lin_A[n] * x[n];
            
            gainSmoothPrev = gainSmooth;
     
    
    }
}
