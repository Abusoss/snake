int move(char type[], int *arg)
{
   printf("menu: %d\n", strcmp(type, "menu"));
   printf("game: %d\n", strcmp(type, "game"));
   int ch;
   if (strcmp(type, "menu") == 0)
   {
      printf("arg: %d\n", *arg);
      ch = _getch();
      /* code */
      // ch = _getch();
      if (ch != 224)
      {
         switch (ch)
         {        // the real value
         case 80: // key up
            printf("up\n");
            if (*arg < 2)
            {
               *arg = *arg + 1;
            }
            break;
         case 72: // key down
            printf("down\n");
            if (*arg > 0 && *arg <= 3)
            {
               *arg = *arg - 1;
            }
            break;
         case 77: // key right
            printf("right\n");
            break;
         case 75: // key left
            printf("left\n");
            break;
         default: // autre
            move(type, *arg);
            break;
         }
      }
      return ch;
   }
   else if (strcmp(type, "game") == 0)
   {
      if (_getch() == '\033')
      {            // if the first value is esc
         _getch(); // skip the [
         printf("%d", _getch());
         /* switch (_getch())
         { // the real value
            {
            case 65: // key up
               break;
            case 66: // key down
               break;
            case 67: // key right
               break;
            case 68: // key left
               break;
            default: // autre
               move(type, arg);
               break;
            }
         } */
      }
   }
}