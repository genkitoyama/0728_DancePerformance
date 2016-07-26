//
//  OscManager.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/23.
//
//

#pragma once

#include "ofxOsc.h"

#include "BodysHand.hpp"
#include "BodysPolyline.hpp"
#include "Weapon.hpp"

class OscManager
{
public:
    
    ofxOscReceiver _oscKinectReceiver;
    ofxOscReceiver _oscMaxReceiver;
    
    BodysPolyline _bodysPolyline;
    BodysHand _bodysHand;
    Weapon _weapon;

    void setup()
    {
        // kinect reciever
        _oscKinectReceiver.setup(Const::OSC_KINECT_SERVER_PORT);
        
        // max reciever
        _oscMaxReceiver.setup(Const::OSC_MAX_SERVER_PORT);
    }
    
    //    // Kinectのパラメータをパース
    void updateKinectParams()
    {
        while(_oscKinectReceiver.hasWaitingMessages())
        {
            ofxOscMessage m;
            _oscKinectReceiver.getNextMessage(m);
            
            _bodysPolyline.update(m);
            _bodysHand.update(m);
            _weapon.update(m);
        }
    }
    
    vector<ofPath> updateKinectBodysPolyline()
    {
        vector<ofPath> bodyPolys;
        bodyPolys = _bodysPolyline.bodyPolyVec;
        return bodyPolys;
    }
    
    
    vector<ofVec3f> updateKinectBodysLeftHand()
    {
        vector<ofVec3f> bodyLeftHand;
        bodyLeftHand = _bodysHand.bodyLeftHandVec;
        return bodyLeftHand;
    }
    
    vector<ofVec3f> updateKinectBodysRightHand()
    {
        vector<ofVec3f> bodyRightHand;
        bodyRightHand = _bodysHand.bodyRightHandVec;
        return bodyRightHand;
    }
    
    vector<ofVec2f> updateKinectWeapon()
    {
        vector<ofVec2f> weapon;
        weapon = _weapon.weaponVec;
        return weapon;
    }
    
    
    // maxのパラメータをパース
    MaxObj updateMax()
    {
        MaxObj maxObj;
        
        int oscCount = 0;
        while(_oscMaxReceiver.hasWaitingMessages())
        {
            // oscからのデータ
            if( 300 < oscCount ){ break; }
            
            // parse osc
            ofxOscMessage m;
            _oscMaxReceiver.getNextMessage(m);
            string key = m.getAddress().erase(0,1);     // アドレスの "/" を削除
            
//            if(m.getAddress() == "/scene")
//            {
//                // シーン変更
//                int val = m.getArgAsInt32(0);
//                maxObj[key] = val;
//                cout << key << " : " << maxObj[key] << "," << endl;
//                break;
//            }
            
            switch( m.getArgType(0) )
            {
                // OSCから拾った値をパラメータにセット
                case OFXOSC_TYPE_INT32:
                case OFXOSC_TYPE_INT64:
                default:
                {
                    int val = m.getArgAsInt32(0);
                    maxObj[key] = val;
                    break;
                }
                    
                case OFXOSC_TYPE_FLOAT:
                {
                    float val2 = m.getArgAsFloat(0);
                    maxObj[key] = val2;
                    break;
                }
            }
            
            
            // 確認
//            cout << key << " : " << maxObj[key] << "," << endl;

            
            if(m.getAddress() == "/bang")
            {
                
            }
        
            // increment
            oscCount++;
        }
        
        if(!maxObj.empty()) cout << "--- end osc --" << endl;
        
        return maxObj;
    }
};

