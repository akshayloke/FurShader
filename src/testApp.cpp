#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	light.enable();
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofBackground(0, 0, 0);
	cam.setDistance(500);
	ofEnableNormalizedTexCoords();
	ofEnableArbTex();

	model.loadModel("bunny.obj", true);
	
	furShader.load("Shaders/FurShader.vert", "Shaders/FurShader.frag");

	furLengthNoiseTexture.loadImage("textures/lengthNoiseTexture.jpg");
	furVisibilityNoiseTexture.loadImage("textures/noisy-texture-4.png");
	furTexture.loadImage("textures/furTexture.jpg");

	w = 400; h = 400;
	finalFBO.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	finalFBO.begin();
	ofClear(0, 0, 0, 255);
	finalFBO.end();

	furTotalLength = 10;
	furNumberOfLayers = 100;
	ofFill();

	ofSetSphereResolution(100);
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(100, 0, 0, 255);
	//finalFBO.begin();
	//ofClear(0, 0, 0, 0);
	cam.begin();
	
	for (int i=0; i< furNumberOfLayers; i++) {
		furCurrentLayer = i / furNumberOfLayers;
		ofVec3f displacement = ofVec3f(0, -1, 0) + ofVec3f(sin(ofGetElapsedTimef()), 0, 0);

		furShader.begin();
		furShader.setUniformTexture("furLengthNoiseTexture", furLengthNoiseTexture.getTextureReference(), 1);
		furShader.setUniformTexture("furVisibilityNoiseTexture", furVisibilityNoiseTexture.getTextureReference(), 2);
		furShader.setUniformTexture("furTexture", furTexture.getTextureReference(), 3);
		furShader.setUniform1f("furLength", furTotalLength);
		furShader.setUniform1f("furCurrentLayer", furCurrentLayer);
		furShader.setUniform3fv("displacement", displacement.getPtr());

		/*glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(-w/2, -h/2, 0);  
		glTexCoord2f(1, 0); glVertex3f(w/2, -h/2, 0);  
		glTexCoord2f(1, 1); glVertex3f(w/2, h/2, 0);  
		glTexCoord2f(0, 1);  glVertex3f(-w/2, h/2, 0);
		glEnd();*/
		ofSphere(100);
		//dogModel.draw(ofPolyRenderMode::OF_MESH_FILL);
		furShader.end();
	}
	ofSphere(1);
	cam.end();
	//finalFBO.end();
	//finalFBO.draw(0, 0);
}

