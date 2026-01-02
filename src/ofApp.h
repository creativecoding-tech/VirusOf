#pragma once

#include "ofMain.h"
#include "BezierCurve.h"


using Pattern = std::vector<std::shared_ptr<BezierCurve>>;
class ofApp : public ofBaseApp{

	public:

		bool isRunning = false;
		float goldenAngle = 137.5;
		float scaleFactor = 10;
		std::vector<std::shared_ptr<BezierCurve>> allCurves;
		std::vector<Pattern> patterns;
		int cols = 5;
		int rows = 4;
		bool phyllotaxisMode = false;
		std::vector<std::vector<float>> gridPositions;
		std::vector<std::vector<float>> phyllPositions;

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
