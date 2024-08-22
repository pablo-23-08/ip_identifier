#include <stdio.h>
#include <stdlib.h>

void get_ip(char *chaine, int *a, int *b, int *c, int *d);
void classify_ip(int *a, int *b, int *c, int *d);

int main ()
{
	char chaine[255];
	int a=256,b=256,c=256,d=256;
	get_ip(chaine,&a,&b,&c,&d);
	classify_ip(&a,&b,&c,&d);

return 0;	
}

void get_ip(char *chaine, int *a, int *b, int *c, int *d)
{
	printf("Entrez une addresse ip: \n");
	scanf("%s",chaine);
	sscanf(chaine,"%d.%d.%d.%d",a,b,c,d);
	while(!(*a<=255 && *b<=255 && *c<=255 && *d<=255))
	{
		printf("L'addresse ip que vous avez entrez est fausse. Recommencez! \n");
		printf("Entrez une addresse ip: \n");
		scanf("%s",chaine);
		sscanf(chaine,"%d.%d.%d.%d",a,b,c,d);
	}
}

void classify_ip(int *a, int *b, int *c, int *d)
{
	if(*a<128)
	{
		printf("L'addresse : %d.%d.%d.%d ",*a,*b,*c,*d);
		printf("est de classe A\n");
	}
	if(127<*a&&*a<192)
	{
		printf("L'addresse : %d.%d.%d.%d ",*a,*b,*c,*d);
		printf("est de classe B\n");
	}
	if(192<*a&&*a<224)
	{
		printf("L'addresse : %d.%d.%d.%d ",*a,*b,*c,*d);
		printf("est de classe C\n");
	}
	if(224<*a&&*a<256)
	{
		printf("L'addresse : %d.%d.%d.%d ",*a,*b,*c,*d);
		printf("est de classe D\n");
	}
}
