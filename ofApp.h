/************************************************************
ofExit()
	sj_note.jpeg の左図。分かり易い

std::exit()
	ofApp::setup()からcall
		O	ofApp::exit()
		X	ofApp::dst()
		X	ofApp内	class obj : dst()
		O	Global	class obj : dst()
		
	ofApp::updata/ draw()からcall
		O	ofApp::exit()
		O	ofApp::dst()
		O	ofApp内	class obj : dst()
		O	Global	class obj : dst()
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"

/************************************************************
************************************************************/
class TEMP{
private:
	string str_Name;
	
public:
	TEMP(string _str_Name)
	: str_Name(_str_Name)
	{
		printf("%s : constructor\n", str_Name.c_str());
		fflush(stdout);
	}
	
	~TEMP()
	{
		printf("%s : destructor\n", str_Name.c_str());
		fflush(stdout);
	}
	
	void exit(){
		printf("%s : exit\n", str_Name.c_str());
		fflush(stdout);
		
		/*
		ofExit();
		std::exit(1);
		*/
		
	}
	
};

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
	/****************************************
	****************************************/
	enum{
		WINDOW_WIDTH	= 500,
		WINDOW_HEIGHT	= 500,
	};
	
	/****************************************
	****************************************/
	bool b_Exit = false;
	TEMP Temp_inner;
	
public:
	/****************************************
	****************************************/
	ofApp();
	~ofApp();
	void exit();
	
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
