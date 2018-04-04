#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * fp = NULL;
    int scale = 0;
    int rdm   = 0;

    if (argc != 2)
    {
        printf("format error!\n");
        return 1;
    }
    scale = atoi ( argv [1] );

    fp = fopen ( "./test.dat", "w");

    srand(time(NULL));   // should only be called once

    for (int i = scale; i >= 2; --i)
    {
        rdm = rand();
        fprintf(fp, "%i,", rdm);
    }
    rdm = rand();
    fprintf(fp, "%i\n", rdm);

    fclose ( fp );
    return 0;
}