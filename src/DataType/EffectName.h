//
//  EffectName.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/23.
//
//
//
//  エフェクト名を格納するためのデータ型
//

#pragma once


class EffectName
{
public:
    string name;
    ofxPostGlitchType enumName;
    
    EffectName(string n, ofxPostGlitchType e)
    {
        name = n;
        enumName = e;
    }
};




