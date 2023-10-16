struct Position
{
    int x;
    int y;
}; // Les struc servent a structurer la donnee et a derirre resteindre les valeurs possible
struct Cellule
{
    char type[2];        // type est a tableau de char de taille 2 pas plus pas moins
    struct Position pos; // pos est a tableau qui a pour type la structure Position donc tableau[2] avec un x int et un y int
};
struct Colonne
{
    struct Cellule cellule[largeur]; //
};
struct Map
{
    struct Colonne colonne[hauteur];
};
struct Config
{
    int hauteur;
    int largeur;
    int mode[2];
    int vitesse;
    int son[5];
    int musique[5];
    int taille[3];
    int difficulte[3];
};
struct Game
{
    int currentPommes;
    int gameState;
    int score;
    int direction;
    struct Config config;
    struct Map map;
};
extern struct Game game;
extern char composants[6];
// ---------------- DECLARATION MAP -----------------
void constructMap();
void printMap();

// --------------- DECLARATION POMME -----------------
void pommeAdd();
void pommePositionGenerator(struct Position allPos[3], int count);

// ----------------- DECLARATION INITIALISATION -----------------
void initialisation(SDL_Renderer *render);

// ----------------- DECLARATION GAME -----------------
void start(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);

// ----------------- DECLARATION MENU -----------------
void menu(BOOLEAN *selected, BOOLEAN *change, char *mode, SDL_Renderer *render, TTF_Font *police, SDL_Window *window);
void menuGenerator(int *option, BOOLEAN **change, SDL_Renderer *render, TTF_Font *police, SDL_Window *window);
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