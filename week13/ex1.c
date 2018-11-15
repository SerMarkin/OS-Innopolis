#include <stdio.h>
#include <stdlib.h>
void readInput(FILE *f, int m, int n, int *e, int *a, int **c, int **r)
{
    for (int i = 0; i < m; i++)
        fscanf(f, "%1d", &e[i]);

    for (int i = 0; i < m; i++)
        fscanf(f, "%1d", &a[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(f, "%1d", &c[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(f, "%1d", &r[i][j]);
}
int main()
{
    //input
    int m = 3, n = 5;
    int *e, *a, **c, **r;
    e = malloc(m * sizeof(*e));
    a = malloc(m * sizeof(*a));

    c = malloc(n * sizeof(*c));
    r = malloc(n * sizeof(*r));
    for (int i = 0; i < n; i++)
    {
        c[i] = malloc(m * sizeof(*c[i]));
        r[i] = malloc(m * sizeof(*r[i]));
    }
    FILE *f = fopen("input_ok.txt", "r");
    readInput(f, m, n, e, a, c, r);
    //main part
    int have_one = 0;
    int dl = 0;
    int *look = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        have_one = 0;
        for (int j = 0; j < n; j++)
        {
            if (look[j])
                continue;
            int run = 1;
            for (int k = 0; k < m; k++)
            {
                if (c[j][k] + a[k] < r[j][k])
                {
                    run = 0;
                    break;
                }
            }
            if (run == 0)
            {
                look[j] = 1;
                have_one = 1;
                for (int k = 0; k < m; k++)
                {
                    a[k] += c[j][k];
                    c[j][k] = 0;
                }
                break;
            }
        }
        if (have_one == 0)
            dl = 1;
    }
    //output part
    FILE *fout = fopen("output_ok.txt", "w");
    if (dl)
    {
        fprintf(fout, "Deadlocks:\n");
        for (int i = 0; i < n; i++)
        {
            if (!look[i])
                fprintf(fout, "%d\n", i + 1);
        }
    }
    else
        fprintf(fout, "No deadlock\n");
    fclose(f);
    fclose(fout);
    return 0;
}