void affichage(SDL_Renderer *render,TTF_Font *police,SDL_Window *window)
{
   SDL_Color fontColor = {255, 255, 255};
   SDL_Surface *surfaceMessage = TTF_RenderText_Solid(police, "hello", fontColor);
   SDL_Texture *Message = SDL_CreateTextureFromSurface(render, surfaceMessage);
   SDL_Rect Message_rect; // create a rect
   Message_rect.x = 0;    // controls the rect's x coordinate
   Message_rect.y = 0;    // controls the rect's y coordinte
   Message_rect.w = 200;    // controls the rect's x coordinate
   Message_rect.h = 200;    // controls the rect's y coordinte

   // printf("largeur : %d\n", surfaceMessage->w);
   // printf("hauteur : %d\n", Message_rect.h);
   // Message_rect.w = surfaceMessage->w;  // controls the width of the rect
   // Message_rect.h = surfaceMessage->h;  // controls the height of the rect
   SDL_RenderCopy(render, Message, NULL, &Message_rect);
   SDL_RenderPresent(render);
   SDL_Delay(2000); // Pause for 2 seconds
   // Don't forget to free your surface and texture
   SDL_DestroyTexture(Message);
   SDL_FreeSurface(surfaceMessage);
   SDL_RenderClear(render);
}