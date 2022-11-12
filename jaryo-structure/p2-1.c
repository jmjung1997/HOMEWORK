#include <stdio.h>
#define MAX_SIZE 100
float sum(float list[], int);
float input[MAX_SIZE], answer;
int i; 
void main(void)
{
    printf("정재민           2018038067\n\n");
    for(i=0; i<MAX_SIZE; i++)
    input[i]=i;//0~99까지 imput 배열에 순서대로 대입한다. 
    printf("address of input = %p\n", input); // input의 주소를 출력 한다. 

    answer=sum(input,MAX_SIZE);//sum 함수 호출해서 input 배열 합계산 하기
    printf("The sum is: %f\n",answer);

}

float sum(float list[], int n) //sum 함수
                              //list[] 매개변수로 input배열 받기
{
    printf("value of list = %p\n", list); //list매개변수의 값 출력시 input배열의 주소값이 나온다.
    printf("address of list = %p\n\n", &list); //list의 주소값 출력한다. 
    /*매개변수 list[]에 input 주소만 전달된다는 것을 알 수 있습니다.*/
    
    int i;
    float tempsum =0; //list[]에 들어있는값들 합
    for(i=0;i<n;i++)
    tempsum+=list[i];//배열 순서대로 더하기
    return tempsum;

}