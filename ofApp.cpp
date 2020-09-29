/************************************************************
ofExit();
	call ofApp::exit();
	別classから呼び出してもofApp::exit();に来る。
	ofApp::exit();の後、そのまま、呼び出し元に戻って、今の関数は続ける
	今の関数抜けたら、終了する(Destructorもきちんと呼ばれる)
	
opApp::exit()にてstd::exit(1);で終了すると、当然ここで終了。
つまり、その後の関数処理も行われない。
しかし、opApp::~ofApp()も呼ばれない。
ofApp内で定義したclass memberのDestructorも呼ばれない。


結論
	ERRORで抜ける場合は、std::exit(1);を直接呼び出す。
	∵
	強制終了意外でもofApp:exit()はcallされるので、ofApp::exit()の最後にstd::exit(1);を入れるのはNG。
	ofExit();の後にreturn;してその関数を抜ければOK.
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
	printf("%s\n", __FUNCTION__);
	fflush(stdout);
}

/******************************
******************************/
ofApp::~ofApp()
{
	printf("%s\n", __FUNCTION__);
	fflush(stdout);
}

/******************************
******************************/
void ofApp::exit(){
	printf("%s\n", __FUNCTION__);
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
	// ofExit();
	std::exit();
}

/******************************
******************************/
void ofApp::update(){
	if(b_Exit){
		printf("ofApp:update:b_Exit\n");
		fflush(stdout);
		
		/*
		ofExit();
		std::exit(1);
		*/
	}
	
	printf("%s\n", __FUNCTION__);
	fflush(stdout);
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(30);
	
	printf("%s\n", __FUNCTION__);
	fflush(stdout);
}

/******************************
******************************/
void ofApp::keyPressed(int key){
	switch(key){
		case ' ':
			b_Exit = true;
			printf("%s : Exit\n", __FUNCTION__);
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
