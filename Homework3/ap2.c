#include<stdio.h>
#include<stdlib.h>

void main()
{
int list[5];
int *plist[5];
printf("\n\n�����             2018038067\n\n");

plist[0]=(int*)malloc(sizeof(int));// plist[0]�� 4byte�� �����Ҵ��ϱ�

printf("list[0] \t= %d\n", list[0]);// list[0]�� ������ �ִ� �� ���
printf("address of list \t=%p\n", list); //�迭 list�� �ּ� �� ���
printf("address of list[0] \t=%p\n", &list[0]);//list[0]�� �ּҰ� ���
printf("address of list + 0 \t=%p\n", list+0);// list+ 0�� �ּҰ�   
printf("address of list + 1 \t=%p\n", list+1);//list+ 1�� �ּҰ�
printf("address of list + 2 \t=%p\n", list+2);//list+ 2�� �ּҰ�
printf("address of list + 3 \t=%p\n", list+3);//list+ 3�� �ּҰ�
printf("address of list + 4 \t=%p\n", list+4);//list+ 4�� �ּҰ�
printf("address of list[4] \t=%p\n", &list[4]);//&list[4]�� �ּҰ�
free(plist[0]);
/* list[0] �Ǵ� list�� ������ 0���� ���� 1�� ������ �� ���� ������ �������� 4��ŭ �ּҰ��� �����Ѵ�. 
*/
}