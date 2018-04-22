
#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "PlayerObject.hpp"
#include "Map.hpp"

#include "Components.hpp"
//#include "ECS.hpp"

PlayerObject* player;
GameObject* enemy;
GameObject* enemy2;
GameObject* enemy3;
GameObject* enemy4;
GameObject* enemy5;
Map* map;

SDL_Renderer* Game::renderer = nullptr;
Manager manager;
auto& newPlayer(manager.addEntity());


Game::Game(){
    
}
Game::~Game(){
    
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
    
    int flags=0;
    if (fullscreen){
        flags=SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout<<"Subsystems Initialized..."<< std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            std::cout<<"Window created..."<<std::endl;
        }
        renderer=SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<<"Renderer Created..."<<std::endl;
        }
        
        isRunning=true;
    }
    
    else{
        isRunning=false;
    }
    
    player = new PlayerObject("/Users/zachweisblatt/Desktop/rocket1.png",0,550);
    enemy = new GameObject("/Users/zachweisblatt/Desktop/rock.png",300,0);
    enemy2 = new GameObject("/Users/zachweisblatt/Desktop/rock.png",0,-10);
    enemy3 = new GameObject("/Users/zachweisblatt/Desktop/rock.png",100,-60);
    enemy4 = new GameObject("/Users/zachweisblatt/Desktop/rock.png",640,-100);
    enemy5 = new GameObject("/Users/zachweisblatt/Desktop/rock.png",200,-150);

    map = new Map();
    
    newPlayer.addComponent<PositionComponent>();
    
}

void Game::handleEvents(){
    
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning=false;
            break;
            
        default:
            break;
    }
    
    const Uint8* currentKeyState = SDL_GetKeyboardState(NULL);
    if (currentKeyState[SDL_SCANCODE_A] || currentKeyState[SDL_SCANCODE_LEFT])
    {
        player->moveLeft();
    }
    if (currentKeyState[SDL_SCANCODE_D] || currentKeyState[SDL_SCANCODE_RIGHT])
    {
        player->moveRight();
    }
}

void Game::update(){
    
    player->update();
    enemy->update();
    enemy2->update();
    enemy3->update();
    enemy4->update();
    enemy5->update();
    manager.update();
    std::cout<<newPlayer.getComponent<PositionComponent>().x()<<","<<newPlayer.getComponent<PositionComponent>().y()<<std::endl;
    
}

void Game::render(){
    
    SDL_RenderClear(renderer);
    map->drawMap();
    player->render();
    enemy->render();
    enemy2->render();
    enemy3->render();
    enemy4->render();
    enemy5->render();
    SDL_RenderPresent(renderer);
    
}

void Game::clean(){
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game Cleaned..."<<std::endl;
    
    
}
