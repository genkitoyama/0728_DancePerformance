#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);

    // state machine
    _stateMachine.addState<BlackScene>();
    _stateMachine.addState<TestScene>();
    _stateMachine.addState<ScanScene>();
    _stateMachine.addState<FirstScene>();
    _stateMachine.addState<NosajScene>();
    _stateMachine.addState<StroboScene>();
//    _stateMachine.addState<SecondScene>();
    _stateMachine.addState<SamsScene>();
//    _stateMachine.addState<KansoScene>();
    _stateMachine.addState<TateScene>();
//    _stateMachine.addState<AngoScene>();
    _stateMachine.addState<BaigaeshiScene>();
//    _stateMachine.addState<LastSonicScene>();
//    _stateMachine.addState<LastScene>();
    
    changeSceneAt("BlackScene");
    
    // scene names
    _sceneNames["0"] = "FirstScene";
    _sceneNames["1"] = "ScanScene";
    _sceneNames["2"] = "FirstScene";
    _sceneNames["3"] = "NosajScene";
    _sceneNames["4"] = "StroboScene";
    _sceneNames["5"] = "FirstScene";
    _sceneNames["6"] = "SamsScene";
    _sceneNames["7"] = "StroboScene";
    _sceneNames["8"] = "FirstScene";
    _sceneNames["9"] = "TateScene";
    _sceneNames["10"] = "FirstScene";
    _sceneNames["11"] = "BaigaeshiScene";
    _sceneNames["12"] = "FirstScene";
    _sceneNames["13"] = "StroboScene";
    _sceneNames["14"] = "FirstScene";
    _sceneNames["15"] = "BlackScene";
    
//    _sceneNames["0"] = "TestScene";
//    _sceneNames["1"] = "ScanScene";
//    _sceneNames["2"] = "FirstScene";
//    _sceneNames["3"] = "NosajScene";
//    _sceneNames["4"] = "StroboScene";
//    _sceneNames["5"] = "SecondScene";
//    _sceneNames["6"] = "SamsScene";
//    _sceneNames["7"] = "StroboScene";
//    _sceneNames["8"] = "KansoScene";
//    _sceneNames["9"] = "TateScene";
//    _sceneNames["10"] = "AngoScene";
//    _sceneNames["11"] = "BaigaeshiScene";
//    _sceneNames["12"] = "LastSonicScene";
//    _sceneNames["13"] = "StroboScene";
//    _sceneNames["14"] = "LastScene";

    // effect name
    _effectNames.push_back( EffectName("effect_rgb", OFXPOSTGLITCH_CONVERGENCE) );
    _effectNames.push_back( EffectName("effect_glow", OFXPOSTGLITCH_GLOW) );
    _effectNames.push_back( EffectName("effect_twist", OFXPOSTGLITCH_TWIST) );
    _effectNames.push_back( EffectName("effect_shaker", OFXPOSTGLITCH_SHAKER) );
    _effectNames.push_back( EffectName("effect_cutslider", OFXPOSTGLITCH_CUTSLIDER) );
    
    // shared data
    _stateMachine.getSharedData().fbo.allocate(Const::WIDTH, Const::HEIGHT, GL_RGBA, 4);
    
    // osc
    _oscManager.setup();
    
    // postglitch
    _postGlitch.setFbo( & _stateMachine.getSharedData().fbo );
    
    // syphon
    _mainOutputSyphonServer.setName("Screen Outputh");
    _mClient.setup();
    _mClient.setApplicationName("Simple Serverh");
    _mClient.setServerName("");
}

//--------------------------------------------------------------
void ofApp::update(){
    int getFrameNum = ofGetFrameNum();
    
    // --------- //
    // Maxのパラメータチェック
    // --------- //
    MaxObj maxObj = _oscManager.updateMax();
    if( !maxObj.empty() )
    {
        for (auto e : maxObj)
        {
            cout << e.first << "::" << e.second << endl;
            _stateMachine.getSharedData().params[ e.first ] = e.second;
        }
    }
    
    // Maxのパラメータに変更があったら、設定を変更する系
    if( !_stateMachine.getSharedData().params.empty() )
    {
        // シーンの変更
        if( 0 < maxObj.count("scene") )
        {
            changeSceneAt( _sceneNames[ ofToString(maxObj["scene"]) ] );
        }
        
        // ポストエフェクト編
        for( EffectName e : _effectNames )
        {
            if( 0 < maxObj.count( e.name ) )
            {
                changeEffectSetting( e.name, maxObj[e.name]);
            }
        }
    }
    
    
    // --------- //
    // Kinectのパラメータチェック
    // --------- //
    
    _oscManager.updateKinectParams();
    
    vector<ofPath> bodyPoly = _oscManager.updateKinectBodysPolyline();
    if( !bodyPoly.empty() )
    {
        _stateMachine.getSharedData().bodysPolyline = bodyPoly;
    }
    
    vector<ofVec3f> bodyLeftHand = _oscManager.updateKinectBodysLeftHand();
    if(!bodyLeftHand.empty())
    {
        _stateMachine.getSharedData().bodyLeftHand = bodyLeftHand;
    }
    
    vector<ofVec3f> bodyRightHand = _oscManager.updateKinectBodysRightHand();
    if(!bodyRightHand.empty())
    {
        _stateMachine.getSharedData().bodyRightHand = bodyRightHand;
    }
    
    vector<ofVec2f> weaponVec = _oscManager.updateKinectWeapon();
    if(!weaponVec.empty())
    {
        _stateMachine.getSharedData().weaponVec = weaponVec;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // FBO
    ofSetColor(255);
    _postGlitch.generateFx();
    _stateMachine.getSharedData().fbo.draw(0, 0);
    
    _mainOutputSyphonServer.publishScreen();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::changeSceneAt(string sceneName)
{
    _stateMachine.changeState(sceneName + ".h");
}

//--------------------------------------------------------------
void ofApp::changeEffectSetting(string effectName ,int flag)
{
    bool e_flag = (flag == 0) ? false : true;
    
    for( EffectName effect : _effectNames )
    {
        if( effectName == effect.name )
        {
            _postGlitch.setFx(effect.enumName, e_flag);
        }
    }
}
