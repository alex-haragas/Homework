#include <stdio.h>
#include <stdlib.h>

void labmove(int n,int m,int **lab,int curow,int curcol,int** traillab,int nrsteps, int *nr);
int isout(int n,int m,int row,int col);

int main() {
    int n,m;
    int** lab;
    int startrow,startcol;
    printf("Input nr of rows:");
    scanf("%d",&n);
    printf("Input nr of columns:");
    scanf("%d",&m);
    lab=(int**)malloc(n* sizeof(int*));
    int** traillab=(int**)malloc(n*sizeof(int*));
    printf("Input labyrinth map:\n");
    for(int i=0;i<n;i++)
    {
        lab[i]=(int*)malloc(m* sizeof(int));
        traillab[i]=(int*)malloc(m* sizeof(int));
        for(int j=0;j<m;j++)
        {
            scanf("%d",&lab[i][j]);
            traillab[i][j]=0;
        }
    }
    printf("Input starting row:");
    scanf("%d",&startrow);
    printf("Input starting col:");
    scanf("%d",&startcol);
    if(lab[startrow][startcol]==0 || isout(n,m,startrow,startcol))
    {
        printf("Impossible to find a way out");
    }
    else {
        int nr = 0;
        labmove(n, m, lab, startrow, startcol, traillab, 0, &nr);
        if(nr==0)
            printf("Impossible to find a way out");
    }
    for(int i=0;i<n;i++)
    {
        free(lab[i]);
        free(traillab[i]);
    }
    free(lab);
    free(traillab);
    return 0;
}
int isout(int n,int m,int row,int col)
{
    if(row>=n || row<0)
        return 1;
    if(col>=m || col<0)
        return 1;
    return 0;
}
int ismargin(int n,int m,int row,int col)
{
    if(row==0 || row==n-1)
        return 1;
    if(col==0 || col==m-1)
        return 1;
    return 0;
}
void printroad(int n,int m,int** trailab,int nr)
{
    printf("Option %d:\n",nr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d",trailab[i][j]);
        printf("\n");
    }
    printf("\n");
}
void labmove(int n,int m,int **lab,int currow,int curcol,int** traillab,int nrsteps, int *nr)
{
    if(lab[currow][curcol]!=0)
    {
        traillab[currow][curcol]=nrsteps+1;
        lab[currow][curcol]=0;
        if (ismargin(n, m, currow,curcol))
        {
            *nr=(*nr)+1;
            printroad(n,m,traillab,*nr);
        }
        else
            {
                 labmove(n, m, lab, currow - 1, curcol, traillab, nrsteps + 1, nr);
                 labmove(n, m, lab, currow, curcol + 1, traillab, nrsteps + 1, nr);
                 labmove(n, m, lab, currow + 1, curcol , traillab, nrsteps + 1,nr);
                 labmove(n, m, lab, currow , curcol - 1, traillab, nrsteps + 1,nr);
            }
        lab[currow][curcol]=1;
        traillab[currow][curcol]=0;
    }
}