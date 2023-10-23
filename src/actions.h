void actions()
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
         if (strcmp(game.gameState, "game") == FALSE)
         {
            if (game.direction == HAUT || game.direction == BAS)
            {
               break;
            }

            /* code */
         }
         game.previousDirection = game.direction;
         game.direction = HAUT;
         game.isChange = TRUE;
         break;
      case SDLK_DOWN:
         if (strcmp(game.gameState, "game") == FALSE)
         {
            if (game.direction == BAS || game.direction == HAUT)
            {
               break;
            }

            /* code */
         }
         game.previousDirection = game.direction;
         game.direction = BAS;
         game.isChange = TRUE;
         break;
      case SDLK_LEFT:
         if (strcmp(game.gameState, "game") == FALSE)
         {
            if (game.direction == GAUCHE || game.direction == DROITE)
            {
               break;
            }

            /* code */
         }
         game.previousDirection = game.direction;
         game.direction = GAUCHE;
         game.isChange = TRUE;
         break;
      case SDLK_RIGHT:
         if (strcmp(game.gameState, "game") == FALSE)
         {
            if (game.direction == GAUCHE || game.direction == DROITE)
            {
               break;
            }

            /* code */
         }
         game.previousDirection = game.direction;
         game.direction = DROITE;
         game.isChange = TRUE;
         break;
      case SDLK_RETURN:
         game.selected = TRUE;
         game.isChange = TRUE;
         break;
      default:
         break;
      }
      break;
   default:
      break;
   }
}