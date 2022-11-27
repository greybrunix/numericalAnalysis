#include <stdio.h>
#include <stdlib.h>

double
poLagrange(xi,yi,x,n)
double *xi;
double *yi;
double x;
int n;
{

double px = 0;
double num; double den;
int i = 0; int j = 0;
for (i = 0; i<n; i++)
{
    num=1.0;den=1.0;
    for (j = 0;j<n;j++)
    {
        if (j != i)
        {
            num = num*(x-xi[j]);
            den = den*(xi[i]-xi[j]);
        }
    }
    px = px + yi[i] * (num/den);
}

return px;
}

int
main(argc, argv)
int argc;
char**argv;
{ int flag_err = 0;
if (argc != 2)
{
    flag_err = 1;
}
if (!flag_err)
{
    char * pointer;
    double *xi = malloc(10*sizeof (double));
    xi[0] = 0.1;
    xi[1] = 0.3;
    xi[2] = 0.5;
    xi[3] = 0.6;
    xi[4] = 0.7;
    double *yi = malloc(10*sizeof (double));
    yi[0] = 1.1;
    yi[1] = 5.8;
    yi[2] = 7.9;
    yi[3] = 4.2;
    yi[4] = 9.6;
    double x = strtod(*(argv+1),&pointer);
    int n = 5;
    double y = poLagrange(xi,yi,x, n);

    printf("%lf\n",y);
    free(xi);
    free(yi);
}
return flag_err;
}
