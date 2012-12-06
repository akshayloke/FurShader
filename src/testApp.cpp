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

	dogModel.loadModel("bunny.obj", true);
	//animationTime = 0.0f;

	furLengthNoiseTexture.loadImage("textures/lengthNoiseTexture.jpg");
	furVisibilityNoiseTexture.loadImage("textures/visibilityNoiseTexture.jpg");
	furTexture.loadImage("textures/furTexture.jpg");
	furShader.load("Shaders/FurShader.vert", "Shaders/FurShader.frag");

	w = 400; h = 400;
	finalFBO.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	finalFBO.begin();
	ofClear(0, 0, 0, 255);
	finalFBO.end();

	furTotalLength = 10;
	furNumberOfLayers = 100;
	ofFill();
}

//--------------------------------------------------------------
void testApp::update(){
	/*animationTime += ofGetLastFrameTime() * 0.3f;
	if (animationTime >= 1.0f)
		animationTime = 0.0f;
	dogModel.setNormalizedTime(animationTime);
	dogModel.getCurrentAnimatedMesh(0);*/
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(100, 0, 0, 255);
	//finalFBO.begin();
	//ofClear(0, 0, 0, 0);
	cam.begin();
	ofVec3f VS_gravity = cam.worldToCamera(ofVec3f(0, -10, 0), ofGetCurrentViewport());
	for (int i=0; i< furNumberOfLayers; i++) {
		furLayerLength = i * furTotalLength / furNumberOfLayers;
		furLayerFraction = i / furNumberOfLayers;

		furShader.begin();
		furShader.setUniformTexture("furLengthNoiseTexture", furLengthNoiseTexture.getTextureReference(), 1);
		furShader.setUniformTexture("furVisibilityNoiseTexture", furVisibilityNoiseTexture.getTextureReference(), 2);
		furShader.setUniformTexture("furTexture", furTexture.getTextureReference(), 3);
		furShader.setUniform1f("furLayerLength", furLayerLength);
		furShader.setUniform1f("furLayerFraction", furLayerFraction);

		/*glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(-w/2, -h/2, 0);  
		glTexCoord2f(w, 0); glVertex3f(w/2, -h/2, 0);  
		glTexCoord2f(w, h); glVertex3f(w/2, h/2, 0);  
		glTexCoord2f(0, h);  glVertex3f(-w/2, h/2, 0);
		glEnd();*/
		
		ofSphere(100);
		//dogModel.draw(ofPolyRenderMode::OF_MESH_FILL);
		furShader.end();
	}
	
	cam.end();
	//finalFBO.end();
	//finalFBO.draw(0, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}