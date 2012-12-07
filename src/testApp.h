#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofxAssimpModelLoader model;
		ofLight light;
		ofEasyCam cam;
		ofShader furShader;
		ofImage furLengthNoiseTexture, furVisibilityNoiseTexture, furTexture;
		ofFbo finalFBO;
		float animationTime;
		int w, h;
		float furTotalLength, furNumberOfLayers, furCurrentLayer;
};
