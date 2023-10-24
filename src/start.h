void start(void)
{
   while (fonctionne)
   {
      actions();
      if (strcmp(game.gameState, "menu") == FALSE)
      {
         menu();
      }
      else if (strcmp(game.gameState, "game") == FALSE)
      {
         gameFn();
         actions();
      }
      else if (strcmp(game.gameState, "gameover") == FALSE)
      {
         supprimerList(game.serpent);
         SplashScreen("GAME OVER");
         TTF_CloseFont(game.police);
         game.police = NULL;
         saveScore();
         initialisation();
      }
      else if (strcmp(game.gameState, "options") == FALSE)
      {
         printf("options\n");
         // options(render, police, window);
      }
      SDL_RenderPresent(game.render);
      SDL_Delay(strcmp(game.gameState, "game") == FALSE ?  game.config.vitesse : 0);
   }
   TTF_CloseFont(game.police);
}