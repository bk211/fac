# ifndef WINDOW_HPP
# define WINDOW_HPP
# include <stdlib.h>
# include <stdio.h>

# ifdef _WIN32
# include "glm\glm.hpp"
# else
# include "glm/glm.hpp"
# endif
using namespace glm;

class Window
{
	private:
		int width,height;
		int nb_pixels;
		int sample; //Number of sampling for anti-aliasing function
		unsigned char * pixels;
		unsigned char * pixels_final;//Final pixel buffer when anti-aliasing enabled

	public:
		Window();
		~Window();

		const int get_width();
		const int get_height();
		unsigned char * get_pixels();
		vec3 get_pixel(vec2 p);
		int get_sample(){
			return sample;
		}

		void clear();
		void reshape(int, int);
		void draw_pixel(vec2, vec3);
		void draw_pixel_sampled(vec2, vec3);
		void draw_line(vec2, vec2, vec3);
		void draw_circle(vec2, unsigned int, vec3);
		void draw_circle_parts(vec2, vec2, vec3);
		void raster_buffer_insert(int, int[2]);
		void draw_horizontal_line(int, int, int, vec3);
		void draw_quad(vec2[4], vec3);
		void raster_buffer_insert(int, int[2], vec3, vec3[2]);
		void draw_horizontal_line(int, int, int, vec3[2]);
		void draw_quad(vec2[4], vec3[4]);

		void antialiasing();//anti-aliasing by oversampling

	private:
		unsigned char f2c(float);
		float c2f(unsigned char);
};

# endif // WINDOW_HPP
