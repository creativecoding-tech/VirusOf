#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableAntiAliasing();
	ofEnableSmoothing();

	ofSetBackgroundAuto(false);

	ofSetEscapeQuitsApp(false);

	int curvePerPattern = 99;
	int totalPatterns = cols * rows;

	float spacingX = ofGetWidth() / cols;
	float spacingY = ofGetHeight() / rows;

	int patternIndex = 0;


	for (int col = 0; col < cols;col++) {
		for (int row = 0; row < rows;row++) {
			float centerX = spacingX * col + spacingX / 2;
			float centerY = spacingY * row + spacingY / 2;

			gridPositions.push_back({ centerX,centerY });

			float phyllAngle = DEG_TO_RAD * patternIndex * goldenAngle;
			float phyllRadius = ofMin(ofGetWidth(), ofGetHeight()) * 0.35
				* sqrt(patternIndex) / sqrt(totalPatterns);

			float phyllX = ofGetWidth() / 2 + phyllRadius * cos(phyllAngle);
			float phyllY = ofGetHeight() / 2 + phyllRadius * sin(phyllAngle);

			phyllPositions.push_back({ phyllX,phyllY });

			std::vector<std::shared_ptr<BezierCurve>> patternCurves;
			float baseHue = ofMap(patternIndex, 0, totalPatterns, 0, 255);

			for (int i = 0; i < curvePerPattern; i++) {
				float angle = DEG_TO_RAD * i * goldenAngle;
				float radius = scaleFactor * sqrt(i);

				float x = centerX + radius * cos(angle);
				float y = centerY + radius * sin(angle);

				float anchor1x = x + (radius * 0.3) * cos(angle);
				float anchor1y = y + (radius * 0.3) * sin(angle);

				float anchor2x = x - (radius * 0.3) * cos(angle);
				float anchor2y = y - (radius * 0.3) * sin(angle);

				float hue = fmod(baseHue + ofMap(i, 0, curvePerPattern, 0, 50), 255.0f);
				ofColor c = ofColor(hue, ofRandom(150, 255), ofRandom(150, 255));

				std::shared_ptr<BezierCurve> curve = std::make_shared<BezierCurve>(
					anchor1x, anchor1y, anchor2x, anchor2y,
					centerX, centerY,
					ofRandom(3, 8), ofRandom(3, 8), c);
				allCurves.push_back(curve);
				patternCurves.push_back(curve);
			}
			patterns.push_back(patternCurves);
			patternIndex++;
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	float lerpSpeed = 0.05;

	for (int i = 0;i < patterns.size();i++) {
		auto& pattern = patterns.at(i);
		float targetX = phyllotaxisMode ? phyllPositions[i][0] : gridPositions[i][0];
		float targetY = phyllotaxisMode ? phyllPositions[i][1] : gridPositions[i][1];
		for (auto& curve : pattern) {
			curve->centerX = ofLerp(curve->centerX, targetX, lerpSpeed);
			curve->centerY = ofLerp(curve->centerY, targetY, lerpSpeed);

			curve->updateControlPoint();
		}
	}

	if (isRunning) {
		for (auto& curve : allCurves) {
			curve->update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofFill();
	ofSetColor(0, 20);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofNoFill();
	for (auto& curve : allCurves) {
		curve->display();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'a' || key == 'A') phyllotaxisMode = !phyllotaxisMode;
	if (key == 'q' || key == 'Q') ofExit();
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
	isRunning = !isRunning;
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
