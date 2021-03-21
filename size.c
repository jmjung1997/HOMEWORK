#include<stdio.h>
#include<stdlib.h>
void main()
{
    int **x;

    printf("정재민              2018038067\n\n");
    printf("sizeof(x) = %lu\n", sizeof(x)); // 더블 포인터 X의 값은 주소 메모리값인데 현재 기기가 32bit이므로 4byte가 출력 된다.
    printf("sizeof(*x) = %lu\n", sizeof(*x)); // 더블 포인터 x가 가리키는 값 또한 주소 메모리를 가지고 있어 4byte가 출력된다.
    printf("sizeof(**x) = %lu\n", sizeof(**x));// *p가 가리키고 있는 값은 정수형이므로 4byte가 출력된다.

}  