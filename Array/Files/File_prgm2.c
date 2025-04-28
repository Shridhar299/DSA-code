#include<stdio.h>  
void main( )  
{  
FILE *fp ;  
char ch, filename[20];
scanf("%s",&filename);  
fp = fopen(filename,"r");  
while ( 1 )  
{  
ch = fgetc ( fp ) ;  
if ( ch == EOF )  
break ;  
printf("%c",ch) ;  
}  
fclose (fp ) ;  
}  
