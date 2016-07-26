//
//  DrawPrimitives.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/25.
//
//

#pragma once

#include "MoverEasing.h"
#include "Particle2D.h"

//まだやってない
class DrawPrimitives: public ofBaseApp{
private:
    
    MoverEasing _mover;
    ofVec2f _from;
    ofVec2f _to;
    
public:
    
    void setup()
    {
        _mover.setup(10, EASING_CIRC, _from, _to, 2000, 500);
    }
    
    void drawLine()
    {
        ofDrawLine(_mover.getF)
    }
    
};