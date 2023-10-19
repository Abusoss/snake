void gameStart(SDL_Renderer *render, TTF_Font *police, SDL_Window *window)
{
   police = TTF_OpenFont("./police.ttf", taillePoliceGame); // this opens a font style and sets a size
   BOOLEAN change = TRUE;
   BOOLEAN selected = FALSE;
   addSerpend();
   // TODO: ajouter une fonction qui grandit le serpent
   growSerpend();
   growSerpend();
   // growSerpend();
   gameGenerator(render, police, window);
   while (fonctionne)
   {
      actions(&change, &selected);
      moveSerpend(&change);
      if (change)
      {
         // gameGenerator(render, police, window);
         change = FALSE;
      }
   }
}

// ----------------- GAMEGENERATOR -----------------

void gameGenerator(SDL_Renderer *render, TTF_Font *police, SDL_Window *window)
{
   SDL_SetRenderDrawColor(render, 30, 30, 30, 255); // clear the renderer to the draw color
   SDL_RenderClear(render);
   SDL_Color fontColor = {255, 255, 255, 255};
   SDL_Surface *surfaceMessage = NULL;
   SDL_Texture *Message = NULL;
   SDL_Rect Message_rect = {0, 0, 0, 0};
   Position pos = {};
   game.direction = rand() % 5;
   for (int c = 0; c <= hauteur - 1; c++)
   {
      for (int l = 0; l <= largeur - 1; l++)
      {
         // printf("%s",game.map.colonne[c].cellule[l].type);

         pos.x = l;
         pos.y = c;
         if (l == 0 || l == largeur -1)
         {
            switch (game.map.colonne[c].cellule[l].type[0])
            {
            case 'm':
               renderComponent(pos, composants[3], police, fontColor, render, surfaceMessage, Message, Message_rect);
               // printf("%c", composants[3]);
               break;
            default:
               break;
            }
         }
         else
         {
            switch (game.map.colonne[c].cellule[l].type[0])
            {
            case 'm':
                  renderComponent(pos, composants[4], police, fontColor, render, surfaceMessage, Message, Message_rect);
               // printf("%c", composants[4]);
               break;
            case 'v':
               renderComponent(pos, composants[2], police, fontColor, render, surfaceMessage, Message, Message_rect);
               // printf("%c", composants[2]);
               break;
            case 's':
               renderComponent(pos, composants[6], police, fontColor, render, surfaceMessage, Message, Message_rect);
               // printf("%c", composants[5]);
            case 'S':
               renderComponent(pos, composants[5], police, fontColor, render, surfaceMessage, Message, Message_rect);
               // printf("%c", composants[5]);
               break;
            case 'p':
               renderComponent(pos, composants[0], police, fontColor, render, surfaceMessage, Message, Message_rect);
               // printf("%c", composants[0]);
               break;
            case 'P':
               renderComponent(pos, composants[1], police, fontColor, render, surfaceMessage, Message, Message_rect);
               // printf("%c", composants[1]);
               break;
            default:
               break;
            }
         }
      }
   }
   SDL_RenderPresent(render);
}

void renderComponent(Position pos, Uint16 text, TTF_Font *police, SDL_Color fontColor, SDL_Renderer *render, SDL_Surface *surfaceMessage, SDL_Texture *Message, SDL_Rect Message_rect)
{
   Uint16 textStr[2] = {text, '\0'};
   surfaceMessage = TTF_RenderUNICODE_Blended(police, textStr, fontColor);
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
   Message_rect.x = pos.x * taillePoliceGame; // controls the rect's x coordinate
   Message_rect.y = pos.y * taillePoliceGame; // controls the rect's y coordinte
   Message_rect.w = surfaceMessage->w;        // controls the width of the rect
   Message_rect.h = surfaceMessage->h;        // controls the height of the rect
   // printf("largeur : %d\n", surfaceMessage->w);
   // printf("hauteur : %d\n", Message_rect.h);
   // Message_rect.w = surfaceMessage->w;  // controls the width of the rect
   // Message_rect.h = surfaceMessage->h;  // controls the height of the rect
   SDL_RenderCopy(render, Message, NULL, &Message_rect);
}
