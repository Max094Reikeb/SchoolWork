/**Packages */
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main ()
{

     float a1, b1, c1, a2, b2, c2, det, x, y;

     printf ("Résolution de deux équations à deux inconnues :\n");

     printf ("\nax + by = c\ndx + ey = f\n\nVeuillez saisir les coefficients a, b, ..., f :\n");
     printf ("a = ");
     scanf ("%f", &a1);
     printf ("b = ");
     scanf ("%f", &b1);
     printf ("c = ");
     scanf ("%f", &c1);
     printf ("d = ");
     scanf ("%f", &a2);
     printf ("e = ");
     scanf ("%f", &b2);
     printf ("f = ");
     scanf ("%f", &c2);

     det = a1*b2-a2*b1;
     x = (b1*c2-b2*c1)/det;
     y = (c1*a2-c2*a1)/det;

     printf ("\nLe determinant vaut : %f\n", det);

     if (det=0)
         printf ("\nPas de solution.\n");
     else
         printf ("x = %f\ny = %f\n", x, y);
}
