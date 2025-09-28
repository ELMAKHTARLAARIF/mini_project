#include <stdio.h>
#include <string.h>
#include <stdlib.h>
        typedef struct {
                char  cne[20];
                char  nom[40];
                char  prenom[40];
		float notes[4];
		float moyenne;
	}etudiente;
	etudiente class[30];
	int	numberedu = 0;
	int	Menu();
	void	Ajouter();
	void	saisirNotes();
	void	calculerMoyenneEtudiant();
	void	calculerMoyenneGenerale();
	void	afficherEtudiants();
	void	afficherBulletin();
int	Menu()
{

	int     choix;
        printf("------------------Menu-------------------\n");
        printf("1-Ajouter un etudiant\n");
        printf("2-Saisir les notes\n");
        printf("3-Afficher tous les etudiants\n");
	printf("4-Affiche bulttane\n");
	printf("5-Calculer Moyenne generale\n");
        printf("0-Pour Quitter\n");
        printf("entrer votre choix :");
        scanf("%d",&choix);
	system("clear");
	        switch(choix)
        {
                case 1:
                        Ajouter();
                        break;
                case 2:
                        saisirNotes();
                        break;
                case 3:
                        afficherEtudiants();     
                        break;
		case 4:
                        afficherBulletin();
                        break;
                case 5:
                        calculerMoyenneGenerale();
                        break;
                case 0:
                        return 0;
                default:
                        printf("Next Time ");
        }

}
void saisirNotes()
{
	char search_ID[20];
	int i = 0;
	int	found = 0;

	printf("ENTER YOUR ID: ");
	scanf("%s", search_ID);
	while (i <= numberedu)
	{
		if (strcmp(class[i].cne, search_ID) == 0)
		{
			printf("enter note 1: ");
			scanf("%f", &class[i].notes[0]);

			printf("enter note 2: ");
			scanf("%f", &class[i].notes[1]);

			printf("enter note 3: ");
			scanf("%f", &class[i].notes[2]);

			printf("enter note 4: ");
			scanf("%f", &class[i].notes[3]);
			found = 1;
			calculerMoyenneEtudiant(search_ID);
			printf("la Moyenne est :%.2f\n",class[i].moyenne);
			break;
		}
		i++;
	}
	if (!found)
		printf("We don't have any id\n");
	Menu();
}
void	calculerMoyenneEtudiant(char cne[])
{
	float	result;
	result = 0;
	int	j = 0;
	for (int j = 0;j <= numberedu;j++)
	{
		if (strcmp(class[j].cne,cne) == 0)
		{
			result += class[j].notes[0] + class[j].notes[1] + class[j].notes[2] + class[j].notes[3];
			class[j].moyenne = result / 4;
			break;
		}
	}
}
void	calculerMoyenneGenerale()
{
	 int	i;
	 i = 0;
	 float	moyennegenerale;
	 moyennegenerale = 0;
	 float	somme = 0;

	 while (i < numberedu)
	{
		somme += class[i].moyenne;
		i++;
	}
	 moyennegenerale = somme / numberedu;
	 printf("la moyenne generale est : %.2f\n",moyennegenerale);
	 Menu();
}
void	afficherEtudiants()
{
	int	i;
	i = 0;
	while (i < numberedu)
	{
		printf("CNE : %s    Nom : %s    Prenom : %s   la Moyenne de %s : %.2f\n",class[i].cne,class[i].nom,class[i].prenom,class[i].nom,class[i].moyenne);
		i++;
	}
	Menu();
}
void Ajouter(void)
{
	char uniqueid[20];
	int i;

	if (numberedu == 30) 
	{
        	printf("Sorry class is Full!\n");
        	return;
	}

	printf("ENTER YOUR ID : ");
	scanf("%s", uniqueid);
	for (i = 0; i < numberedu; i++) 
	{
		if (strcmp(uniqueid, class[i].cne) == 0) 
		{
			printf("Ce numéro existe déjà. Veuillez en saisir un autre.\n");
			Menu();
			return;
		}
	}
	strcpy(class[numberedu].cne, uniqueid);
	scanf("%*c");
	printf("ENTER YOUR NAME : ");
	scanf("%s", class[numberedu].nom);
	scanf("%*c");
	printf("ENTER YOUR LAST NAME : ");
	scanf("%s", class[numberedu].prenom);

 	numberedu++;
	Menu();
}
void	afficherBulletin(void)
{
	char searchCNE[20];
	int i, j;
	int found = 0;

	if (numberedu == 0) 
	{
		printf("Aucun etudiant n'est enregistre.\n");
        	return;
	}

	printf("Entrer le CNE de l'etudiant : ");
	scanf("%s", searchCNE);

	for (i = 0; i < numberedu; i++) 
	{
		if (strcmp(searchCNE, class[i].cne) == 0) 
		{
			found = 1;
			printf("CNE : %s\n", class[i].cne);
			printf("Nom : %s\n", class[i].nom);
			printf("Prenom : %s\n", class[i].prenom);

			printf("Notes : ");
			float result = 0;
			for (j = 0; j < 4; j++) 
			{
				printf("%.2f ", class[i].notes[j]);
				result += class[i].notes[j];
			}

			class[i].moyenne = result/j;
			printf("\nLa Moyenne de %s : %.2f\n", class[i].nom, class[i].moyenne);
			printf("----------------------------\n");
			break;
		}
	}

	if (!found) 
	{
		printf("Aucun etudiant avec ce CNE n'est trouvé.\n");
	}
}

int	main()
{
	Menu();
}
