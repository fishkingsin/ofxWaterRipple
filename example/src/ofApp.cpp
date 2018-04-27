#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	agua.setup(1024, 768);
    gui.setup(); // most of the time you don't need a name
    gui.add(damping.setup("damping", 0.999, 0.99, 0.9999999));
    player.load("video.mp4");
    player.setLoopState(OF_LOOP_NORMAL);
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    player.update();
    ofImage image;
    ofPixels pixel;
    pixel.allocate(player.getWidth(), player.getHeight(), OF_IMAGE_COLOR);
    pixel.setFromPixels(player.getPixels().getData(), player.getWidth(), player.getHeight(), OF_IMAGE_COLOR);
    pixel.resize(agua.gpuCompute.getWidth(), agua.gpuCompute.getHeight());

    agua.gpuCompute.tex.loadData(pixel);
    
    agua.pDamping = damping;
	agua.update();
	ofSetWindowTitle( ofToString(ofGetFrameRate()) + " FPS" );
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	agua.draw(false);
    gui.draw();
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
	agua.disturb(x,y,10,128);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_1)
		agua.disturb(x,y,10,128);
	else
		agua.disturb(x,y,50,500);

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
