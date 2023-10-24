#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <time.h>
#include <math.h>
#include <locale.h>
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
#include "./src/list.h"
#include "./src/window.h"
#include "./src/utils.h"
#include "./src/functions.h"
#include "./src/actions.h"
#include "./src/splashScreen.h"
#include "./src/start.h"
#include "./src/menu.h"
#include "./src/pomme.h"
#include "./src/game.h"
#include "./src/serpend.h"
#include "./src/score.h"
#include "./src/save.h"
Game game = {0};
int main(int argc, char *argv[])
{
    setlocale(LC_CTYPE, "");
    SDL_Init(SDL_INIT_EVERYTHING);
    // ---------------- Init window
    initWindow();
    // ---------------- Init police
    game.police = NULL;
    TTF_Init();
    srand(time(NULL));
    initialisation();
    printf("init\n");
    SplashScreen("SNAKE");
    TTF_CloseFont(game.police);
    game.police = NULL;
    printf("Splash\n");
    start();
    printf("Start\n");

    printf("fonctionne : %d\n", fonctionne);
    quitterWindow();
    return EXIT_SUCCESS;
}