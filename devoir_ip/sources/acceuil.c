#include <stdio.h>

void acceuil();

int main()
{
   acceuil();
   return 0;
}

void acceuil()
{
	printf("Content-Type: text/html\n\n");
    printf("<HTML>\n");
    printf("<HEAD><TITLE>acceuil</TITLE><META CHARSET='utf-8'></HEAD>\n");
    printf("<BODY BGCOLOR='#DDFFFF'>\n");
    printf("<H1>Connexion</H1>\n");
    printf("<FORM ACTION='login.cgi' METHOD='GET'>\n");
    printf("<LABEL FOR='username'>Nom d'utilisateur: </LABEL>");
    printf("<INPUT TYPE='text' NAME='username' ID='username' PLACEHOLDER='entrer votre nom'/><BR><BR>\n");
    printf("<LABEL FOR='password'>Mot de passe: </LABEL>");
    printf("<INPUT TYPE='password' NAME='password' ID='password' PLACEHOLDER='entrer votre mot de passe'/><BR><BR>\n");
    printf("<INPUT TYPE='SUBMIT' VALUE='Se connecter'/>\n");
    printf("</FORM>\n");
    printf("<A HREF='create_account.cgi'>Créer un compte</A>\n");
    printf("</BODY>\n");
    printf("</HTML>\n");
}




