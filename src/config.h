// #define HAUT 1;
// #define BAS 2;
// #define GAUCHE 3;
// #define DROITE 4;
// int windowFlag = SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_BORDERLESS ;
// hauteur et largeur de la map les enum peuvent etre util pour declarer plusieurs variables(
enum direction
{
    HAUT = 1,
    BAS = 2,
    GAUCHE = 3,
    DROITE = 4,
};
enum gameConfig
{
    windowWidth = 820,
    windowHeight = 820,
    hauteur = 18,
    largeur = 18,
    taillePoliceSplash = 150,
    taillePoliceMenu = 58,
    marge = 20,
    taillePoliceGame = (windowWidth-(windowWidth / marge))/largeur,
    goldenPommeChance = 20,
    goldenNumber = goldenPommeChance / 2,
    pommeNumber = 3,
    vitesse = 1,
    mode = 1,
    son = 5,
    musique = 5,
    difficulte = 1,
    taille = 1
}; // hauteur et largeur de la map les enum peuvent etre util pour declarer plusieurs variables(constantes)
enum options
{
    jouer = 0,
    quitter = 1,
    options = 2,
    modeOption = 3,
    vitesseOption = 4,
    sonOption = 5,
    musiqueOption = 6,
    difficulteOption = 7,
    tailleOption = 8,
};

int windowFlag = SDL_WINDOW_ALLOW_HIGHDPI;
int fonctionne = TRUE;
Uint16 composants[7] = {0x0058, 0x0023, 0x0020, 0x25A1, 0x25A1, 0x2612, 0xE108};
char menuTitle[9][15] = {"1. Jouer", "2. Options", "3. Quitter", "4. Mode", "5. Vitesse", "6. Son", "7. Musique", "8. Difficulte", "9. Taille"};
// extern enum gameConfig;
// extern enum options;