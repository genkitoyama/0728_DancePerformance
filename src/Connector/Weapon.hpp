//
//  Weapon.hpp
//  oscPolylineTest02_receiver
//
//  Created by yuitoshiya on 2016/07/23.
//
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include <stdio.h>

#include "ofMain.h"
#include "ofxOsc.h"

class Weapon {
public:
    Weapon ();
    //oscを受けて更新
    void update(ofxOscMessage & mes);
    
    //描画
    void draw();
    bool isOsc();
    int getWeaponNum();
    //oscを受け取ったかどうか
    bool bGetWeapon;
    bool bGetNoWeapon;
    
    //左0, 右1
    vector<int> weaponNo;
    
    //polylineのベクター
    vector<ofVec2f> weaponVec;
private:
    
    
};

#endif /* Weapon_hpp */
