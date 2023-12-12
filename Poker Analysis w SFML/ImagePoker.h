//
// Created by ASUS on 10/19/2023.
//

#ifndef SFML_PROJECT_IMAGEPOKER_H
#define SFML_PROJECT_IMAGEPOKER_H

#include "SFML/Graphics.hpp"

class ImagePoker {
private:
    //Static: u don;t need an object to use it
    static sf::Texture texture; //static: only one get created
    static void loadTexture();

public:
    static sf::Texture& getImage();


};


#endif //SFML_PROJECT_IMAGEPOKER_H
