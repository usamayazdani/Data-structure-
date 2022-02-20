#include <iostream>
using namespace std;

struct node
{
	int info;
	node *next;
};

// Class
class list
{
private:
	int key;
	int counter;
	string choice;
	node *head;
	node *temp;
	node *temp1;

public:
	list()
	{
		head = temp = temp1 = NULL;
		int counter = 0;
	}

	void add()
	{
		if (head == NULL)
		{
			cout << "Enter the Value of Head. " << endl;
			head = new node;
			cin >> head->info;
			head->next = NULL;
			return;
		}

		temp = head;
		//	while(temp->next != NULL)
		//			{
		//				temp = temp->next;
		//			}
		//			temp1 = new node;
		//			cout<<"please enter value"<<endl;
		//			cin>>temp1->info;
		//			temp1->next = NULL;
		//			temp->next=temp1;
		//			temp=temp1;
		//			return;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		cout << "Plz Add the Value. " << endl;
		temp1 = new node;
		cin >> temp1->info;
		temp1->next = NULL;
		temp->next = temp1;
		temp = temp1;
		return;

		//	temp = temp -> next;
	}
	void reversePrint(node *current)
	{
		if (current != NULL)
		{
			reversePrint(current->next);  //print the tail
			cout << current->info << " "; //print the node
		}
	}
	void insert()
	{
		if (head == NULL)
		{
			head = new node;
			cout << "please enter value" << endl;
			cin >> head->info;
			head->next = NULL;
			return;
		}
		int choice;
		cout << "Press 1 for value enter before head  or press 0 for middle in the array. " << endl;
		cin >> choice;
		if (choice == 1)
		{
			temp1 = new node;
			cout << "enter the head value you want to enter" << endl;
			cin >> temp1->info;
			temp1->next = head;
			head = temp1;
		}
		else if (choice == 0)
		{

			temp = head;
			cout << "after wich value you want to enter " << endl;
			cin >> key;
			while (temp != NULL)
			{

				if (temp->info == key)
				{
					temp1 = new node;
					cout << "Enter the value of node ." << endl;
					cin >> temp1->info;
					temp1->next = temp->next;
					temp->next = temp1;
					return;
				}

				temp = temp->next;
			}
		}
	}
	void counting_of_nodes()
	{
		temp = head;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
	}
	void duplicate()
	{
	}

	void print()
	{
		temp = head;
		if (temp == NULL)
		{
			cout << "The list is empty.There is no value to print." << endl;
		}
		while (temp != NULL)
		{
			cout << temp->info << " " << endl;
			temp = temp->next;
		}
		//cout<<"Number of nodes in lnked_ List is"<<counter;
	}

	void search()
	{
		temp = head;
		cout << "Now you are going to search value. " << endl;
		cin >> key;
		if (temp == NULL)
		{
			cout << "The list is empty." << endl;
			return;
		}
		while (temp != NULL)
		{
			if (temp->info == key)
			{
				//		cout <<"The key is found. " << endl;
				cout << "The key " << key << " is found at this position. " << counter << endl;
				counter++;
			}
			temp = temp->next;
		}
	}

