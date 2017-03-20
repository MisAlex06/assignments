/**
* @Name: Alejandra Brambila
* @ProgramName: Postfix Calculator
* @Description:
*     Changes from infix to postfix and calculates the output.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: Mar 20 2017
*/

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "ClassesandFunc.h"


using namespace std;

/**
* @FunctionName: evaluate
* @Description:
*     Retrieves whatever into the infile, checks and change certain characters  values by using switch statements. Then by using the value we determine whether to pop or push to do the calculations.
*
* @Params:
*    ifstream &problems
* @Returns:
*    void
*/



int main(){

	
	int numCount;
	string expression;
	int calculate;
	char temp;
	double firstNum = 0;
	double secondNum = 0;
	int mod1 = 0;
	int mod2 = 0;
	int change = 0;
	int check = 0;
	double result = 0;
	
	ifstream infile;
	infile.open("exp.txt");

	infile >> numCount;
	getline(infile, expression);

	//first checks and then changes the value uising switch statements.
	//Then checks stack and if the new change is higher it pushes it, otherwise it pops until it can push.
	for (int y = 0; y < numCount; y++){
		getline(infile, expression);
		Queue que(expression.length() + 1);
		Stack stk(expression.length() + 1);
		CalcuStack calculate(expression.length() + 1);
		stk.push('(');

		for (int i = 0; i< expression.length(); i++){
			temp = expression[i];

			switch (temp){
			case '(':
				change = 0;
				break;
			case '+':
			case '-':
				change = 1;
				break;
			case '*':
			case '/':
			case '%':
				change = 2;
				break;
			case '^':
				change = 3;
				break;
			default:
				change = -1;
			}

			if (48 <= temp&&temp <= 57)
			{
				que.Push(temp);
			}
			else if (temp != ' ')
			{
				if (temp == ')')
				{
					check = stk.peek();
					while (check != 0)
					{
						que.Push(stk.pop());
						check = stk.peek();
					}
					stk.pop();
				}
				else if (temp == '(')
					stk.push(temp);
				else
				{
					check = stk.peek();
					while (check >= change)
					{
						que.Push(stk.pop());
						check = stk.peek();
					}
					stk.push(temp);
				}
			}
		}

		//Push what is left on the stack onto the queue except the ( operator
		while (!stk.empty()){
			temp = stk.pop();
			if (temp != '(')
				que.Push(temp);
		}

		//Checks what is being popped off the queue then moves it
		while (!que.Empty()){
			temp = que.Pop();
			if (48 <= temp&&temp <= 57)
			{
				firstNum = temp - '0';
				calculate.Push(firstNum);
			}
			else if (temp == '+')
			{
				firstNum = calculate.Pop();
				secondNum = calculate.Pop();
				secondNum += firstNum;
				calculate.Push(secondNum);
			}
			else if (temp == '-')
			{
				firstNum = calculate.Pop();
				secondNum = calculate.Pop();
				secondNum = firstNum;
				calculate.Push(secondNum);
			}
			else if (temp == '*')
			{
				firstNum = calculate.Pop();
				secondNum = calculate.Pop();
				secondNum *= firstNum;
				calculate.Push(secondNum);
			}
			else if (temp == '/')
			{
				firstNum = calculate.Pop();
				secondNum = calculate.Pop();
				if (firstNum != 0)
				{
					secondNum /= firstNum;
					calculate.Push(secondNum);
				}
				else
				{
					cout << "wrong." << endl;
					calculate.Push(0);
				}
			}
			else if (temp == '^')
			{
				firstNum = calculate.Pop();
				secondNum = calculate.Pop();
				secondNum = pow(secondNum, firstNum);
				calculate.Push(secondNum);
			}
			else if (temp == '%')
			{
				firstNum = calculate.Pop();
				secondNum = calculate.Pop();
				mod1 = firstNum;
				mod2 = secondNum;
				if (mod1 == firstNum&&mod2 == secondNum)
				{
					mod2 %= mod1;
					calculate.Push(mod2);
				}
				else
				{
					cout << "Can't have reminder and change to 1." << endl;
					calculate.Push(1);
				}
			}
		}
		result = calculate.Pop();
		for(int k = 0; k < expression.length() - 1; k++){
			{
				cout << expression[k];
			}
			cout << " = " << result << endl;
		}
	}


	
	infile.close;
	system("pause");
	return 0;
}
