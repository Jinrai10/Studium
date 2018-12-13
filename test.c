#include <stdio.h>
// STandarD Input Output

void drucken(char ausgabe[])
{
    printf("%s\n", ausgabe);
}

int function(int x)
{
    return x*x;
}

int main()
{
    int x = 5;
    int y = function(x);
    // der ganzzahl y wird der Rückgabewert der Funktion function mit dem Parameter x zugewiesen
    printf("%i\n", y);

    int * b = NULL;
    int c = 5;
    int *zeiger = &c;
    b = zeiger;
    (*b)+=1;
    printf("Pointer: %p\nValue: %i\n",zeiger, *zeiger );
    printf("Pointer: %p\nValue: %i\n",b, *b );
    //printf("%i_%i\n", *a, *b);

    return 0;
}
