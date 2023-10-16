// ----------------- MENU -----------------
void start(SDL_Renderer *render, TTF_Font *police, SDL_Window *window)
{
   police = TTF_OpenFont("./police.ttf", 58); // this opens a font style and sets a size
   char mode[5] = "menu";
   BOOLEAN change = TRUE;
   BOOLEAN selected = FALSE;
   while (fonctionne)
   {
      actions(&change, &selected);
      if (strcmp(mode, "menu") == FALSE)
      {
         // do something
         menu(&selected, &change, mode, render, police, window);
      }
      else if (strcmp(mode, "game") == FALSE)
      {
         // do something else
         printf("game\n");
         // gameGenerator(&change, render, police, window);
      }
      // pommeAdd();
      // array 3 position
      // position par defaut 0 = number
      // move increase or decrease(if not 0) number
      // when press enter and number = 0 jouer else if number = 1 options else if number = 2 quitter
      SDL_Delay(10);
   };
   TTF_CloseFont(police);
}