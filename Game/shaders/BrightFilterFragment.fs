#version 120

varying vec2 textureCoords;

uniform sampler2D textureSampler;

void main(void) 
{
	vec4 orginalColor = texture2D(textureSampler, textureCoords);
	float brightness = (orginalColor.r * 0.2126) + (orginalColor.g * 0.7152) + (orginalColor.b * 0.0722);
	
	gl_FragColor = orginalColor * brightness;
}