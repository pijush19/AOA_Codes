#include <stdio.h>
#include <math.h>
#include <string.h>
#define SIZE 50

void RabinKarp(const char T[], const char P[], int d, int q)
{
    int n = strlen(T);
    int m = strlen(P);
    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    int p = 0, t = 0;
    int ts = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + P[i]) % q;
        t = (t * d + T[i]) % q;
    }

    for (int s = 0; s <= n - m; s++)
    {
        if (p == t)
        {
            int j = 0;
            for (j = 0; j < m; j++)
            {
                if (T[s + j] != P[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                printf("Pattern found with shift :%d", s);
            }
        }
        if (s < n - m)
        {
            t = (d * (t - T[s] * h) + T[s + m]) % q;

            if (t < 0)
            {
                t = t + q;
            }
        }
    }
}
int main()
{
    // t = (d * (t - T[s] * h) + T[s + m] ) % q;
    int d = 256;
    int q = 101;
    char text[SIZE], pattern[SIZE];
    printf("Enter text:\n");
    scanf("%s", &text);
    printf("Enter pattern:\n");
    scanf("%s", &pattern);

    RabinKarp(text, pattern, d, q);
    return 0;
}