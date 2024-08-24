#include <stdio.h>
#include <stdlib.h>

// https://github.com/pablo-23-08/ip_identifier.git

void get_ip(int *a, int *b, int *c, int *d, char *e);
void classify_ip(int *a, int *b, int *c, int *d);

int main ()
{
	int a, b, c, d;
	char e;
	get_ip(&a, &b, &c, &d, &e);
	classify_ip(&a, &b, &c, &d);

return 0;	
}

void get_ip(int *a, int *b, int *c, int *d, char *e)
{
	char *chaine = NULL;
    chaine = getenv("QUERY_STRING");
	*a=256, *b=256, *c=256, *d=256;
	sscanf(chaine,"ip=%d.%d.%d.%d.%c", a, b, c, d, e);
	if(*a<0 || *a>255 || *b<0 || *b>255 || *c<0 || *c>255 || *d<0 || *d>255 || *e!='\0')
	{
		printf("Content-Type: text/html\n\n");
        printf("<HTML>\n");
        printf("<HEAD><TITLE>ipidentifier</TITLE><META CHARSET=\"utf-8\"></META></HEAD>\n");
        printf("<BODY BGCOLOR=\"#DDFFFF\">\n");
        printf("<H1>L'addresse ip que vous avez entrez est fausse. Recommencez! \n</H1><BR>\n");
        printf("<FORM ACTION=\"get_ip.cgi\" METHOD=\"GET\">\n");
        printf("<INPUT TYPE=\"SUBMIT\" VALUE=\"Recommencez\"/>\n");
        printf("</FORM>\n");
        printf("</BODY>\n");
        printf("</HTML>\n");
	}
	else
	{
		printf("Content-Type: text/html\n\n");
        printf("<HTML>\n");
        printf("<HEAD><TITLE>ipidentifier</TITLE><META CHARSET=\"utf-8\"></META></HEAD>\n");
        printf("<BODY BGCOLOR=\"#DDFFFF\">\n");
        
	}
}

void classify_ip(int *a, int *b, int *c, int *d)
{
	if(*a<128)
	{
		printf("<H1>L'addresse : %d.%d.%d.%d ", *a, *b, *c, *d);
		printf("est de classe A</H1>\n");
		printf("<FORM ACTION=\"get_ip.cgi\" METHOD=\"GET\">\n");
		printf("<INPUT TYPE=\"SUBMIT\" VALUE=\"Identifier une autre addresse ip\"/>\n");
		printf("</FORM>\n");
		printf("</BODY>\n");
		printf("</HTML>\n");
	}
	if(127<*a && *a<192)
	{
		printf("<H1>L'addresse : %d.%d.%d.%d ", *a, *b, *c, *d);
		printf("est de classe B</H1>\n");
		printf("<FORM ACTION=\"get_ip.cgi\" METHOD=\"GET\">\n");
		printf("<INPUT TYPE=\"SUBMIT\" VALUE=\"Identifier une autre addresse ip\"/>\n");
		printf("</FORM>\n");
		printf("</BODY>\n");
		printf("</HTML>\n");
	}
	if(192<*a && *a<224)
	{
		printf("<H1>L'addresse : %d.%d.%d.%d ", *a, *b, *c, *d);
		printf("est de classe C</H1>\n");
		printf("<FORM ACTION=\"get_ip.cgi\" METHOD=\"GET\">\n");
		printf("<INPUT TYPE=\"SUBMIT\" VALUE=\"Identifier une autre addresse ip\"/>\n");
		printf("</FORM>\n");
		printf("</BODY>\n");
		printf("</HTML>\n");
	}
	if(224<*a && *a<256)
	{
		printf("<H1>L'addresse : %d.%d.%d.%d ", *a, *b, *c, *d);
		printf("est de classe D</H1>\n");
		printf("<FORM ACTION=\"get_ip.cgi\" METHOD=\"GET\">\n");
		printf("<INPUT TYPE=\"SUBMIT\" VALUE=\"Identifier une autre addresse ip\"/>\n");
		printf("</FORM>\n");
		printf("</BODY>\n");
		printf("</HTML>\n");
	}
}
