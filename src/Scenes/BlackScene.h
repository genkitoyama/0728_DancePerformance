//
//  BlackScene.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/25.
//
//  なにもしません

#pragma once

#include "ofxState.h"

class BlackScene : public itg::ofxState<SharedData>
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
            ofBackground(0);
            
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
