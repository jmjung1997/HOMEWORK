#include<stdio.h>
#include<stdlib.h>

void main()
{
int list[5];
int *plist[5];
printf("\n\n정재민             2018038067\n\n");

plist[0]=(int*)malloc(sizeof(int));// plist[0]에 4byte로 동적할당하기

printf("list[0] \t= %d\n", list[0]);// list[0]이 가지고 있는 값 출력
printf("address of list \t=%p\n", list); //배열 list의 주소 값 출력
printf("address of list[0] \t=%p\n", &list[0]);//list[0]의 주소값 출력
printf("address of list + 0 \t=%p\n", list+0);// list+ 0의 주소값   
printf("address of list + 1 \t=%p\n", list+1);//list+ 1의 주소값
printf("address of list + 2 \t=%p\n", list+2);//list+ 2의 주소값
printf("address of list + 3 \t=%p\n", list+3);//list+ 3의 주소값
printf("address of list + 4 \t=%p\n", list+4);//list+ 4의 주소값
printf("address of list[4] \t=%p\n", &list[4]);//&list[4]의 주소값
free(plist[0]);
/* list[0] 또는 list의 기준점 0으로 부터 1씩 증가할 때 마다 정수형 사이즈인 4만큼 주소값이 증가한다. 
*/
}