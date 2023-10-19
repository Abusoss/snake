typedef struct Position
{
    int x;
    int y;
}Position; // Les struc servent a structurer la donnee et a derirre resteindre les valeurs possible
typedef struct Cellule
{
    SDL_Texture* texture;
    char type[2];        // type est a tableau de char de taille 2 pas plus pas moins
    Position pos; // pos est a tableau qui a pour type la structure Position donc tableau[2] avec un x int et un y int
}Cellule;
typedef struct Colonne
{
    Cellule cellule[largeur]; //
}Colonne;
typedef struct Map
{
    Colonne colonne[hauteur];
}Map;
typedef struct Config
{
    int hauteur;
    int largeur;
    int mode[2];
    int vitesse;
    int son[5];
    int musique[5];
    int taille[3];
    int difficulte[3];
}Config;

#ifndef __List_H__
#define __List_H__
typedef struct List_type{
    Cellule cellule;
    // TODO: Ajouter SDL_Texture* texture pour chaque cellule ou avoir un poiteur vers une cellule de map et jouter une SDL_Texture* texture dans le struct Cellule
    struct List_type *suivant;
    struct List_type *precedent;
}List, Cell;
#endif

typedef struct Game
{
    int currentPommes;
    int gameState;
    int score;
    int previousDirection;
    int direction;
    int currentOption;
    BOOLEAN scanner[4];
    List *serpent;
    List *reverseSerpent;
    Config config;
    Map map;
}Game;
extern Game game;
extern Uint16 composants[7];

// --------------- DECLARATION POMME -----------------
void pommeAdd();
void pommePositionGenerator(Position allPos[3], int count);

// ----------------- DECLARATION INITIALISATION -----------------
void initialisation(SDL_Renderer *render);
void constructMap();

// ----------------- DECLARATION START -----------------
void start(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);

// ----------------- DECLARATION MENU -----------------
void menu(BOOLEAN *selected, BOOLEAN *change, char *mode, SDL_Renderer *render, TTF_Font *police, SDL_Window *window);
void menuGenerator(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);

// ----------------- DECLARATION GAME -----------------
void gameStart(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);
void gameGenerator(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);
void renderComponent(Position pos, Uint16 text, TTF_Font *police, SDL_Color fontColor, SDL_Renderer *render, SDL_Surface *surfaceMessage, SDL_Texture *Message, SDL_Rect Message_rect);

// ----------------- DECLARATION SERPEND -----------------
void addSerpend(void);
void growSerpend(void);
void removeQueueSerpend();
void serpendPositionGenerator(Position *pos);
void moveSerpend(BOOLEAN *change);
void scanSerpend(int mode);

// ----------------- DECLARATION ACTIONS -----------------
void actions(BOOLEAN *change, BOOLEAN *selected);

// ----------------- DECLARATION WINDOW -----------------
int initWindow(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);
void quitterWindow(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);

// ----------------- DECLARATION SPLASH SCREEN -----------------
void SplashScreen(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);
// ----------------- DECLARATION AFFICHAGE -----------------
void affichage(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);
// ----------------- DECLARATION MISE A JOUR -----------------
void miseAJour(void);



// ----------------- DECLARATION UTILS -----------------
BOOLEAN str_to_uint16(const char *str, Uint16 *res);


// ----------------- DECLARATION FONCTION DE LIST CHAÎNÉE -----------------
#ifndef __List_H__
static Cell *creeCell(Cellule cellule);
BOOLEAN estVide(List *liste);
long tailleList(List *liste);

List *creeList(void);

List *ajoutA(List *liste, Cellule cellule, int pos);
List *supprimerA(List *liste, Cellule cellule, int pos);

List *ajouterFinA(List *liste, Cellule data, int pos);
List *supprimerFin(List *liste);

List *supprimerList(List *liste);

Cellule rechercheA(List *liste, int pos);
Cellule rechercheAReverse(List *liste, int pos);
void afficherListe(List *liste);
#endif