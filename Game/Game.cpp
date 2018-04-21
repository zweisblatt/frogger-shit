
#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

#include "Components.hpp"
//#include "ECS.hpp"

GameObject* player;
GameObject* enemy;
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
    
    player = new GameObject("/Users/oliverhodge/Desktop/Game/Assets/rocket1.png",0,0);
    enemy = new GameObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png", -100, -100);
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
    
}

void Game::update(){
    
    player->update();
    enemy->update();
    manager.update();
    std::cout<<newPlayer.getComponent<PositionComponent>().x()<<","<<newPlayer.getComponent<PositionComponent>().y()<<std::endl;
    
}

void Game::render(){
    
    SDL_RenderClear(renderer);
    map->drawMap();
    player->render();
    enemy->render();
    SDL_RenderPresent(renderer);
    
}

void Game::clean(){
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game Cleaned..."<<std::endl;
    
    
}
