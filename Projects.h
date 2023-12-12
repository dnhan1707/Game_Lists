//
// Created by ASUS on 12/9/2023.
//

#ifndef SFML_PROJECT_PROJECTS_H
#define SFML_PROJECT_PROJECTS_H

#include "Nameable.h"
#include "Runable.h"
#include "Updatable.h"
#include "EventHandlable.h"

class Projects : public Nameable, public Runable, public Updatable, public EventHandlable, public sf::Drawable
{

};


#endif //SFML_PROJECT_PROJECTS_H
