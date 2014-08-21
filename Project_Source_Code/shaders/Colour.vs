uniform mat4 projectionMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ModelMatrix;



void main(void)
{
	gl_Position = projectionMatrix*ViewMatrix*ModelMatrix*gl_Vertex;
}
