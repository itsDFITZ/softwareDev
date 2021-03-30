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


void SoftClip::processSignal(float * signal, const int numSamples, const int c) {
    
    thresh = 1;
    
    for (int n = 0; n < numSamples; n++){
        float x = signal[n];
       

      
       if (x > thresh)
           signal[n] = thresh;
       if (x < -thresh)
           signal[n] = -thresh;
        
    }
}
