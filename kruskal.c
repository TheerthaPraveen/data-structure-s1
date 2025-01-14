#include <stdio.h>
#include <stdlib.h>
void kruskal();

int n, a[20][20] = {0}, r[30][30] = {0}, p[20];
void main()
{
    int i, j;
    printf("Enter the no of vertices");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            printf("(%d,%d)=", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        p[i] = i;
    }
   
    
     kruskal();

}

int find(int x)
{
    while (p[x] != x)
    {
        x = p[x];
    }
    return x;
}
void uni(int x, int y)
{
    int m, n;
    m = find(x);
    n = find(y);
    p[n] = m;
}


void kruskal()
{

    int e = 0, i, min, j, u, v,c=0;
    while (e < n - 1)
    {
        min = 9999;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][j] < min && a[i][j]!=0)
                {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        a[u][v] = 9999;
        a[v][u] = 9999;


        if (find(u) != find(v))
        {
            uni(u,v);
            r[u][v] = min;
            r[v][u] = min;
            c=c+min;
            e += 1;
    printf("Edge (%d, %d) = %d\n", u, v, min); // Print the edge.
        }
    }
    printf("Total cost of MST: %d\n", c);
}

