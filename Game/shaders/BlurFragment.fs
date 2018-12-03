#version 120

varying vec2 blurTextureCoords[21];

uniform sampler2D textureSampler;

void main(void) 
{
	const float KERNEL_OFFSETS[21] = float[](0.000001, 0.00001, 0.000078, 0.000489, 0.002403, 0.009245, 0.027835, 0.065591, 0.120978, 0.174666, 0.197413, 0.174666, 0.120978, 0.065591, 0.027835, 0.009245, 0.002403, 0.000489, 0.000078, 0.00001, 0.000001);
	
	gl_FragColor = vec4(0.0);

	for(int i = 0; i < 21; i++)
	{
		gl_FragColor += texture2D(textureSampler, blurTextureCoords[i]) * KERNEL_OFFSETS[i];
	}
}