//
//  BodysPolyline.cpp
//  oscPolylineTest02_receiver
//
//  Created by yuitoshiya on 2016/07/23.
//
//

#include "BodysPolyline.hpp"

BodysPolyline::BodysPolyline(){
    bGetNoBody = true;
}


void BodysPolyline::update(ofxOscMessage & mes){
    //ボディの信号をうけとったら
    bGetBodyPoly = false;
    if(mes.getAddress() == "/bodyPoly"){
        //フラグを立てる
        bGetBodyPoly = true;
    }else if(mes.getAddress() == "/noBody"){
        // bodyがなくなったときの最初のみ送信
        bGetNoBody = true;
    }
    
    if(bGetBodyPoly){
        //初期化
        bGetNoBody = false;
        bodyPolyVec.clear();
        bodyNo.clear();
        int mN = mes.getNumArgs();
        int nowMesNo = 0;
        
        //oscをpolylineに入れる
        // 型: /bodyPoly (ボディの番号 lineの点の数　座標X 座標Y ....) (ボディの番号 lineの点の数　座標X 座標Y ....) ...
        while(nowMesNo < mN){
            ofPath bodyPoly;
            int no = mes.getArgAsInt(nowMesNo);
            nowMesNo++;
            int loopNum = mes.getArgAsInt(nowMesNo);
            nowMesNo++;
            for(int i = 0 ; i < loopNum; i++){
                bodyPoly.lineTo(mes.getArgAsInt(nowMesNo), mes.getArgAsInt(nowMesNo+1));
                nowMesNo+=2;
            }
            bodyPoly.close();
            bodyPolyVec.push_back(bodyPoly);
            bodyNo.push_back(no);
        }
    }
}

void BodysPolyline::draw(){
    if(bGetNoBody){
        ofBackground(100, 100, 100);
    }else{
        ofBackground(0, 0, 255);
    }
    
    for(int i = 0; i < bodyPolyVec.size(); i++){
        if(bodyNo[i] == 0 ){ ofSetColor(255,0,0);}
        else{ ofSetColor(0,255,0);}
        bodyPolyVec[i].draw();
    }
}

int BodysPolyline::getPolyNum(){
    return bodyPolyVec.size();
}

int BodysPolyline::getBodyNum(){
    //buffer的に蓄えているのでbodyが0はない。
    if(!bGetNoBody){
        bool b0=false;
        bool b1 = false;
        for(int i = 0; i < bodyNo.size(); i++){
            if(bodyNo[i] == 0){
                b0 = true;
            }else{
                b1 = true;
            }
        }
        if(b0 && b1){
            return 2;
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}

bool BodysPolyline::isOsc(){
    return bGetBodyPoly && bGetNoBody;
}