//
//  BunshinScene.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/26.
//
//


#pragma once

#include "ofxState.h"

class BunshinScene : public itg::ofxState<SharedData>
{
public:
    
    string getName()
    {
        return FILE;
    }
    
    void setup()
    {
    }
    
    void stateEnter()
    {
    }
    
    void stateExit()
    {
        
    }
    
    void update()
    {
        
        getSharedData().fbo.begin();
        {
            ofClear(0,0,0,255);
            
            
#if DEBUG_MODE != 1
            
            ofSetColor(0,255,0);
            stringstream msg;
            msg << FILE << endl;
            msg << ofToString(ofGetFrameRate(),2) << endl;
            ofDrawBitmapString(msg.str(), 10, 40);
#endif
            
        }
        getSharedData().fbo.end();
        
    }
    
};
