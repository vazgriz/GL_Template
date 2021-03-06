#ifndef AmbientQuad_h
#define AmbientQuad_h
#include <gl3w/gl3w.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include <map>
#include "ScreenQuad.h"

class AmbientQuad : public ScreenQuad {

public:

	AmbientQuad();

	~AmbientQuad();
	
	void init(std::map<std::string, GLuint> textureIds, const GLuint reflection, const GLuint irradiance);
	
	/// Draw function,
	void draw(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) const;
	
	void drawSSAO(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) const;
		
	void clean() const;
	
private:
	
	GLuint setupSSAO();
	
	GLuint _texCubeMap;
	GLuint _texCubeMapSmall;
	
	ScreenQuad _ssaoScreen;
	
	std::vector<glm::vec3> _samples;
	
};

#endif
