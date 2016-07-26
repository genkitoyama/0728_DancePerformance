//
//  BodysPolyline.hpp
//  oscPolylineTest02_receiver
//
//  Created by yuitoshiya on 2016/07/23.
//
//

#ifndef BodysPolyline_hpp
#define BodysPolyline_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxOsc.h"

class BodysPolyline {
public:
    BodysPolyline();
    //oscを受けて更新
    void update(ofxOscMessage & mes);
    
    //描画
    void draw();
    bool isOsc();
    int getPolyNum();
    int getBodyNum();
    //oscを受け取ったかどうか
    bool bGetBodyPoly;
    bool bGetNoBody;
    
    //左0, 右1
    vector<int> bodyNo;
    
    //polylineのベクター
    vector<ofPath> bodyPolyVec;
private:
    
    
};

#endif /* BodysPolyline_hpp */
