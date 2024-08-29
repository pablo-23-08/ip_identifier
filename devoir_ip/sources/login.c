#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_data(char* username, char* password);
void display(char* username, char* password);
int already_registered(char* username, char* password);

int main() 
{
    char username[256], password[256];
    get_data(username, password);
    display(username, password);
    return 0;
}

void get_data(char* username, char* password)
{
    char *chaine = NULL;
    chaine = getenv("QUERY_STRING");
    char *username_ = NULL, *password_ = NULL;
    if (chaine != NULL) {
        // pour séparer les différents champs
        username_ = strtok(chaine, "&");
        password_ = strtok(NULL, "&");

        // pour enlever les =
        username_ = strtok(username_, "=");
        username_ = strtok(NULL, "=");
        password_ = strtok(password_, "=");
        password_ = strtok(NULL, "=");

        // pour enlever les +
        for (int i = 0; i < strlen(username_); i++) {
            if (username_[i] == '+') {
                username_[i] = ' ';
            }
        }
        for (int i = 0; i < strlen(password_); i++) {
            if (password_[i] == '+') {
                password_[i] = ' ';
            }
        }
        

        strcpy(username, username_);
        strcpy(password, password_);
    }
}

int already_registered(char* username, char* password)
{
    FILE *fichier;
    char ligne[256];
    char file_username[256], file_password[256];
    fichier = fopen("users.txt", "r");
    if (fichier != NULL) 
    {
		while (fgets(ligne, sizeof(ligne), fichier)) 
		{
			sscanf(ligne, "%255[^;];%255[^;]", file_username, file_password);
			if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) 
			{
				fclose(fichier);
				return 1;
			}
		}
		fclose(fichier);
		return 0;
	}
	else
	{
		return 0;
	} 
}

void display(char* username, char* password)
{
	FILE *fichier;
	if (already_registered(username, password)) 
	{
        printf("Content-Type: text/html\n\n");
        printf("<HTML>\n");
        printf("<HEAD><TITLE>welcome</TITLE><META CHARSET=\"utf-8\"></META></HEAD>\n");
        printf("<BODY BGCOLOR=\"#DDFFFF\">\n");
        printf("<H1>%s, connexion avec succès!</H1><BR>\n", username);
        printf("<FORM ACTION=\"get_ip.cgi\" METHOD=\"GET\">\n");
        printf("<INPUT TYPE=\"SUBMIT\" VALUE=\"aller sur l'identificateur IP\"/>\n");
        printf("</FORM>\n");
        printf("<A HREF='acceuil.cgi'>Se déconnecter</A>\n");
        printf("</BODY>\n");
        printf("</HTML>\n");
    }
    else 
    {
		printf("Content-Type: text/html\n\n");
        printf("<HTML>\n");
        printf("<HEAD><TITLE>erreur_de_connexion</TITLE><META CHARSET=\"utf-8\"></META></HEAD>\n");
        printf("<BODY BGCOLOR=\"#DDFFFF\">\n");
        printf("<H1>Ce compte n'existe pas ou login ou mot de passe incorrect</H1><BR>\n");
        printf("<FORM ACTION=\"acceuil.cgi\" METHOD=\"GET\">\n");
        printf("<INPUT TYPE=\"SUBMIT\" VALUE=\"Recommencer\"/>\n");
        printf("</FORM>\n");
        printf("</BODY>\n");
        printf("</HTML>\n");
    }
}

