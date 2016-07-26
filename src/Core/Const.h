//
//  Const.h
//  定数クラス
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/23.
//
//

#pragma once

//デバッグモード。 1:本番／2:デバッグ1(セカンドディスプレイがあるとき)/3:デバッグ2（mac book 単体のとき）
#define DEBUG_MODE 2

// ファイル名
#define FILE (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)


//------//
// typedef
//------//

// maxから送られてくるパラメータはこの型を使う
typedef map<string, int> MaxObj;

// Kinectから送られてくるパラメータはこの型を使う
//typedef map<int, MaxObj> KinectObj;


//------//
// enum scene id
//------//

enum SCENE_TYPE{
    TEST_SCENE = 1,
    SCAN_SCENE = 2,
    NOSAJ_SCENE = 3,
//    LYRIC_SCENE = 4,
//    RYTHMGAME_SCENE = 5,
//    TEST_SCENE = 6,
//    GENKIDAMA_SCENE = 7,
//    QUATRO_SCENE = 8,
//    DOTROTATE_SCENE = 9,
//    AURA_SCENE = 10,
//    WWW_SCENE = 11
};


class Const {
public:

    //window size
    
#if DEBUG_MODE == 1
    
    // ウィンドウの幅（セカンドスクリーン）
    const static int WIDTH = 1920;
    
    // ウィンドウの高さ（セカンドスクリーン）
    const static int HEIGHT = 1080;
    
    // ファーストスクリーンの幅
    const static int FIRST_SCREEN_WINDOW_WIDTH = 1680;

    
#elif DEBUG_MODE == 2
    
    // ウィンドウの幅（セカンドスクリーン）
    const static int WIDTH = 1920;
    
    // ウィンドウの高さ（セカンドスクリーン）
    const static int HEIGHT = 1080;
    
    // ファーストスクリーンの幅
    const static int FIRST_SCREEN_WINDOW_WIDTH = 1680;
//    const static int FIRST_SCREEN_WINDOW_WIDTH = 0;

    
#elif DEBUG_MODE == 3
    
    // ウィンドウの幅（セカンドスクリーン）
    const static int WIDTH = 1280;
    
    // ウィンドウの高さ（セカンドスクリーン）
    const static int HEIGHT = 720;
    
    // ファーストスクリーンの幅
    const static int FIRST_SCREEN_WINDOW_WIDTH = 0;

#endif
    
    //----------//
    // OSC 系
    //----------//
    // Kinect用 受け PORT
    const static int OSC_KINECT_SERVER_PORT = 12346;
    
    // MAX用 受け PORT
    const static int OSC_MAX_SERVER_PORT = 6002;
    
    
    //----------//
    // Kinect 系
    //----------//
    // Kinectの横幅
    const static int KINECT_WIDTH = 512;
    
    // Kinectの縦幅
    const static int KINECT_HEIGHT = 424;
    
    
    //----------//
    // MAX 系
    //----------//
    const static int SYNC_MAX = 40;
    const static int VAR1_MAX = 100;
};





