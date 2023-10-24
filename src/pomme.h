void pommeAdd()
{
   game.currentPommes = pommeNumber;
   struct Position allPos[pommeNumber] = {};
   int goldenPomme;

   for (int i = 0; i < pommeNumber; i++)
   {
      pommePositionGenerator(allPos, i);
   }

   for (int i = 0; i < pommeNumber; i++)
   {
      goldenPomme = rand() % (goldenPommeChance + 1);
      if (goldenPomme == goldenNumber)
      {
         strcpy_s(game.map.colonne[allPos[i].y].cellule[allPos[i].x].type, 100, "P");
      }
      else
      {
         strcpy_s(game.map.colonne[allPos[i].y].cellule[allPos[i].x].type, 100, "p");
      }
   }
}

void pommePositionGenerator(struct Position allPos[3], int count)
{
   struct Position unePos = {0, 0};
   do
   {
      unePos.x = rand() % largeur;
      unePos.y = rand() % hauteur;
   } while (game.map.colonne[unePos.y].cellule[unePos.x].type[0] != 'v');

   allPos[count] = unePos;
}