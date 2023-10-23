void gameStart(SDL_Renderer *render, TTF_Font *police, SDL_Window *window)
{
   police = TTF_OpenFont("./police.ttf", taillePoliceGame); // this opens a font style and sets a size
   game.isChange = TRUE;
   pommeAdd();
   addSerpend();
   // TODO: ajouter une fonction qui grandit le serpent
   // gameGenerator(render, police, window);
   while (fonctionne && strcmp(game.gameState, "game") == FALSE)
   {
      gameGenerator(render, police, window);
      actions();
      SDL_Delay(game.config.vitesse);
      moveSerpend();
      // if (change)
      // {
      //    change = FALSE;
      // }
   }
}

void gameGenerator(SDL_Renderer *render, TTF_Font *police, SDL_Window *window)
{
   SDL_SetRenderDrawColor(render, 30, 30, 30, 255);
   SDL_RenderClear(render);
   SDL_Color fontColor = {255, 255, 255, 255};
   SDL_Rect Message_rect = {0, 0, 0, 0};
   Position pos = {};
   // game.direction = rand() % 3 + 1;

   for (int c = 0; c < hauteur; c++)
   {
      for (int l = 0; l < largeur; l++)
      {
         pos.x = l;
         pos.y = c;
         int componentIndex = -1;

         switch (game.map.colonne[c].cellule[l].type[0])
         {
         case 'm':
            componentIndex = (l == 0 || l == largeur - 1) ? 3 : 4;
            break;
         case 'v':
            componentIndex = 2;
            break;
         case 's':
            componentIndex = 6;
            break;
         case 'S':
            componentIndex = 5;
            break;
         case 'p':
            componentIndex = 0;
            break;
         case 'P':
            componentIndex = 1;
            break;
         default:
            break;
         }

         if (componentIndex >= 0)
         {
            renderComponent(pos, composants[componentIndex], police, fontColor, render, game.map.colonne[c].cellule[l].surface, game.map.colonne[c].cellule[l].texture, Message_rect);
         }
      }
   }

   SDL_RenderPresent(render);
}

void renderComponent(Position pos, Uint16 text, TTF_Font *police, SDL_Color fontColor, SDL_Renderer *render, SDL_Surface *surfaceMessage, SDL_Texture *Message, SDL_Rect Message_rect)
{
   Uint16 textStr[2] = {text, '\0'};
   surfaceMessage = TTF_RenderUNICODE_Blended(police, textStr, fontColor);
   int width;  // largeur du texte réellement
   int height; // hauteur du texte réellement
   TTF_SizeUNICODE(police, textStr, &width, &height);
   if (surfaceMessage == NULL || (Message = SDL_CreateTextureFromSurface(render, surfaceMessage)) == NULL)
   {
      printf("Error: %s\n", SDL_GetError());
      fonctionne = FALSE;
      return;
   }
   Message_rect = (SDL_Rect){
       .x = pos.x * taillePoliceGame + round((taillePoliceGame - width) / 2),
       .y = pos.y * taillePoliceGame,
       .w = surfaceMessage->w,
       .h = surfaceMessage->h};
   SDL_RenderCopy(render, Message, NULL, &Message_rect);
   SDL_DestroyTexture(Message);
   SDL_FreeSurface(surfaceMessage);
}
