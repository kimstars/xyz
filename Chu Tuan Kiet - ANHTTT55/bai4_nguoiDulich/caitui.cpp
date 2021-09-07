#include <iostream>
#include <stdio.h>
#include <conio.h>
#define MAX 100
int x[MAX], y[MAX];
int w[MAX];
int v[MAX];
int n;
int m;
int wrem;
int a;
float b;
int vmax, vsel, wsel;
FILE *fp;
char *finp = "balo.inp";
char *fout = "balo.out";
void init();
void ouput();
void ghinhan();
void Try(int i);
void main()
{
    init();
    Try(1);
    output();
    getch();
}
void init()
{
    int i;
    if ((fp = fopen(finp, "r")) != NULL)
    {
        fscanf(fp, "%d %d\n", &n, &m);
        for (i = 1; i <= n; i++)
        {
            fscanf(fp, "%d", &w[i]);
        }
        fscanf(fp, "\n");
        for (i = 1; i <= n; i++)
        {
            fscanf(fp, "%d", &v[i]);
        }
        //======
        a = 0;
        wrem = m;
        b = wrem * v[1] / (float)w[1];
        vmax = 0;
        vsel = 0;
        wsel = 0;
        fclose(fp);
    }
    else
    {
        printf("Khong tim thay file input");
        exit(1);
    }
}
void output()
{
    if ((fp = fopen(fout, "w")) != NULL)
    {
        int i;
        fprintf(fp, "%d\n", vmax);
        for (i = 1; i <= n; i++)
        {
            fprintf(fp, "%3d", y[i]);
        }
        fclose(fp);
    }
    else
    {
        printf("Khong tim thay file output");
    }
}
void ghiNhan()
{
    int i;
    if (vmax < vsel)
    {
        vmax = vsel;
        for (i = 1; i <= n; i++)
        {
            y[i] = x[i];
        }
    }
}
void Try(int i)
{
    int j;
    for (j = 0; j <= wrem / (float)w[i]; j++)
    {
        b = vsel + j * v[i] + (wrem - j * w[i]) * v[i + 1] / (float)w[i + 1];
        if (b >= vmax)
        {
            x[i] = j;
            vsel = vsel + j * v[i];
            wsel = wsel + j * w[i];
            wrem = wrem - j * w[i];
            if ((i == n) || (wrem <= 0)){}
            else ghiNhan();
            Try(i + 1);
            x[i] = 0;
            vsel = vsel - j * v[i];
            wsel = wsel - j * w[i];
            wrem = wrem + j * w[i];
        }
    }
    return ;
}