#ifndef Plane_h
#define Plane_h
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Plane {

public:

	Plane();

	~Plane();

	/// Init function
	void init(GLuint shadowMapTextureId);

	/// Draw function
	void draw(float elapsed, const glm::mat4& view, const glm::mat4& projection, const size_t pingpong);
	
	/// Draw depth function
	void drawDepth(float elapsed, const glm::mat4& vp);
	
	/// Clean function
	void clean();


private:
	
	GLuint _programId;
	GLuint _programDepthId;
	GLuint _vao;
	GLuint _ebo;
	GLuint _lightUniformId;
	GLuint _shadowMapId;
	
	size_t _count;
	
	glm::mat4 _lightMVP;

};

#endif
