#include<stdio.h>

void print1 (int *ptr, int rows);

int main()
{
    printf("\n\n�����               2018038067\n\n");
    int one[]={0,1,2,3,4};
    printf(" one       = %p\n", one ); //�迭 one�� ��
    printf("&one      = %p\n", &one); //�迭 one�� �ּҰ�
    printf("&one[0]   = %p\n", &one[0]); //�迭 one[0]�� �ּҰ�
    printf("\n");

    print1(&one[0], 5); // �迭 ������� ���

    return 0;
}

void print1 (int *ptr, int rows) // ������ ���� ptr�� �迭 one�� �ּҰ��� ���� �޴´�.
{
    int i;
    printf("Address \t Contents\n");
    for(i=0; i<rows; i++)
        printf("%p \t  %5d\n", ptr + i, *(ptr+i)); /* ��ĭ�� ���ϸ鼭 ����Ѵ�. 
                                                    ptr�� �ּҰ��� int���̼� 4byte�� �����ϸ鼭 ��µǰ� �ش簪�� ��ĭ�� �̷����鼭 �� ��ġ�� ���� ���� ��µȴ�.*/

    printf("\n");
 }