//
// Created by ASUS on 12/9/2023.
//

#include "Portfolio.h"

Portfolio::Portfolio()
:left("<", sf::Color::Red), right(">", sf::Color::Red)
{

    left.setRadius(30);
    left.setPosition({850, 700});
    left.setTextColor(sf::Color::White);

    right.setRadius(30);
    right.setPosition({1000, 700});
    right.setTextColor(sf::Color::White);
}

void Portfolio::run()
{
    sf::RenderWindow window({1500,1000,32}, "Portfolio");
    window.setFramerateLimit(60);

    iter = projects.begin();
    projectName.setCharacterSize(24);
    projectName.setColor({80,80,80});
    projectName.setSize({300,50});
    projectName.setPosition({300 ,0});

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            eventHandler(window, event);
            (*iter) ->eventHandler(window, event);
        }
        (*iter) -> run();
        (*iter) -> update();
        update();
        projectName.setText((*iter) -> getName());
        window.clear();
        window.draw(*(*iter));
        window.draw(left);
        window.draw(right);
        window.draw(projectName);
        window.display();
    }

}

void Portfolio::addProject(Projects &project) {
    projects.push_back(&project);
}

void Portfolio::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    left.eventHandler(window,event);
    right.eventHandler(window,event);

//    while(MouseEventsPortfolio::isClicked(left.getButton(),window))
//    {
//        buttonLeft = true;
//    }
    if(MouseEventsPortfolio::isClicked(left.getButton(),window))
    {
        if(iter != projects.begin())
            --iter;
        else if(iter == projects.begin())
            iter = projects.end()-1;
//        buttonLeft = false;
    }
//    while(MouseEventsPortfolio::isClicked(right.getButton(),window))
//    {
//        buttonRight = true;
//    }
    if(MouseEventsPortfolio::isClicked(right.getButton(),window))
    {
        if(iter != projects.end()-1)
            ++iter;
        else
            iter = projects.begin();
//        buttonRight = false;
    }
}

void Portfolio::update()
{
    left.update();
    right.update();
}
