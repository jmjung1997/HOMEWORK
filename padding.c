#include<stdio.h>

struct student{ //student 구조체 선언
    char lastName[13];
    int studentId; 
    short grade;
};


int main()
{
    printf("정재민       2018038067\n\n");
    struct student pst; //pst 타입 구조체 선언하기

    printf("size of student = %ld\n", sizeof(struct student)); // student 구조체 padding에 의해 19byte가 아닌 24byte출력
    printf("size of int = %ld\n", sizeof(int)); // int 사이즈 4byte 출력
    printf("size of short = %ld\n", sizeof(short)); // short 사이즈 2byte 출력

    return 0; 

}


