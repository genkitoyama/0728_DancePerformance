//
//  SharedData.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/23.
//
//

#pragma once

//#include "BodysPolyline.hpp"
//#include "BodysHand.hpp"
//#include "Weapon.hpp"

class SharedData
{
public:
    
    // 描画データ
    ofFbo fbo;
    
    // maxからのパラメータ
    MaxObj params;
    
    // kinectからのパフォーマー位置パラメータ
//    KinectObj performerPositions;
    
    vector<ofPath> bodysPolyline;
    vector<ofVec3f> bodyLeftHand;
    vector<ofVec3f> bodyRightHand;
    vector<ofVec2f> weaponVec;
    
//    BodysPolyline bodysPolyline;
//    BodysHand bosyHand;
//    Weapon weapon;
    
    // maxからbangがきたかどうかのbool
    bool isBangFired;
    
};
