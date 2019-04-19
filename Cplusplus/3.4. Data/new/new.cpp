#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<iostream>

#define MAXSIZE 10000
#define STACKINCREMENT 2000


typedef struct {
	int stacksize;
	int *top, *base;
}SqStack;

typedef struct {
	int stacksize;
	long long int *top, *base;
}SqStackL;


void InitStack(SqStack &S) {
	S.base = (int*)malloc(MAXSIZE * sizeof(int));
	if (!S.base) {
		return;
	}
	S.stacksize = MAXSIZE;
	S.top = S.base;
}

void InitStackL(SqStackL &S) {
	S.base = (long long int*)malloc(MAXSIZE * sizeof(long long int));
	if (!S.base) {
		return;
	}
	S.stacksize = MAXSIZE;
	S.top = S.base;
}

int StackEmpty(SqStack S) {
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

int StackEmptyL(SqStackL S) {
	if (S.base == S.top)
		return 1;
	else
		return 0;
}

void Push(SqStack &S, int x) {
	if ((S.top - S.base) >= S.stacksize) {
		S.base = (int*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
		if (!S.base)return;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = x;
}

int PushL(SqStackL &S, long long int x) {
	if ((S.top - S.base) >= S.stacksize) {
		S.base = (long long int*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(long long int));
		if (!S.base)return -1;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = x;
	return 0;
}

int Pop(SqStack&S, int & x) {
	if (S.top == S.base)return 0;
	S.top--;
	x = *S.top;
	return 1;
}

int PopL(SqStackL &S, long long int &x) {
	if (S.top == S.base)return 0;
	S.top--;
	x = *S.top;
	return 1;
}


void GetTop(SqStack S, int &e) {
	if (S.top == S.base) {
		return;
	}
	e = *(S.top - 1);
}

int isoperator(char c) {
	if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '^' || c == '\0') {
		return 1;
	}
	else return 0;
}
int preop(char c, char ch)
{
	int p[8][8] = { { 1,1,-1,-1,-1,-1,1,1 },{ 1,1,-1,-1,-1,-1,1,1 },{ 1,1,1,1,-1,-1,1,1 },{ 1,1,1,1,-1,-1,1,1 },{ 1,1,1,1,1,-1,1,1 },{ -1,-1,-1,-1,-1,-1,0,0 },
	{ 1,1,1,1,1,0,1,1 },{ -1,-1,-1,-1,-1,-1,0,0 } };
	int i, j;
	switch (c) {
	case'+': i = 0; break;
	case'-': i = 1; break;
	case'*': i = 2; break;
	case'/': i = 3; break;
	case'^': i = 4; break;
	case'(': i = 5; break;
	case')': i = 6; break;
	case'\0': i = 7; break;
	}
	switch (ch) {
	case'+': j = 0; break;
	case'-': j = 1; break;
	case'*': j = 2; break;
	case'/': j = 3; break;
	case'^': j = 4; break;
	case'(': j = 5; break;
	case')': j = 6; break;
	case'\0': j = 7; break;
	}
	return p[i][j];
}


int isleft(char c) {
	if (c == '(' || c == '[' || c == '{') {
		return 1;
	}
	else return 0;
}

int isright(char c) {
	if (c == ')' || c == ']' || c == '}') {
		return 1;
	}
	return 0;
}


int ismatch(char c, char ch) {
	if (c == '('&&ch == ')')
		return 1;
	if (c == '['&&c == ']')
		return 1;
	if (c == '{'&&c == '}')
		return 1;
	return 0;
}

int istrue(char exp[]) {
	char *p = exp;
	int c, ch;
	SqStack S;
	InitStack(S);
	while ((c = *p) != '\0') {
		if (isleft(c)) {
			Push(S, c);
		}
		else if (isright(c)) {
			if (!Pop(S, ch)) {
				return -1;
			}
			if (!ismatch(ch, c)) {
				return -2;
			}
		}
		p++;
	}
	if (!StackEmpty(S))
		return -3;
	else
		return 1;
}

long long int operatorl(long long int a, char c, long long int b) {
	long long int i, t;
	t = 1;
	switch (c) {
	case'+':
		return(a + b);
		break;
	case'-':
		return(a - b);
		break;
	case'*':
		return(a*(b));
		break;
	case'^':
		for (i = b; b > 0; b--) {
			t = t * a;
		}
		return t;
		break;
	}
	return 0;
}


void conver(char exp[], char suffix[]) {
	SqStack S;
	InitStack(S);
	Push(S, '\0');
	int k = 0, ch, a, b, c;
	char *p;
	p = exp;
	ch = *p++;
	while (!(ch == '\0' && b == '\0')) {
		if (ch == ' ') {
			ch = *p++;
			continue;
		}
		if (!isoperator(ch)) {
			suffix[k++] = ch;
			ch = *p++;
			if (isoperator(ch) || ch == ' ') {
				suffix[k++] = ' ';
			}
			GetTop(S, b);
		}
		else {
			GetTop(S, c);
			switch (preop(c, ch)) {
			case -1:
				Push(S, ch);
				ch = *p++;
				GetTop(S, b);
				break;
			case 0:
				Pop(S, a);
				ch = *p++;
				GetTop(S, b);
				break;
			case 1:
				Pop(S, c);
				suffix[k++] = (char)c;
				GetTop(S, b);
				break;
			}
		}
	}
	suffix[k++] = '\0';
}


long long int Value(char exp[], long long int y) {
	long long int a, b, e, sum, temp;
	SqStackL S;
	char *p = exp, ch;
	InitStackL(S);
	while ((ch = *p) != '\0') {
		if (!isoperator(ch)) {
			temp = 0;
			while (ch != ' ' && !(isoperator(ch))) {
				if (ch == 'x') {
					temp = temp * 10 + (y);
					ch = *(++p);
				}
				else {
					temp = temp * 10 + (ch - '0');
					ch = *(++p);
				}
			}
			PushL(S, temp);
			p++;
		}
		else {
			PopL(S, b);
			PopL(S, a);
			PushL(S, operatorl(a, ch, b));
			p++;
		}
		ch = *p;
	}
	PopL(S, sum);
	return sum;
}


int isequal(char exp[], char c[]) {
	long long int a[10] = { 0,1,13,30,-2 }, i;
	char ta[10000], tb[10000];
	conver(exp, ta);
	conver(c, tb);
	for (i = 0; i <= 5; i = i++) {
		if (Value(ta, a[i]) != Value(tb, a[i]))
			return 0;
	}
	return 1;
}

int main() {
	using namespace std;
	char c[27][400];
	int n, i;

	cin >> n; getchar();
	gets(c[0]);
	for (i = 1; i <= n; i++) {
		gets(c[i]);
	}
	for (i = 1; i <= n; i++) {
		if ((istrue(c[i])) != 1) {
			c[i][0] = '\0';
		}
	}
	for (i = 1; i <= n; i++) {
		if (c[i][0] == '\0') {
			continue;
		}
		if (isequal(c[0], c[i])) {
			printf("%c", 'A' + i - 1);
		}
	}
	return 0;
}