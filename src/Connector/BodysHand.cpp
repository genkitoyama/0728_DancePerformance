//
//  BodysHand.cpp
//  oscPolylineTest02_receiver
//
//  Created by yuitoshiya on 2016/07/23.
//
//

#include "BodysHand.hpp"

BodysHand::BodysHand(){
    bGetNoBody = true;
}

void BodysHand::update(ofxOscMessage & mes){
    
    
    
    //ボディの信号をうけとったら
    bGetBodyHand = false;
    if(mes.getAddress() == "/bodyHand"){
        //フラグを立てる
        bGetBodyHand = true;
        
    }else if(mes.getAddress() == "/noBodyHand"){
        // bodyがなくなったときの最初のみ送信
        bGetNoBody = true;
    }
    
    if(bGetBodyHand){
        //初期化
        
        bGetNoBody = false;
        bodyLeftHandVec.clear();
        bodyRightHandVec.clear();
        bodyLeftHandState.clear();
        bodyRightHandState.clear();
        bodyNo.clear();
        int mN = mes.getNumArgs();
        int nowMesNo = 0;
        
        while(mN>
              nowMesNo){
        int no = mes.getArgAsInt(nowMesNo+0);
        bodyNo.push_back(no);
        
        ofVec3f bodyLeftHand,bodyRightHand;
        bodyLeftHand = ofVec3f(mes.getArgAsInt(nowMesNo+1),mes.getArgAsInt(nowMesNo+2),mes.getArgAsInt(nowMesNo+3));
        bodyRightHand = ofVec3f(mes.getArgAsInt(nowMesNo+4),mes.getArgAsInt(nowMesNo+5),mes.getArgAsInt(nowMesNo+6));
        bodyLeftHandVec.push_back(bodyLeftHand);
        bodyRightHandVec.push_back(bodyRightHand);
        
        bodyLeftHandState.push_back(mes.getArgAsInt(nowMesNo+7));
        bodyRightHandState.push_back(mes.getArgAsInt(nowMesNo+8));
            
            nowMesNo+=9;
        }
    }
}

void BodysHand::draw(){
    if(bGetNoBody){
        ofSetColor(100, 100, 100,100);
        ofRectangle(0,0,512,426);
    }else{
        ofSetColor(0, 0, 255,100);
        ofRectangle(0,0,512,426);
    }
    
    if(!bGetNoBody){
    for(int i = 0; i < bodyLeftHandVec.size(); i++){
        if(bodyNo[i] == 0 ){ ofSetColor(255,100,100);}
        else{ ofSetColor(100,255,100);}
        ofDrawCircle( bodyLeftHandVec[i].x,bodyLeftHandVec[i].y,10);
        ofDrawCircle( bodyRightHandVec[i].x,bodyRightHandVec[i].y,10);
    }
    }
}


int BodysHand::getBodyNum(){
    if(!bGetNoBody){
        return bodyLeftHandVec.size();
    }else{
        return 0;
    }
}

bool BodysHand::isOsc(){
    return bGetBodyHand && bGetNoBody;
}