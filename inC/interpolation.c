#include <stdio.h>
#include <stdlib.h>


void
div_dif_table(T,xi,yi,n)
    double **T, *xi, *yi;
    int n;
{
int i,j;

for (i = 0; i<n; i++)
T[i][0] = yi[i];

for (j=1;j<n;j++)
for (i=j;i<n;i++)
T[i][j]=(double)((T[i][j-1]) - (T[i-1][j-1]))/(xi[i]-xi[(i-j)+1]);
}

double
poNewton(xi,yi,x,n)
    double *xi, *yi, x;
    int n;
{

double px;
int i;

double **T = (double **)malloc(n * sizeof(double*));
for (i = 0; i < n; i++)
T[i] = (double *)malloc(n * sizeof(double));
div_dif_table(T,xi,yi,n);
    
px = T[n-1][n-1];
for (i=n-1;i>=0;i--)
px = px*(x-*(xi+i))+T[i][i];

free(T);
return px;
}

double
poLagrange(xi,yi,x,n)
    double *xi, *yi;
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
{ 
int flag_err = 0;
if (argc != 2)
flag_err = 1;
if (!flag_err)
{
char * pointer;
double *xi = malloc(10*sizeof (double));
double *yi = malloc(10*sizeof (double));
double x = strtod(*(argv+1),&pointer);
xi[0] = 0.1;
xi[1] = 0.3;
xi[2] = 0.5;
xi[3] = 0.6;
xi[4] = 0.7;
yi[0] = 1.1;
yi[1] = 5.8;
yi[2] = 7.9;
yi[3] = 4.2;
yi[4] = 9.6;
int n = 5;
double px = poLagrange(xi,yi,x,n);
printf("%lf\n",px);
    
free(xi);
free(yi);
}
return flag_err;
}
