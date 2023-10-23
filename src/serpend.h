void addSerpend(void)
{
   Position unePos = {0, 0};
   game.direction = rand() % 3 + 1;

   do
   {
      for (int i = 0; i < 3; i++)
      {
         game.scanner[i] = -1;
      }
      serpendPositionGenerator(&unePos);
      scanSerpend(2, TRUE, unePos);
   } while (game.scanner[game.direction] == FALSE);

   ajoutA(game.serpent, &game.map.colonne[unePos.y].cellule[unePos.x], 0);
   strcpy_s(game.serpent->cellule->type, 100, "S");
}
void growSerpend(void)
{
   int rnd = 0;
   for (int i = 0; i < 3; i++)
   {
      game.scanner[i] = -1;
   }
   scanSerpend(1, FALSE, (Position){0, 0});

   do
   {
      rnd = rand() % 3 + 1;
   } while (game.scanner[rnd] == FALSE);

   int y = game.reverseSerpent->cellule->pos.y;
   int x = game.reverseSerpent->cellule->pos.x;
   switch (rnd)
   {
   case 0:
      ajouterFinA(game.reverseSerpent, &game.map.colonne[y - 1].cellule[x], 0);
      break;
   case 1:
      ajouterFinA(game.reverseSerpent, &game.map.colonne[y + 1].cellule[x], 0);
      break;
   case 2:
      ajouterFinA(game.reverseSerpent, &game.map.colonne[y].cellule[x - 1], 0);
      break;
   case 3:
      ajouterFinA(game.reverseSerpent, &game.map.colonne[y].cellule[x + 1], 0);
      break;
   }

   strcpy_s(game.reverseSerpent->cellule->type, 100, "s");
}
void removeQueueSerpend()
{
}

// TODO: dans functions.h, dans la fonction constructMap() malloc toute les cellules, dans decla cellule de map sera un poiteur vers chaque cellule de la map, comme ca quand je growSerpent() et cache cell du serpent aura un  pointeur "cellule" vers une cellule

void scanSerpend(int range, int begin, Position pos)
{
   int y;
   int x;
   if (begin == TRUE)
   {
      x = pos.x;
      y = pos.y;
   }
   else
   {
      y = game.reverseSerpent->cellule->pos.y;
      x = game.reverseSerpent->cellule->pos.x;
   }

   for (int i = -range; i <= range; i++)
   {
      if (i == 0)
         continue;
      if (game.map.colonne[y + i].cellule[x].type[0] == 'v')
      {
         if (!game.scanner[i < 0 ? 0 : 1])
         {
            game.scanner[i < 0 ? 0 : 1] = TRUE;
            game.scanner[i < 0 ? 1 : 0] = FALSE;
         }
      }
      if (game.map.colonne[y].cellule[x + i].type[0] == 'v')
      {
         if (!game.scanner[i < 0 ? 2 : 3])
         {
            game.scanner[i < 0 ? 2 : 3] = TRUE;
            game.scanner[i < 0 ? 3 : 2] = FALSE;
         }
      }
   }
}
void serpendPositionGenerator(Position *pos)
{
   do
   {
      pos->x = rand() % largeur;
      pos->y = rand() % hauteur;

   } while (game.map.colonne[pos->y].cellule[pos->x].type[0] != 'v');
}

void moveSerpend()
{
   Sleep(200);
   int x = 0, y = 0;
   List *currentCell;
   switch (game.direction)
   {
   case HAUT:
      y--;
      break;
   case BAS:
      y++;
      break;
   case GAUCHE:
      x--;
      break;
   case DROITE:
      x++;
      break;
   default:
      break;
   }
   // Update the position of the snake's head
   int newX = game.serpent->cellule->pos.x + x;
   int newY = game.serpent->cellule->pos.y + y;
   verifySerpend(newX, newY);
   if (strcmp(game.gameState, "game") == FALSE)
   {
      if (game.serpent->suivant != NULL)
      {
         // Update the position of the snake's body
         currentCell = game.reverseSerpent;
         while (currentCell->precedent != NULL)
         {
            if (currentCell == game.reverseSerpent)
            {
               strcpy_s(game.reverseSerpent->cellule->type, 100, "v");
            }

            List *nextCell = currentCell->precedent;
            currentCell->cellule = currentCell->precedent->cellule;
            strcpy_s(currentCell->cellule->type, 100, "s");
            currentCell = nextCell;
         }
      }
      // strcpy_s(game.serpent->cellule->type, 100, "v");
      else {
         strcpy_s(game.serpent->cellule->type, 100, "v");
      }
      game.serpent->cellule = &game.map.colonne[newY].cellule[newX];
      strcpy_s(game.serpent->cellule->type, 100, "S");
   }
}

void verifySerpend(int newX, int newY)
{

   if (strcmp(game.map.colonne[newY].cellule[newX].type, "m") == FALSE)
   {
      SDL_Delay(3000);
      strcpy_s(game.gameState, 10, "gameover");
      // fonctionne = FALSE;
   }
   else if (strcmp(game.map.colonne[newY].cellule[newX].type, "s") == FALSE)
   {
      SDL_Delay(3000);
      strcpy_s(game.gameState, 10, "gameover");
      // fonctionne = FALSE;
   }
   else if (strcmp(game.map.colonne[newY].cellule[newX].type, "p") == FALSE)
   {
      growSerpend();
      game.currentPommes--;
      game.score++;
      game.config.vitesse = game.config.vitesse - 10;
   }
   else if (strcmp(game.map.colonne[newY].cellule[newX].type, "P") == FALSE)
   {
      growSerpend();
      growSerpend();
      game.score = game.score + 4;
      game.currentPommes--;
      game.config.vitesse = game.config.vitesse - 20;
   }
   if(game.currentPommes == 0){
      pommeAdd();
   }
   // if (game.serpent->suivant != NULL)
   // {
   //    List *currentCell = game.serpent->suivant;
   //    while (currentCell->suivant != NULL)
   //    {
   //       if (currentCell->cellule->pos.x == game.serpent->cellule->pos.x && currentCell->cellule->pos.y == game.serpent->cellule->pos.y)
   //       {
   //          printf("perdu\n");
   //          fonctionne = FALSE;
   //          break;
   //       }
   //       currentCell = currentCell->suivant;
   //    }
   // }
}