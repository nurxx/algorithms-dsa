#include <iostream>
using namespace std;

#define maxSize 1000
struct Stack {
	int top=-1;
	int arr[maxSize];
	int peek()
	{
		if (top == -1)return -1;
		else return arr[top];
	}
	int pop() {
		if (top == -1)return 0;
		else
		{
			int x = arr[top--];
			return x;
		}
	}
	bool push(int x) {
		if (top >= maxSize - 1)return false;
		else {
			arr[++top] = x;
			return true;
		}
	}
	bool empty() {
		return top == -1;
	}
};

int main()
{
	struct Stack s;
	s.push(14);
	s.push(8);
	s.push(7954);
	cout<<s.pop()<<"popped"<<endl;
	cout << s.peek() << endl;
	s.push(19);
	cout << s.peek() << endl;

	cout << "Elements in stack: " << endl;
	while (!s.empty())
	{
		cout << s.pop() << endl;
	}
	system("pause");
	return 0;
}