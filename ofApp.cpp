/************************************************************
ofExit();
	call ofApp::exit();
	ofApp::exit();の後、そのまま、呼び出し元に戻って、今の関数は続ける
	今の関数抜けたら、終了する(Destructorもきちんと呼ばれる)
	
opApp::exit()にてstd::exit(1);で終了すると、当然ここで終了。
つまり、その後の関数処理も行われない。
しかし、opApp::~ofApp()も呼ばれない。


結論 1
	ofApp::exit();の最後でstd::exit(1);
		強制終了以外でもofApp::exit()はcallされるので、opApp::exit()の最後にstd::exit(1);を入れるのは正直少し乱暴。
		しかし、ofExit();をexit(xx);と同じ感覚で使用するなら、このsolutionが適当。
		
注意
	ofApp::~ofApp();
	にclean-up 処理を記述せず、全て、ofApp::exit();内で掃除すること。
	
	
結論 2
	丁寧に処理するなら、
	ofExit();の後にreturn;してその関数を抜ければOK.
************************************************************/

#include "ofApp.h"

/******************************
******************************/
void TEST::exit()
{
	printf("%s\n", __FUNCTION__);
}

/******************************
******************************/
ofApp::~ofApp()
{
	printf("%s\n", __FUNCTION__);
}

/******************************
******************************/
void ofApp::exit()
{
	test.exit();
	
	printf("Good-bye\n");
	// std::exit(1);
}

/******************************
******************************/
void TEST::keyPressed(int key){
	switch(key){
		case 'q':
			ofExit();
			return;
			
			printf("process after ofExit()\n");
			break;
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Exit test");
	ofSetFrameRate(60);
	ofSetWindowShape(600, 400);
	ofSetEscapeQuitsApp(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	test.keyPressed(key);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
