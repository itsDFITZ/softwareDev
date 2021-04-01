//
//  RMSComp.h
//  ExampleProject - VST3
//
//  Created by Dylan Page on 3/23/21.
//  Copyright © 2021 DFITZ SP. All rights reserved.
//

#ifndef RMSComp_h
#define RMSComp_h

class RMSComp{
public:
    RMSComp(){};
    void rmsComp(float * signal, const int numSamples, const int c);
    void processSignal(float * signal, const int numSamples, const int c);
        float processSample(float x, int c){
        return 1.f;
    };
    void setThreshold(float newThreshold);
    void setRatio(float newRatio);
    void setAttack (float newAttack);
    void setRelease (float newRelease);
    
//    void prepare(float newFs);
private:
 
    
//    int thresh;
//    float ratio;
  float x;
    float x_db;
    float gainChange_dB;
    float gainSC;
    float gainSmoothPrev;
    float gainSmooth;
    float alphaA;
    float alphaR;
    float lin_A;
};


#endif /* RMSComp_h */
