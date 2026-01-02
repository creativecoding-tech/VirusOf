#include "BezierCurve.h"

BezierCurve::BezierCurve(float a1x, float a1y, float a2x, float a2y,
    float cpX_start, float cpY_start,
    float sx, float sy, ofColor c) {

    centerX = cpX_start;
    centerY = cpY_start;

    anchor1OffsetX = a1x - cpX_start;
    anchor1OffsetY = a1y - cpY_start;
    anchor2OffsetX = a2x - cpX_start;
    anchor2OffsetY = a2y - cpY_start;

    updateAnchors();

    cpX = cpX_start;
    cpY = cpY_start;
    speedX = sx;
    speedY = sy;

    // Random direction for control point movement
    angle = ofRandom(TWO_PI);
    moveRadius = 0;
    oscillationTime = 0; // Timer untuk easing
    expanding = true; // Start with expanding state

    strokeColor = c;
}

void BezierCurve::updateAnchors() {
    anchor1x = centerX + +anchor1OffsetX;
    anchor1y = centerY + +anchor1OffsetY;
    anchor2x = centerX + anchor2OffsetX;
    anchor2y = centerY + anchor2OffsetY;
}

void BezierCurve::updateControlPoint() {
    cpX = centerX + moveRadius * cos(angle);
    cpY = centerY + moveRadius * sin(angle);
}

void BezierCurve::update() {
    float maxRadius = ofMin(ofGetWidth(), ofGetHeight()) * 0.4;
    float cycleDuration = 1000; // Frame per cycle (mengembang + menyusut)

    // Update timer
    oscillationTime += 1;
    if (oscillationTime > cycleDuration) {
        oscillationTime = 0;
    }

    // Easing function: Smooth ease-in-out using sine
    // Normalized time 0 to 1
    float t = ofMap(oscillationTime, 0, cycleDuration, 0, TWO_PI);

    // Apply ease-in-out with sine wave
    // sin(t) gives us -1 to 1, map to 0 to 1
    float easedT = (sin(t - HALF_PI) + 1) / 2;

    // Calculate radius with easing
    moveRadius = easedT * maxRadius;

    // Update posisi dengan rotasi spiral
    angle += 0.02;
    updateControlPoint();
}

void BezierCurve::display() {
    updateAnchors();
    ofSetColor(strokeColor);
    ofSetLineWidth(strokeWeightVal);

    // Gambar bezier curve
    ofDrawBezier(anchor1x, anchor1y, cpX, cpY, anchor2x, anchor2y, anchor2x, cpY);
}

void BezierCurve::setColor(ofColor c) {
    strokeColor = c;
}

void BezierCurve::setStrokeWeight(float sw) {
    strokeWeightVal = sw;
}