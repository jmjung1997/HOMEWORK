/*
 * postfix.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

 /* stack 내에서 우선순위, lparen = 0 가장 낮음 */
typedef enum {
	lparen = 0,  /* ( 왼쪽 괄호 */
	rparen = 9,  /* ) 오른쪽 괄호*/
	times = 7,   /* * 곱셈 */
	divide = 6,  /* / 나눗셈 */
	plus = 5,    /* + 덧셈 */
	minus = 4,   /* - 뺄셈 */
	operand = 1 /* 피연산자 */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	/* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		/* 계산을 위해 필요한 스택 */

int postfixStackTop = -1;  /* postfixStack용 top */
int evalStackTop = -1;	   /* evalStack용 top */

int evalResult = 0;	   /* 계산 결과를 저장 */

void postfixPush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char* c);
void toPostfix();
void debug();
void reset();
void evaluation();

int main()
{
	char command;
	printf("\n\n[----- [Jeong Jae Min] [2018038067] -----]\n\n");
	do {
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //명령어 값을 입력 받는다

		switch (command) {
		case 'i': case 'I': //계산하고자 하는 수식을 입력 받는다
			getInfix();
			break;
		case 'p': case 'P': // 후위 표기법으로 전환한다
			toPostfix();
			break;
		case 'e': case 'E': // 후위 표기법으로 값을 계산한다
			evaluation();
			break;
		case 'd': case 'D': // 디버그 된 상황을 보여준다
			debug();
			break;
		case 'r': case 'R': // 모든 값을 초기화 한다
			reset();
			break;
		case 'q': case 'Q': // 프로그램을 종료한다
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}

void postfixPush(char x) //postfix로 변환하기 위해 임시로 해당 값을 스택에 넣어주는 함수이다
{
	postfixStack[++postfixStackTop] = x;
}

char postfixPop()//postfixstack의 맨위에 있는 값을 꺼내어 반환 해주는 함수이다
{
	char x;
	if (postfixStackTop == -1)
		return '\0';
	else {
		x = postfixStack[postfixStackTop--];//반환과 동시에 postfixstackTop의 크기를 줄인다
	}
	return x;
}

void evalPush(int x) // postfix로 변환된 식을 계산할 때 evalStack에 피연산자를 넣어주는 함수이다
{
	evalStack[++evalStackTop] = x;
}

int evalPop()//postfix로 변환된 식을 계산할 때 evalStack에서 피연산자가 주는 함수이다
{
	if (evalStackTop == -1)
		return -1;
	else
		return evalStack[evalStackTop--]; //나옴과 동시에 top의 위치가 1 준다
}

/**
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix() //수식을 입력 받는 함수 이다
{
	printf("Type the expression >>> ");
	scanf("%s", infixExp); //infixExp 배열로 입력 받는다
}

precedence getToken(char symbol) // 각 기호에 맞는 우선순위 값을 반환 해주는 함수이다
{
	switch (symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	default: return operand;
	}
}


precedence getPriority(char x) //우선 순위값을 반환해주는 함수를 호출한다
{
	return getToken(x);
}

/**
 * 문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char* c)//postfixExp 스택에 데이터를 넣어주는 함수이다
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix()
{
	/* infixExp의 문자 하나씩을 읽기위한 포인터 */
	char* exp = infixExp;
	char x; /* 문자하나를 임시로 저장하기 위한 변수 */
	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */

	while (*exp != '\0') //exp가 빈 값이 나올때까지 반복
	{

		if (getPriority(*exp) == operand) // 피 연산자일 경우 
		{
			charCat(exp); //postfixExp에 넣어준다.

		}
		else if (getPriority(*exp) == lparen)// '('일 때 우선 무조건 postfixstack에 넣어준다. 
		{
			postfixPush(*exp);
		}
		else if (getPriority(*exp) == rparen) /* ')'일 때 '('가 나올때 까지 postfixstack에서 연산자를 빼서 postfixExp에 넣어준다*/
		{
			while (getPriority(postfixStack[postfixStackTop]) != lparen)
			{
				x = postfixPop(); // postfixstack에서 연산자를 빼준다
				charCat(&x);//postfixExp에 넣어준다

			}

			postfixPop(); //'('괄호는 postfixstack에서 빼준다.
		}

		else
		{/*postfixstack에 집어 넣으려고 하는 연산자가 postfixStack[postfixStackTop] 보다 우선 순위가 낮으면
		postfixStack[postfixStackTop]를 빼서 postfixExp에 넣어준 후 postfixstack에 들어간다*/
			while (getPriority(postfixStack[postfixStackTop]) >= getPriority(*exp))
			{
				x = postfixPop();// postfixstack에서 연산자를 빼준다.
				charCat(&x);//postfixExp에 넣어준다

			}
			postfixPush(*exp); // postfixstack에서 연산자를 넣어준다.
		}


		exp++; //exp는 infixExp의 주소값을 가지므로 하나 증가 시켜 주소값을 1byte 증가시킨다.
	}

	while (postfixStack[postfixStackTop] != '\0') /* 배열 postfixStack에 들어 있는 연산자들을 후입선출식으로 꺼내어
												   postfixExp에 넣어준다*/
	{
		x = postfixPop();
		charCat(&x);
	}

}
void debug() //디버그함수, 입력받은 수식, 후위표기법으로 바뀐 수식, 계산된 값, postfixstack에 있었던 수식들을 보여주는 함수이다
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset() //모든 값을 초기화 해주는 함수이다
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for (int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';

	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation() // 후위표기법으로 된 식을 계산해주는 함수이다
{
	char* cal = postfixExp; //후위표기법으로 된 식을 가지고 있는 배열 postfixExp의 주소를 포인터 변수 cal에 대입한다
	int op1, op2;
	while (*cal != '\0') //*cal 하나씩 출력하면서 빈 값이 나올 때 까지 반복한다
	{
		if (getPriority(*cal) == operand) //피연산자일 경우
		{
			int n = *cal - 48; // char형이므로 int형으로 바꾸어 n에 대입한다
			evalPush(n); //evalstack에 넣는다
		}
		else//연산자일 경우
		{
			op2 = evalPop(); /*피연산자 두개를 호출하여 각 각 op2, op1에 대입한다*/
			op1 = evalPop();
			switch (getPriority(*cal)) // 해당하는 연산자의 연산을 수행하여 값을 계산한다
			{
			case plus:
				evalPush(op1 + op2);
				break;
			case minus:
				evalPush(op1 - op2);
				break;
			case times:
				evalPush(op1 * op2);
				break;
			case divide:
				evalPush(op1 / op2);
				break;

			}
		}
		cal++; //postfixExp의 주소값을 1만큼 증가한다
	}
	evalResult = evalPop(); //결과값을 evalResult에 대입한다
}









