/************************************************************
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
		printf("%s : %s\n", str_Name.c_str(), __FUNCTION__);
		fflush(stdout);
	}
	
	~TEMP()
	{
		printf("%s : %s\n", str_Name.c_str(), __FUNCTION__);
		fflush(stdout);
	}
	
	void exit(){
		ofExit();
		printf("%s : %s\n", str_Name.c_str(), __FUNCTION__);
		fflush(stdout);
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
