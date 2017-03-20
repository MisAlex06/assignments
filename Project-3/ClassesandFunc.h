#include <iostream>
#include <string>

using namespace std;

/**
* @FunctionName: CalcuStack
* @Description:
*     Implementation of a double stack
*/
class CalcuStack{
private:
	//////////////////////////////////////////////////////

	double *S;
	int top;
	int size;

public:
	//////////////////////////////////////////////////////

	/**
	* @FunctionName: CalcStack
	* @Description:
	*     Class constructor
	* @Params:
	*    int insize: initial stack size
	* @Returns:
	*    void
	*/
	void CalcStack(int insize){
		size = insize;
		top = -1;
		S = new double[size];
	}

	/**
	* @FunctionName: push
	* @Description:
	*     Adds a character to the stack
	* @Params:
	*    char c - character to add
	* @Returns:
	*    void
	*/
	void Push(char c){
		if (!Full()){
			S[++top] = c;
		}
		else{
			cout << "Stack Overflow!" << endl;
		}
	}

	/**
	* @FunctionName: pop
	* @Description:
	*     Returns a character from the top of the stack
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	char Pop(){
		if (!Empty())
			return S[top--];
		else
			return -1;
	}

	/**
	* @FunctionName: printStack
	* @Description:
	*     Prints stack to stdout for debugging purposes
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	void PrintStack(){
		for (int i = top; i >= 0; i--){
			cout << S[i] << " ";
		}
		cout << endl;
	}

	/**
	* @FunctionName: empty
	* @Description:
	*     Checks to see if stack is empty.
	* @Params:
	*    None
	* @Returns:
	*    bool - true if empty / false otherwise
	*/
	bool Empty(){
		return top == -1;
	}

	/**
	* @FunctionName: full
	* @Description:
	*     Checks if stack is full
	* @Params:
	*    None
	* @Returns:
	*    bool - true if full / false otherwise
	*/
	bool Full(){
		return top == size - 1;
	}

	/**
	* @FunctionName: Peek
	* @Description:
	*     Goes to the top of stack
	* @Params:
	*    None
	* @Returns:
	*    top of stack
	*/
	int peek(){
		return S[top];
	}
};

/**
* @FunctionName: Stack
* @Description:
*     Implementation of a char stack
*/
class Stack{
private:
	//////////////////////////////////////////////////////

	char *S;
	int top;
	int size;

public:
	//////////////////////////////////////////////////////

	/**
	* @FunctionName: Stack
	* @Description:
	*     Class constructor
	* @Params:
	*    int insize - initial stack size
	* @Returns:
	*    void
	*/
	Stack(int insize){
		size = insize;
		top = -1;
		S = new char[size];
	}

	/**
	* @FunctionName: push
	* @Description:
	*     Adds a character to the stack
	* @Params:
	*    char c - character to add
	* @Returns:
	*    void
	*/
	void push(char c){
		if (!full()){
			S[++top] = c;
		}
		else{
			cout << "Stack Overflow!" << endl;
		}
	}

	/**
	* @FunctionName: pop
	* @Description:
	*     Returns a character from the top of the stack
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	char pop(){
		if (!empty())
			return S[top--];
		else
			return -1;
	}

	/**
	* @FunctionName: printStack
	* @Description:
	*     Prints stack to stdout for debugging purposes
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	void printStack(){
		for (int i = top; i >= 0; i--){
			cout << S[i] << " ";
		}
		cout << endl;
	}

	/**
	* @FunctionName: empty
	* @Description:
	*     Checks to see if stack is empty.
	* @Params:
	*    None
	* @Returns:
	*    bool - true if empty / false otherwise
	*/
	bool empty(){
		return top == -1;
	}

	/**
	* @FunctionName: full
	* @Description:
	*     Checks if stack is full
	* @Params:
	*    None
	* @Returns:
	*    bool - true if full / false otherwise
	*/
	bool full(){
		return top == size - 1;
	}

	/**
	* @FunctionName: Peek
	* @Description:
	*     Goes to the top of stack
	* @Params:
	*    None
	* @Returns:
	*    top of stack
	*/
	int peek(){
		if (S[top] == '(')
		{
			return 0;
		}
		else if (S[top] == '+' || S[top] == '-')
		{
			return 1;
		}
		else if (S[top] == '*' || S[top] == '/' || S[top] == '%')
		{
			return 2;
		}
		else if (S[top] == '^')
		{
			return 3;
		}
		else
			return 4;
	}

};

/**
* @FunctionName: Queue
* @Description:
*     Implementation of a char queue
*/
class Queue{
private:
	//////////////////////////////////////////////////////

	int ArraySize;
	char *Q;
	int Front;
	int Rear;
	int NumItems;

public:
	//////////////////////////////////////////////////////

	/**
	* @FunctionName: Queue
	* @Description:
	*     Class constructor
	* @Params:
	*    int insize - initial queue size
	* @Returns:
	*    void
	*/
	Queue(int insize){
		ArraySize = insize;
		Q = new char[ArraySize];
		Front = Rear = NumItems = 0;
	}

	/**
	* @FunctionName: push
	* @Description:
	*     Adds a character to the queue
	* @Params:
	*    char c - character to add
	* @Returns:
	*    void
	*/
	void Push(char c){
		if (Full()){
			cout << "Queue Full!" << endl;
			return;
		}
		Q[Rear] = c;
		Rear = (Rear + 1) % ArraySize;
		NumItems++;
		return;
	}

	/**
	* @FunctionName: pop
	* @Description:
	*     Returns a character from the top of the queue
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	char Pop(){
		if (Empty()){
			cout << "Queue Empty!" << endl;
			return false;
		}
		int Temp = Q[Front];
		Front = (Front + 1) % ArraySize;
		NumItems--;
		return Temp;
	}

	/**
	* @FunctionName: printQueue
	* @Description:
	*     Prints queue to stdout for debugging purposes
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	void PrintQueue(){
		for (int i = Front, j = 0; j<NumItems; j++, i = (i + 1) % ArraySize){
			cout << Q[i] << " ";
		}
		cout << endl;
	}

	/**
	* @FunctionName: empty
	* @Description:
	*     Checks to see if queue is empty.
	* @Params:
	*    None
	* @Returns:
	*    bool - true if empty / false otherwise
	*/
	bool Empty(){
		return (NumItems == 0);
	}

	/**
	* @FunctionName: full
	* @Description:
	*     Checks if queue is full
	* @Params:
	*    None
	* @Returns:
	*    bool - true if full / false otherwise
	*/
	bool Full(){
		return (NumItems == ArraySize);
	}
};

