void saveScore(void)
{
   if (game.playeur.score > game.bestPlayeur.score)
   {
      FILE *fichier = fopen("save.txt", "w");
      if (fichier != NULL)
      {
         fprintf(fichier, "%s:%d", game.playeur.name, game.playeur.score);
         fclose(fichier);
      }
      game.bestPlayeur.score = game.playeur.score;
      strcpy_s(game.bestPlayeur.name, 100, game.playeur.name);
   }
}

void lireScore(void)
{
   FILE *fichier = fopen("save.txt", "r");
   char tmpName[20];
   if (fichier != NULL)
   {
      fscanf(fichier, "%[^:]:%d", tmpName, &game.bestPlayeur.score);
      fclose(fichier);
      strcpy_s(game.bestPlayeur.name, 100, tmpName);
   }
}