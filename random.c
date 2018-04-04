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
    }
    scale = atoi ( argv [1] );

    fp = fopen ( "./test.dat", "w");

    srand(time(NULL));   // should only be called once

    for (int i = scale; i >= 2; --i)
    {
        rdm = rand();
        fprintf(fp, "%d, ", rdm);
    }
    rdm = rand();
    fprintf(fp, "%d\n", rdm);

    fclose ( fp );
}