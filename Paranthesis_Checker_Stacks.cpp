//header files
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
//linked list
struct Node
{
	char number; //data for the lnked list
	Node* next;  //next node
};
//class for stack
class Stack
{

public:
	Node* top;  //top node

	Stack() //constructor for assigning the top node as a NULL at first
	{
		top = NULL;
	}
	void Push(char x); //function to push a variable
	char Pop();  //fuction to pop the top element
};

void Stack::Push(char x)
{
	//creating and assigning the new node
	Node* temp = new Node;
	temp->number = x;

	temp->next = top;  //assigning the new node as the first node
	//updating the top variable
	top = temp;

}

char Stack::Pop()
{
	//if (top == NULL)  //check for underflow condition
	//	cout << "Under Flow Condition" << endl;
	Node* temp = top;   //node to hold the top of the stack
	char data = top->number;  //getting the data of the top element
	top = top->next;  //updating the top element for the nexe one (Popping)
	delete(temp);  //free the space taken by the top node
	return data; //return the retrieved data
}
//function  to chech the balnace ness of paranthesis
bool IsParanthesisBalanced(string str, Stack s)
{
	vector<char> expression; //expression to hold the equation
	stringstream ss(str); //string stream to break the string and get each element
	char input;
	while (ss >> input)  //pushing each element to a vector separately
	{
		expression.push_back(input);  
	}
	for (int i = 0; i < expression.size(); i++)  //loop until end of the equation
	{
		if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
			return false;
		if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')  //if there is either a (, [, { we pop it to the stack
		{
			s.Push(expression[i]);
		}
		char x;
		switch (expression[i]) //check the next element for a closing bracket
		{
		case ')': //if it is this 

			// Store the top element in x and pops it
			x = s.Pop();
			if (x == '{' || x == '[') //check the paranthesis popped is the same
				return false;  //return false if the found one is not this
			break;

		case '}':

			// Store the top element in x
			x = s.Pop();
			if (x == '(' || x == '[')
				return false;
			break;

		case ']':

			// Store the top element in x 
			x = s.Pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
	}
	if (s.top != NULL)
		return false;
}

//main function
int main()
{
	Stack stack1;  //stack object

	string str; //enter the equation
	cout << "Enter Your Equation" << endl;
	cin >> str;
	//calling function to check the paranthesis
	bool status = true;
	status = IsParanthesisBalanced(str, stack1);

	if (status)
		cout << "Brackets are Balanced" << endl;
	else
		cout << "Brackets are Not Balanced" << endl;
	

	system("pause");
	return 0;
}