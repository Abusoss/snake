void initialisation(SDL_Renderer *render)
{
   SDL_SetRenderDrawColor(render, 30, 30, 30, 255);
   SDL_RenderClear(render);
   printf("Map initialisation\n");
   printf("hauteur : %zu\n", sizeof(game.map) / sizeof(game.map.colonne[0]));
   printf("largeur: %zu\n", sizeof(game.map.colonne[0]) / sizeof(game.map.colonne[0].cellule[0]));
   game.selected = FALSE;
   game.currentPommes = pommeNumber;
   game.score = 0;
   game.previousDirection = 0;
   game.direction = 0;
   game.currentOption = 0;
   strcpy_s(game.gameState, 100, "menu");
   game.config.vitesse = vitesse;
   game.config.difficulte[difficulte - 1] = 1;
   game.config.mode[mode - 1] = 1;
   game.config.musique[musique - 1] = 1;
   game.config.taille[taille - 1] = 1;
   constructMap();
   List *serpent = creeList();
   game.serpent = serpent;
}

void constructMap()
{

   // TODO: ICI

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

