void initWindow(void)
{
   // (windowWidth - windowWidth * (marge / 100)) / largeur)
   game.window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
   if (game.window == NULL)
   {
      printf("Could not create window: %s\n", SDL_GetError());
      fonctionne = FALSE;
   }
   printf("Window created !!!\n");
   // ---------------- Init render
   game.render = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if (game.render == NULL)
   {
      printf("Could not create render: %s\n", SDL_GetError());
      fonctionne = FALSE;
   }
   printf("Render created !!!\n");
}

void quitterWindow()
{
   *supprimerList(game.serpent);
   SDL_DestroyRenderer(game.render);
   SDL_DestroyWindow(game.window);
   TTF_CloseFont(game.police);

   TTF_Quit();
   SDL_Quit();
}