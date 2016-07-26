#pragma once

#include "ofMain.h"

#include "ofxStateMachine.h"
#include "ofxPostGlitch.h"
#include "ofxSyphon.h"

#include "Const.h"
#include "SharedData.h"
#include "OscManager.h"
#include "EffectName.h"

#include "TestScene.h"
#include "ScanScene.h"
#include "NosajScene.h"
#include "StroboScene.h"
#include "BlackScene.h"
#include "SamsScene.h"
#include "TateScene.h"
#include "FirstScene.h"
#include "SecondScene.h"
#include "KansoScene.h"
#include "AngoScene.h"
#include "BaigaeshiScene.h"
#include "LastSonicScene.h"
#include "LastScene.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
    
    // my functions
    void changeSceneAt(string sceneName);
    void changeEffectSetting(string effectName ,int flag);
    
    itg::ofxStateMachine<SharedData> _stateMachine;
    ofxPostGlitch _postGlitch;
    OscManager _oscManager;
    
    // datas
    map<string, string> _sceneNames;
    vector<EffectName> _effectNames;
    
    //syphon
    ofxSyphonServer _mainOutputSyphonServer;
    ofxSyphonServer _individualTextureSyphonServer;
    ofxSyphonClient _mClient;

};
