#!/bin/bash

#J'ai conçu ce script pour eviter de compiler un à un chaque fichier .c

gcc sources/acceuil.c -o sources/acceuil.cgi
cp sources/acceuil.cgi /var/www/html

gcc sources/create_account.c -o sources/create_account.cgi
cp sources/create_account.cgi /var/www/html

gcc sources/login.c -o sources/login.cgi
cp sources/login.cgi /var/www/html

gcc sources/save.c -o sources/save.cgi
cp sources/save.cgi /var/www/html

gcc sources/get_ip.c -o sources/get_ip.cgi
cp sources/get_ip.cgi /var/www/html

gcc sources/ipidentifier.c -o sources/ipidentifier.cgi
cp sources/ipidentifier.cgi /var/www/html

systemctl restart apache2



