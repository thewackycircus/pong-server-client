#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"
#include "SDL_ttf.h"
#include "Vector2.h"

#pragma once
class Text
{
    private:
        TTF_Font* font;

    public:
        void init();
        SDL_Texture* createTextureFromString(SDL_Renderer* renderer, std::string text, SDL_Color color);
        vector2 positionText(vector2 initPosition, int textW, int textH);
        void renderText(SDL_Renderer* renderer, int xPos, int yPos, std::string text, SDL_Color color);
};
