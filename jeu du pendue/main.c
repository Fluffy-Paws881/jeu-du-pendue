#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char saisieInit[255], recup[255];
int  life =9;
int check =0;


void recupChaine() //demande de la saisie du mots rechercher a l utilisateur
{
    printf("saisissez un mots\n");
    scanf("%s",saisieInit);

     for (int i = 0; i<strlen(saisieInit);i++)
    {
        recup[i] = '_';
    }
    system("cls");
}

void selecChar(char *rec)//selection d'un caractere par l utilisateur
{
    char selecLetr;

    printf ("choisisez une lettre\n") ;
    scanf("%c",&selecLetr);

    *rec = selecLetr;
    system("cls");
}

int verifSelect(char *rec)//verifcation et assignation des bonnes lettres
{
    int checked = 0;

    for (int i =0;i<strlen(saisieInit);i++ )
    {

        if (rec == saisieInit[i])
        {
            recup[i] = rec;
            check++;
            checked = 1;
        }
    }

    if (checked==0)//verifie si la lettre n'as pas etait trouvé dans la chaine
    {
        life--;
    }

    return checked;
}



int main()
{
    char carac;

    recupChaine();

    int verifBool =0;

   do
   {
       fflush(stdin);


      selecChar(&carac);


      verifBool = verifSelect(carac);

      printf("%s\n",recup);
      printf("nombre de vie : %d\n",life);


    if (life == 0) break;
   }
   while(check !=strlen(saisieInit));


if (life == 0)
{
    printf("perdue, le mots etait : %s\n",saisieInit);
}else{
    printf("felicitation, vous avez trouvez le mots\n");
}







    return 0;
}
