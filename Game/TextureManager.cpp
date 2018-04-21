#include "TextureManager.hpp"


SDL_Texture* TextureManager::LoadTexture(const char* Texture){
  
    SDL_Surface* tmpSurface = IMG_Load(Texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    return tex;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
