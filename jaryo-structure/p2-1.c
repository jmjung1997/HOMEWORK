#include <stdio.h>
#define MAX_SIZE 100
float sum(float list[], int);
float input[MAX_SIZE], answer;
int i; 
void main(void)
{
    printf("�����           2018038067\n\n");
    for(i=0; i<MAX_SIZE; i++)
    input[i]=i;//0~99���� imput �迭�� ������� �����Ѵ�. 
    printf("address of input = %p\n", input); // input�� �ּҸ� ��� �Ѵ�. 

    answer=sum(input,MAX_SIZE);//sum �Լ� ȣ���ؼ� input �迭 �հ�� �ϱ�
    printf("The sum is: %f\n",answer);

}

float sum(float list[], int n) //sum �Լ�
                              //list[] �Ű������� input�迭 �ޱ�
{
    printf("value of list = %p\n", list); //list�Ű������� �� ��½� input�迭�� �ּҰ��� ���´�.
    printf("address of list = %p\n\n", &list); //list�� �ּҰ� ����Ѵ�. 
    /*�Ű����� list[]�� input �ּҸ� ���޵ȴٴ� ���� �� �� �ֽ��ϴ�.*/
    
    int i;
    float tempsum =0; //list[]�� ����ִ°��� ��
    for(i=0;i<n;i++)
    tempsum+=list[i];//�迭 ������� ���ϱ�
    return tempsum;

}