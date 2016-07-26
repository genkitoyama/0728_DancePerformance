//
//  TateScene.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/25.
//
//

#pragma once

#include "ofxState.h"

class TateScene : public itg::ofxState<SharedData>
{
public:
    
    vector<ofPath> _path;
    vector<vector<ofPolyline>> _polys;
    ofColor _pathColor;
    
    vector<ofVec2f> _triangleVec;
    
    string getName()
    {
        return FILE;
    }
    
    void setup()
    {
        _path.clear();
        _polys.clear();
    }
    
    void stateEnter()
    {
        _triangleVec.clear();
        _polys.clear();
        _path = getSharedData().bodysPolyline;
        
        for(int i=0;i<_path.size();i++)
        {
            vector<ofPolyline> poly;
            poly = _path[i].getOutline();
            _polys.push_back(poly);
        }
    }
    
    void stateExit()
    {
        _path.clear();
        _polys.clear();
    }
    
    void update()
    {
        _polys.clear();
        _path = getSharedData().bodysPolyline;
        for(int i=0;i<_path.size();i++)
        {
            vector<ofPolyline> poly;
            poly = _path[i].getOutline();
            _polys.push_back(poly);
        }
        
        _triangleVec.clear();
        int count = 0;
        for(int k=0;k<50;k++)
        {
            for(int i=0;i<_polys.size();i++)
            {
                for(int j=0;j<_polys[i].size();j++)
                {
                    ofVec2f vec = ofVec2f(ofRandom(_polys[i][j].getBoundingBox().getLeft(),_polys[i][j].getBoundingBox().getRight()),
                                          ofRandom(_polys[i][j].getBoundingBox().getTop(),_polys[i][j].getBoundingBox().getBottom()));

                    if(_polys[i][j].inside(vec))
                    {
                        _triangleVec.push_back(vec);
//                        count++;
//                        break;
                    }
                }
            }
            
        }
        
        getSharedData().fbo.begin();
        {
            ofClear(0,0,0,255);
            
            ofSetColor(0,255,0);
            for(int i=0;i<_polys.size();i++)
            {
                for(int j=0;j<_polys[i].size();j++)
                {
                    int g = ofClamp((j+1)*100, 0,255);
                    ofSetColor(255, g, 0);
                    _polys[i][j].draw();
//                    for(int k=0;k<_polys[i][j].getVertices().size();k++)
//                    {
//                        ofVec2f pos = ofVec2f(_polys[i][j].getVertices()[k]);
//                        ofDrawTriangle(pos.x, pos.y, pos.x+10, pos.y+20, pos.x-10, pos.y+20);
//                    }
                }
            }
            
            ofSetColor(0, 255, 255);
            int length = 10;
            for(int i=0; i<_triangleVec.size();i++)
            {
                ofDrawTriangle(_triangleVec[i]+ofVec2f(0,-length),
                               _triangleVec[i]+ofVec2f(length*sqrt(3)/2,length/2),
                               _triangleVec[i]+ofVec2f(-length*sqrt(3)/2,length/2));
            }
            
#if DEBUG_MODE != 1
            
            ofSetColor(0,255,0);
            stringstream msg;
            msg << FILE << endl;
            msg << ofToString(ofGetFrameRate(),2) << endl;
            ofDrawBitmapString(msg.str(), 10, 40);
#endif
            
        }
        getSharedData().fbo.end();
        
    }
    
};
