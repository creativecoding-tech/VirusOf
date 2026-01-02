#pragma once
#include <ofMain.h>
class BezierCurve
{
public:
	float anchor1OffsetX, anchor1OffsetY;
	float anchor2OffsetX, anchor2OffsetY;

	float anchor1x, anchor1y;
	float anchor2x, anchor2y;

	float cpX, cpY;
	float speedX, speedY;
	float angle;
	float moveRadius;
	float oscillationTime;
	bool expanding;

	float centerX, centerY;

	ofColor strokeColor;
	float strokeWeightVal = 10;

	BezierCurve(float a1x, float a1y, float a2x, float a2y,
		float cpX_start, float cpY_start,
		float sx, float sy, ofColor c);

	void updateAnchors();
	void updateControlPoint();
	void update();
	void display();
	void setColor(ofColor c);
	void setStrokeWeight(float sw);

};

