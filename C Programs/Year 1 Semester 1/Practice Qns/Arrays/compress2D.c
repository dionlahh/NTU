#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main()
{
    int data[SIZE][SIZE];
    int i,j;
    int rowSize, colSize;
    printf("Enter the array size (rowSize, colSize): \n");
    scanf("%d %d", &rowSize, &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++) 
        for (j=0; j<colSize; j++)
            scanf("%d", &data[i][j]);
    printf("compress2D(): \n");
    compress2D(data, rowSize, colSize);
    return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
    int i, j, k, current, count, result_rpos = 0, result_cpos = 0;
    int result[SIZE*2][SIZE*2];

    for (i=0; i<rowSize; i++)
    {
        current = data[i][0];
        count = 0;
        result_cpos = 0;
        result[result_rpos][result_cpos] = current;
        result[result_rpos][++result_cpos] = 0;
        for (j=0; j<colSize; j++)
        {
            if (data[i][j] == current)
            {
                result[result_rpos][result_cpos]++;
            }
            else
            {
                current = data[i][j];
                result[result_rpos][++result_cpos] = data[i][j];
                result[result_rpos][++result_cpos] = 1;
            }
            
        }
    
        for (k=0; k<=result_cpos; k++)
        {
            printf("%d ", result[result_rpos][k]);
        }
        printf("\n");
        result_rpos++;
    }
} 