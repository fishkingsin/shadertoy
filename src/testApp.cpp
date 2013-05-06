#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    dir.allowExt("frag");
    nFile = dir.listDir("");
    shader.load("", "volumeExplosion.frag");
    
    
    grabber.initGrabber(640,480);
}

//--------------------------------------------------------------
void testApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    shader.begin();
    shader.setUniform3f("iResolution",640,480,0);
    shader.setUniform2f("iMouse",ofGetMouseX(),ofGetMouseY());
    shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
    grabber.draw(0, 0, 640,480);
    
    shader.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key== ' ')
    {
        shader.load("",dir.getPath((int)ofRandom(0,nFile)));
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}