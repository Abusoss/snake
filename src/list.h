static Cell *creeCell(Cellule *data)
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

/**
 * Ajoute une nouvelle cellule avec les données spécifiées à la position indiquée dans la liste.
 * Si la liste est vide, la nouvelle cellule devient la tête de la liste.
 * Si la position est 0, la nouvelle cellule est ajoutée au début de la liste.
 * Si la position autre que 0, la nouvelle cellule est ajoutée à la position indiquée dans la liste.
 * Si la position est supérieure à la taille de la liste, la nouvelle cellule est ajoutée à la fin de la liste.
 * @param liste La liste à laquelle ajouter la nouvelle cellule.
 * @param data Les données à stocker dans la nouvelle cellule.
 * @param pos La position à laquelle ajouter la nouvelle cellule.
 * @return La liste mise à jour avec la nouvelle cellule ajoutée.
 */
List *ajoutA(List *liste, Cellule *data, int pos)
{
   List *precedent = liste;
   List *courant = liste;
   int i = 0;
   Cell *cell = creeCell(data);
   if (estVide(liste))
   {
      printf("estVide\n");
      game.reverseSerpent = cell;
      game.serpent = cell;
      return cell;
   }
   if (pos == 0)
   {
      cell->suivant = liste;
      cell->precedent = NULL;
      // print  cell->suivant adreese
      // printf("cell->suivant : %p\n", cell->suivant);
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
List *ajouterFinA(List *liste, Cellule *data, int pos)
{
   List *courant = liste;
   int i = 0;
   // printf("ajouterFinA\n");
   // printf("data type : %s\n", data.type);
   Cell *cell = creeCell(data);
   // printf("liste type : %s\n", liste->cellule.type);
   // printf("cell type : %s\n", cell->cellule.type);
   if (estVide(liste))
   {
      printf("estVide\n");
      game.reverseSerpent = cell;
      return cell;
   }
   if (pos == 0)
   {
      courant->suivant = cell;
      cell->suivant = NULL;
      cell->precedent = courant;
      game.reverseSerpent = cell;
      // printf("liste type : %s\n", cell->cellule.type);
      // printf("cell type : %s\n", cell->cellule.type);
   }
   return cell;
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

Cellule *rechercheA(List *liste, int pos)
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
Cellule *rechercheAReverse(List *liste, int pos)
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