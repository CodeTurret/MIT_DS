#include <stdio.h>
#include <stdlib.h>

// Written By Mushfiq Fuad

// Function Initialization
int solvemaze(int r1, int c1);
void printSolution();


int main()
{
    int r,c,r1,c1;
    int i,j;

    // Two files, one for Maze and one for Solution
    FILE *fp;
    FILE *pf;

    printf("Please enter the row number: ");
    scanf("%d",&r);
    printf("Please enter the Column number: ");
    scanf("%d",&c);

    // Maze array
    int a[r][c];

    // Solution Array
    int solution[r][c];

    // open the file to write the Maze
    fp = fopen("ds.txt","w");
    if(fp==NULL)
     {
        printf("\nError opening File\n");
     }


    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            a[i][j]=rand() % 2;
            fprintf(fp, "%d\t", a[i][j]);
        }
        fprintf(fp, "\n\n");
    }

    fclose(fp);

    printf("\tThe Maze\n");

    // Filling the array with  Random Number
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }


    // for solution file
    pf = fopen("ds_solve.txt","w");
    if(pf==NULL)
     {
        printf("\nError opening File\n");
     }



    // Solution of Maze
    int solvemaze(r1,  c1)
    {
        //if destination is reached, maze is solved
        //destination is the last cell(maze[r-1][c-1])
        if((r1==r-1) && (c1==c-1))
        {
            solution[r1][c1] = 2;
            fprintf(pf, "%d\t", solution[r1][c1]);
            return 1;
        }
        //checking if we can visit in this cell or not
        //the indices of the cell must be in (0,r-1)
        //and solution[r1][c1] == 0 is making sure that the cell is not already visited
        //a[r][c] == 0 is making sure that the cell is not blocked
        if(r1>=0 && c1>=0 && r1<r && c1<c && solution[r1][c1] == 0 && a[r1][c1] == 0)
        {
            //if safe to visit then visit the cell
            solution[r1][c1] = 2;
            fprintf(pf, "%d\t", solution[r1][c1]);
            //going down
            if(solvemaze(r1+1, c1))
                return 1;
            //going right
            if(solvemaze(r1, c1+1))
                return 1;
            //going up
            if(solvemaze(r1-1, c1))
                return 1;
            //going left
            if(solvemaze(r1, c1-1))
                return 1;
            //backtracking
            solution[r1][c1] = 0;
            fprintf(pf, "%d\t", solution[r1][c1]);
            return 0;
        }
        return 0;

    }


    // Printing the solution
    void printSolution()
    {
        int i,j;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                {
                    printf("%d",solution[i][j]);
                  }
                printf("\n\n");
            }
     }


    printf("\n\tSolution Maze");
    if (solvemaze(0,0)){
        printSolution();
     }
    else{
        printf("\nNo Solution Found\n");
        fprintf(pf, "\n No Solution\n");
     }

    // close the second file
    fclose(pf);


    return 0;

}


