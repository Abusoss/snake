void score(void)
{
   SDL_Color fontColor = {255, 255, 255, 255};
   char title[20];
   snprintf(title, 20, "Score : %d", game.playeur.score); // puts string into buffer
   int width, height;                             // hauteur du texte réellement
   SDL_Surface *SurfaceScore = TTF_RenderText_Blended(game.police, title, fontColor);
   SDL_Texture *MessageScore = SDL_CreateTextureFromSurface(game.render, SurfaceScore);
   SDL_Rect posScore;
   posScore.x = 0;
   posScore.y = 10;
   TTF_SizeText(game.police, title, &width, &height);
   SDL_Rect Message_rectScore = {
       .x = posScore.x + ceil((windowWidth * (marge / 100)) / 2),
       .y = posScore.y,
       .w = SurfaceScore->w,
       .h = SurfaceScore->h};
   SDL_RenderCopy(game.render, MessageScore, NULL, &Message_rectScore);
   SDL_DestroyTexture(MessageScore);
   SDL_FreeSurface(SurfaceScore);
}