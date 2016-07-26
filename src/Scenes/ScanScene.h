//
//  ScanScene.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/23.
//
//
//  カラダスキャン

#pragma once

#include "ofxState.h"
#include "MoverEasing.h"

class ScanScene : public itg::ofxState<SharedData>
{
public:
    ofVideoPlayer _video;
    
    MoverEasing _mover;
    ofVec2f _scanStartPos;
    ofVec2f _scanEndPos;
    
    ofShader _shader;
    ofFbo _bodyFbo;
    ofFbo _scanFbo;
    
//    ofTexture _tex;
    
    string getName()
    {
        return FILE;
    }
    
    void setup()
    {
        _video.load("videos/scan.mov");
        _video.setPosition(0.0);
        _video.setVolume(0.0);
        _video.setPaused(true);
        
        _bodyFbo.allocate(ofGetWidth(),ofGetHeight());
        _scanFbo.allocate(ofGetWidth(),ofGetHeight());
        
        _scanStartPos = ofVec2f(_bodyFbo.getWidth()*0.7, _bodyFbo.getHeight());
        _scanEndPos = ofVec2f(_bodyFbo.getWidth()*0.7, _bodyFbo.getHeight()*0.2);
        
        _shader.load("", "mask/mask.frag");
    }
    
    void stateEnter()
    {
        _video.setPaused(false);
        
        _mover.setup(1, EASING_CUBIC, _scanStartPos, _scanEndPos, 2000, 0);
        
    }
    
    void stateExit()
    {
//        _video.setPaused(true);
//        _video2.setPaused(true);
        _video.close();
        
        _bodyFbo.clear();
        _scanFbo.clear();
    }
    
    void update()
    {
        _video.update();
        
        if(_mover.isCompleted())
        {
            _mover.setup(1, EASING_CUBIC, _scanStartPos, _scanEndPos, 2000, 0);
        }
        
        _mover.update();
        
        _bodyFbo.begin();
        {
            ofClear(0,0,0,255);
        
            for(int i=0;i<getSharedData().bodysPolyline.size();i++)
            {
                getSharedData().bodysPolyline[i].setColor(ofColor(255,0,0));
                getSharedData().bodysPolyline[i].draw();
            }
            
        }
        _bodyFbo.end();
        
        _scanFbo.begin();
        {
            if(_mover.isCompleted()) ofClear(0,0,0,255);
            else
            {
            ofSetColor(255,255,0);
            float posx = _mover.getPosition().x;
            float posy = _mover.getPosition().y;
            
            for(int i=0;i<300;i++)
            {
                float x = ofRandomWidth();
                float y = posy + ofRandom(-15,15);
                
                ofDrawRectangle(x, y, ofRandom(45,45), ofRandom(25,30));
            }
            }

        }
        _scanFbo.end();
        
        getSharedData().fbo.begin();
        {
            ofClear(0,0,0,255);
            
            ofSetColor(255);
            _video.draw(0,0,ofGetWidth(),ofGetHeight());
            
            _shader.begin();
            _shader.setUniformTexture("tex0", _scanFbo.getTexture() , 1 );
            _shader.setUniformTexture("maskTex", _bodyFbo.getTexture() , 4 );
            
            _bodyFbo.draw(0,0,ofGetWidth(),ofGetHeight());
            _shader.end();
        
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
