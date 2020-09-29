/************************************************************
************************************************************/

/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/
TEMP Temp_inner("Temp_outer");


/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp()
: Temp_inner("Temp_inner")
{
	printf("ofApp : constructor\n");
	fflush(stdout);
}

/******************************
******************************/
ofApp::~ofApp()
{
	printf("ofApp : destructor\n");
	fflush(stdout);
}

/******************************
******************************/
void ofApp::exit(){
	printf("ofApp : exit\n");
	fflush(stdout);
}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetBackgroundAuto(true);
	
	ofSetWindowTitle("oFExit");
	ofSetVerticalSync(true);
	ofSetFrameRate(10);
	ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
	
	/********************
	********************/
	/*
	ofExit();
	std::exit(1);
	*/
}

/******************************
******************************/
void ofApp::update(){
	printf("ofApp : update in\n");
	fflush(stdout);
	
	if(b_Exit){
		printf("ofApp:update:b_Exit\n");
		fflush(stdout);
		
		/*
		ofExit();
		std::exit(1);
		*/
	}
	
	printf("ofApp : update out\n");
	fflush(stdout);
}

/******************************
******************************/
void ofApp::draw(){
	printf("ofApp : draw in\n");
	fflush(stdout);
	
	ofBackground(30);
	
	if(b_Exit){
		printf("ofApp:draw:b_Exit\n");
		fflush(stdout);
		
		/*
		ofExit();
		std::exit(1);
		*/
	}
	
	printf("ofApp : draw out\n");
	fflush(stdout);
}

/******************************
******************************/
void ofApp::keyPressed(int key){
	switch(key){
		case ' ':
			b_Exit = true;
			printf("ofApp : key ; exit\n");
			fflush(stdout);
			break;
			
		case 'e':
			Temp_inner.exit();
			break;
	}
}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
