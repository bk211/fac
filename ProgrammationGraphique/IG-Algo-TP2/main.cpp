# ifdef __APPLE__
# include <GLUT/glut.h>
# else
# include <GL/glut.h>
# endif
# include <math.h>
# include "window.hpp"
# include "object.hpp"
# include <vector>

Window window;
void display();
void reshape(int, int);
void keyboard_down(unsigned char, int, int);

mat4 transformation_matrix(double, double, double, vec3);
mat4 projection_matrix(double);
void load_box(Object &);
void load_sphere(Object &);

Object myobject;
double angle = 0;
vec4 light(0.5773, 0.5773, -0.5773, 0);

int main(int argc, char** argv)
{
	//load_box(myobject);
	load_sphere(myobject);

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );
	glutInitWindowSize(window.get_width(), window.get_height());
	glutCreateWindow("IG");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard_down);

	glutMainLoop();
}

void reshape(int width, int height)
{
	window.reshape(width, height);
}

void keyboard_down(unsigned char key, int x, int y)
{
	switch( key )
	{
		case 'q' :
		case 'Q' :
		case 27 :
			exit( EXIT_SUCCESS );
			break;
		default :
			break;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Draw what you want...
	/*** TP02 ****/
	myobject.draw_method = DRAW_WIRE;

	/*** TP03 ***
	myobject.draw_method = DRAW_FILL;
	*/
	/*** TP04 ***
	myobject.draw_method = DRAW_LAMBERT;
	myobject.draw_method = DRAW_GOURAUD;
	*/
	/***Code to uncomment after TP01 ****/
	vec3 trans(0.0f, 0.0f, -800.0f);
	mat4 trans_matrix = transformation_matrix(angle, angle, angle, trans);
	mat4 proj_matrix = projection_matrix(1000.0f);
	angle += 0.25;

	myobject.update_transformation(trans_matrix);
	myobject.update_projection(proj_matrix);

	/*** TP03 ***
	myobject.backface_culling(trans_matrix);
	*/

	/*** To uncomment after TP01 ****/
	myobject.draw(window, light);


    /***Don't change anything from here***/
	window.antialiasing();

	glDrawPixels(window.get_width(), window.get_height(), GL_RGB, GL_UNSIGNED_BYTE, window.get_pixels());
	glutSwapBuffers();
	glutPostRedisplay();
	window.clear();
}

mat4 transformation_matrix(double pitch, double yaw, double roll, vec3 translation)
{
	mat4 Rotx = mat4();
	Rotx[1][1] = cos(pitch);
	/* vec4(1,0,0,0),
					  vec4(0, cos(pitch),sin(pitch),0),
					  vec4(0, -sin(pitch), cos(pitch),0),
					  vec4(0,0,0,1));*/

	mat4 Roty = mat4( vec4(cos(yaw),0,-sin(yaw),0),
 	 					vec4(0, 1,0,0),
	 					vec4(sin(yaw), 0,cos(yaw),0),
 						vec4(0,0,0,1));

	mat4 Rotz = mat4( vec4(cos(roll),sin(roll),0,0),
	 					vec4(-sin(roll), cos(roll),0,0),
						vec4(0,0,1,0),
 						vec4(0,0,0,1));

	mat4 Trans = mat4( vec4(1,0,0,0),
							vec4(0,1,0,0),
							vec4(0,0,1,0),
							vec4(translation,1));

	return Trans * Rotx * Roty * Rotz ;
}

mat4 projection_matrix(double focal)
{
	// TODO => TP02 //
	return mat4();
}

void load_box(Object & o)
{
	////Vertex defintion//////////////////////////
	float dim = 100;

	o.vertices.push_back(vec4(-dim, -dim, -dim, 1));
	o.vertices.push_back(vec4( dim, -dim, -dim, 1));
	o.vertices.push_back(vec4( dim,  dim, -dim, 1));
	o.vertices.push_back(vec4(-dim,  dim, -dim, 1));

	o.vertices.push_back(vec4( dim, -dim, dim, 1));
	o.vertices.push_back(vec4(-dim, -dim, dim, 1));
	o.vertices.push_back(vec4(-dim,  dim, dim, 1));
	o.vertices.push_back(vec4( dim,  dim, dim, 1));

	float n = 0.577350269;
	o.normals.push_back(vec4(-n, -n, -n, 0));
	o.normals.push_back(vec4( n, -n, -n, 0));
	o.normals.push_back(vec4( n,  n, -n, 0));
	o.normals.push_back(vec4(-n,  n, -n, 0));

	o.normals.push_back(vec4( n, -n, n, 0));
	o.normals.push_back(vec4(-n, -n, n, 0));
	o.normals.push_back(vec4(-n,  n, n, 0));
	o.normals.push_back(vec4( n,  n, n, 0));

	Face f;

	/////face 1///////////////////////////////////
	f.vertex_index[0] = 0;
	f.vertex_index[1] = 1;
	f.vertex_index[2] = 2;
	f.vertex_index[3] = 3;
	f.normal = vec4(0, 0, -1, 0);
	f.color = vec3(0,0,1);
	o.faces.push_back(f);

	/////face 2/////////////////////////////////////////
	f.vertex_index[0] = 4;
	f.vertex_index[1] = 5;
	f.vertex_index[2] = 6;
	f.vertex_index[3] = 7;
	f.normal = vec4(0, 0, 1, 0);
	f.color = vec3(0,1,0);
	o.faces.push_back(f);

	////face 3//////////////////////////////////////////
	f.vertex_index[0] = 1;
	f.vertex_index[1] = 2;
	f.vertex_index[2] = 7;
	f.vertex_index[3] = 4;
	f.normal = vec4(1, 0, 0, 0);
	f.color = vec3(0,1,1);
	o.faces.push_back(f);

	////face 4//////////////////////////////////////////
	f.vertex_index[0] = 0;
	f.vertex_index[1] = 3;
	f.vertex_index[2] = 6;
	f.vertex_index[3] = 5;
	f.normal = vec4(-1, 0, 0, 0);
	f.color = vec3(1,0,0);
	o.faces.push_back(f);

	////face 5//////////////////////////////////////////
	f.vertex_index[0] = 5;
	f.vertex_index[1] = 0;
	f.vertex_index[2] = 1;
	f.vertex_index[3] = 4;
	f.normal = vec4(0, -1, 0, 0);
	f.color = vec3(1,0,1);
	o.faces.push_back(f);

	////face 6///////////////////////////////////////////
	f.vertex_index[0] = 2;
	f.vertex_index[1] = 3;
	f.vertex_index[2] = 6;
	f.vertex_index[3] = 7;
	f.normal = vec4(0, 1, 0, 0);
	f.color = vec3(1,1,0);
	o.faces.push_back(f);
}

void load_sphere(Object & o)
{
	int i, j;
	int slice = 40, stack = 20;
	float radius = 100;
	for(i=0; i<=stack; i++)
	{
		float phi = i * M_PI / (float)stack;
		for(j=0; j<slice; j++)
		{
			float theta = j * 2.0f * M_PI / (float)slice;
			float x = cos(theta) * sin(phi);
			float y = sin(theta) * sin(phi);
			float z = cos(phi);
			o.vertices.push_back(vec4(radius * x, radius * y, radius * z, 1));
			o.normals.push_back(vec4(x, y, z, 0));
		}
	}

	for(i=0; i<slice; i++)
	{
		float theta = (i+0.5) * 2.0f * M_PI / (float)slice;
		for(j=0; j<stack; j++)
		{
			float phi = (j+0.5) * M_PI / (float)stack;
			Face f;

			f.vertex_index[0] = i + slice*j;
			f.vertex_index[1] = (i+1)%slice + slice*j;
			f.vertex_index[2] = (i+1)%slice + slice*(j+1);
			f.vertex_index[3] = i + slice*(j+1);

			f.normal.x = cos(theta) * sin(phi);
			f.normal.y = sin(theta) * sin(phi);
			f.normal.z = cos(phi);

			f.color = vec3(1,1,1);

			o.faces.push_back(f);
		}
	}
}
