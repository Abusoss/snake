void SplashScreen(char *text)
{
   game.police = TTF_OpenFont("./police.ttf", taillePoliceSplash);
   if (game.police == NULL)
   {
      printf("police : %s\n", SDL_GetError());
      fonctionne = FALSE;
      return;
   }

   Uint8 alpha = 255;
   SDL_Color fontColor = {255, 255, 255, alpha};

   while (alpha > 0)
   {
      SDL_SetRenderDrawColor(game.render, 30, 30, 30, 255);
      SDL_RenderClear(game.render);

      fontColor.a = alpha;
      SDL_Surface *surfaceMessage = TTF_RenderText_Blended(game.police, text, fontColor);
      if (surfaceMessage == NULL)
      {
         printf("surfaceMessage : %s\n", SDL_GetError());
         fonctionne = FALSE;
         return;
      }

      SDL_Texture *Message = SDL_CreateTextureFromSurface(game.render, surfaceMessage);
      if (Message == NULL)
      {
         printf("Message : %s\n", SDL_GetError());
         fonctionne = FALSE;
         return;
      }

      SDL_Rect Message_rect = {
          .x = windowWidth / 2 - surfaceMessage->w / 2,
          .y = windowHeight / 2 - surfaceMessage->h / 2,
          .w = surfaceMessage->w,
          .h = surfaceMessage->h};

      SDL_RenderCopy(game.render, Message, NULL, &Message_rect);
      SDL_DestroyTexture(Message);
      SDL_FreeSurface(surfaceMessage);
      SDL_RenderPresent(game.render);

      if (alpha == 255)
      {
         SDL_Delay(3000);
      }

      alpha -= 5;
   }
}