#include "ofApp.h"
#include <ctime>
#include <cstdlib>
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Maze Escape");
	ofSetFrameRate(15);
	ofBackground(255, 255, 255);

	windowWidth = ofGetWidth();
	windowHeight = ofGetHeight();
	startX = 120; startY = 120;
	targetX = 680; targetY = 680;
	currentX = startX; currentY = startY;

	startflag = 0; playflag = 0; endflag = 0;
	startTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::update(){
	int i, j;
	if (startflag == 1) {
		elapsedTime = ofGetElapsedTimef() - startTime;
		if (elapsedTime > 5.0) {
			timeflag = 1;
		}
	}
	
	if (currentX == targetX && currentY == targetY) {
		endflag = 1;
	}
		
}

//--------------------------------------------------------------
void ofApp::draw(){

	int i, j;
	if (startflag == 0) {
		ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
		ofSetColor(127, 23, 31);
		ofDrawBitmapString("***************WELCOME!!!***************", 220, 380);
		ofDrawBitmapString("         Press 'S' to Start Game        ", 220, 400);
		ofDrawBitmapString("         Press 'Q' to Quit Game         ", 220, 420);
		ofDrawBitmapString("****************************************", 220, 440);
	}

	if (startflag == 1) {
		if (playflag == 0) {
			drawMaze();
			ofSetColor(255, 0, 0);
			ofDrawCircle(startX, startY, 10);
			//ofDrawCircle(startX, startY + 40, 10);
			ofSetColor(0, 0, 255);
			ofDrawCircle(680, 680, 10);

			ofSetColor(0);
			if (timeflag == 1) {
				for (i = 0; i < 15; i++) {
					for (j = 0; j < 15; j++) {
						if (i >= 0 && i <= 2 && j >= 0 && j <= 2) continue;
						ofDrawRectangle(i * 40 + 100, j * 40 + 100, 40, 40);
					}
				}
			}
		}

		if (playflag == 1) {
			drawMaze();
			ofSetColor(255, 0, 0);
			//cout << currentX << currentY << endl;
			ofDrawCircle(currentX, currentY, 10);
			ofSetColor(0, 0, 255);
			ofDrawCircle(680, 680, 10);

			ofSetColor(0);
			int idx = (currentX - 120) / 40;
			int idy = (currentY - 120) / 40;
			for (i = 0; i < 15; i++) {
				for (j = 0; j < 15; j++) {
					if (i >= idx - 2 && i <= idx + 2 && j >= idy - 2 && j <= idy + 2) continue;
					ofDrawRectangle(i * 40 + 100, j * 40 + 100, 40, 40);
				}
			}
		}

		if (endflag == 1) {
			ofSetColor(ofColor::white);
			ofDrawRectangle(220, 350, 360, 100);
			ofSetColor(ofColor::blue);
			ofDrawBitmapString("       Congratulation!! You Win!!       ", 220, 380);
			ofDrawBitmapString("        Press 'E' to Restart Game       ", 220, 420);

		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 's') {
		startflag = 1;
		endflag = 0;
		playflag = 0;
		createMaze();
	}
	
	if (key == 'q') {
		freeMemory();
		ofExit();
	}

	if (key == 'e') {
		ofClear(255);
		startflag = 0;
		currentX = startX; currentY = startY;
		timeflag = 0;
		startTime = ofGetElapsedTimef();
	}
	int i = (currentY - 120) / 40; int j = (currentX - 120) / 40;
	if (key == OF_KEY_LEFT) {
		if (maze[2 * i + 1][2 * j] == ' ') {
			currentX -= 40;
			playflag = 1;
		}
	}
	else if (key == OF_KEY_RIGHT) {
		if (maze[2 * i + 1][2 * j + 2] == ' ') {
			currentX += 40;
			playflag = 1;
		}
	}
	else if (key == OF_KEY_UP) {
		if (maze[2 * i][2 * j + 1] == ' ') {
			currentY -= 40;
			playflag = 1;
		}
	}
	else if (key == OF_KEY_DOWN) {
		if (maze[2 * i + 2][2 * j + 1] == ' ') {
			currentY += 40;
			playflag = 1;
		}
	}
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

void ofApp::createMaze() {  //15x15 크기의 랜덤한 형태의 미로를 생성하기 위한 함수
	int i, j, k, m;
	row = 15; col = 15;
	int setnum = 1;
	width = 31; height = 31;
	maze = (char**)malloc(sizeof(char*) * height);
	for (i = 0; i < height; i++)
		maze[i] = (char*)malloc(sizeof(char) * width);
	for (i = 0; i < height; i++) {
		if (i % 2 == 0) {
			for (j = 0; j < width; j += 2) {
				if (j == width - 1) maze[i][j] = '+';
				else {
					maze[i][j] = '+';
					maze[i][j + 1] = '-';
				}
			}
		}
		else {
			for (j = 0; j < width; j += 2) {
				if (j == width - 1) maze[i][j] = '|';
				else {
					maze[i][j] = '|';
					maze[i][j + 1] = ' ';
				}
			}
		}
	}
	set = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++)
		set[i] = (int*)malloc(sizeof(int) * col);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			set[i][j] = 0;

	::srand((unsigned int)time(NULL));
	int random;
	int set_idx = 0;
	//int idx_i, idx_j;
	for (i = 0; i < col; i++)
		set[0][i] = setnum++;
	for (i = 0; i < row - 1; i++) {
		for (j = 0; j < col - 1; j++) {
			if (set[i][j] != set[i][j + 1]) {
				random = rand() % 2;
				if (random == 1) {
					maze[2 * i + 1][2 * j + 2] = ' ';
					int temp1 = set[i][j + 1];
					for (k = 0; k < row; k++) {
						for (m = 0; m < col; m++) {
							if (set[k][m] == temp1)
								set[k][m] = set[i][j];
						}
					}
				}
			}
		}
		set_idx = 0;
		int random_check = 0;
		j = 0;
		while (1) {
			random = rand() % 2;
			random_check += random;
			if (random == 1) {
				set[i + 1][j] = set[i][j];
				maze[2 * i + 2][2 * j + 1] = ' ';
			}
			if (set[i][j] != set[i][j + 1] || j == col - 1) {
				if (random_check == 0) {
					j = set_idx;
					continue;
				}
				else {
					if (j == col - 1) {
						break;
					}
					random_check = 0;
					set_idx = j + 1;
				}
			}
			j++;
		}
		for (j = 0; j < col; j++) {
			if (set[i + 1][j] == 0) set[i + 1][j] = setnum++;
		}
	}
	if (i == row - 1) {
		for (j = 0; j < col - 1; j++) {
			if (set[i][j] != set[i][j + 1]) {
				maze[2 * i + 1][2 * j + 2] = ' ';
				int temp2 = set[i][j + 1];
				for (k = 0; k < row; k++) {
					for (m = 0; m < col; m++) {
						if (set[k][m] == temp2)
							set[k][m] = set[i][j];
					}
				}
			}
		}
	}
}

void ofApp:: drawMaze() {
	ofClear(255);
	ofSetColor(0);
	ofSetLineWidth(4);
	int x = 100; int y = 100;
	int i, j;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (maze[i][j] == '-') {
				ofDrawLine(x, y, x + 40, y);
				x += 40;
			}
			if (maze[i][j] == '|') {
				ofDrawLine(x, y, x, y + 40);
				if (j == width - 1)
					y += 40;
			}
			if (maze[i][j] == ' ') {
				if (i % 2 == 0) {
					x += 40;
				}
				else {
					if (j % 2 == 1) { x += 40; }
				}
			}
		}
		x = 100;
	}
}

void ofApp::freeMemory() {  // malloc한 memory를 free해주는 함수

	for (int i = 0; i < height; i++)
		delete[] maze[i];
	delete[] maze;

	for (int j = 0; j < row; j++)
		delete[] set[j];
	delete[] set;
	

}