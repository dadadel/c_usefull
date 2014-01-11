/* 
 * This is just for fun! It is really unusefull and 
 * ugly unless you need to multiply two numbers 
 * without using any multiplication or division.
 * I found this in a very old notebook where I was 
 * writing some C code ago to convert to assembly.
 *
 */

#include <stdio.h> 
#include <stdlib.h> 

int mul(int a, int b)
{
    int c,i,n1=0,n2=0;
    if (b>a){c=a; a=b; b=c;}
    c=0;
    if(b<0){n1=1; b=-b;}
    if(a<0){n2=1; a=-a;}
    for(i=14;i>=0;i--)if(b & (1<<i))c+=a<<i;
    if(n1 ^ n2)c=-c;
    return c;
}

int main(int argc, char **argv)
{
    int a, b;
    if (argc == 3)
    {
      a = atoi(argv[1]);
      b = atoi(argv[2]);
      printf ("%d * %d = %d (expected %d)\n",a, b, mul(a, b), a * b);
    }
    printf("5 * 2 = %d (expected %d)\n",mul(5,2), 5 * 2);
    printf("-155 * 2 = %d (expected %d)\n",mul(-155, 13), -155 * 13);
    printf("26981 * 49853 = %d (expected %d)\n",mul(26981, 49853), 26981 * 49853 );
    
    return 0;
}
