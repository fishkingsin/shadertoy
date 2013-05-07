#include "testApp.h"
//--------------------------------------------------------------
void addFace(ofMesh& mesh, ofVec3f a, ofVec3f b, ofVec3f c) {
	ofVec3f normal = ((b - a).cross(c - a)).normalize();
	mesh.addNormal(normal);
	mesh.addTexCoord(a);
	mesh.addVertex(a);
	mesh.addNormal(normal);
	mesh.addTexCoord(b);
	mesh.addVertex(b);
	mesh.addNormal(normal);
	mesh.addTexCoord(c);
	mesh.addVertex(c);
}

//--------------------------------------------------------------
void addFace(ofMesh& mesh, ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d) {
	addFace(mesh, a, b, c);
	addFace(mesh, a, c, d);
}
//--------------------------------------------------------------
void testApp::setup(){
    dir.allowExt("frag");
    nFile = dir.listDir("");
//        currentPath = "volumeExplosion.frag";
//    
//    shader.load("", currentPath);
//    shader.load("plasma.vert","plasma.frag");
    shader.load("","plasma.frag");
    grabber.initGrabber(640,480);
    
    
    fbo.allocate(640,480);
    int width = fbo.getWidth();
	int height = fbo.getHeight();
	int step = 8;

    mainMesh.setMode(OF_PRIMITIVE_TRIANGLES);
	//add one vertex to the mesh for each pixel
	for (int y = 0; y < height; y+=step){
		for (int x = 0; x<width; x+=step){
			ofVec3f nw = ofVec3f( x, y , 0);
			ofVec3f ne = ofVec3f( x + step, y, 0);
			ofVec3f sw = ofVec3f( x, y + step, 0);
			ofVec3f se = ofVec3f( x + step, y + step, 0);
			
			addFace(mainMesh, nw, ne, se, sw);
			
		}
	}
}

//--------------------------------------------------------------
void testApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    fbo.begin();
	ofClear(0);
    grabber.draw(0, 0, 640,480);
    fbo.end();
    fbo.draw(0, 0,ofGetWidth(),ofGetHeight());
    cam.begin();
    shader.begin();
    shader.setUniform3f("iResolution",640,480,0);
    shader.setUniform2f("iMouse",ofGetMouseX(),ofGetMouseY());
    shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
    	shader.setUniform1i("tex", 0);
        	shader.setUniform1i("maxHeight", mouseY);

    fbo.getTextureReference().bind();
    mainMesh.drawFaces();
    fbo.getTextureReference().unbind();
    
    shader.end();
    cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key== ' ')
    {
        currentPath = dir.getPath((int)ofRandom(0,nFile));
        shader.load("",currentPath);
    }
    if(key == 'r')
    {
        shader.load("",currentPath);
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