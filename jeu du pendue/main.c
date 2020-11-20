#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void *recupChaine(char* ,char*);
void selecChar(char*);
int verifSelect(char* ,char*,char*,int*);


int main()
{
    int  life =9, check =0;
    char saisieInit[255],recup[255],carac;

    recupChaine(&saisieInit,&recup);

    int verifBool;

   do
   {
       fflush(stdin);


      selecChar(&carac);


      verifBool = verifSelect(carac,saisieInit,recup,&check);

      if (verifBool==0)//verifie si la lettre n'as pas etait trouvé dans la chaine
    {
        life--;
    }

      printf("%s\n",recup);
      printf("nombre de vie : %d\n",life);


    //if (life == 0) break;
   }
   while((check !=strlen(saisieInit))&& (life != 0));


if (life == 0)
{
    printf("perdue, le mots etait : %s\n",saisieInit);
}else{
    printf("felicitation, vous avez trouvez le mots\n");
}



    return 0;
}

void *recupChaine(char *j_saisie,char *j_recup) //demande de la saisie du mots rechercher a l utilisateur
{

    printf("saisissez un mots\n");
    scanf("%s",j_saisie);

     for (int i = 0; i<strlen(j_saisie);i++)
    {
        j_recup[i] = '_';
    }
    system("cls");
    //return *j_saisie;
}

void selecChar(char *rec)//selection d'un caractere par l utilisateur
{
    char selecLetr;

    printf ("choisisez une lettre\n") ;
    scanf("%c",&selecLetr);

    *rec = selecLetr;
    system("cls");
}

int verifSelect(char *rec,char *saisieInit,char *recup,int *j_check)//verifcation et assignation des bonnes lettres
{
    int checked = 0, compt=0;

    for (int i =0;i<strlen(saisieInit);i++ )
    {

        if (rec == saisieInit[i])
        {
            recup[i] = rec;
            compt++;
            checked = 1;
        }
    }
    *j_check+=compt;
    return checked;
}
