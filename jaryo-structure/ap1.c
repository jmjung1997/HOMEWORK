    #include<stdio.h>
    #include<stdlib.h>

    void main()
    {
        int list[5];
        int *plist[5]={NULL,};

        plist[0]=(int*)malloc(sizeof(int)); //malloc�� ���� int �����ŭ heap������ �޸𸮸� �Ҵ��Ѵ�.

        list[0]=1;
        list[1]=100;

        *plist[0]=200;

        printf("\n\n�����           2018038067\n\n");

        printf("value of list[0]         = %d\n", list[0]); //list[0]�� �� 
        printf("address of list[0]       = %p\n", &list[0]); //list[0]�� �ּҰ�
        printf("value of list            = %p\n", list);//list�� ��
        printf("address of list(&list)   = %p\n", &list);// list�� �ּҰ�
        
        /* list[0]�� �ּҰ�, list�� ��, list�� �ּҰ� �� ����. */ 
        

    printf("---------------------------------------------\n\n");//�������� ��� �����Ƿ� NULL ���� ����. 
    
        printf("value of list[1]     = %d\n", list[1]); // list[1]�� ��
        printf("address of list[1]   = %p\n", &list[1]);// list[1]�� �ּҰ�
        printf("value of *(list+1)   = %d\n", *(list+1));//list+1�� ����Ű�� ��
        printf("address of list+1    = %p\n", list+1);//list+1�� �ּҰ�
    /* list[1]�� �ּҰ��� list+1�� �ּҰ��� ����. list[1]�� ���� list+1�� ����Ű�� ���� ����.*/

    printf("---------------------------------------------\n\n");
        
        printf("value of *plist[0]   = %d\n", *plist[0]); // *plist[0]�� ����Ű�� �� 
        printf("&plist[0]            = %p\n", &plist[0]); //plist[0]�� �ּ� ��
        printf("&plist               = %p\n", &plist);// plist �迭�� �ּҰ�
        printf("plist                = %p\n", plist); // plist �� ���
        printf("plist[0]             = %p\n", plist[0]); //plist�� ������ �ִ� �ּҰ�
        printf("plist[1]             = %p\n", plist[1]);//�������� ��� �����Ƿ� NULL ���� ����. 
        printf("plist[2]             = %p\n", plist[2]);//�������� ��� �����Ƿ� NULL ���� ����. 
        printf("plist[3]             = %p\n", plist[3]);//�������� ��� �����Ƿ� NULL ���� ����. 
        printf("plist[4]             = %p\n", plist[4]);//�������� ��� �����Ƿ� NULL ���� ����. 
     /* plist[0]�� �ּҰ�, plist �迭�� �ּҰ�,plist�� ���� �� ����. 
     plist[0]�� ������ �ִ� ���� �����Ҵ翡 ���� heap�� �����Ǵ� plist[0]�� �޸� ������ �ּҸ� �ǹ��Ѵ�. 
     */

    free(plist[0]);
    
      
    }