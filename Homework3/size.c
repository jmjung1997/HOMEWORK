#include<stdio.h>
#include<stdlib.h>
void main()
{
    int **x;

    printf("�����              2018038067\n\n");
    printf("sizeof(x) = %lu\n", sizeof(x)); // ���� ������ X�� ���� �ּ� �޸𸮰��ε� ���� ��Ⱑ 32bit�̹Ƿ� 4byte�� ��� �ȴ�.
    printf("sizeof(*x) = %lu\n", sizeof(*x)); // ���� ������ x�� ����Ű�� �� ���� �ּ� �޸𸮸� ������ �־� 4byte�� ��µȴ�.
    printf("sizeof(**x) = %lu\n", sizeof(**x));// *p�� ����Ű�� �ִ� ���� �������̹Ƿ� 4byte�� ��µȴ�.

}  