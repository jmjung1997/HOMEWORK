#include<stdio.h>
int humanEqual (struct humanBeing person1, struct humanBeing person2);
#define FALSE 0;
#define TRUE 1;
struct student1 { //student1 구조체 선언
    char lastName;
    int studentId;
    char grade;
};

typedef struct{ //typedef를 이용한 student2 구조체 선언
    char lastName;
    int studentId;
    char grade;
} student2;

int main() 
{
    printf("\n\n정재민            2018038067\n\n");
    struct student1 st1 = {'A', 100, 'A'}; // st1이라는 타입을 만들고 거기에 데이터를 집어 넣은다. 
                                            // 이때 struct을 꼭 붙여주어 구조체 라는것을 선언해야 한다.
    printf("st1.lastName = %c\n", st1.lastName); 
    printf("st1.studentID = %d\n", st1.studentId);
    printf("st1.grade = %c\n", st1.grade);

    student2 st2 = {'B',200 , 'B'}; //st2라는 타입을 만들고 거기에 데이터를 집어 넣은다. typedef struct이므로 선언할때 struct은 생략한다.

    printf("\nst.2lastName = %c\n", st2.lastName);
    printf("st.studentId = %d\n", st2.studentId);
    printf("st2.grade = %c\n", st2.grade);

    student2 st3;//st3 타입 선언

    st3 = st2; //st2에 있던 구조체 값들을  st3로 대입한다.

    printf("\nst3.lastName = %c\n",st3.lastName);   /* 츨력시 st2와 같은 값이 나온다는 것을 알 수 있다.*/
    printf("st3.studentId = %d\n", st3.studentId );
    printf("st3.grade = %c\n", st3.grade);

    int s;
    s= humansEqual(st3, st2); //st3, st2 구조체 비교 함수 출력하기
    if (s==1)
        printf("\n\n일치합니다. \n\n"); 
    else
        printf("\n\n일치하지 않습니다.\n\n");

}

int humansEqual ( student2 st3, student2 st2)   /*st3와 st2가 같은지 확인해보는 함수*/
{
    if (strcmp(&st3.lastName,&st2.lastName)) /*하나라도 다른게 있다면 FALSE 반환*/
        return FALSE;
    if (st3.studentId != st2.studentId)
        return FALSE;
    if (st3.grade != st2.grade)
       { 
           return FALSE; 
       }
    
     return TRUE;  //전부일치하면 TRUE 값 반환

}