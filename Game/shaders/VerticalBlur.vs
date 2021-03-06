#version 120

attribute vec2 position;

varying vec2 blurTextureCoords[21];

uniform float textureHeight;

void main(void)
{	
	gl_Position = vec4(position, 0.0, 1.0);
	float pixelSize = 1.0 / textureHeight;
	vec2 centerTextureCoords = position * 0.5 + 0.5;

	for(int i = -10; i <= 10; i++) 
	{
		blurTextureCoords[i+10] = centerTextureCoords + vec2(0.0, pixelSize * i);
	}
}