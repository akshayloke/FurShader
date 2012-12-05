#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	light.enable();
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofBackground(0, 0, 0);
	cam.setDistance(100);

	//dogModel.loadModel("DogIdleStand.dae", true);
	//animationTime = 0.0f;

	noiseTexture.loadImage("textures/noiseTexture.jpg");
	furShader.load("Shaders/FurShader.vert", "Shaders/FurShader.frag");

	w = 100; h = 50;
	finalFBO.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	finalFBO.begin();
	ofClear(0, 0, 0, 255);
	finalFBO.end();

	furTotalLength = 10;
	furNumberOfLayers = 5;
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
	for (int i=0; i< furNumberOfLayers; i++) {
		furLayerLength = i * furTotalLength / furNumberOfLayers;
		furLayerFraction = i / furNumberOfLayers;

		furShader.begin();
		furShader.setUniformTexture("noiseTexture", noiseTexture.getTextureReference(), 1);
		furShader.setUniform1f("furLayerLength", furLayerLength);
		furShader.setUniform1f("furLayerFraction", furLayerFraction);

		glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(0, 0, 0);  
		glTexCoord2f(noiseTexture.getWidth(), 0); glVertex3f(w, 0, 0);  
		glTexCoord2f(noiseTexture.getWidth(), noiseTexture.getHeight()); glVertex3f(w, h, 0);  
		glTexCoord2f(0, noiseTexture.getHeight());  glVertex3f(0, h, 0);
		glEnd();

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