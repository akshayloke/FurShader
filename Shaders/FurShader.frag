#version 120
#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect furLengthNoiseTexture, furVisibilityNoiseTexture, furTexture;
varying float currentLayer;

void main() {
	vec4 furColor = texture2DRect(furTexture, gl_TexCoord[0].st * 400);
	float furLengthNoiseColor = texture2DRect(furLengthNoiseTexture, gl_TexCoord[0].st * 400).r;
	float furVisibilityNoiseColor = texture2DRect(furVisibilityNoiseTexture, gl_TexCoord[0].st * 400).r;

	float shadow = mix(0.4, 1, currentLayer);
	gl_FragColor = furColor * shadow;

	float visibility = (currentLayer > furVisibilityNoiseColor)? 0: furLengthNoiseColor;
	visibility = (visibility < 0.5)? 0: 1;
	gl_FragColor.a = (currentLayer < 0.01)? 1: visibility;
}