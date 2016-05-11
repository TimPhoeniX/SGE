//
//  main.cpp
//  ZombieGame
//
//  Created by Hamashy on 13.02.2016.
//  Copyright © 2016 Hamashy. All rights reserved.
//

#include <iostream>
#include <thread>
#include <chrono>

//#include "MainGameWindow.hpp"

#include "../SimpleGameEngine/SGE/SGE.hpp"

#include "../SimpleGameEngine/SGE/Action/Actions/sge_action_move.hpp"

/* ===================================================================================== */

//std::function<void(void)> nonSGE = []{
//    float gameBox[] = { SCREEN_WIDTH, SCREEN_HEIGHT };
//    MainGameWindow* mainWindow = new MainGameWindow(gameBox[0], gameBox[1]);
//
//    mainWindow->init();
//    mainWindow->show();
//
//    mainWindow->run();
//    delete mainWindow;
//};

/* ===================================================================================== */


class MainScene : public SGE::Scene{
    SGE::ObjectManager* manager = nullptr;
    
public:
    MainScene(SGE::ObjectManager* _manager) : manager(_manager) {
        
		std::string path = SGE::getPath() + "level1.txt";
		std::map<char, std::string> mask = {
//			{'.',"."},{'Z',"."},{'@',"."},
			{'R',PATH"ZombieGame/Resources/Textures/red_bricks.png"},
			{'B',PATH"ZombieGame/Resources/Textures/red_bricks.png"},
			{'G',PATH"ZombieGame/Resources/Textures/glass.png"},
			{'L',PATH"ZombieGame/Resources/Textures/light_bricks.png"} };

		this->loadLevel(path.c_str(), mask);
	}

	void finalize()
	{
        ;
	}
    
	void onDraw()
	{
        //debug only:
        std::cerr << "onDraw!" << std::endl;
        
        SGE::Action* move = new SGE::ACTION::Move(100, 100, 2);
        move->setObjectManager(this->manager->getActionHandler());
        //SGE::Action::ID a1 = this->manager->addAction(move);

	}
};

int main(int argc, char * argv[]) {
    std::cout.setf(std::ios::boolalpha);

//	SGE::Rectangle* tile = (SGE::Rectangle*)(SGE::getBaseTileShape());
//	tile->setHeight(256); //This works nicely
//	tile->setWidth(256);

	SGE::Director* director = SGE::Director::getDirector(1024,768);
	SGE::ObjectManager* manager = SGE::ObjectManager::getManager();
    
	SGE::Scene::ID S1 = director->addScene(new MainScene(manager));
    
    SGE::Object::ID camID = manager->getCameraID();
    
    SGE::Action::ID AW = manager->addAction(new SGE::ACTION::Move(0, 1000.f, 0));
    SGE::Action::ID AA = manager->addAction(new SGE::ACTION::Move(-1000.f, 0, 0));
    SGE::Action::ID AS = manager->addAction(new SGE::ACTION::Move(0, -1000.f, 0));
    SGE::Action::ID AD = manager->addAction(new SGE::ACTION::Move(1000.f, 0, 0));
    
    SGE::ActionBinder B1(camID, AW, SGE::Key::W);
    SGE::ActionBinder B2(camID, AS, SGE::Key::S);
    SGE::ActionBinder B3(camID, AA, SGE::Key::A);
    SGE::ActionBinder B4(camID, AD, SGE::Key::D);

	manager->mapAction(B1);
    manager->mapAction(B2);
    manager->mapAction(B3);
    manager->mapAction(B4);
    
    
	director->showScene(S1);
    
        std::string t;
        std::getline(std::cin, t);

	director->deleteScene(S1);
	
	manager->finalize();
	director->finalize();

    return 0;
}
