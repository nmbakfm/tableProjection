#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(30);
    
    Setting::load();
    
#if DEBUG
    testImage.loadImage("testImage.jpg");
#endif
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    for (int i=0; i<3; ++i) {
        mesh.addVertex(Setting::targetVertices[i][0]);
        mesh.addVertex(Setting::targetVertices[i][1]);
        mesh.addVertex(Setting::targetVertices[i][2]);
        mesh.addVertex(Setting::targetVertices[i][0]);
        mesh.addVertex(Setting::targetVertices[i][3]);
        mesh.addVertex(Setting::targetVertices[i][2]);
        
        mesh.addTexCoord(Setting::orgVertices[i][0]);
        mesh.addTexCoord(Setting::orgVertices[i][1]);
        mesh.addTexCoord(Setting::orgVertices[i][2]);
        mesh.addTexCoord(Setting::orgVertices[i][0]);
        mesh.addTexCoord(Setting::orgVertices[i][3]);
        mesh.addTexCoord(Setting::orgVertices[i][2]);
    }
    
    fbo.allocate(Setting::movieWidth, Setting::movieHeight);
    fbo.setUseTexture(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    fbo.begin();
//    ofBackground(0);
    
#if DEBUG
    testImage.draw(0,0,Setting::movieWidth, Setting::movieHeight);
//    ofBackground(0);
//    ofSetColor(255);
//    for(int i=0; 20*i<960; ++i){
//        ofLine(0, i*20, 4800, i*20);
//    }
//    for (int i=0; 20*i<4800; ++i) {
//        ofLine(i*20, 0, i*20, 960);
//    }
#endif
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.getTextureReference().bind();
    mesh.draw();
    fbo.getTextureReference().unbind();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
