void start(SDL_Renderer *render, TTF_Font *police, SDL_Window *window)
{
   game.isChange = TRUE;
   BOOLEAN selected = FALSE;
   int option = jouer;
   while (fonctionne)
   {
      actions();
      if (strcmp(game.gameState, "menu") == FALSE)
      {
         // do something
         menu( render, police, window);
      }
      else if (strcmp(game.gameState, "game") == FALSE)
      {
         // do something else

         gameStart(render, police,window);
         // gameGenerator(&change, render, police, window);
      }else if(strcmp(game.gameState, "gameover") == FALSE){
         supprimerList(game.serpent);
         char *title = "GAME OVER";
         SplashScreen(render, police, window, title);
         initialisation(render);
      }
      else if (strcmp(game.gameState, "options") == FALSE)
      {
         // do something else
         printf("options\n");
         // options(&selected, &change, render, police, window);
      }
      // pommeAdd();
      // array 3 position
      // position par defaut 0 = number
      // move increase or decrease(if not 0) number
      // when press enter and number = 0 jouer else if number = 1 options else if number = 2 quitter
      // SDL_Delay(10);
   };
   TTF_CloseFont(police);
}