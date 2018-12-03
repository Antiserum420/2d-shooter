#version 120

varying vec2 textureCoords;

uniform sampler2D textureSampler;
uniform float tx;
uniform float ty;

void main(void)
{
	float xCorrection = ( 0.55 * textureCoords.x) + 0.5;
    float yCorrection = (-0.55 * textureCoords.y) + 0.5;

	float x = sin( 25.0 * yCorrection + 30.0 * xCorrection + 6.28 * tx) * 0.05;
	float y = sin( 25.0 * yCorrection + 30.0 * xCorrection + 6.28 * ty) * 0.05;

    vec2 result = vec2(xCorrection + x, xCorrection + y);

	gl_FragColor = texture2D(textureSampler, result);
}