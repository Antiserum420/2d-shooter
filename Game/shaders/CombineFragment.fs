#version 120

varying vec2 textureCoords;

uniform sampler2D orginalTexture;
uniform sampler2D bloomTexture;

uniform float orginalSaturation;
uniform float bloomSaturation;

uniform float orginalIntensity;
uniform float bloomIntensity;

vec4 adjustSaturation(vec4 color, float saturation)
{
	vec4 luminosity = vec4(dot(color, vec4(0.3f, 0.59f, 0.11f, 0.f)));
	
	return mix(luminosity, color, saturation);
}

void main(void)
{
	vec4 orginalColor = texture2D(orginalTexture, textureCoords);
	vec4 bloomColor = texture2D(bloomTexture, textureCoords);

	orginalColor = adjustSaturation(orginalColor, orginalSaturation) * orginalIntensity;
	bloomColor = adjustSaturation(bloomColor, bloomSaturation) * bloomIntensity;

	orginalColor *= (1.f - clamp(bloomColor, 0.f, 1.f));

	gl_FragColor = orginalColor + bloomColor;
}