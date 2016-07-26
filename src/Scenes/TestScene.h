//
//  TestScene.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/23.
//
//

//
//  テストシーン
//

#pragma once

#include "ofxState.h"

class TestScene : public itg::ofxState<SharedData>
{
public:
    
    // vars
    ofVideoPlayer _video;
    
    float _preSoundSync;
    int _sceneStartTime = ofGetElapsedTimeMillis();
    
    string getName()
    {
        return FILE;
    }
    
    void setup()
    {
        _video.load("videos/testscene.mov");
        _video.setPosition(0.0);
        _video.setVolume(0.0);
        _video.play();
        _video.setPaused(true);
    }
    
    void stateEnter()
    {
        _preSoundSync = getSharedData().params["sound_sync"];
        _video.setPaused(false);

    }
    
    void stateExit()
    {
        _video.setPaused(true);

    }
    
    void update()
    {
        
        // maxでsound_syncのバーを調整した場合
//        if( _preSoundSync != getSharedData().params["sound_sync"] )
//        {
//            _preSoundSync = getSharedData().params["sound_sync"];
//            float newVideoPosition =  _video.getPosition() + _preSoundSync / 100.0;
//            _video.setPosition(newVideoPosition);
//        }
        
        // video update
        _video.update();
        
        
        getSharedData().fbo.begin();
        {
            ofBackground(0);
            
            // ムービー
            _video.draw(0,0,ofGetWidth(),ofGetHeight());
            
#if DEBUG_MODE != 1
            //
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
