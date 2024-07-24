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
		
		float startTime, elapsedTime; //���۽ð� ������ ����ð� ����
		float windowHeight, windowWidth; //windowâ�� ���̿� �ʺ�
		int startflag, endflag; //�̷� ������ ���۰� ���� Ȯ���ϴ� flag����
		int playflag; 
		//�÷��̾ �÷��̸� �������� �˷��ִ� flag����
		//(startflag�ʹ� �ٸ����� startflag�� ���� ��ü�� �����ϱ� ���� �غ� ������ ��Ÿ���� playflag�� �÷��̾ ������ ���������� ��Ÿ��)
 		int timeflag = 0; //������ ���۵��� 5�ʰ� �������� Ȯ���ϴ� flag����
		int width, height, row, col; //�̷� char �迭�� �ʺ�� ũ�� & �̷��� �ʺ�� ũ��
		int startX, startY, targetX, targetY; //�̷��� �������� Ż������
		int currentX, currentY; //���� �÷��̾��� ��ġ
		char** maze; //�̷� char�迭
		int** set;

		
};
