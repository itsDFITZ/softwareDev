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
    
    newThreshold = -6.f;
    setAttack = 3.f;
    setRelease = 3.f;
    setRatio = 20.f;
    
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
       

     
        
    }
}
