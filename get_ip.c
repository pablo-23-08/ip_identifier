#include <stdio.h>

void get_ip();

int main() {
   get_ip();
    return 0;
}

void get_ip()
{
	printf("Content-Type: text/html\n\n");
    printf("<HTML>\n");
    printf("<HEAD><TITLE>get_ip</TITLE><META CHARSET=\"utf-8\"></META></HEAD>\n");
    printf("<BODY BGCOLOR=\"#DDFFFF\">\n");
    printf("<H1>Veuillez entrer une addresse IP : </H1>\n");
    printf("<FORM ACTION=\"ipidentifier.cgi\" METHOD=\"GET\">\n");
    printf("<INPUT TYPE=\"text\" NAME=\"ip\" VALUE=\"\" PLACEHOLDER=\"XXX.XXX.XXX.XXX\"/><BR><BR>\n");
    printf("<INPUT TYPE=\"SUBMIT\" VALUE=\"Identifier\"/>\n");
    printf("</FORM>\n");
    printf("</BODY>\n");
    printf("</HTML>\n");
}



