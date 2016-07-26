//
//  StroboScene.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/25.
//
//  ストロボたく

#pragma once

#include "ofxState.h"

class StroboScene : public itg::ofxState<SharedData>
{
public:
    
    int _stroboDuration;
    
    ofFbo _bodyFbo;
    ofFbo _stroboFbo;
    
    ofShader _shader;
    
    string getName()
    {
        return FILE;
    }
    
    void setup()
    {
        _stroboDuration = 70;
        
        _bodyFbo.allocate(ofGetWidth(), ofGetHeight());
        _stroboFbo.allocate(ofGetWidth(), ofGetHeight());
        _shader.load("","mask/mask.frag");
    }
    
    void stateEnter()
    {
    }
    
    void stateExit()
    {
    }
    
    void update()
    {
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

        _stroboFbo.begin();
        {
            float alpha = (sin(ofGetElapsedTimef()*_stroboDuration)+1)*128;
            ofSetColor(255, alpha);
            ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
            
            ofSetColor(0);
            for(int i=0;i<30;i++)
            {
                ofDrawRectangle(ofVec2f(0,ofRandomHeight()), ofGetWidth(), ofRandom(3));
            }
        }
        _stroboFbo.end();
        
        
        getSharedData().fbo.begin();
        {
            ofClear(0,0,0,255);
            
            //背景はここに書く
            
            ofSetColor(255);
            
            _shader.begin();
            _shader.setUniformTexture("tex0", _stroboFbo.getTexture() , 1 );
            _shader.setUniformTexture("maskTex", _bodyFbo.getTexture() , 4 );
            
            _bodyFbo.draw(0,0,ofGetWidth(),ofGetHeight());
            _shader.end();
            
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
