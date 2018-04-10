#include "testApp.h"
#include "RedState.h"
#include "GreenState.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // setup events
    stateMachine.setup(OF_EVENT_ORDER_BEFORE_APP, OF_EVENT_ORDER_BEFORE_APP);
    
	// setup shared data
	stateMachine.getShared().counter = 0;
	stateMachine.getShared().lastUpdate = ofGetElapsedTimeMillis();
	stateMachine.getShared().font.load("vag.ttf", 50);
	
	// initialise state machine
	stateMachine.addState<RedState>();
	stateMachine.addState<GreenState>();
	stateMachine.changeState("green");
}

//--------------------------------------------------------------
void testApp::update()
{
  
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("This text is drawn in testApp.\nKey released changes event order.\nMouse click changes state.", 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
    stateMachine.disableAppEvents();
    
    if (switchEvents) stateMachine.setup(OF_EVENT_ORDER_AFTER_APP, OF_EVENT_ORDER_AFTER_APP);
    else stateMachine.setup(OF_EVENT_ORDER_BEFORE_APP, OF_EVENT_ORDER_BEFORE_APP);
    
    switchEvents = !switchEvents;
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
