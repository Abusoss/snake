void move(char type[], int *arg, boolean *state)
{
   printf("menu: %d\n", strcmp(type, "menu"));
   printf("game: %d\n", strcmp(type, "game"));
   if (strcmp(type, "menu") == 0)
   {
      printf("arg: %d\n", *arg);
      /* code */
      // ch = _getch();
      _getch();
      if (GetAsyncKeyState(VK_UP) & 0b1)
      {
         printf("up\n");
         if (*arg > 0 && *arg <= 3)
         {
            *arg = *arg - 1;
         }
         *state = FALSE;
      }
      else if (GetAsyncKeyState(VK_DOWN) & 0b1)
      {
         printf("down\n");
         if (*arg < 2)
         {
            *arg = *arg + 1;
         }
         *state = FALSE;
      }
      else if (GetAsyncKeyState(VK_RETURN))
      {
         *state = TRUE;
      }
      else{
         *state = FALSE;
      }
   }
   else if (strcmp(type, "game") == 0)
   {
      // game move
   }
}