void menu(void)
{
   if (!game.police)
   {
      game.police = TTF_OpenFont("./police.ttf", taillePoliceMenu);
   }

   if (game.isChange == TRUE && game.selected == FALSE)
   {
      if (game.direction == HAUT && game.currentOption > 0)
      {
         game.currentOption--;
      }
      else if (game.direction == BAS && game.currentOption < (game.gameStart ? 3 : 2))
      {
         game.currentOption++;
      }

      menuGenerator();
      game.isChange = FALSE;
   }
   if (game.selected != FALSE)
   {
      game.choix = game.currentOption;
      if (game.gameStart)
      {
         switch (game.choix)
         {
         case 0:
            strcpy_s(game.gameState, 100, "game");
            game.direction = game.previousGameDirection;
            TTF_CloseFont(game.police);
            game.police = NULL;
            break;
         case 1:
            strcpy_s(game.gameState, 100, "game");
            restart();
            game.gameStart = FALSE;
            TTF_CloseFont(game.police);
            game.police = NULL;
            break;
         case 2:
            strcpy_s(game.gameState, 100, "options");
            break;
         case 3:
            fonctionne = FALSE;
            TTF_CloseFont(game.police);
            game.police = NULL;
            break;
         }
      }
      else
      {
         switch (game.choix)
         {
         case 0:
            strcpy_s(game.gameState, 100, "game");
            TTF_CloseFont(game.police);
            game.police = NULL;
            break;
         case 1:
            strcpy_s(game.gameState, 100, "options");
            break;
         case 2:
            fonctionne = FALSE;
            TTF_CloseFont(game.police);
            game.police = NULL;
            break;
         }
      }
   }
}

void menuGenerator(void)
{
   SDL_SetRenderDrawColor(game.render, 30, 30, 30, 255);
   SDL_RenderClear(game.render);
   SDL_Color fontColor = {255, 255, 255, 255};
   SDL_Surface *surfaceMessage = NULL;
   SDL_Texture *Message = NULL;
   SDL_Rect Message_rect = {0, 0, 0, 0};
   size_t numTitles = game.gameStart ? sizeof(continueMenuTitles) / sizeof(continueMenuTitles[0]) : sizeof(menuTitles) / sizeof(menuTitles[0]);
   for (size_t i = 0; i < numTitles; i++)
   {
      if (game.currentOption == i)
      {
         TTF_SetFontStyle(game.police, TTF_STYLE_UNDERLINE);
      }
      else
      {
         TTF_SetFontStyle(game.police, TTF_STYLE_NORMAL);
      }
      const char *title = game.gameStart ? continueMenuTitles[i] : menuTitles[i];
      surfaceMessage = TTF_RenderText_Blended(game.police, title, fontColor);
      if (surfaceMessage == NULL)
      {
         printf("surfaceMessage : %s\n", SDL_GetError());
         fonctionne = FALSE;
         return;
      }
      Message = SDL_CreateTextureFromSurface(game.render, surfaceMessage);
      if (Message == NULL)
      {
         printf("Message : %s\n", SDL_GetError());
         fonctionne = FALSE;
         return;
      }
      Message_rect.x = (windowWidth / 2) - (surfaceMessage->w / 2);
      Message_rect.y = windowHeight / 2 - (surfaceMessage->h * 3) / 2 + i * surfaceMessage->h + i * 1;
      Message_rect.w = surfaceMessage->w;
      Message_rect.h = surfaceMessage->h;
      SDL_RenderCopy(game.render, Message, NULL, &Message_rect);
      SDL_DestroyTexture(Message);
      SDL_FreeSurface(surfaceMessage);
   }
}