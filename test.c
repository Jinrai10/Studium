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
    return 0;
}
