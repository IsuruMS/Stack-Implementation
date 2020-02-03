#include<iostream>
using namespace std;

//structure for the linked list
struct Node
{
	int number; //holds data
	Node* next; //hosld next address
};

class Stack  //class for implimentation of stacks
{
private:
	Node* top;  //hold the top variable
public:
	Stack() //constructor
	{
		top = NULL;
	}
	void Push(int x); //push a number to the top of the stack
	int Pop(); //take out and remove the top number of the stack
	void Print(); //print the stack
	Stack Reverse(); //reverse the stack
	int Count(); //count the no. of elemnts in the stack
	void Delete(); //delete the whole stack
};

void Stack::Push(int x)
{
	//new node to hold the new data
	Node* temp = new Node;
	temp->number = x;
	//setting the new node's next address to the current top
	temp->next = top;
	top = temp;  //current top is no longer the top, new node is updated as top
	
}

int Stack::Pop()
{
	// check for stack underflow 
	if (top == NULL) {
		cout << "Stack Underflow" << endl;
		exit(1);
	}
	//temp pointer to hold the top
	Node* temp = top;
	//take the data out of the top node
	int data = top->number;
	//set the top node to the next node
	top = top->next;
	delete(temp); //delete the current top node
	return data; //return the data that was retrieved
}

void Stack::Print()
{
	// check for stack underflow 
	if (top == NULL) {
		cout << "Stack Underflow" << endl;
		exit(1);
	}
	//traverse and print
	Node* temp = top;
	while (temp != NULL)
	{
		cout << temp->number << "\n------" << endl;
		temp = temp->next;
	}
}

Stack Stack::Reverse()
{
	// check for stack underflow 
	if (top == NULL) {
		cout << "Stack Underflow" << endl;
		exit(1);
	}
	//a temperory stack
	Stack temp;
	//pointer to the top
	Node* ptr = top;
	//traverse through the stack
	//top node is popped and pushed to temp
	while (ptr != NULL)
	{
		ptr = ptr->next;
		temp.Push(this->Pop());
	}
	//print the reversed stack
	temp.Print();
	return temp;
}

int Stack::Count()
{
	// check for stack underflow 
	if (top == NULL) {
		cout << "Stack Underflow" << endl;
		exit(1);
	}
	Node* temp = top;
	int count = 0; 
	//traverse and count the no of variables
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void Stack::Delete()
{
	// check for stack underflow 
	if (top == NULL) {
		cout << "Stack Underflow" << endl;
		exit(1);
	}
	//to delete the stack we need to make the top variable has nothing 
	top = NULL;
}

//main function
//program starts here
int main()
{
	Stack s; //stack object
	int noOfElements;
	cout << "Opening No. of Elements in the Stack : ";
	cin >> noOfElements;
	int input;
	//inserting the elemets to the stack
	for (int i = 0; i < noOfElements; i++)
	{
		cin >> input;
		s.Push(input);
	}
	system("cls");
	s.Print();
	cout << endl << endl;
//jumppoint to retun when a task is done
jumppoint:
	//getting the user input for various tasks on stacks
	cout << "1. Push\n2. Pop\n3. Print\n4. Reverse\n5. Count\n6. Delete\n7. Exit" << endl;
	cout << "Enter Your Choice : ";
	cin >> input;
	//switch statement fot performing each task
	switch (input)
	{
	case 1:
	{
		cout << "Number : ";
		cin >> input;
		s.Push(input);
		cout << endl;
		s.Print();
		break;
	}
	case 2:
	{
		s.Pop();
		cout << endl;
		s.Print();
		cout << endl;
		break;
	}
	case 3:
	{
		s.Print();
		cout << endl;
		break;
	}
	case 4:
	{
		s = s.Reverse();
		break;
	}
	case 5:
	{
		cout << "Number of Elemets in Stack : " << s.Count() << endl;
		break;
	}
	case 6:
	{
		s.Delete();
		s.Print();
		break;
	}
	case 7:
	{
		return 0;
		break;
	}
	}
	goto jumppoint;

	//program ends here
	system("pause");
}