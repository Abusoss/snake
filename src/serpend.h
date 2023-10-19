void addSerpend(void)
{
   Position unePos = {0, 0};
   //
   serpendPositionGenerator(&unePos);
   game.map.colonne[unePos.y].cellule[unePos.x].type[0] = 'S';
   ajoutA(game.serpent, game.map.colonne[unePos.y].cellule[unePos.x], 0);
}
void growSerpend(void)
{
   // printf("col -1 : %c\n", game.map.colonne[game.reverseSerpent->cellule.pos.y - 1].cellule[game.reverseSerpent->cellule.pos.x].type[0]);
   // printf("col +1 : %c\n", game.map.colonne[game.reverseSerpent->cellule.pos.y + 1].cellule[game.reverseSerpent->cellule.pos.x].type[0]);
   // printf("cellule -1 : %c\n", game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x -1].type[0]);
   // printf("cellule +1 : %c\n", game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x +1].type[0]);
   int rnd = 0;
   for (size_t i = 0; i < sizeof(game.scanner) / sizeof(game.scanner[0]); i++)
   {
      game.scanner[i] = FALSE;
   }
   scanSerpend(2);

   // if (isOk[0] == FALSE && isOk[1] == FALSE && isOk[2] == FALSE && isOk[3] == FALSE)
   // {
   //    printf("GAME OVER\n");
   //    game.gameState = GAMEOVER;
   // }

   do
   {
      rnd = rand() % 4;
   } while (game.scanner[rnd] == FALSE);
   game.direction = rnd+1;
   switch (rnd)
   {
   case 0:
      strcpy_s(game.map.colonne[game.reverseSerpent->cellule.pos.y - 1].cellule[game.reverseSerpent->cellule.pos.x].type, 8, "s");
      printf("type : %s\n", game.map.colonne[game.reverseSerpent->cellule.pos.y -1].cellule[game.reverseSerpent->cellule.pos.x ].type);
      ajouterFinA(game.reverseSerpent, game.map.colonne[game.reverseSerpent->cellule.pos.y - 1].cellule[game.reverseSerpent->cellule.pos.x], 0);
      printf("type 2: %s\n", game.map.colonne[game.reverseSerpent->cellule.pos.y -1].cellule[game.reverseSerpent->cellule.pos.x ].type);
      break;
   case 1:
      strcpy_s(game.map.colonne[game.reverseSerpent->cellule.pos.y + 1].cellule[game.reverseSerpent->cellule.pos.x].type, 8, "s");
      printf("type : %s\n", game.map.colonne[game.reverseSerpent->cellule.pos.y +1].cellule[game.reverseSerpent->cellule.pos.x ].type);
      ajouterFinA(game.reverseSerpent, game.map.colonne[game.reverseSerpent->cellule.pos.y + 1].cellule[game.reverseSerpent->cellule.pos.x], 0);
      printf("type 2: %s\n", game.map.colonne[game.reverseSerpent->cellule.pos.y +1].cellule[game.reverseSerpent->cellule.pos.x ].type);
      break;
   case 2:
      strcpy_s(game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x - 1].type, 8, "s");
      printf("type : %s\n", game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x - 1].type);
      ajouterFinA(game.reverseSerpent, game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x - 1], 0);
      printf("type 2: %s\n", game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x - 1].type);
      break;
   case 3:
      strcpy_s(game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x + 1].type, 8, "s");
      //print type
      printf("type : %s\n", game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x + 1].type);
      ajouterFinA(game.reverseSerpent, game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x + 1], 0);
      printf("type 2: %s\n", game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x + 1].type);
      break;

   default:
      break;
   }
}
void removeQueueSerpend()
{
}

