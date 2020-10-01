#include<stdio.h>

int main()
{

    int n, m, c, d, p, q, k, first[10][10], second[10][10], pro[10][10],sum = 0; //Initialize variables

    printf("\nEnter the number of rows and columns of the first matrix: \n\n");
    scanf("%d%d", &m, &n);

    printf("\nEnter the %d elements (row-wise) of the first matrix: \n\n", m*n);
    for(c = 0; c < m; c++)   // to iterate the rows
        for(d = 0; d < n; d++)   // to iterate the columns
            scanf("%d", &first[c][d]);

    printf("\nEnter the number of rows and columns of the first matrix: \n\n");
    scanf("%d%d", &p, &q);

    if(n != p)
        printf("Matrices with the given order cannot be multiplied with each other.\n\n");

    else    // matrices can be multiplied
    {
        printf("\nEnter the %d elements (row-wise) of the second matrix: \n\n",m*n);

        for(c = 0; c < p; c++)   // to iterate the rows
            for(d = 0; d < q; d++)   // to iterate the columns
                scanf("%d", &second[c][d]);

        // printing the first matrix
        printf("\n\nThe first matrix is: \n\n");
        for(c = 0; c < m; c++)   // to iterate the rows
        {
            for(d = 0; d < n; d++)   // to iterate the columns
            {
                printf("%d\t", first[c][d]);
            }
            printf("\n");
        }

        // printing the second matrix
        printf("\n\nThe second matrix is: \n\n");
        for(c = 0; c < p; c++)   // to iterate the rows
        {
            for(d = 0; d < q; d++)   // to iterate the columns
            {
                printf("%d\t", second[c][d]);
            }
            printf("\n");
        }

        for(c = 0; c < m; c++)   // to iterate the rows
        {
            for(d = 0; d < q; d++)   // to iterate the columns
            {
                for(k = 0; k < p; k++)
                {
                    sum = sum + first[c][k]*second[k][d];
                }
            pro[c][d] = sum;    // resultant element of pro after multiplication
            sum = 0;    // to find the next element from scratch
            }
        }

        // printing the elements of the product matrix
        printf("\n\nThe multiplication of the two entered matrices is: \n\n");
        for(c = 0; c < m; c++)   // to iterate the rows
        {
            for(d = 0; d < q; d++)   // to iterate the columns
            {
                printf("%d\t", pro[c][d]);
            }
            printf("\n"); // to take the control to the next row
        }
    }

    return 0;
}
