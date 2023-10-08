// ----------------- MENU -----------------
void menu()
{
   int choix = 0;
   int option = jouer;
   int subOption = jouer;
   int ch;
   do
   {
      // pommeAdd();
      do
      {
      clear_screen();
      printMap();
      printf("%d\n",option);
      menuGenerator(&option);
       ch = move("menu", &option);
      } while (ch != 13);

      switch (choix)
      {
      case 1:

         break;
      case 2:
         /* code */
         break;
      case 3:
         exit(0);
         /* code */
         break;

      default:
         choix = option;
         break;
      }
      // array 3 position
      // position par defaut 0 = number
      // move increase or decrease(if not 0) number
      // when press enter and number = 0 jouer else if number = 1 options else if number = 2 quitter
   } while (choix != 3);
}

// ----------------- MENUGENERATOR -----------------

void menuGenerator(int *option)
{
   int size = 0;
   char underline[20];
   if (*option <= 3)
   {
      for (size_t i = 0; i < (sizeof(menuTitle) / sizeof(menuTitle[0])) - 6; i++)
      {
         if (*option == i)
         {
            size = strlen(menuTitle[i])-1;

            for (int s = 0; s < size; s++)
            {
               // printf("%d  %d\n  %s", s, size, underline[s]);
               strcpy(underline, "--------------");
               /* code */
            }
            // strcpy(underline[size],'\0');
            /* code */
            printf("%s%s\n", menuTitle[i], underline);
         }
         else
         {
            printf("%s\n", menuTitle[i]);
         }
      }
   }
   else
   {
      for (size_t i = (sizeof(menuTitle) / sizeof(menuTitle[0])) - 6; i < sizeof(menuTitle) / sizeof(menuTitle[0]); i++)
      {
         size = strlen(menuTitle[i])-1;
         for (int s = 0; s < size; s++)
         {
            strcpy(underline, "--------------");
            /* code */
         }
         strcpy(underline, "--------------");
         printf("%s%s\n", menuTitle[i], underline);
      }
   }
   // lstrlenA determine la longueur d'une chaîne de caractère
}