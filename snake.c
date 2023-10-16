#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#if __linux__
#include <ncurses.h>
#elif __APPLE__
#elif _WIN32
#include <conio.h>
#endif
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "./src/config.h"
#include "./src/declar.h"
#include "./src/window.h"
#include "./src/functions.h"
#include "./src/affichage.h"
#include "./src/actions.h"
#include "./src/splashScreen.h"
#include "./src/start.h"
#include "./src/menu.h"
struct Game game = {0};
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    // ---------------- Init window
    SDL_Window *window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
    if (window == NULL){printf("Could not create window: %s\n", SDL_GetError());fonctionne = FALSE;}
    printf("Window created !!!\n");

    // ---------------- Init render
    SDL_Renderer *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (render == NULL){printf("Could not create render: %s\n", SDL_GetError());fonctionne = FALSE;}
    printf("Render created !!!\n");
    // ---------------- Init police
    TTF_Font *police = NULL;
    TTF_Init();
    srand(time(NULL));
    // fonctionne = initWindow(render, police, window);
    // printf("fonctionne : %d\n", fonctionne);
    initialisation(render);
    // affichage();
    SplashScreen(render, police, window);
    start(render, police, window);
    // while (fonctionne)
    // {
    //     actions();
    //     miseAJour();
    //     // affichage();
    //     // SDL_Delay(500); // Pause for 2 seconds
    // }
    printf("fonctionne : %d\n", fonctionne);
    quitterWindow(render, police, window);
    return EXIT_SUCCESS;
}