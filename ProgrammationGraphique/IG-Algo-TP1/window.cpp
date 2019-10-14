# include <limits>
# include <math.h>
# include "window.hpp"

# define MININT std::numeric_limits<int>::min()

Window::Window()
{
	pixels = NULL;
	pixels_final = NULL;
	width = 300;
	height = 300;
	sample = 1;
	width *= sample;
	height *= sample;
	nb_pixels = width*height;
}

Window::~Window()
{
	if (pixels != NULL)
	{
		delete[] pixels;
	}
	if(pixels_final != NULL)
	{
		delete[] pixels_final;
	}
}

const int Window::get_width()
{
	return width / sample;
}

const int Window::get_height()
{
	return height / sample;
}

unsigned char * Window::get_pixels()
{
	if(sample == 1)
	{
		return pixels;
	}
	else
	{
		return pixels_final;
	}
}

vec3 Window::get_pixel(vec2 p)
{
	if(0<=p.x && p.x<width && 0<=p.y && p.y<height)
	{
		int indice = (p.x + p.y*width) * 3;
		return vec3(c2f(pixels[indice]), c2f(pixels[indice+1]), c2f(pixels[indice+2]));
	}

	return vec3();
}

void Window::draw_pixel(vec2 p, vec3 c)
{
	if(p.x>=0 && p.x<width && p.y>=0 && p.y<height)
	{
		int indice = (p.x + p.y*width) * 3;
		pixels[indice] = f2c(c.x);
		pixels[indice+1] = f2c(c.y);
		pixels[indice+2] = f2c(c.z);
	}
}

void Window::draw_pixel_sampled(vec2 p, vec3 c)
{
	if(0<=p.x && p.x<width && 0<=p.y && p.y<height)
	{
		int indice = (p.x + p.y*width/sample) * 3;
		pixels_final[indice] = f2c(c.x);
		pixels_final[indice+1] = f2c(c.y);
		pixels_final[indice+2] = f2c(c.z);
	}
}

void Window::clear()
{
	//Clear color
	for(int i=0; i<nb_pixels*3; i+=3)
	{
		pixels[i] = 0;
		pixels[i+1] = 0;
		pixels[i+2] = 0;
	}
}

void Window::reshape(int w, int h)
{
	width = w;
	height = h;
	width *= sample;
	height *= sample;
	nb_pixels = width * height;

	if(pixels != NULL)
	{
		delete[] pixels;
	}
	if(pixels_final != NULL)
	{
		delete[] pixels_final;
	}

	pixels = new unsigned char[nb_pixels*3];
	pixels_final = new unsigned char[(nb_pixels/(sample*sample))*3];
	//Clear color
	for(int i=0; i<nb_pixels*3; i+=3)
	{
		pixels[i] = 0;
		pixels[i+1] = 0;
		pixels[i+2] = 0;
	}
}

void Window::antialiasing()
{
    // TODO => TP01
}

void Window::draw_line(vec2 p1, vec2 p2, vec3 c)//droite du pt p1 vers p2, du couleur c
{
	int x,y;
	vec2 start, end;

	if(p1.x < p2.x){
		start = p1; end = p2;
	}//p1 est a gauche de p2
	else{
	start = p2; end = p1;
}//p1 est a droite de p2

	x = start.x;
	y = start.y;
	int incX, incY; // incrementation de x et de y;
	incX = (start.x < end.x)? 1: -1;
	//start est plus bas que end, on incremente y, sinon on decremente y
	incY = (start.y < end.y)? 1: -1;


	float a,e;
	float dx, dy;
	e = 0;
	dx = (int)abs(end.y - start.y);
	dy = (int)abs(end.x - start.x);
	if(!dy) dy =1;

	a = (float)dx / (float)dy;// a est la pente
	a = abs(a);

	if(a < 1){
		for (x = start.x; x < end.x; x+=incX) {
			draw_pixel(vec2(x,y) ,c);
			e = e+a;
			if( e > 0.5){
				e = e-1;
				y = y + incY;
			}
		}
	}
	if(a == 1){
		for (y = start.y; y < end.y; y+=incY) {
			draw_pixel(vec2(x,y) ,c);
			e = e+a;
			if( e > 0.5){
				e = e-1;

			}
		}
	}
}

void Window::draw_circle(vec2 center, unsigned int r, vec3 c)
{
    // TODO => TP01
}

void Window::draw_circle_parts(vec2 p, vec2 center, vec3 c)
{
    // TODO => TP01
}

void Window::raster_buffer_insert(int x, int raster_buffer[2])
{
	// TODO => TP03
}

void Window::raster_buffer_insert(int x, int raster_buffer[2], vec3 color, vec3 color_buffer[2])
{
	// TODO => TP04
}

void Window::draw_horizontal_line(int y, int x1, int x2, vec3 c)
{
	// TODO => TP03
}

void Window::draw_horizontal_line(int y, int x1, int x2, vec3 c[2])
{
	// TODO => TP04
}

void Window::draw_quad(vec2 p[4], vec3 c)
{
	// TODO => TP03
}

void Window::draw_quad(vec2 p[4], vec3 c[4])
{
	// TODO => TP04
}

unsigned char Window::f2c(float f)
{
	return (unsigned char)(f * 255);
}

float Window::c2f(unsigned char c)
{
	return ((float)c / 255.0f);
}
