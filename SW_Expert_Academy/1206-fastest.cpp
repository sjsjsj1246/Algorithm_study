#include<stdio.h>
#define max(a,b) ((a)>=(b)?(a):(b))
int main()
{
    int a[1000];
    int i, j, k, n, m, t, cnt, ans, max, min, lmax, rmax;
    for (i = 0; i < 10; i++)
    {
        ans = 0;
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        for (j = 2; j < n - 2; j++)
        {
            lmax = 0;
            rmax = 0;
            for (k = 1; k < 3; k++)
            {
                if (lmax < a[j - k])
                    lmax = a[j - k];
                if (rmax < a[j + k])
                    rmax = a[j + k];
            }
            if (a[j] > max(lmax, rmax))
                ans += a[j] - max(lmax, rmax);
        }
        printf("#%d %d\n", i + 1, ans);
    }
}