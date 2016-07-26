//
//  Weapon.cpp
//  oscPolylineTest02_receiver
//
//  Created by yuitoshiya on 2016/07/23.
//
//

#include "Weapon.hpp"

Weapon::Weapon(){
    bGetNoWeapon = true;
}


void Weapon::update(ofxOscMessage & mes){
    
    //ボディの信号をうけとったら
    bGetWeapon = false;
    if(mes.getAddress() == "/Weapon"){
        //フラグを立てる
        bGetWeapon = true;
        
    }else if(mes.getAddress() == "/noWeapon"){
        // bodyがなくなったときの最初のみ送信
        bGetNoWeapon = true;
    }
    
    if(bGetWeapon){
        //初期化
        
        bGetNoWeapon = false;
        weaponVec.clear();
        weaponNo.clear();
        int mN = mes.getNumArgs();
        int nowMesNo = 0;
        
        while(mN>nowMesNo){
            int no = mes.getArgAsInt(nowMesNo+0);
            weaponNo.push_back(no);
            
            ofVec2f wV;
            wV = ofVec3f(mes.getArgAsInt(nowMesNo+1),mes.getArgAsInt(nowMesNo+2));
            weaponVec.push_back(wV);
            
            nowMesNo+=3;
        }
    }
}

void Weapon::draw(){
    if(bGetNoWeapon){
        ofSetColor(100, 100, 100,100);
        ofRectangle(0,0,512,426);
    }else{
        ofSetColor(0, 0, 255,100);
        ofRectangle(0,0,512,426);
    }
    
    if(!bGetNoWeapon){
        for(int i = 0; i < weaponVec.size(); i++){
            if(weaponNo[i] == 0 ){ ofSetColor(255,255,100);}
            else{ ofSetColor(100,255,255);}
            ofDrawRectangle(weaponVec[i]-ofVec2f(5,5),10,10);
        }
    }
}


int Weapon::getWeaponNum(){
    if(!bGetNoWeapon){
        return weaponVec.size();
    }else{
        return 0;
    }
}

bool Weapon::isOsc(){
    return bGetWeapon && bGetNoWeapon;
}