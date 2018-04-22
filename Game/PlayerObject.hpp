#include "Game.hpp"

class PlayerObject{
public:
    PlayerObject(const char* texturesheet, int x, int y);
    ~PlayerObject();
    
    void update();
    void render();
    
    void moveLeft();
    void moveRight();
    
private:
    int xpos;
    int ypos;
    
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    
};
