int initWindow(SDL_Renderer *render,TTF_Font *police,SDL_Window *window)
{

   window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 600, windowFlag);
   if (!window)
   {
      printf("Could not create window: %s\n", SDL_GetError());
      return FALSE;
   }
   printf("Window created !!!\n");
   // SDL_Event event;
   // while (TRUE)
   // {
   //    if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
   //    {
   //       break;
   //    }
   // }

   render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
   if (!render)
   {
      printf("Could not create render: %s\n", SDL_GetError());
      return FALSE;
   }
   printf("Render created !!!\n");
   return TRUE;
}

void quitterWindow(SDL_Renderer *render,TTF_Font *police,SDL_Window *window)
{
   SDL_DestroyRenderer(render);
   SDL_DestroyWindow(window);
   TTF_CloseFont(police);
   TTF_Quit();
   SDL_Quit();
}