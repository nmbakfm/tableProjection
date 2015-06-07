//
//  Setting.cpp
//  tableProjection
//
//  Created by 南部 晃史 on 2015/06/07.
//
//

#include "Setting.h"

ofxXmlSettings Setting::xml;

ofPoint Setting::orgVertices[3][4], Setting::targetVertices[3][4];
float Setting::movieWidth, Setting::movieHeight;

void Setting::load(){
    xml.load(SETTING_XML_FILENAME);
    
    xml.pushTag("settings");
    
    movieWidth = xml.getAttribute("movieSize", "width", 0.0);
    movieHeight = xml.getAttribute("movieSize", "height", 0.0);
    
    xml.pushTag("calibrations");
    for (int i=0; i<3; ++i) {
        xml.pushTag("calibration", i);
        
        xml.pushTag("orgVertices");
        for(int j=0; j<4; ++j){
            orgVertices[i][j] = ofPoint(xml.getAttribute("vertex", "x", 0.0, j), xml.getAttribute("vertex", "y", 0.0, j));
        }
        xml.popTag();//orgVertices
        
        xml.pushTag("targetVertices");
        for (int j=0; j<4; ++j) {
            targetVertices[i][j] = ofPoint(xml.getAttribute("vertex", "x", 0.0, j), xml.getAttribute("vertex", "y", 0.0, j));
        }
        xml.popTag();//targetVertices
        
        xml.popTag();//calibration i
    }
    xml.popTag(); // calibrations
    
    xml.popTag(); // settings
}