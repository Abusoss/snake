// ----------------- INITIALISATION -----------------
void initialisation(SDL_Renderer *render)
{
   SDL_SetRenderDrawColor(render, 30, 30, 30, 255);
   SDL_RenderClear(render);
   printf("Map initialisation\n");
   printf("hauteur : %zu\n", sizeof(game.map) / sizeof(game.map.colonne[0]));
   printf("largeur: %zu\n", sizeof(game.map.colonne[0]) / sizeof(game.map.colonne[0].cellule[0]));
   game.config.vitesse = vitesse;
   game.config.difficulte[difficulte - 1] = 1;
   game.config.mode[mode - 1] = 1;
   game.config.musique[musique - 1] = 1;
   game.config.taille[taille - 1] = 1;
   constructMap();
}

// ----------------- DECLARATION SNAKE -----------------

// ----------------- DECLARATION MENU -----------------

// ----------------- DECLARATION GAME -----------------

// ----------------- DECLARATION SCORE -----------------

// ----------------- DECLARATION OPTION -----------------

// ----------------- DECLARATION SAVE -----------------

// ----------------- DECLARATION LOAD -----------------

// ----------------- DECLARATION EXIT -----------------

// ----------------- DECLARATION HELP -----------------

// ---------------- MAP -----------------
void constructMap()
{
   for (int c = 0; c < hauteur; c++)
   {
      game.map.colonne[c].cellule[0].pos.x = 0;
      game.map.colonne[c].cellule[0].pos.y = c;
      strcpy_s(game.map.colonne[c].cellule[0].type, 8, "m");
      game.map.colonne[c].cellule[largeur - 1].pos.x = largeur - 1;
      game.map.colonne[c].cellule[largeur - 1].pos.y = c;
      strcpy_s(game.map.colonne[c].cellule[largeur - 1].type, 8, "m");

      for (int l = 1; l < largeur - 1; l++)
      {
         game.map.colonne[c].cellule[l].pos.x = l;
         game.map.colonne[c].cellule[l].pos.y = c;
         strcpy_s(game.map.colonne[c].cellule[l].type, 8, "v");
      }
   }
   for (int l = 0; l < largeur; l++)
   {
      game.map.colonne[0].cellule[l].pos.x = l;
      game.map.colonne[0].cellule[l].pos.y = 0;
      strcpy_s(game.map.colonne[0].cellule[l].type, 8, "m");

      game.map.colonne[hauteur - 1].cellule[l].pos.x = l;
      game.map.colonne[hauteur - 1].cellule[l].pos.y = hauteur - 1;
      strcpy_s(game.map.colonne[hauteur - 1].cellule[l].type, 8, "m");
   }
}
// struct Map modifyMap(struct Map arg, int x, int y, char type)
// {
//    else
//    {
//       switch (arg.colonne[c].cellule[l].type[0])
//       {
//       case 'm':
//          break;
//       case 'v':
//          break;
//       case 's':
//          break;
//       case 'p':
//          break;
//       case 'P':
//          break;
//       default:
//          arg.colonne[c].cellule[l].type[0] = 'p';
//          break;
//       }
//    }
// }

void printMap()
{
   for (int c = 0; c < hauteur; c++)
   {
      for (int l = 0; l < largeur; l++)
      {
         // printf("%s",game.map.colonne[c].cellule[l].type);

         if (l == 0 || l == largeur - 1)
         {
            switch (game.map.colonne[c].cellule[l].type[0])
            {
            case 'm':
               printf("%c", composants[3]);
               break;
            default:
               break;
            }
         }
         else
         {
            switch (game.map.colonne[c].cellule[l].type[0])
            {
            case 'm':
               printf("%c", composants[4]);
               break;
            case 'v':
               printf("%c", composants[2]);
               break;
            case 's':
               printf("%c", composants[5]);
               break;
            case 'p':
               printf("%c", composants[0]);
               break;
            case 'P':
               printf("%c", composants[1]);
               break;
            default:
               break;
            }
         }
      }
      printf("\n");
   }
}

// ---------------- POMME -----------------
void pommeAdd()
{
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
         strcpy(game.map.colonne[allPos[i].y].cellule[allPos[i].x].type, "P");
         // printf("%s\n", arg.colonne[allPos[i].y].cellule[allPos[i].x].type);
      }
      else
      {
         strcpy(game.map.colonne[allPos[i].y].cellule[allPos[i].x].type, "p");
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