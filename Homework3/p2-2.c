#include<stdio.h>

void print1 (int *ptr, int rows);

int main()
{
    printf("\n\n정재민               2018038067\n\n");
    int one[]={0,1,2,3,4};
    printf(" one       = %p\n", one ); //배열 one의 값
    printf("&one      = %p\n", &one); //배열 one의 주소값
    printf("&one[0]   = %p\n", &one[0]); //배열 one[0]의 주소값
    printf("\n");

    print1(&one[0], 5); // 배열 순서대로 출력

    return 0;
}

void print1 (int *ptr, int rows) // 포인터 변수 ptr이 배열 one의 주소값을 전달 받는다.
{
    int i;
    printf("Address \t Contents\n");
    for(i=0; i<rows; i++)
        printf("%p \t  %5d\n", ptr + i, *(ptr+i)); /* 한칸씩 더하면서 출력한다. 
                                                    ptr의 주소값은 int형이서 4byte씩 증가하면서 출력되고 해당값도 한칸씩 미뤄지면서 각 위치에 대한 값이 출력된다.*/

    printf("\n");
 }