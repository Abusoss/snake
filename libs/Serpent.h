
void addSerpent()
{
    struct Position pos = {};
    pos = serpentPositionGenerator();
    strcpy(game.map.colonne[pos.y].cellule[pos.x].type, "S");
}
struct Position serpentPositionGenerator()
{
    struct Position unePos = {0, 0};
    do
    {
        unePos.x = rand() % largeur;
        unePos.y = rand() % hauteur;
    } while (game.map.colonne[unePos.y].cellule[unePos.x].type[0] != 'v');
    // printf("x:%d,y:%d", pos.x,pos.y);
    return unePos;
}