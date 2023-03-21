#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL.h>

class Draw
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    Draw();
    ~Draw();

    void SetRenderDrawColor(int r, int g, int b, int a);
    void RenderDrawPoint(int x, int y);
    void RenderPresent();
};

#endif // DRAW_H
