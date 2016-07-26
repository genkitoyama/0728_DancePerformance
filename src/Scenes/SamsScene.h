//
//  SamsScene.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/25.
//
//

#pragma once

#include "ofxState.h"

class SamsScene : public itg::ofxState<SharedData>
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
            
            for(int i=0;i<getSharedData().bodyLeftHand.size();i++)
            {
                ofSetColor(255,0,0);
                ofDrawCircle(getSharedData().bodyLeftHand[i].x, getSharedData().bodyLeftHand[i].y, getSharedData().bodyLeftHand[i].z/50);
                ofSetColor(0,255,0);
                ofDrawCircle(getSharedData().bodyRightHand[i].x, getSharedData().bodyRightHand[i].y, getSharedData().bodyRightHand[i].z/50);
            }
            
            ofSetRectMode(OF_RECTMODE_CENTER);
            for(int i=0;i<getSharedData().weaponVec.size();i++)
            {
                ofSetColor(255, 255, 0);
                ofDrawRectangle(getSharedData().weaponVec[i], 30, 30);
            }
            ofSetRectMode(OF_RECTMODE_CORNER);
            
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
