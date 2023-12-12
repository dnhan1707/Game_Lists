cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sfml_project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Portfolio.cpp Portfolio.h Projects.cpp Projects.h Nameable.cpp Nameable.h Runable.cpp Runable.h Updatable.cpp Updatable.h EventHandlable.cpp EventHandlable.h ButtonPortfolio.cpp ButtonPortfolio.h MouseEventsPortfolio.cpp DisplayProjectName.cpp DisplayProjectName.h StatesPortfolio.cpp FontPortfolio.cpp FontEnumPortfolio.h PositionPortfolio.cpp Galaga/Alien.cpp Galaga/AlienShip.h Galaga/AlienShip.cpp Galaga/AnimatedSprite.cpp Galaga/BackgroundGalaga.cpp Galaga/ButtonGalaga.cpp Galaga/DisplayGalaga.cpp Galaga/FighterJet.cpp Galaga/FontGalaga.cpp Galaga/Galaga.cpp Galaga/GameOver.cpp Galaga/Gun.cpp Galaga/Image.cpp Galaga/Rocket.cpp Galaga/StatesGalaga.cpp SFML_Template/greenCircle.cpp Calculator/BackgroundCalculator.cpp Calculator/ButtonCalculator.cpp Calculator/Calculator.cpp Calculator/DisplayCalculator.cpp Calculator/Font.cpp Calculator/RPN.cpp Calculator/StatesCalculator.cpp Clock/functions.cpp Clock/clockHand.cpp Clock/Clock.cpp Clock/Clock.h "Poker Analysis w SFML/Card.cpp" "Poker Analysis w SFML/CardGraphic.cpp" "Poker Analysis w SFML/CardHand.cpp" "Poker Analysis w SFML/CardHandScorer.cpp" "Poker Analysis w SFML/Deck.cpp" "Poker Analysis w SFML/getRandomCard.cpp" "Poker Analysis w SFML/HandContainer.cpp" "Poker Analysis w SFML/LetterBox.cpp" "Poker Analysis w SFML/ScoreHand.cpp" "Poker Analysis w SFML/PokerAnalysis.cpp" "Poker Analysis w SFML/PokerAnalysis.h" "Poker Analysis w SFML/ImagePoker.cpp" BouncingBall/Ball.cpp BouncingBall/BouncingBall.cpp BouncingBall/BouncingBall.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()