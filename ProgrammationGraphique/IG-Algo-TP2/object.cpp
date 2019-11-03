# include "object.hpp"
#include "iostream"
void check_color(vec3 & color)
{
	color = max(color, vec3(0.0, 0.0, 0.0));
	color = min(color, vec3(1.0, 1.0, 1.0));
}

void Object::update_transformation(mat4 m)
{
	for(auto v : vertices){
		vertices_transformed.push_back(m*v);
	}
}

void Object::update_projection(mat4 m)
{

	for(auto v : vertices){
		vertices_projected.push_back(m*v);
	}
}

void Object::draw(Window & window, vec4 light)
{
	for(unsigned int i=0; i<faces.size(); i++)
	{
		switch(draw_method)
		{
			case DRAW_WIRE :
				// TODO => TP02 //
				break;
			case DRAW_FILL :
				// TODO => TP03 //
				break;
			case DRAW_LAMBERT :
				// TODO => TP04 //
				break;
			case DRAW_GOURAUD :
				// TODO => TP04 //
				break;
			default :
				break;
		}
	}
}

void Object::backface_culling(mat4 trans_matrix)
{
	// TODO => TP03 //
}
