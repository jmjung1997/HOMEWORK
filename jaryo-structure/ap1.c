    #include<stdio.h>
    #include<stdlib.h>

    void main()
    {
        int list[5];
        int *plist[5]={NULL,};

        plist[0]=(int*)malloc(sizeof(int)); //malloc을 통해 int 사이즈만큼 heap영역에 메모리를 할당한다.

        list[0]=1;
        list[1]=100;

        *plist[0]=200;

        printf("\n\n정재민           2018038067\n\n");

        printf("value of list[0]         = %d\n", list[0]); //list[0]의 값 
        printf("address of list[0]       = %p\n", &list[0]); //list[0]의 주소값
        printf("value of list            = %p\n", list);//list의 값
        printf("address of list(&list)   = %p\n", &list);// list의 주소값
        
        /* list[0]의 주소값, list의 값, list의 주소값 다 같다. */ 
        

    printf("---------------------------------------------\n\n");//나머지는 비어 있으므로 NULL 값이 들어간다. 
    
        printf("value of list[1]     = %d\n", list[1]); // list[1]의 값
        printf("address of list[1]   = %p\n", &list[1]);// list[1]의 주소값
        printf("value of *(list+1)   = %d\n", *(list+1));//list+1이 가리키는 값
        printf("address of list+1    = %p\n", list+1);//list+1의 주소값
    /* list[1]의 주소값과 list+1의 주소값이 같다. list[1]의 값과 list+1이 가리키는 값이 같다.*/

    printf("---------------------------------------------\n\n");
        
        printf("value of *plist[0]   = %d\n", *plist[0]); // *plist[0]이 가리키는 값 
        printf("&plist[0]            = %p\n", &plist[0]); //plist[0]의 주소 값
        printf("&plist               = %p\n", &plist);// plist 배열의 주소값
        printf("plist                = %p\n", plist); // plist 값 출력
        printf("plist[0]             = %p\n", plist[0]); //plist가 가지고 있는 주소값
        printf("plist[1]             = %p\n", plist[1]);//나머지는 비어 있으므로 NULL 값이 들어간다. 
        printf("plist[2]             = %p\n", plist[2]);//나머지는 비어 있으므로 NULL 값이 들어간다. 
        printf("plist[3]             = %p\n", plist[3]);//나머지는 비어 있으므로 NULL 값이 들어간다. 
        printf("plist[4]             = %p\n", plist[4]);//나머지는 비어 있으므로 NULL 값이 들어간다. 
     /* plist[0]의 주소값, plist 배열의 주소값,plist의 값은 다 같다. 
     plist[0]이 가지고 있는 값은 동적할당에 의해 heap에 생성되는 plist[0]의 메모리 공간의 주소를 의미한다. 
     */

    free(plist[0]);
    
      
    }