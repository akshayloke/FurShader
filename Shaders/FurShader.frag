#version 120
#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect noiseTexture, furTexture;
varying float varying_furLayerFraction;

void main() {
	vec4 furColor = texture2DRect(furTexture, gl_TexCoord[0].st);
	float noiseColor = texture2DRect(noiseTexture, gl_TexCoord[0].st).r;

	float shadow = mix(0.4, 1, varying_furLayerFraction);
	gl_FragColor = furColor * shadow;

	float visibility = (varying_furLayerFraction > noiseColor)? 0: noiseColor;
	gl_FragColor.a = (varying_furLayerFraction < 0.01)? 1: visibility;
}