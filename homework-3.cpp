/**
* @Homework: Homework-3
* @Author: Alejandra Brambila
* @Description: Updated the print function of the ArrQueue class. 
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 28/02/2017
*/

#include <iostream>
#include <random>

using namespace std;

class ArrQueue {
private:
	int ArraySize;
	int *Q;
	int Front;
	int Rear;
	int NumItems;
public:
	ArrQueue(int size = 10) {
		ArraySize = size;
		Q = new int[ArraySize];
		Front = Rear = NumItems = 0;
	}

	bool Push(int value) {
		if (Full()) {
			cout << "Queue Full!" << endl;
			return false;
		}
		Q[Rear] = value;
		Rear = (Rear + 1) % ArraySize;
		NumItems++;
		return true;
	}

	int Pop() {
		if (Empty()) {
			cout << "Queue Empty!" << endl;
			return false;
		}
		int Temp = Q[Front];
		Front = (Front + 1) % ArraySize;
		NumItems--;
		return Temp;
	}

	bool Empty() {
		return (NumItems == 0);
	}

	bool Full() {
		return (NumItems == ArraySize);
	}

	void PrintFR() {
		cout << "Front: " << Front << "Rear: " << Rear << endl;
	}

	/**
	* @FunctionName: Print
	* @Description: In this function it will print what it is in the circular array
	*				based queue. To fix the problem when the queue is full, I added a boolean
	*				variable. That way it can determine if the queue is full is making the
  *       bool equal the Full function.True if full and if false it will go through
  *       the while loop.
	* @Params:
	*    NONE
	* @Returns:
	*    NONE
	*/
	void Print() {
	
		int Index = Front;
		bool fixed_queue = Full(); 

		while (Index != Rear || fixed_queue) {
			cout << Q[Index] << " ";
			Index = ((Index + 1) % (ArraySize));
			fixed_queue = false;
		}
		cout << endl;
	}
};

int main() {
	srand(983475);
	ArrQueue Q;
	int r = 0;
	bool result;

	for (int i = 0; i<12; i++) {
		r = rand() % 100;
		result = Q.Push(r);
		if (result)
			cout << r << endl;
	}
	
	Q.PrintFR();
	Q.Print();

	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;

	Q.Print();
	
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << endl;

	for (int i = 0; i<3; i++) {
		r = rand() % 100;
		result = Q.Push(r);
		if (result)
			cout << r << endl;
	}
	
	system("pause");
	return 0;
	
}
