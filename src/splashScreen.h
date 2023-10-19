void SplashScreen(SDL_Renderer *render, TTF_Font *police, SDL_Window *window)
{
   police = TTF_OpenFont("./police.ttf", taillePoliceSplash); // this opens a font style and sets a size
   if (police == NULL)
   {
      printf("police : %s\n", SDL_GetError());
      fonctionne = FALSE;
   }
   printf("Police created !!!\n");
   BOOLEAN delay = FALSE;
   Uint8 alpha = 255;
   SDL_Color fontColor = {255, 255, 255, alpha};
   // printf("Surface created !!!");
   while (alpha > 0)
   {
      SDL_SetRenderDrawColor(render, 30, 30, 30, 255); // clear the renderer to the draw color
      SDL_RenderClear(render);
      fontColor.a = alpha;
      SDL_Surface *surfaceMessage = TTF_RenderText_Blended(police, "SNAKE", fontColor);
      if (surfaceMessage == NULL)
      {
         printf("surfaceMessage : %s\n", SDL_GetError());
         fonctionne = FALSE;
         // return FALSE;
      }
      SDL_Texture *Message = SDL_CreateTextureFromSurface(render, surfaceMessage);
      if (Message == NULL)
      {
         printf("Message : %s\n", SDL_GetError());
         fonctionne = FALSE;
         // return FALSE;
      }
      // printf("Message created !!!");

      SDL_Rect Message_rect;                            // create a rect
      Message_rect.x = windowWidth / 2 - surfaceMessage->w / 2; // controls the rect's x coordinate
      Message_rect.y = windowHeight / 2 - surfaceMessage->h / 2; // controls the rect's y coordinte
      Message_rect.w = surfaceMessage->w;               // controls the width of the rect
      Message_rect.h = surfaceMessage->h;               // controls the height of the rect
      // printf("largeur : %d\n", surfaceMessage->w);
      // printf("hauteur : %d\n", Message_rect.h);
      // Message_rect.w = surfaceMessage->w;  // controls the width of the rect
      // Message_rect.h = surfaceMessage->h;  // controls the height of the rect
      SDL_RenderCopy(render, Message, NULL, &Message_rect);
      SDL_RenderPresent(render);
      if (!delay)
      {
         SDL_Delay(3000);
         delay = TRUE;
      }
      alpha -= 5;
      /* code */
   }
   TTF_CloseFont(police);
}