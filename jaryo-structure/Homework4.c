#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    printf("[----- [�����]  [2018038067] -----]\n");

    int row, col;
    srand(time(NULL));//�׻� ���ϴ� time�� �̿��ؼ� srand ���� �ִ´�.

    printf("Input row and col : ");
    scanf("%d %d", &row, &col); //��� ���� �Է� �޴´�.
    
    while (row <= 0 || col <= 0)//��� ���� 0���� �Է� �޾��� �� �ٽ� �Է� �޴´�.
    {
        printf("�ٽ� �Է��ϼ��� : ");
        scanf("%d %d", &row, &col); 
    }


    int** matrix_a = create_matrix(row, col);/*�����Ҵ��� ���� �迭���� ����*/
    int** matrix_b = create_matrix(row, col);/*�����Ҵ��� ���� �迭���� ����*/
    int** matrix_a_t = create_matrix(col, row);/*�����Ҵ��� ���� �迭���� ����*/

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) { return -1; }

    do {                                  /*�޴� ���*/
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command); //switch��ɾ� �Է� 

        switch (command)
        {
        case 'z': case 'Z': //��� �ʱ�ȭ ���
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col); //fill_data�Լ��� �̿��ؼ� ������ �ֱ�
            fill_data(matrix_b, row, col);//fill_data�Լ��� �̿��ؼ� ������ �ֱ�
            break;
        case 'p': case 'P'://matrix_a, matrix_b ��� ���
            printf("Print matrix\n\n\n");
            printf("matrix_a\n\n");
            print_matrix(matrix_a, row, col);
            printf("\nmatrix_b\n\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A'://matrix_a, matrix_b ��� ����
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S'://matrix_a, matrix_b ��� ����
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T'://matrix_a ��� ��ġ
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            int **matrix_t=transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_t, col, row);
            break;
        case 'm': case 'M'://matrix_a�� matrix_a_t�� �� 
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);            
            break;
        case 'q': case 'Q'://�����Ҵ� �� �޸𸮵��� ����
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col) //��� �����Ҵ� �Լ�
{    
    
    int** matrix = malloc(sizeof(int*) * row); //���� �����͸� �̿��Ͽ� �ּ��� ũ�⸦ �����ŭ �Ҵ� 
    for (int i = 0; i < row; i++)
        matrix[i] = malloc(sizeof(int) * col); //�� �࿡  ������ �����ŭ ���� �迭�Ѵ�. 
    
    return matrix; 
    
}







/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col) //��� ����Լ�
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%2d  ", matrix[i][j]);
        }
        printf("\n");
    }



}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col) //�Ҵ�� �޸� �����Լ�
{
    for (int i = 0; i < row; i++) //���� �� �࿡ ���� �޸𸮺��� �����Ѵ�.
    {
        free(matrix[i]);
    }
    free(matrix); //���� �ش��ϴ� ���� �޸𸮸� �����Ѵ�.
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)//��Ŀ� �����͸� ������.
{
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] = rand() % 20; //rand �Լ��� �̿��Ͽ� ��Ŀ� �����͸� �ִ´�.
    return matrix;

        if (matrix == NULL) //���� ��� ���� ���� 0�� �� ����϶� fill_data�Լ��� �ٽ� ȣ���Ѵ�.
    {
        fill_data(matrix,row,col); 
    }
    return matrix;


}
/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)//�� ���� ����� ���ϴ� �Լ�
{
    int** matrix_sum = malloc(sizeof(int*) * row); /*����� ���ؼ� ���� �� �� �ִ� ������ �����Ҵ��� ���� ����*/

    for (int i = 0; i < row; i++)
        matrix_sum[i] = malloc(sizeof(int) * col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    print_matrix(matrix_sum, row, col);//���� ��� ����ϱ�


    free_matrix(matrix_sum, row, col);//matrix_sum �Ҵ�� �޸� ���� �ϱ�

}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)//�� ���� ����� ���� �Լ�
{
    int** matrix_sub = malloc(sizeof(int*) * row);/*����� ���� ���� �� �� �ִ� ������ �����Ҵ��� ���� ����*/

    for (int i = 0; i < row; i++)
        matrix_sub[i] = malloc(sizeof(int) * col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];
        }
    print_matrix(matrix_sub, row, col);//�� ��� ����ϱ�

    free_matrix(matrix_sub, row, col);//matrix_sub �Ҵ�� �޸� ���� �ϱ�
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col) //��ġ ��� �Լ�
{
    
    
    for (int j = 0; j < row; j++)
        for (int i = 0; i <col; i++)
            matrix_t[j][i] = matrix[i][j];//�� ���� �� ���� �ִ� �����͸� ���� �ٲ۴�.
  
    return(matrix_t);//��ġ�� �Լ� ����
   

}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)//matrix_a�� ��ġ�� matrix_t �� ���ϱ�
{
    int mul = 0;
    int** matrix_multi = malloc(sizeof(int*) * row); /*�� ����� ���ؼ� ���� �� �� �ִ� ������ �����Ҵ��� ���� ����*/

    for (int i = 0; i < row; i++)
        matrix_multi[i] = malloc(sizeof(int) * row);
   
    
    for (int t = 0; t < row; t++) // matrix_a�� �� �ݺ�
    {
        for (int i = 0; i < row; i++)//matrix_t�� �� �ݺ� 
        {
            mul = 0;
            for (int j = 0; j < col; j++)//matrix_a ���� matrix_b�� �� �ݺ�
            {
               mul += matrix_a[t][j] * matrix_t[j][i]; //�� ����� ������ ��

            }
            matrix_multi[t][i] = mul; //�� ��,���� �ش��ϴ� ������ ���� matrix_multi�� ���� 
        }
        
    }

    print_matrix(matrix_multi, row, row); 
    free_matrix(matrix_multi, row, row); //���� �޸��Ҵ� ����
}


