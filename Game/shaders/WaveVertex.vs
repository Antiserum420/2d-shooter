#version 120

varying vec2 textureCoords;

void main()
{
	textureCoords = gl_Vertex.xy;
	gl_Position = gl_Vertex;
}