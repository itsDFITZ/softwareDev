//
//  SoftClip.cpp
//  ExampleProject - VST3
//
//  Created by Dylan Page on 3/23/21.
//  Copyright © 2021 DFITZ SP. All rights reserved.
//

#include "SoftClip.h"
#include <stdio.h>

using namespace std;
SoftClip::SoftClip(){};

void SoftClip::softClip(float * signal, const int numSamples, const int c){};
float SoftClip::processSample(float x, int c){
    return 1.f;
};

void SoftClip::processSignal(float * signal, const int numSamples, const int c) {
    
    thresh = 1.f;
    
    for (int n = 0; n < numSamples; n++){
        float x = signal[n];
       

      
       if (x > thresh)
           x[n] = thresh;
       if (x < -thresh)
           x[n] = -thresh;
       else x[n] = x[n];
        
    }
}
