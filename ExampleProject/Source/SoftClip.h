//
//  Header.h
//  ExampleProject - VST3
//
//  Created by Dylan Page on 3/23/21.
//  Copyright © 2021 DFITZ SP. All rights reserved.
//

#ifndef SoftClip_h
#define SoftClip_h
#include "PluginProcessor.h"

class SoftClip{
public:
    SoftClip(){};
    void softClip(float * signal, const int numSamples, const int c);
    void processSignal(float * signal, const int numSamples, const int c);
    
    float processSample(float x, int c){
        return 1.f;
    };
    
//    void prepare(float newFs);
private:
 
    
    int thresh;
    float x;
};


#endif /* SoftClip_h */
