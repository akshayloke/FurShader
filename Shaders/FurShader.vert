#version 120
#extension GL_ARB_texture_rectangle: enable

uniform float furLayerLength, furLayerFraction;
varying float varying_furLayerFraction;

void main() {
	
	vec3 p = gl_Vertex.xyz + (gl_Normal * furLayerLength);
	
	float k = pow(furLayerFraction, 2);
	vec3 gravity = vec3(0, -1, 0);
	p += gravity * k;

	gl_Position = gl_ModelViewProjectionMatrix * vec4(p, 1.0);
	gl_TexCoord[0] = gl_MultiTexCoord0;
	varying_furLayerFraction = furLayerFraction;
}