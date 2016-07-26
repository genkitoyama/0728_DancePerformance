//
//  MoverEasing.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/24.
//
//

#pragma once

#include "ofxTween.h"

enum EASING_TYPES{
    EASING_BACK = 1,
    EASING_BOUNCE,
    EASING_CIRC,
    EASING_CUBIC,
    EASING_ELASTIC,
    EASING_EXPO,
    EASING_LINEAR,
    EASING_QUAD,
    EASING_QUART,
    EASING_QUINT,
    EASING_SINE,
};

enum EASING_MODE{
    EASING_IN = 1,
    EASING_OUT,
    EASING_INOUT,
};

class MoverEasing : public ofBaseApp {
private:
    int _ID;
    ofVec2f _position;
    ofVec2f _from;
    ofVec2f _to;
    int _duration;
    int _delay;
    ofxTween _myTween;
    
    EASING_TYPES EASING_TYPE;
    
    ofxEasingBack       _easingBack;
    ofxEasingBounce 	_easingBounce;
    ofxEasingCirc       _easingCirc;
    ofxEasingCubic      _easingCubic;
    ofxEasingElastic    _easingElastic;
    ofxEasingExpo       _easingExpo;
    ofxEasingLinear 	_easingLinear;
    ofxEasingQuad       _easingQuad;
    ofxEasingQuart      _easingQuart;
    ofxEasingQuint      _easingQuint;
    ofxEasingSine       _easingSine;
    
public:
    MoverEasing()
    {
        
    }
    
    ~MoverEasing(){}
    
    void setup(int ID, EASING_TYPES type, ofVec2f from, ofVec2f to, int duration, int delay)
    {
        _ID = ID;
        _position = from;
        _from = from;
        _to = to;
        _duration = duration;
        _delay = delay;
        
        switch(type)
        {
            case EASING_BACK:
                _myTween.setParameters(_ID, _easingBack, ofxTween::easeInOut, 0, 1, _duration, _delay);
            case EASING_BOUNCE:
                _myTween.setParameters(_ID, _easingBounce, ofxTween::easeInOut, 0, 1, _duration, _delay);
            case EASING_CIRC:
                _myTween.setParameters(_ID, _easingCirc, ofxTween::easeInOut, 0, 1, _duration, _delay);
            case EASING_CUBIC:
            default:
                _myTween.setParameters(_ID, _easingCubic, ofxTween::easeInOut, 0, 1, _duration, _delay);
            case EASING_ELASTIC:
                _myTween.setParameters(_ID, _easingElastic, ofxTween::easeInOut, 0, 1, _duration, _delay);
            case EASING_EXPO:
                _myTween.setParameters(_ID, _easingExpo, ofxTween::easeInOut, 0, 1, _duration, _delay);
            case EASING_LINEAR:
                _myTween.setParameters(_ID, _easingLinear, ofxTween::easeInOut, 0, 1, _duration, _delay);
            case EASING_QUAD:
                _myTween.setParameters(_ID, _easingQuad, ofxTween::easeInOut, 0, 1, _duration, _delay);
            case EASING_QUART:
                _myTween.setParameters(_ID, _easingQuart, ofxTween::easeInOut, 0, 1, _duration, _delay);
            case EASING_QUINT:
                _myTween.setParameters(_ID, _easingQuint, ofxTween::easeInOut, 0, 1, _duration, _delay);
            case EASING_SINE:
                _myTween.setParameters(_ID, _easingSine, ofxTween::easeInOut, 0, 1, _duration, _delay);
        }
        
    }
    
    void update()
    {
        ofVec2f velocity = _to - _from;        
        _position = _from + velocity * _myTween.update();
//        cout << _myTween.update() << endl;
    }
    
    float getUpdateVal()
    {
        return _myTween.update();
    }
    
    void draw()
    {
        ofDrawCircle(_position, 20);
        ofDrawRectangle(_to, 5, 5);
    }
    
    void drawLine()
    {
        ofDrawLine(_from, _position);
    }
    
    void drawRectangle()
    {
        float length = ofMap(_myTween.update(),0,1,0,70);
        ofDrawRectangle(_to, length, length);
    }
    
    void drawTriangle()
    {
        float length = ofMap(_myTween.update(),0,1,0,50);
        ofDrawTriangle(_to+ofVec2f(0,-length),
                       _to+ofVec2f(length*sqrt(3)/2,length/2),
                       _to+ofVec2f(-length*sqrt(3)/2,length/2));
    }
    
    ofVec2f getPosition()
    {
        return _position;
    }
    
    bool isCompleted()
    {
        return _myTween.isCompleted();
    }
    
    ofVec2f getFromVec()
    {
        return _from;
    }
    
    ofVec2f getToVec()
    {
        return _to;
    }
};