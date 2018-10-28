/*
I wonder whether I should answer your messages.
修改容量: Max
修改类型: typedef
判断空栈,满栈,用isempty() isfull() 或者 看push和pop的返回值
*/
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum {Max = 10};
	Item items[Max];
	int top;	//  index for top stack item
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	bool pop(Item & item);
};

#endif 
