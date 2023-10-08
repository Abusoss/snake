#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
// #include <threads.h>
// #include <curses.h>
#if __linux__
#include <ncurses.h>
#elif __APPLE__
#elif _WIN32
#include <conio.h>
#endif
#include "./libs/config.h"
#include "./libs/var.h"
#include "./libs/clear.h"
#include "./libs/functions.h"
#include "./libs/menu.h"
#include "./libs/move.h"
char composants[6] = {'X', '#', ' ', '|', '-', 'O'};
struct Game game = {0};

int main()
{
    srand(time(NULL));
    // struct Map map[] = {
    //     [0] = {
    //         ligne : {
    //             [0] = {
    //                 cellule : {
    //                     [0] = {
    //                         type : "mur",
    //                         pos : {[0]= {x:0, y:0}}
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // };

    // Initialisation de la map
    // l = ligne et c = colonne



// [[]]
// [[]]
    // printf("%s", init.ligne[5].cellule[5].type);
    // printf("\n");
    clear_screen();
    initialisation();
    return 0;
}