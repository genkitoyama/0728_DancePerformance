//
//  FirstScene.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/25.
//
//  いちばん

#pragma once

#include "ofxState.h"

class FirstScene : public itg::ofxState<SharedData>
{
public:
    
    ofVideoPlayer _video;
    
    string getName()
    {
        return FILE;
    }
    
    void setup()
    {
        _video.load("videos/0726_2040.mov");
        _video.setPosition(0.0);
        _video.setVolume(0.3);
        _video.play();
        _video.setLoopState(OF_LOOP_NONE);
        _video.setPaused(true);
    }
    
    void stateEnter()
    {
        if(_video.isPaused()) _video.setPaused(false);
    }
    
    void stateExit()
    {
        _video.setPaused(true);
    }
    
    void update()
    {
        _video.update();
        
        getSharedData().fbo.begin();
        {
            ofBackground(0);
            _video.draw(0, 0, ofGetWidth(), ofGetHeight());
            
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
