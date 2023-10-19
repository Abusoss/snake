void menu(BOOLEAN *selected, BOOLEAN *change, char *mode, SDL_Renderer *render, TTF_Font *police, SDL_Window *window)
{
   police = TTF_OpenFont("./police.ttf", taillePoliceMenu); // this opens a font style and sets a size
   int choix = 0;
   int subOption = jouer;
   // printMap();
   // printf("%d\n", option);
   // printf("%s\n", change ? TRUE : FALSE);
   if (*change == TRUE)
   {
      if (game.direction == HAUT)
      {
            printf("minus: %d\n", game.currentOption);
         if (game.currentOption > 0)
         {
            printf("minus: %d\n", game.currentOption);
            game.currentOption--;
         }
      }
      else if (game.direction == BAS)
      {
         printf("first: %d\n", game.currentOption);
         if (game.currentOption < 2)
         {
            printf("before: %d\n", game.currentOption);
            game.currentOption++;
            printf("after: %d\n", game.currentOption);
         }
      }
      menuGenerator(render, police, window);
      *change = FALSE;
      /* code */
   }
   // move(menu, game.currentOption, &selected);
   // printf("%d\n", selected);
   if (*selected != FALSE)
   {
      /* code */
      choix = game.currentOption;
      switch (choix)
      {
      case 0:
         strcpy(mode, "game");
         break;
      case 1:
         /* code */
         break;
      case 2:
         printf("%d\n", fonctionne);
         printf("quitter\n");
         fonctionne = FALSE;
         printf("%d\n", fonctionne);
         // quitterWindow(render, police, window);
         /* code */
         break;
      }
   }
}

// ----------------- MENUGENERATOR -----------------

void menuGenerator(SDL_Renderer *render, TTF_Font *police, SDL_Window *window)
{
   // Uint32 frameStart = SDL_GetTicks();
   SDL_SetRenderDrawColor(render, 30, 30, 30, 255); // clear the renderer to the draw color
   SDL_RenderClear(render);
   SDL_Color fontColor = {255, 255, 255, 255};
   SDL_Surface *surfaceMessage = NULL;
   SDL_Texture *Message = NULL;
   SDL_Rect Message_rect = {0, 0, 0, 0};
   // printf("%d\n", game.currentOption);
   if (game.currentOption <= 2)
   {
      for (size_t i = 0; i < (sizeof(menuTitle) / sizeof(menuTitle[0])) - 6; i++)
      {
         // SDL_SetRenderDrawColor(render, 30, 30, 30, 255); // clear the renderer to the draw color
         // SDL_RenderClear(render);
         if (game.currentOption == i)
         {
            TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
         }
         else
         {
            TTF_SetFontStyle(police, TTF_STYLE_NORMAL);
         }
         surfaceMessage = TTF_RenderText_Blended(police, menuTitle[i], fontColor);
         if (surfaceMessage == NULL)
         {
            printf("surfaceMessage : %s\n", SDL_GetError());
            fonctionne = FALSE;
            // return FALSE;
         }
         Message = SDL_CreateTextureFromSurface(render, surfaceMessage);
         if (Message == NULL)
         {
            printf("Message : %s\n", SDL_GetError());
            fonctionne = FALSE;
            // return FALSE;
         }
         // printf("Message created !!!");                                                          // create a rect
         Message_rect.x = (windowWidth / 2) - (surfaceMessage->w / 2);                                    // controls the rect's x coordinate
         Message_rect.y = windowHeight / 2 - (surfaceMessage->h * 3) / 2 + i * surfaceMessage->h + i * 1; // controls the rect's y coordinte
         Message_rect.w = surfaceMessage->w;                                                              // controls the width of the rect
         Message_rect.h = surfaceMessage->h;                          // controls the height of the rect
         // printf("largeur : %d\n", surfaceMessage->w);
         // printf("hauteur : %d\n", Message_rect.h);
         // Message_rect.w = surfaceMessage->w;  // controls the width of the rect
         // Message_rect.h = surfaceMessage->h;  // controls the height of the rect
         SDL_RenderCopy(render, Message, NULL, &Message_rect);
      }
      SDL_RenderPresent(render);
   }
   else
   {
      for (size_t i = (sizeof(menuTitle) / sizeof(menuTitle[0])) - 6; i < sizeof(menuTitle) / sizeof(menuTitle[0]); i++)
      {
         // code here
      }
   }
   SDL_DestroyTexture(Message);
   /* code */
   // lstrlenA determine la longueur d'une chaîne de caractère
}