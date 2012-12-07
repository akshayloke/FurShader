#version 120
#extension GL_ARB_texture_rectangle: enable

uniform float furLength, furCurrentLayer;
varying float currentLayer;
uniform vec3 displacement;

void main() {
	vec3 p = gl_Vertex.xyz + (gl_Normal * furLength * furCurrentLayer);
	
	float k = pow(furCurrentLayer, 3);
	p += displacement * k;

	gl_Position = gl_ModelViewProjectionMatrix * vec4(p, 1.0);
	gl_TexCoord[0] = gl_MultiTexCoord0;
	currentLayer = furCurrentLayer;
}