#include<stdio.h>

struct student{ //student ����ü ����
    char lastName[13];
    int studentId; 
    short grade;
};


int main()
{
    printf("�����       2018038067\n\n");
    struct student pst; //pst Ÿ�� ����ü �����ϱ�

    printf("size of student = %ld\n", sizeof(struct student)); // student ����ü padding�� ���� 19byte�� �ƴ� 24byte���
    printf("size of int = %ld\n", sizeof(int)); // int ������ 4byte ���
    printf("size of short = %ld\n", sizeof(short)); // short ������ 2byte ���

    return 0; 

}


