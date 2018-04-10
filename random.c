#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define BASE_PONT 100000
int main(int argc, char const *argv[])
{
    FILE * fp = NULL;
    int scale = 0;
    int i     = 0;
    int same  = 0;
    char choice;
    double rdm = 0.0;
    double q   = 0.0;
    double r   = 0.0;
    double temp;

    if (argc != 4)
    {
        printf("format error!\n");
        return 1;
    }
    scale = atoi ( argv [1] );

    fp = fopen ( argv [2], "w");
    choice = * argv [3];
    switch(choice)
    {
    case 's':
        same = 1;
        break;
    case 'd':
        same = 0;
        break;
    default:
        printf("Just 's' or 'd'\n");
        break;
    }

    srand(time(NULL));   // should only be called once

    q = (double)rand();
    do
    {
        r = ((double)(rand() % BASE_PONT))/BASE_PONT;
    } while (r == (double)0.0);
    temp = q+r;

    for (i = scale; i >= 2; --i)
    {
        if (same)
        {
            rdm = temp;
            fprintf(fp, "%f,", rdm);
        }
        else
        {
            q = (double)rand();
            do
            {
                r = ((double)(rand() % BASE_PONT))/BASE_PONT;
            } while (r == (double)0.0);
            rdm = q+r;
            fprintf(fp, "%f,", rdm);
        }
    }
    rdm = temp;
    fprintf(fp, "%f\n", rdm);

    fclose ( fp );
    return 0;
}
