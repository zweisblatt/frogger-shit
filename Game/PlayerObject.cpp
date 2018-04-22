#include "PlayerObject.hpp"
#include "TextureManager.hpp"

PlayerObject::PlayerObject(const char* texturesheet, int x, int y){
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

void PlayerObject::update(){
    
    srcRect.h = 570;
    srcRect.w = 570;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w/6;
    destRect.h = srcRect.h/6;
}

void PlayerObject::render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

void PlayerObject::moveLeft()
{
    if (xpos <= -20) {
        xpos = -20;
    } else {
        xpos -= 5;
    }
    
}
void PlayerObject::moveRight()
{
    if (xpos >= 730) {
        xpos = 730;
    } else {
        xpos += 5;
    }
    
}
