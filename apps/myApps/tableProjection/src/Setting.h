//
//  Setting.h
//  tableProjection
//
//  Created by 南部 晃史 on 2015/06/07.
//
//

#ifndef __tableProjection__Setting__
#define __tableProjection__Setting__

#include "ofMain.h"
#include "ofxXmlSettings.h"

#define DEBUG TRUE

#define SETTING_XML_FILENAME "setting.xml"


class Setting {
public:
    static void load();
    
    static ofxXmlSettings xml;
    
    static float movieWidth, movieHeight;
    static ofPoint orgVertices[3][4];
    static ofPoint targetVertices[3][4];

};

#endif /* defined(__tableProjection__Setting__) */
