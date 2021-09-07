#include <iostream>
#include <cmath>

using namespace std;
int a[20][20] = {0};

int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};

int main()
{
    a[5][5] = 1;

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("------------------------------------------");
    
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (a[i][j])
            {
                for (int t = 0; t < 8; t++)
                {
                    int x = i + X[t];
                    int y = j + Y[t];
                    a[x][y] = 1;
                }
                goto LABEL1;
            }
        }
        printf("\n");
    }
LABEL1 :

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}