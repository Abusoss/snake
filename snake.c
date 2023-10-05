#include "./libs/functions.h"
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
    constructMap();
    // printf("%s", init.ligne[5].cellule[5].type);
    // printf("\n");
    initialisation();
    printMap();
    return 0;
}