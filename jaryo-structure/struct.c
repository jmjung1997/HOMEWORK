#include<stdio.h>
int humanEqual (struct humanBeing person1, struct humanBeing person2);
#define FALSE 0;
#define TRUE 1;
struct student1 { //student1 ����ü ����
    char lastName;
    int studentId;
    char grade;
};

typedef struct{ //typedef�� �̿��� student2 ����ü ����
    char lastName;
    int studentId;
    char grade;
} student2;

int main() 
{
    
    printf("\n\n�����            2018038067\n\n");
    struct student1 st1 = {'A', 100, 'A'}; // st1�̶�� Ÿ���� ����� �ű⿡ �����͸� ���� ������. 
                                            // �̶� struct�� �� �ٿ��־� ����ü ��°��� �����ؾ� �Ѵ�.
    printf("st1.lastName = %c\n", st1.lastName); 
    printf("st1.studentID = %d\n", st1.studentId);
    printf("st1.grade = %c\n", st1.grade);

    student2 st2 = {'B',200 , 'B'}; //st2��� Ÿ���� ����� �ű⿡ �����͸� ���� ������. typedef struct�̹Ƿ� �����Ҷ� struct�� �����Ѵ�.

    printf("\nst.2lastName = %c\n", st2.lastName);
    printf("st.studentId = %d\n", st2.studentId);
    printf("st2.grade = %c\n", st2.grade);

    student2 st3;//st3 Ÿ�� ����

    st3 = st2; //st2�� �ִ� ����ü ������  st3�� �����Ѵ�.

    printf("\nst3.lastName = %c\n",st3.lastName);   /* ���½� st2�� ���� ���� ���´ٴ� ���� �� �� �ִ�.*/
    printf("st3.studentId = %d\n", st3.studentId );
    printf("st3.grade = %c\n", st3.grade);

    int s;
    s= humansEqual(st3, st2); //st3, st2 ����ü �� �Լ� ����ϱ�
    if (s==1)
        printf("\n\n��ġ�մϴ�. \n\n"); 
    else
        printf("\n\n��ġ���� �ʽ��ϴ�.\n\n");

}

int humansEqual ( student2 st3, student2 st2)   /*st3�� st2�� ������ Ȯ���غ��� �Լ�*/
{
    if (strcmp(&st3.lastName,&st2.lastName)) /*�ϳ��� �ٸ��� �ִٸ� FALSE ��ȯ*/
        return FALSE;
    if (st3.studentId != st2.studentId)
        return FALSE;
    if (st3.grade != st2.grade)
       { 
           return FALSE; 
       }
    
     return TRUE;  //������ġ�ϸ� TRUE �� ��ȯ

}