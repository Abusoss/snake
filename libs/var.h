#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define true 1
#define false 0
typedef int boolean;
enum
{
    hauteur = 19,
    largeur = 101,
    goldenPommeChance = 20,
    goldenNumber = goldenPommeChance/2,
    pommeNumber = 3
};
 // hauteur et largeur de la map les enum peuvent etre util pour declarer plusieurs variables(constantes)
 
 
struct Position
{
    int x;
    int y;
};// Les struc servent a structurer la donnee et a derirre resteindre les valeurs possible
struct Cellule
{
    char type[2]; // type est a tableau de char de taille 2 pas plus pas moins
    struct Position pos;// pos est a tableau qui a pour type la structure Position donc tableau[2] avec un x int et un y int
};
struct Colonne
{
    struct Cellule cellule[largeur]; //
};
struct Map
{
    struct Colonne colonne[hauteur];
};
struct Serpent
 {
    struct Cellule tete;
    struct Cellule corps[];
    enum direction 
    {
        HAUT,BAS,GAUCHE,DROITE
    };
    
    
 };
struct Game
{
      struct Map map;
      int currentPommes;
      struct Serpent serpent;
};
extern struct Game game;
extern char composants[6];


// ---------------- DECLARATION MAP -----------------
void constructMap();
void printMap();

// --------------- DECLARATION POMME -----------------
void pommeAdd();
void pommePositionGenerator(struct Position allPos[3], int count);

// ----------------- DECLARATION SERPENT -----------------
void serpentPositionGenerator(struct Position pos);
void addSerpent();
// ----------------- DECLARATION INITIALISATION -----------------
void initialisation();