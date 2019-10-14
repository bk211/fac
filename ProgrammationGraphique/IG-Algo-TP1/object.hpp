# ifndef OBJECT_HPP
# define OBJECT_HPP
# include <vector>
# include "window.hpp"

class Face // face structure
{
	public:
		std::vector<int> vertex_index;
		vec4 normal;
		vec4 normal_transformed;
		vec3 color;
		int visible;  // Face's state
		Face()
		{
			vertex_index.resize(4, -1);
		}
};

typedef enum type_draw_u {
	DRAW_WIRE,
	DRAW_FILL,
	DRAW_LAMBERT,
	DRAW_GOURAUD
} type_draw;

class Object
{
	public:
		std::vector<vec4> vertices;
		std::vector<vec4> vertices_transformed;
		std::vector<vec2> vertices_projected;
		std::vector<vec4> normals;
		std::vector<vec4> normals_transformed;
		std::vector<Face> faces;
		type_draw draw_method;
		void update_transformation(mat4);
		void update_projection(mat4);
		void draw(Window &, vec4 light = vec4(-1000,0,0,0));
		void backface_culling(mat4);
};


# endif // OBJECT_HPP
