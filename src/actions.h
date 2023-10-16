void actions(BOOLEAN *change, BOOLEAN *selected)
{
   SDL_Event action;
   SDL_PollEvent(&action);
   switch (action.type)
   {
   case SDL_QUIT:
      fonctionne = FALSE;
      break;
   case SDL_KEYDOWN:
      switch (action.key.keysym.sym)
      {
      case SDLK_ESCAPE:
         fonctionne = FALSE;
         break;
      case SDLK_UP:
         game.direction = HAUT;
         *change=TRUE;
         break;
      case SDLK_DOWN:
         game.direction = BAS;
         *change=TRUE;
         break;
      case SDLK_LEFT:
         game.direction = GAUCHE;
         *change=TRUE;
         break;
      case SDLK_RIGHT:
         game.direction = DROITE;
         *change=TRUE;
         break;
      case SDLK_RETURN:
         *selected = TRUE;
         *change = TRUE;
         break;
      default:
         break;
      }
      break;
   default:
      break;
   }
}