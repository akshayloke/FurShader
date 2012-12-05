#version 120
#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect noiseTexture;

void main() {
	vec4 noiseColor = texture2DRect(noiseTexture, gl_TexCoord[0].st);
	gl_FragColor = vec4(noiseColor.xyz, noiseColor.r);
}