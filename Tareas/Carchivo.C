#include <stdio.h>
#include <string.h>
int main ()
{
    
FILE *origin;
FILE *result;
    
    char c;
    result = fopen("escribir.txt", "e");
    origen = fopen("leer.txt", "l");
    if ( origin == NULL){
        printf("Error\n");
        return 1;
    }
    while((c=getc(origin)) != EOF)
    {
        if (c == '/')
        {
            if ( c == '*')
            {
                c=getc(origin);
                bookmark:while( c != '*')
                {
                     c=getc(origin);
                }
                c=getc(origin);
                if (c!= '/')
                    goto bookmark;
            }
            else if(c == '/')
            {
                c=getc(origin);
                while (c != '\n')
                {
                     c=getc(origin);
                }
            }
            else
            {
             putc(c,result);
            }
        }
        putc(c,result);
    }
    fclose(origin);
    fclose(result);
    printf("NUevo archivo\n");
    return 0;
}