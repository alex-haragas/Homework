#include <stdio.h>
#include <stdlib.h>

void labmove(int n, int **chess, int curow, int curcol, int nrsteps, int *nr);

int main() {
    int n;
    int** chess;
    printf("Input board size: ");
    scanf("%d", &n);
    chess=(int**)malloc(n * sizeof(int*));
    for(int i=0;i<n;i++)
    {
        chess[i]=(int*)malloc(n * sizeof(int));
        for(int j=0;j<n;j++)
        {
            chess[i][j]=0;
        }
    }
    int nr = 0;
    labmove(n, chess, 0, 0, 1, &nr);
    if(nr==0)
        printf("Impossible to create a trail");
    for(int i=0;i<n;i++)
    {
        free(chess[i]);
    }
    free(chess);
    return 0;
}
int isout(int n,int row,int col) {
    if (row >= n || row < 0)
        return 1;
    if (col >= n || col < 0)
        return 1;
    return 0;
}
void printroad(int n,int** chess,int nr)
{
    printf("Option %d:\n",nr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",chess[i][j]);
        printf("\n");
    }
    printf("\n");
}
void labmove(int n, int **chess, int currow, int curcol, int nrsteps, int *nr)
{
    if(isout(n,currow,curcol)==0) {
        if (chess[currow][curcol] == 0)
        {
            chess[currow][curcol] = nrsteps;
            if (nrsteps == n * n) {
                *nr = (*nr) + 1;
                printroad(n, chess, *nr);
            } else {
                labmove(n, chess, currow - 2, curcol - 1, nrsteps + 1, nr);
                labmove(n, chess, currow - 2, curcol + 1, nrsteps + 1, nr);
                labmove(n, chess, currow - 1, curcol + 2, nrsteps + 1, nr);
                labmove(n, chess, currow + 1, curcol + 2, nrsteps + 1, nr);
                labmove(n, chess, currow + 2, curcol + 1, nrsteps + 1, nr);
                labmove(n, chess, currow + 2, curcol - 1, nrsteps + 1, nr);
                labmove(n, chess, currow + 1, curcol - 2, nrsteps + 1, nr);
                labmove(n, chess, currow - 1, curcol - 2, nrsteps + 1, nr);
            }
            chess[currow][curcol] = 0;
        }
    }
}