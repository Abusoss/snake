
void addSerpent()
{
    struct Position pos = {0,0};
    serpentPositionGenerator(pos);
    strcpy(game.map.colonne[pos.y].cellule[pos.x].type, "S");
}
void serpentPositionGenerator(struct Position pos)
{
    do
    {
        pos.x = rand() % largeur;
        pos.y = rand() % hauteur;
    } while (game.map.colonne[pos.y].cellule[pos.x].type[0] != 'v');
    // printf("x:%d,y:%d", pos.x,pos.y);
}