static Cell *creeCell(Cellule data)
{
   Cell *cell = (Cell *)malloc(sizeof(Cell));
   if (!cell)
   {
      return NULL;
   }
   cell->cellule = data;
   cell->suivant = NULL;
   cell->precedent = NULL;
   return cell;
}

List *creeList(void)
{
   return NULL;
}

BOOLEAN estVide(List *liste)
{
   return liste == NULL ? TRUE : FALSE;
}

List *ajoutA(List *liste, Cellule data, int pos)
{
   List *precedent = liste;
   List *courant = liste;
   int i = 0;
   Cell *cell = creeCell(data);
   if (estVide(liste))
   {
      game.reverseSerpent = cell;
      return cell;
   }
   if (pos == 0)
   {
      cell->suivant = liste;
      cell->precedent = NULL;
      // print  cell->suivant adreese
      printf("cell->suivant : %p\n", cell->suivant);
      return cell;
   }
   while (i < pos)
   {
      precedent = courant;
      courant = courant->suivant;
      i++;
   }
   precedent->suivant = cell;
   cell->precedent = precedent;
   cell->suivant = courant;
   if (cell->suivant == NULL)
   {
      game.reverseSerpent = cell;
   }

   return liste;
}

// -------------- reverseSerpent List --------------
// TODO: transfomer en ajouterFinA
List *ajouterFinA(List *liste, Cellule data, int pos)
{
   List *courant = liste;
   int i = 0;
   printf("ajouterFinA\n");
   // printf("data type : %s\n", data.type);
   Cell *cell = creeCell(data);
   if (estVide(liste))
   {
      printf("estVide\n");
      return cell;
   }
   if (pos == 0)
   {
      printf("pos 0\n");
      cell->suivant = NULL;
      cell->precedent = courant;
      liste = cell;
      printf("liste type : %s\n", liste->cellule.type);
      printf("cell type : %s\n", liste->cellule.type);
      printf("liste type : %s\n", cell->cellule.type);
      printf("cell type : %s\n", cell->cellule.type);
      return cell;
   }
   return liste;
}

List *supprimerList(List *liste)
{
   List *tmp = NULL;
   while (liste != NULL)
   {
      tmp = liste->suivant;
      free(liste);
      liste = tmp;
   }
   return liste;
}

long tailleList(List *liste)
{
   long taille = 0;
   while (liste)
   {
      taille++;
      liste = liste->suivant;
   }
   return taille;
}

Cellule rechercheA(List *liste, int pos)
{
   int i = 0;
   if (liste == NULL)
   {
      return liste->cellule;
   }
   while (i < pos)
   {
      liste = liste->suivant;
      i++;
   }
   return liste->cellule;
}
Cellule rechercheAReverse(List *liste, int pos)
{
   // int i = tailleList(liste);
   // if (liste == NULL)
   // {
   //    return liste->cellule;
   // }
   // while (i > pos)
   // {
   //    liste = liste->precedent;
   //    i--;
   // }
   // return liste->cellule;
}