#version 120

uniform float furLayerLength, furLayerFraction;
varying float varying_furLayerFraction;

void main() {
	
	vec3 p = gl_Vertex.xyz + (gl_Normal * furLayerLength);
	
	float k = pow(furLayerFraction, 3);
	vec3 gravity = vec3(0, -2, 0);
	p += gravity * k;

	gl_Position = gl_ModelViewProjectionMatrix * vec4(p, 1.0);
	gl_TexCoord[0] = gl_MultiTexCoord0;
	varying_furLayerFraction = furLayerFraction;
}