	void delete1()
	{
		temp = head;
		int delekey;
		int choice;
		if (temp == NULL)
		{
			cout << "List is Empty. " << endl;
			return;
		}
		cout << "for delete in head press 1 and for whithin array press 0" << endl;
		cin >> choice;
		cout << "Plz enter value which you want to delete. " << endl;
		cin >> delekey;

		if (choice == 1)
		{
			if (head->info == delekey)
			{
				cout << "You are going to delete head" << endl;
				temp = head->next;
				delete head;
				head = temp;
			}
		}
		else if (choice == 0)
		{
			temp = head;

			//	cout << "Plz enter value which you want to delete. " << endl;
			//	cin >> delekey;
			while (temp != NULL)
			{
				if (temp->next->info == delekey)
				{
					temp1 = temp->next;
					temp->next = temp1->next;
					delete temp1;
					return;
				}

				temp = temp->next;
			}
		}
	}
	bool search_a_element(int x)
	{
		temp = head;

		while (temp != NULL)
		{
			if (temp->info == x)
			{
				return true;
			}
			else
			{
				return false;
			}

			temp = temp->next;
		}
	}
	void code()
	{
		int max, min, counter;
		cout << "Check code " << endl;
		max = head->info;
		min = head->info;
		temp = head;
		while (temp != NULL)
		{
			if (max < temp->info)
			{
				max = temp->info;
			}
			else if (min > temp->info)
			{
				min = temp->info;
			}

			temp = temp->next;
		}
		while (temp != NULL)
		{
			if (temp->next->info == max)
			{
				temp1 = temp->next;
				temp->next = temp1->next;
				delete temp1;
			}
			else if (temp->next->info == min)
			{
				temp1 = temp->next;
				temp->next = temp1->next;
				delete temp1;
			}
			temp = temp->next;
		}
	}
	void finding_middle_element()
	{

		int le, mid;
		temp = head;
		while (temp != NULL)
		{
			le++;
			temp = temp->next;
		}

		mid = ((1 + le) / 2);
		if (le % 2 == 0)
		{
			mid++;
		}

		temp = head;
		int i = 1;
		while (temp != NULL)
		{
			if (i == mid)
				cout << "The mid element is : " << temp->info << endl;
			temp = temp->next;
			i++;
		}
	}
	void finding_same_element()
	{
		int check;

		temp = head;
		while (temp != NULL)
		{
			check = temp->info;
			temp1 = head;
			int repetition = 0;

			while (temp1 != NULL)
			{
				if (temp1->info == check)
				{
					repetition = repetition + 1;
				}
				temp1 = temp1->next;
			}

			temp = temp->next;
			cout << "the " << check << " in your list is :" << repetition << endl;
		}
	}
	void deleting_same_element()
	{

		temp = head;
		while (temp != NULL && temp->next != NULL)
		{

			temp1 = temp;

			while (temp1->next != NULL)
			{

				if (temp->info == temp1->next->info)
				{
					temp1->next = temp1->next->next;
				}
				else
				{
					temp1 = temp1->next;
				}
			}

			temp = temp->next;
		}
	}
	void swaping_data(int x, int y)
	{
		temp = head;
		while (temp != NULL)
		{
			temp1 = temp;
			while (temp1 != NULL)
			{
				if (temp->info == x && temp1->info == y)
				{
					int tem;
					tem = temp->info;
					temp->info = temp1->info;
					temp1->info = tem;
				}
				else
				{
					temp1 = temp1->next;
				}
			}
			temp = temp->next;
		}
	}
	void reversed()
	{
		node *prev, *current, *next_ptr;
		current = NULL;
		prev = NULL;
		next_ptr = NULL;
		current = head;
		while (current != NULL)
		{
			next_ptr = current->next;
			current->next = prev;

			prev = current;

			current = next_ptr;
		}
		head = prev;
	}
	void using_only_two()
	{
		node *next_ptr, *back_Ptr;
		next_ptr = head;
		back_Ptr = NULL;
		while (next_ptr != NULL)
		{
			back_Ptr = next_ptr;
			next_ptr = next_ptr->next;
			//back_Ptr->next=next_ptr;
		}
		head = back_Ptr;
	}
	void checking_ascending()
	{
		node *first = head;
		node *second = head;
		second = first->next;
		while (first != NULL)
		{
			if (first->next < second->next)
			{
				first = first->next;
				second = second->next;
			}
			else
				cout << "NOT ascending ";
		}
	}
};

int main()
{
	list obj;
	obj.add();
	obj.add();
	obj.add();
	obj.add();
	//obj.using_only_two();
	//obj.swaping_data(1,3);
	//obj.add();
	//obj.add();
	//obj.reversed();
	//obj.add();
	//obj.add();
	//obj.insert();
	//obj.print();
	//obj.finding_middle_element();
	//	obj.deleting_same_element();
	//obj.code();
	//obj.print();
	//cout<<"Returning vlaues"<<obj.search_a_element(16);
	//obj.search();
	//obj.search();
	//obj.counting_of_nodes();
	node *first;
	obj.reversePrint(first);
	//obj.delete1();
	return 0;
}
