//
// Created by Engin Manap on 13.02.2016.
//


#include "World.h"

World::World(GLHelper* glHelper){
    this->glHelper = glHelper;
    Model *star = new Model(glHelper);
    star->setWorldTransform(glm::translate(glm::mat4(1.0f),glm::vec3(0.5f, 0.3f, -3.0f)));
    objects.push_back(star);
}

void World::play(Uint32 ticks){
    float rotation = ticks / 5000.0f * 3.14f * 2;
    glm::mat4 transform;
    transform = glm::translate(glm::mat4(1.0f),glm::vec3(0.5f, 0.3f, -3.0f));
    transform *= glm::rotate(glm::mat4(1.0f),rotation, glm::vec3(0.0f, 1.0f, 0.0f));
    objects[0]->setWorldTransform(transform);
}

void World::render(){
    for(std::vector<Model*>::iterator it = objects.begin(); it != objects.end(); ++it){
        (*it)->render(glHelper);
    }
}