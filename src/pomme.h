// ---------------- POMME -----------------
void pommeAdd()
{
   game.currentPommes = pommeNumber;
   int x;
   int y;
   int count = 0;
   struct Position allPos[pommeNumber] = {};
   int goldenPomme;

   do
   {
      pommePositionGenerator(allPos, count);
      count++;
   } while (count < pommeNumber);
   // for (size_t i = 0; i < sizeof(allPos) / sizeof(allPos[0]); i++)
   // {
   //    printf("stored x : %d\n", allPos[i].x);
   //    printf("stored y : %d\n", allPos[i].y);
   // }

   for (size_t i = 0; i < sizeof(allPos) / sizeof(allPos[0]); i++)
   {
      goldenPomme = rand() % (goldenPommeChance + 1);
      if (goldenPomme == goldenNumber)
      {
         /* code */
         strcpy_s(game.map.colonne[allPos[i].y].cellule[allPos[i].x].type, 100, "P");
         // printf("%s\n", arg.colonne[allPos[i].y].cellule[allPos[i].x].type);
      }
      else
      {
         strcpy_s(game.map.colonne[allPos[i].y].cellule[allPos[i].x].type, 100, "p");
         // printf("%s\n", arg.colonne[allPos[i].y].cellule[allPos[i].x].type);
      }
   }
}

// void pommeRemove(struct Map arg)
// {
//    int x;
//    int y;
// }

void pommePositionGenerator(struct Position allPos[3], int count)
{
   struct Position unePos = {0, 0};
   do
   {
      unePos.x = rand() % largeur;
      unePos.y = rand() % hauteur;
      // printf("x : %d\n, y : %d\n", unePos.x, unePos.y);
      // printf("type : %s\n", arg.colonne[unePos.y].cellule[unePos.x].type);
      // if (arg.colonne[unePos.y].cellule[unePos.x].type[0] != 'v')
      // {
      //    isNotOn = false;
      // }
      // else
      // {
      //    isNotOn = true;
      // }
   } while (game.map.colonne[unePos.y].cellule[unePos.x].type[0] != 'v');

   allPos[count] = unePos;
}