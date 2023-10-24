void initialisation(void)
{
   SDL_SetRenderDrawColor(game.render, 30, 30, 30, 255);
   SDL_RenderClear(game.render);
   printf("Map initialisation\n");
   printf("hauteur : %d\n", hauteur);
   printf("largeur: %d\n", largeur);
   game.selected = FALSE;
   game.currentPommes = pommeNumber;
   game.playeur.score = 0;
   strcpy_s(game.playeur.name, 100, "player 1");
   game.previousGameDirection = 0;
   game.direction = 0;
   game.gameStart = FALSE;
   game.config.difficulte = difficulte;
   game.config.mode[mode - 1] = 1;
   game.config.musique[musique - 1] = 1;
   game.config.taille[taille - 1] = 1;
   game.choix = 0;
   game.currentOption = 0;
   game.subOption = jouer;
   List *serpent = creeList();
   game.serpent = serpent;
   game.isChange = TRUE;
   strcpy_s(game.gameState, 100, "menu");
   if (game.bestPlayeur.score == NULL || game.bestPlayeur.score == 0)
   {
      printf("best score : %d\n", game.bestPlayeur.score);
      lireScore();
   }
   constructMap();
   addSerpend();
   pommeAdd();
}
void restart(void)
{
   SDL_SetRenderDrawColor(game.render, 30, 30, 30, 255);
   SDL_RenderClear(game.render);
   printf("Map initialisation\n");
   printf("hauteur : %d\n", hauteur);
   printf("largeur: %d\n", largeur);
   game.currentPommes = pommeNumber;
   game.playeur.score = 0;
   strcpy_s(game.playeur.name, 100, "player 1");
   game.direction = 0;
   *supprimerList(game.serpent);
   List *serpent = creeList();
   game.serpent = serpent;
   constructMap();
   addSerpend();
   pommeAdd();
}

void constructMap(void)
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
         game.map.colonne[c].cellule[l].surface = NULL;
         game.map.colonne[c].cellule[l].texture = NULL;
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