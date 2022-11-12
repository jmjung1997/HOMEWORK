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
    printf("[----- [정재민]  [2018038067] -----]\n");

    int row, col;
    srand(time(NULL));//항상 변하는 time을 이용해서 srand 값을 넣는다.

    printf("Input row and col : ");
    scanf("%d %d", &row, &col); //행과 열을 입력 받는다.
    
    while (row <= 0 || col <= 0)//행과 열을 0이하 입력 받았을 때 다시 입력 받는다.
    {
        printf("다시 입력하세요 : ");
        scanf("%d %d", &row, &col); 
    }


    int** matrix_a = create_matrix(row, col);/*동적할당을 통해 배열공간 생성*/
    int** matrix_b = create_matrix(row, col);/*동적할당을 통해 배열공간 생성*/
    int** matrix_a_t = create_matrix(col, row);/*동적할당을 통해 배열공간 생성*/

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) { return -1; }

    do {                                  /*메뉴 출력*/
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command); //switch명령어 입력 

        switch (command)
        {
        case 'z': case 'Z': //행렬 초기화 명령
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col); //fill_data함수를 이용해서 데이터 넣기
            fill_data(matrix_b, row, col);//fill_data함수를 이용해서 데이터 넣기
            break;
        case 'p': case 'P'://matrix_a, matrix_b 행렬 출력
            printf("Print matrix\n\n\n");
            printf("matrix_a\n\n");
            print_matrix(matrix_a, row, col);
            printf("\nmatrix_b\n\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A'://matrix_a, matrix_b 행렬 덧셈
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S'://matrix_a, matrix_b 행렬 뺄셈
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T'://matrix_a 행렬 전치
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            int **matrix_t=transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_t, col, row);
            break;
        case 'm': case 'M'://matrix_a와 matrix_a_t의 곱 
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);            
            break;
        case 'q': case 'Q'://동적할당 된 메모리들을 해제
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
int** create_matrix(int row, int col) //행렬 동적할당 함수
{    
    
    int** matrix = malloc(sizeof(int*) * row); //더블 포인터를 이용하여 주소의 크기를 행수만큼 할당 
    for (int i = 0; i < row; i++)
        matrix[i] = malloc(sizeof(int) * col); //각 행에  정수형 사이즈만큼 열을 배열한다. 
    
    return matrix; 
    
}







/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col) //행렬 출력함수
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
int free_matrix(int** matrix, int row, int col) //할당된 메모리 해제함수
{
    for (int i = 0; i < row; i++) //먼저 각 행에 대한 메모리부터 해제한다.
    {
        free(matrix[i]);
    }
    free(matrix); //열에 해당하는 공간 메모리를 해제한다.
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)//행렬에 데이터를 넣은다.
{
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] = rand() % 20; //rand 함수를 이용하여 행렬에 데이터를 넣는다.
    return matrix;

        if (matrix == NULL) //만약 행렬 전부 값이 0이 될 경우일때 fill_data함수를 다시 호출한다.
    {
        fill_data(matrix,row,col); 
    }
    return matrix;


}
/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)//두 개의 행렬을 더하는 함수
{
    int** matrix_sum = malloc(sizeof(int*) * row); /*행렬을 더해서 저장 할 수 있는 변수를 동적할당을 통해 생성*/

    for (int i = 0; i < row; i++)
        matrix_sum[i] = malloc(sizeof(int) * col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    print_matrix(matrix_sum, row, col);//더한 행렬 출력하기


    free_matrix(matrix_sum, row, col);//matrix_sum 할당된 메모리 해제 하기

}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)//두 개의 행렬을 빼는 함수
{
    int** matrix_sub = malloc(sizeof(int*) * row);/*행렬을 빼서 저장 할 수 있는 변수를 동적할당을 통해 생성*/

    for (int i = 0; i < row; i++)
        matrix_sub[i] = malloc(sizeof(int) * col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];
        }
    print_matrix(matrix_sub, row, col);//뺀 행렬 출력하기

    free_matrix(matrix_sub, row, col);//matrix_sub 할당된 메모리 해제 하기
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col) //전치 행렬 함수
{
    
    
    for (int j = 0; j < row; j++)
        for (int i = 0; i <col; i++)
            matrix_t[j][i] = matrix[i][j];//각 열과 각 행의 있는 데이터를 서로 바꾼다.
  
    return(matrix_t);//전치된 함수 리턴
   

}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)//matrix_a와 전치된 matrix_t 곱 구하기
{
    int mul = 0;
    int** matrix_multi = malloc(sizeof(int*) * row); /*두 행렬을 곱해서 저장 할 수 있는 변수를 동적할당을 통해 생성*/

    for (int i = 0; i < row; i++)
        matrix_multi[i] = malloc(sizeof(int) * row);
   
    
    for (int t = 0; t < row; t++) // matrix_a의 행 반복
    {
        for (int i = 0; i < row; i++)//matrix_t의 열 반복 
        {
            mul = 0;
            for (int j = 0; j < col; j++)//matrix_a 열과 matrix_b의 행 반복
            {
               mul += matrix_a[t][j] * matrix_t[j][i]; //두 행렬의 데이터 곱

            }
            matrix_multi[t][i] = mul; //각 행,열에 해당하는 데이터 곱을 matrix_multi에 저장 
        }
        
    }

    print_matrix(matrix_multi, row, row); 
    free_matrix(matrix_multi, row, row); //동적 메모리할당 해제
}


