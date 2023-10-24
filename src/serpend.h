void addSerpend(void)
{
   Position unePos = {0, 0};
   serpendPositionGenerator(&unePos);
   game.direction = scanSerpend(2, unePos);

   ajoutA(game.serpent, &game.map.colonne[unePos.y].cellule[unePos.x], 0);
   strcpy_s(game.serpent->cellule->type, 100, "S");
}

void growSerpend(void)
{
   int x = game.reverseSerpent->cellule->pos.x;
   int y = game.reverseSerpent->cellule->pos.y;
   int rnd = scanSerpend(1, game.reverseSerpent->cellule->pos);

   switch (rnd)
   {
   case 1:
      ajouterFinA(game.reverseSerpent, &game.map.colonne[y - 1].cellule[x], 0);
      strcpy_s(game.reverseSerpent->cellule->type, 100, "s");
      break;
   case 2:
      ajouterFinA(game.reverseSerpent, &game.map.colonne[y + 1].cellule[x], 0);
      strcpy_s(game.reverseSerpent->cellule->type, 100, "s");
      break;
   case 3:
      ajouterFinA(game.reverseSerpent, &game.map.colonne[y].cellule[x - 1], 0);
      strcpy_s(game.reverseSerpent->cellule->type, 100, "s");
      break;
   case 4:
      ajouterFinA(game.reverseSerpent, &game.map.colonne[y].cellule[x + 1], 0);
      strcpy_s(game.reverseSerpent->cellule->type, 100, "s");
      break;
   }
}

// TODO: dans functions.h, dans la fonction constructMap() malloc toute les cellules, dans decla cellule de map sera un poiteur vers chaque cellule de la map, comme ca quand je growSerpent() et cache cell du serpent aura un  pointeur "cellule" vers une cellule

int scanSerpend(int range, Position pos)
{
   int y = pos.y;
   int x = pos.x;
   BOOLEAN scanner[4] = {FALSE, FALSE, FALSE, FALSE};

   for (int i = -range; i <= range; i++)
   {
      if (i == 0)
         continue;
      if (y + i > 0 && y + i < hauteur)
      {
         if (strcmp(game.map.colonne[y + i].cellule[x].type, "v") == 0)
         {
            scanner[i < 0 ? 0 : 1] = TRUE;
         }
         else
         {
            scanner[i < 0 ? 0 : 1] = FALSE;
         }
      }
      if (x + i > 0 && x + i < largeur)
      {
         if (strcmp(game.map.colonne[y].cellule[x + i].type, "v") == 0)
         {
            scanner[i < 0 ? 2 : 3] = TRUE;
         }
         else
         {
            scanner[i < 0 ? 2 : 3] = FALSE;
         }
      }
   }

   int rnd = 0;
   printf("scanner : \n");
   for (size_t i = 0; i <= 3; i++)
   {
      printf("scanner %d: %d\n", i, scanner[i]);
   }

   do
   {
      rnd = rand() % 4;
   } while (scanner[rnd] == FALSE);

   return rnd + 1;
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
   SDL_Delay(16.333 * 2); /* TODO: A voir si on garde le delai */
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
               if (strcmp(game.reverseSerpent->cellule->type, "m") == TRUE || strcmp(game.reverseSerpent->cellule->type, "p") == TRUE || strcmp(game.reverseSerpent->cellule->type, "P") == TRUE)
               {
                  strcpy_s(game.reverseSerpent->cellule->type, 100, "v");
               }
            }

            List *nextCell = currentCell->precedent;
            currentCell->cellule = currentCell->precedent->cellule;
            strcpy_s(currentCell->cellule->type, 100, "s");
            currentCell = nextCell;
         }
      }
      else
      {
         strcpy_s(game.serpent->cellule->type, 100, "v");
      }
      game.serpent->cellule = &game.map.colonne[newY].cellule[newX];
      strcpy_s(game.serpent->cellule->type, 100, "S");
   }
}

void verifySerpend(int newX, int newY)
{

   if (strcmp(game.map.colonne[newY].cellule[newX].type, "m") == FALSE || strcmp(game.map.colonne[newY].cellule[newX].type, "s") == FALSE)
   {
      SDL_Delay(3000);
      strcpy_s(game.gameState, 10, "gameover");
   }
   else if (strcmp(game.map.colonne[newY].cellule[newX].type, "p") == FALSE)
   {
      growSerpend();
      game.currentPommes--;
      game.playeur.score++;
      if (game.config.vitesse > difficultyValue[game.config.difficulte - 1])
      {
         /* code */
         game.config.vitesse = ceil(game.config.vitesse / 1.1);
      }
      if (game.config.vitesse < difficultyValue[game.config.difficulte - 1])
      {
         game.config.vitesse = difficultyValue[game.config.difficulte - 1];
      }
   }
   else if (strcmp(game.map.colonne[newY].cellule[newX].type, "P") == FALSE)
   {
      growSerpend();
      growSerpend();
      game.playeur.score = game.playeur.score + 4;
      game.currentPommes--;
      game.config.vitesse = game.config.vitesse - 20;
      if (game.config.vitesse > difficultyValue[game.config.difficulte - 1])
      {
         /* code */
         game.config.vitesse = ceil(game.config.vitesse / 1.2);
      }
      if (game.config.vitesse < difficultyValue[game.config.difficulte - 1])
      {
         game.config.vitesse = difficultyValue[game.config.difficulte - 1];
      }
   }
   if (game.currentPommes == 0)
   {
      pommeAdd();
   }
}