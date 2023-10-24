void actions()
{
   // if (strcmp(game.gameState, "game") == TRUE)
   // {
   //    /* code */
   //    SDL_PollEvent(&game.action);
   // }
   if (SDL_PollEvent(&game.action) != FALSE)
   {
      switch (game.action.type)
      {
      case SDL_QUIT:
         fonctionne = FALSE;
         break;
      case SDL_KEYDOWN:
         switch (game.action.key.keysym.sym)
         {
         case SDLK_ESCAPE:
            if (strcmp(game.gameState, "game") == FALSE)
            {
               game.previousGameDirection = game.direction;
               game.direction = HAUT;
               game.selected = FALSE;
               game.choix = 0;
               game.currentOption = 0;
               game.subOption = 0;
               strcpy_s(game.gameState, 100, "menu");
               TTF_CloseFont(game.police);
               game.police = NULL;
            }
            else
            {
               fonctionne = FALSE;
            }
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
      /* code */
   }
   SDL_Delay(16.333);
}