#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
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
		void createMaze();
		void drawMaze();
		void freeMemory();
		
		float startTime, elapsedTime; //시작시간 변수와 경과시간 변수
		float windowHeight, windowWidth; //window창의 높이와 너비
		int startflag, endflag; //미로 게임의 시작과 끝을 확인하는 flag변수
		int playflag; 
		//플레이어가 플레이를 시작함을 알려주는 flag변수
		//(startflag와는 다른점은 startflag는 게임 자체를 시작하기 위한 준비가 됐음을 나타내고 playflag는 플레이어가 게임을 시작했음을 나타냄)
 		int timeflag = 0; //게임이 시작된지 5초가 지났는지 확인하는 flag변수
		int width, height, row, col; //미로 char 배열의 너비와 크기 & 미로의 너비와 크기
		int startX, startY, targetX, targetY; //미로의 시작점과 탈출지점
		int currentX, currentY; //현재 플레이어의 위치
		char** maze; //미로 char배열
		int** set;

		
};
