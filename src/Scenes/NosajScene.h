//
//  NosajScene.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/24.
//
// Nosaj Thing 的シーン

#pragma once

#include "ofxState.h"
#include "MoverEasing.h"
#include "Particle2D.h"

class NosajScene : public itg::ofxState<SharedData>
{
public:
    
    vector<Particle2D> _particles;
    vector<MoverEasing> _movers;
    
    vector<ofPath> _path;
    ofColor _pathColor;
    
    string getName()
    {
        return FILE;
    }
    
    void setup()
    {
        _path.clear();
        _movers.clear();
        _particles.clear();
    }
    
    void stateEnter()
    {
        for(int i=0;i<50;i++)
        {
            MoverEasing mover;
            _movers.push_back(mover);
        }

        for(int i=0;i<_movers.size();i++)
        {
            ofVec2f from = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
            _movers[i].setup(i+1, EASING_CUBIC, from, from+ofVec2f(ofRandom(-100,100), ofRandom(-100,100)),
                        (int)ofRandom(1000,2000), (int)ofRandom(0,500));
        }
        
        _path = getSharedData().bodysPolyline;
        
        for(int i=0;i<80;i++)
        {
            Particle2D p2d;
            p2d.setup(ofVec2f(ofRandom(-1000,-100),ofRandomHeight()),ofVec2f(ofRandom(5,8),0));
            _particles.push_back(p2d);
        }

    }
    
    void stateExit()
    {
        _path.clear();
        _movers.clear();
        _particles.clear();
    }
    
    void update()
    {
        
        for(int i=0;i<_movers.size();i++)
        {
            if(_movers[i].isCompleted())
            {
                ofVec2f from = _movers[i].getPosition();
                _movers[i].setup(i+1, EASING_CUBIC, from, from+ofVec2f(ofRandom(-100,100), ofRandom(-100,100)),
                                 (int)ofRandom(1000,2000), (int)ofRandom(0,500));
            }
            
            _movers[i].update();
        }
        
        for(int i=0;i<_particles.size();i++)
        {
            _particles[i].updatePos();
            
            if(_particles[i].getPosition().x > 2000)
            {
                _particles[i].setup(ofVec2f(ofRandom(-500,-100),ofRandomHeight()),ofVec2f(ofRandom(5,8),0));
            }
        }
        
        int nowFrameNum = ofGetFrameNum()%30;
        if(nowFrameNum == 0)
        {
            _path = getSharedData().bodysPolyline;
            _pathColor = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
        }
        
        float alpha = ofMap(nowFrameNum, 0, 29, 255, 150);
        ofColor col = ofColor(_pathColor.r, _pathColor.g, _pathColor.b, alpha);
        
        getSharedData().fbo.begin();
        {
            ofClear(0, 0, 0, 255);
            ofSetColor(255);

//            ofNoFill();
//            for(int i=0;i<_movers.size();i++)
//            {
//                if(i%3 == 0)
//                {
//                    _movers[i].drawLine();
//                }
//                else if(i%3 == 1)
//                {
//                    _movers[i].drawRectangle();
//                }
//                else
//                {
//                    _movers[i].drawTriangle();
//                }
//            }
//            ofFill();
            
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofNoFill();
            for(int i=0;i<_particles.size();i++)
            {
                ofDrawRectangle(_particles[i].getPosition(), 25, 25);
                ofDrawLine(_particles[i].getPosition(), _particles[i].getPosition()+_particles[i].getVelocity()*(-15));
            }
            ofFill();
            ofSetRectMode(OF_RECTMODE_CORNER);
            
            for(int i=0;i<_path.size();i++)
            {
                _path[i].setColor(col);
                _path[i].draw();
            }
            
            for(int i=0;i<getSharedData().bodysPolyline.size();i++)
            {
                getSharedData().bodysPolyline[i].setColor(ofColor(200));
                getSharedData().bodysPolyline[i].draw();
            }
            
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
