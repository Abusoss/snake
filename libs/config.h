// hauteur et largeur de la map les enum peuvent etre util pour declarer plusieurs variables(
enum gameConfig
{
    hauteur = 19,
    largeur = 101,
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
extern char menuTitle[9][15] = {"1. Jouer\n", "2. Options\n", "3. Quitter\n", "4. Mode\n", "5. Vitesse\n", "6. Son\n", "7. Musique\n", "8. Difficulte\n", "9. Taille\n"};
extern enum gameConfig;
extern enum options;