#ifndef SphereScene_h
#define SphereScene_h

#include "Scene.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>


class SphereScene : public Scene {
public:
	void init();
	void update(double timer, double elapsedTime);
};


void SphereScene::init(){
	
	// Create directional light.
	directionalLights.emplace_back(glm::vec3(-2.0f, 1.5f, 0.0f), glm::vec3(3.0f), glm::ortho(-0.75f,0.75f,-0.75f,0.75f,1.0f,6.0f));
	
	pointLights.emplace_back( glm::vec3(0.5f,-0.1f,0.5f), 3.0f*glm::vec3(0.2f,0.8f,1.2f), 0.9f);
	
	// Objects creation.
	Object sphere1(Object::Type::Regular, "sphere", { {"sphere_wood_lacquered_albedo", true }, {"sphere_wood_lacquered_normal", false}, {"sphere_wood_lacquered_rough_met_ao", false}});
	Object sphere2(Object::Type::Regular, "sphere", { {"sphere_gold_worn_albedo", true }, {"sphere_gold_worn_normal", false}, {"sphere_gold_worn_rough_met_ao", false}});
	const glm::mat4 model1 = glm::translate(glm::scale(glm::mat4(1.0f),glm::vec3(0.3f)), glm::vec3(1.2f,0.0f, 0.0f));
	const glm::mat4 model2 = glm::translate(glm::scale(glm::mat4(1.0f),glm::vec3(0.3f)), glm::vec3(-1.2f,0.0f, 0.0f));
	sphere1.update(model1);
	sphere2.update(model2);
	
	objects.push_back(sphere1);
	objects.push_back(sphere2);
	
	// Background creation.
	background = Object(Object::Type::Skybox, "skybox", {}, {{"studio", true }});
	backgroundIrradiance = Resources::manager().getCubemap("studio_irr").id;
}

void SphereScene::update(double timer, double elapsedTime){
	const glm::mat4 model = glm::rotate(glm::translate(glm::scale(glm::mat4(1.0f),glm::vec3(0.3f)), glm::vec3(1.2f,0.0f, 0.0f)), 0.2f*float(timer), glm::vec3(0.0f,1.0f,0.0f));
	objects[0].update(model);
	
}

#endif
