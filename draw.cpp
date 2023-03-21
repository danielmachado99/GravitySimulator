
#include <iostream>
#include <SDL2/SDL.h>
#include "draw.h"

// Draw:
// {
// private:
//     /* data */
//     SDL_Window *window;
//     SDL_Renderer *renderer;

// public:
Draw::Draw(/* args */)
{

    SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
};

void Draw::SetRenderDrawColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

void Draw::RenderDrawPoint(int x, int y)
{
    SDL_RenderDrawPoint(renderer, x, y);
}
void Draw::RenderPresent()
{
    SDL_RenderPresent(renderer);
}
Draw::~Draw()
{
    SDL_Delay(100);
};
// };

int main()
{
    std::cout << "hello1" << std::endl;
    // SDL_Window *window;
    // SDL_Renderer *renderer;

    // SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // // Probably on a loop
    // SDL_RenderDrawPoint(renderer, 400, 300); // Renders on middle of screen.
    // SDL_RenderDrawPoint(renderer, 400, 301);
    // SDL_RenderDrawPoint(renderer, 400, 302);
    // SDL_RenderDrawPoint(renderer, 400, 303);
    // SDL_RenderDrawPoint(renderer, 400, 304);
    // SDL_RenderDrawPoint(renderer, 400, 305);
    // SDL_RenderPresent(renderer);

    // Draw example;
    // example.SetRenderDrawColor(255, 255, 255, 255);
    // example.RenderDrawPoint(400, 300);
    // example.RenderPresent();

    // SDL_Delay(10000);
    // char s;

    // // Take input using cin
    // std::cin >> s;
    return 0;
}