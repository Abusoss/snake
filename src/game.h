void gameFn(void)
{
   if (!game.police)
   {
      game.police = TTF_OpenFont("./police.ttf", taillePoliceGame); // this opens a font style and sets a size
   }
   // TODO: ajouter une fonction qui grandit le serpent
   if (game.gameStart == FALSE)
   {
      game.config.vitesse = vitesse;
      gameGenerator();
      SDL_RenderPresent(game.render);
      SDL_Delay(3000);
      game.gameStart = TRUE;
   }
   moveSerpend();
   gameGenerator();
   // if (change)
   // {
   //    change = FALSE;
   // }
}

void gameGenerator(void)
{
   SDL_SetRenderDrawColor(game.render, 30, 30, 30, 255);
   SDL_RenderClear(game.render);
   SDL_Color fontColor = {255, 255, 255, 255};
   SDL_Rect Message_rect = {0, 0, 0, 0};
   Position pos = {};
   // game.direction = rand() % 3 + 1;
   score();
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
            renderComponent(pos, composants[componentIndex], fontColor, game.map.colonne[c].cellule[l].surface, game.map.colonne[c].cellule[l].texture, Message_rect);
         }
      }
   }
}

void renderComponent(Position pos, Uint16 text, SDL_Color fontColor, SDL_Surface *surfaceMessage, SDL_Texture *Message, SDL_Rect Message_rect)
{
   Uint16 textStr[2] = {text, '\0'};
   surfaceMessage = TTF_RenderUNICODE_Blended(game.police, textStr, fontColor);
   int width, height; // hauteur du texte réellement
   TTF_SizeUNICODE(game.police, textStr, &width, &height);
   if (surfaceMessage == NULL || (Message = SDL_CreateTextureFromSurface(game.render, surfaceMessage)) == NULL)
   {
      printf("Error: %s\n", SDL_GetError());
      fonctionne = FALSE;
      return;
   }
   Message_rect = (SDL_Rect){
       .x = (pos.x * taillePoliceGame + (taillePoliceGame - width) / 2) + ceil((windowWidth * (marge / 100)) / 2),
       .y = pos.y * taillePoliceGame + ceil((windowHeight * (marge / 100)) / 2),
       .w = surfaceMessage->w,
       .h = surfaceMessage->h};
   SDL_RenderCopy(game.render, Message, NULL, &Message_rect);
   SDL_DestroyTexture(Message);
   SDL_FreeSurface(surfaceMessage);
}
