void menu(SDL_Renderer *render, TTF_Font *police, SDL_Window *window)
{
   police = TTF_OpenFont("./police.ttf", taillePoliceMenu); // this opens a font style and sets a size
   int choix = 0;
   int subOption = jouer;
   while (fonctionne && strcmp(game.gameState, "menu") == FALSE)
   {
      actions();
      // printMap();
      // printf("%d\n", option);
      // printf("%s\n", change ? TRUE : FALSE);
      if (game.isChange == TRUE && game.selected == FALSE)
      {
         if (game.direction == HAUT)
         {
            if (game.currentOption > 0)
            {
               game.currentOption = game.currentOption - 1;
            }
         }
         else if (game.direction == BAS)
         {
            if (game.currentOption < 2)
            {
               game.currentOption = game.currentOption + 1;
            }
         }
         menuGenerator(render, police, window);
         game.isChange = FALSE;
         /* code */
      }
      // move(menu, game.currentOption, &selected);
      // printf("%d\n", selected);
      if (game.selected != FALSE)
      {
         /* code */
         choix = game.currentOption;
         switch (choix)
         {
         case 0:
            strcpy_s(game.gameState, 100, "game");
            break;
         case 1:
            strcpy_s(game.gameState, 100, "options");
            /* code */
            break;
         case 2:
            fonctionne = FALSE;
            // quitterWindow(render, police, window);
            /* code */
            break;
         }
      }
      /* code */
   }
}

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
         Message_rect.h = surfaceMessage->h;                                                              // controls the height of the rect
         // printf("largeur : %d\n", surfaceMessage->w);
         // printf("hauteur : %d\n", Message_rect.h);
         // Message_rect.w = surfaceMessage->w;  // controls the width of the rect
         // Message_rect.h = surfaceMessage->h;  // controls the height of the rect
         SDL_RenderCopy(render, Message, NULL, &Message_rect);
         SDL_DestroyTexture(Message);
         SDL_FreeSurface(surfaceMessage);
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