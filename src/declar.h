typedef struct Position
{
    int x;
    int y;
}Position; // Les struc servent a structurer la donnee et a derirre resteindre les valeurs possible
typedef struct Cellule
{
    SDL_Surface* surface;
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
    Cellule *cellule;
    // TODO: Ajouter SDL_Texture* texture pour chaque cellule ou avoir un poiteur vers une cellule de map et ajouter une SDL_Texture* texture dans le struct Cellule
    struct List_type *suivant;
    struct List_type *precedent;
}List, Cell;
#endif

typedef struct Game
{
    int currentPommes;
    char gameState[10];
    int score;
    int previousDirection;
    int direction;
    int currentOption;
    BOOLEAN isChange;
    BOOLEAN selected;
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

/**
 * ----------------- INITIALISATION -----------------
 *
 * @attention Initialise la carte de jeu et les paramètres de configuration.
 * \param render Le renderer SDL pour dessiner la carte.
 * \param vitesse La vitesse de jeu.
 * \param difficulte Le niveau de difficulté.
 * \param mode Le mode de jeu.
 * \param musique Le choix de musique.
 * \param taille La taille de la carte.
 * \param game L'objet de jeu contenant les informations de jeu.
 */
void initialisation(SDL_Renderer *render);

void reinitialization();

/**
 * @brief Construit la carte de jeu en initialisant les cellules avec leurs positions et types.
 *
 * @attention Cette fonction ne initialise pas les textures et surfaces des cellules.
 *
 * @note Cette fonction ne retourne rien.
 *
 * @param hauteur La hauteur de la carte de jeu.
 * @param largeur La largeur de la carte de jeu.
 */
void constructMap();

/**
 * @attention Cette fonction est la fonction principale du jeu Snake. Elle permet de gérer les différents modes du jeu (menu, jeu) et de lancer le jeu.
 * @param render Le renderer SDL pour afficher les éléments graphiques.
 * @param police La police TTF pour afficher le texte.
 * @param window La fenêtre SDL pour afficher le jeu.
 * @note Cette fonction utilise les fonctions menu(), gameStart() et actions() pour gérer les différents modes et les actions du joueur.
 */
void start(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);

/**
 * @attention Cette fonction gère le menu principal du jeu. Elle prend en charge l'affichage du menu, la sélection des options et la gestion des événements de l'utilisateur.
 *
 * @param change Un pointeur vers un booléen qui indique si une option de menu a été modifiée.
 * @param mode Un pointeur vers une chaîne de caractères qui stocke le mode de jeu sélectionné.
 * @param render Un pointeur vers un SDL_Renderer qui est utilisé pour afficher le menu.
 * @param police Un pointeur vers un TTF_Font qui est utilisé pour afficher le texte du menu.
 * @param window Un pointeur vers un SDL_Window qui est utilisé pour afficher le menu.
 *
 * @note Cette fonction utilise la police de caractères "./police.ttf" avec une taille de police de `taillePoliceMenu`.
 * @note Les options de menu sont numérotées de 0 à 2.
 * @note L'option de menu sélectionnée est stockée dans la variable `game.currentOption`.
 * @note Lorsque l'option de menu est modifiée, la variable `*change` doit être définie sur TRUE.
 * @note Lorsqu'une option de menu est sélectionnée, la variable `*selected` doit être définie sur TRUE et le mode de jeu sélectionné doit être stocké dans la variable `*mode`.
 * @note Cette fonction ne retourne aucune valeur.
 */
void menu(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);

/**
 * @brief Génère le menu principal du jeu.
 *
 * @attention Cette fonction utilise les paramètres SDL_Renderer, TTF_Font et SDL_Window.
 *
 * @param render Le renderer utilisé pour afficher le menu.
 * @param police La police de caractères utilisée pour afficher le menu.
 * @param window La fenêtre dans laquelle le menu est affiché.
 *
 * @note Cette fonction utilise la variable globale game.currentOption pour déterminer l'option sélectionnée.
 *
 */
void menuGenerator(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);

/**
 * @attention Cette fonction démarre le jeu Snake en initialisant les paramètres nécessaires.
 * @param render Le renderer SDL pour afficher le jeu.
 * @param police La police de caractères utilisée pour afficher le texte du jeu.
 * @param window La fenêtre SDL dans laquelle le jeu est affiché.
 * @note Cette fonction ajoute un serpent, le fait grandir et génère le jeu. Elle utilise une boucle while pour continuer le jeu jusqu'à ce que le joueur perde.
 */
void gameStart(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);

/**
 * @attention Cette fonction génère le jeu en initialisant la couleur de rendu, en nettoyant le rendu, en initialisant la couleur de la police, en initialisant la position, en initialisant la direction du jeu et en bouclant sur la hauteur et la largeur de la carte pour afficher les différents composants du jeu.
 *
 * @param render Le rendu SDL pour afficher les composants du jeu.
 * @param police La police TTF pour afficher le texte du jeu.
 * @param window La fenêtre SDL pour afficher les composants du jeu.
 *
 * @note Cette fonction utilise les variables globales suivantes : game, hauteur, largeur, composants.
 */
void gameGenerator(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);

/**
 * @brief Affiche un texte à l'écran à une position donnée.
 *
 * @attention La fonction utilise les bibliothèques SDL2 et SDL_ttf.
 *
 * @param pos La position où afficher le texte.
 * @param text Le texte à afficher.
 * @param police La police de caractères à utiliser.
 * @param fontColor La couleur du texte.
 * @param render Le renderer SDL sur lequel afficher le texte.
 * @param surfaceMessage La surface SDL sur laquelle dessiner le texte.
 * @param Message La texture SDL créée à partir de la surface.
 * @param Message_rect Le rectangle SDL qui définit la position et la taille de la texture.
 *
 * @note La fonction modifie les paramètres surfaceMessage, Message et Message_rect.
 */
void renderComponent(Position pos, Uint16 text, TTF_Font *police, SDL_Color fontColor, SDL_Renderer *render, SDL_Surface *surfaceMessage, SDL_Texture *Message, SDL_Rect Message_rect);

// ----------------- DECLARATION SERPEND -----------------
void addSerpend(void);
void growSerpend(void);
void removeQueueSerpend();
void serpendPositionGenerator(Position *pos);
void moveSerpend();
void scanSerpend(int range, int begin, Position pos);
void verifySerpend(int newX, int newY);

// ----------------- DECLARATION ACTIONS -----------------
void actions();

// ----------------- DECLARATION WINDOW -----------------
int initWindow(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);
void quitterWindow(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);

// ----------------- DECLARATION SPLASH SCREEN -----------------
void SplashScreen(SDL_Renderer *render, TTF_Font *police, SDL_Window *window, char *text);
// ----------------- DECLARATION AFFICHAGE -----------------
void affichage(SDL_Renderer *render, TTF_Font *police, SDL_Window *window);
// ----------------- DECLARATION MISE A JOUR -----------------
void miseAJour(void);



// ----------------- DECLARATION UTILS -----------------
BOOLEAN str_to_uint16(const char *str, Uint16 *res);


// ----------------- DECLARATION FONCTION DE LIST CHAÎNÉE -----------------
#ifndef __List_H__
static Cell *creeCell(Cellule *cellule);
BOOLEAN estVide(List *liste);
long tailleList(List *liste);

List *creeList(void);

List *ajoutA(List *liste, Cellule *cellule, int pos);
List *supprimerA(List *liste, Cellule *cellule, int pos);

List *ajouterFinA(List *liste, Cellule *data, int pos);
List *supprimerFin(List *liste);

List *supprimerList(List *liste);

Cellule *rechercheA(List *liste, int pos);
Cellule *rechercheAReverse(List *liste, int pos);
void afficherListe(List *liste);
#endif