void scanSerpend(int mode)
{
   switch (mode)
   {
   case 1:
      if (game.map.colonne[game.reverseSerpent->cellule.pos.y - 1].cellule[game.reverseSerpent->cellule.pos.x].type[0] == 'v')
      {
         game.scanner[0] = TRUE;
      }
      if (game.map.colonne[game.reverseSerpent->cellule.pos.y + 1].cellule[game.reverseSerpent->cellule.pos.x].type[0] == 'v')
      {
         /* code */
         game.scanner[1] = TRUE;
      }
      if (game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x - 1].type[0] == 'v')
      {
         game.scanner[2] = TRUE;
      }
      if (game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x + 1].type[0] == 'v')
      {
         /* code */
         game.scanner[3] = TRUE;
      }



      game.scanner[0] == FALSE ? game.scanner[1] = FALSE: NULL;
      game.scanner[1] == FALSE ? game.scanner[0] = FALSE: NULL;
      game.scanner[2] == FALSE ? game.scanner[3] = FALSE: NULL;
      game.scanner[3] == FALSE ? game.scanner[2] = FALSE: NULL;
      break;
   case 2:
      if (game.map.colonne[game.reverseSerpent->cellule.pos.y - 2].cellule[game.reverseSerpent->cellule.pos.x].type[0] == 'v')
      {
         game.scanner[0] = TRUE;
      }
      if (game.map.colonne[game.reverseSerpent->cellule.pos.y + 2].cellule[game.reverseSerpent->cellule.pos.x].type[0] == 'v')
      {
         /* code */
         game.scanner[1] = TRUE;
      }
      if (game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x - 2].type[0] == 'v')
      {
         game.scanner[2] = TRUE;
      }
      if (game.map.colonne[game.reverseSerpent->cellule.pos.y].cellule[game.reverseSerpent->cellule.pos.x + 2].type[0] == 'v')
      {
         /* code */
         game.scanner[3] = TRUE;
      }

      game.scanner[0] == FALSE ? game.scanner[1] = FALSE: NULL;
      game.scanner[1] == FALSE ? game.scanner[0] = FALSE: NULL;
      game.scanner[2] == FALSE ? game.scanner[3] = FALSE: NULL;
      game.scanner[3] == FALSE ? game.scanner[2] = FALSE: NULL;
      break;
   default:
      break;
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

void moveSerpend(BOOLEAN *change)
{
   long tailleSerpend = tailleList(game.serpent);
   // printf("taille : %ld\n", tailleSerpend);

   // while (tailleSerpend-1 >= 0)
   // {
   //    game.map.colonne[game.serpent->cellule.pos.y].cellule[game.serpent->cellule.pos.x].type[0] = 'v';
   //    // if (tailleSerpend-1 != 0)
   //    // {
   //    //    game.serpent->cellule.pos.x = game.serpent->precedent->cellule.pos.x;
   //    //    game.serpent->cellule.pos.y = game.serpent->precedent->cellule.pos.y;
   //    //    game.serpent->cellule.type[0] = game.serpent->precedent->cellule.type[0];
   //    //    /* code */
   //    //    game.map.colonne[game.serpent->cellule.pos.y].cellule[game.serpent->cellule.pos.x].type[0] = 's';
   //    // }
   //    // else
   //    // {
   //       switch (game.direction)
   //       {
   //       case HAUT:
   //          if (game.previousDirection != BAS)
   //          {
   //             game.serpent->cellule = game.map.colonne[game.serpent->cellule.pos.y - 1].cellule[game.serpent->cellule.pos.x];
   //          }
   //          break;
   //       case BAS:
   //          if (game.previousDirection != HAUT)
   //          {
   //             game.serpent->cellule = game.map.colonne[game.serpent->cellule.pos.y + 1].cellule[game.serpent->cellule.pos.x];
   //          }
   //          break;
   //       case GAUCHE:
   //          if (game.previousDirection != DROITE)
   //          {
   //             game.serpent->cellule = game.map.colonne[game.serpent->cellule.pos.y].cellule[game.serpent->cellule.pos.x - 1];
   //          }
   //          break;
   //       case DROITE:
   //          if (game.previousDirection != GAUCHE)
   //          {
   //             game.serpent->cellule = game.map.colonne[game.serpent->cellule.pos.y].cellule[game.serpent->cellule.pos.x + 1];
   //          }
   //          break;
   //       default:
   //          break;
   //       }
   //       game.map.colonne[game.serpent->cellule.pos.y].cellule[game.serpent->cellule.pos.x].type[0] = 'S';
   //    // }

   //    game.serpent = game.serpent->precedent;
   //    tailleSerpend--;
   // }
   // *change = TRUE;
}