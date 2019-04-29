#include <iostream>
#include <cstdlib>
using namespace std;
class node
{
public:
	string PRN;
	string name;
	node *next;
};
int count = 0;
node *temp, *temp1;
class pClub
{
	node *head, *last;
public:
	pClub();
	void add();
	void display();
	void reverse();
	void remove();
};
pClub::pClub()
{
	head = NULL; last = NULL;
}
void pClub::display()
{
	if(count == 0)
	{
		cout<<"Add members in the first place!"<<endl;
		return;
	}
	cout<<"\n";
	temp = head;
	while(temp != NULL)
	{
		cout<<temp->name<<"\t"<<temp->PRN<<endl;
		temp = temp->next;
	}
}
void pClub::add()
{
	if(head == NULL)
	{
		temp = new node;
		cout<<"\nEnter PRN of President: ";
		cin>>temp->PRN;
		cout<<"\nEnter name of President: ";
		cin>>temp->name;
		temp->next = NULL;
		head = temp;
		temp = new node;
		cout<<"\nEnter PRN of Secretary: ";
		cin>>temp->PRN;
		cout<<"\nEnter name of Secretary: ";
		cin>>temp->name;
		temp->next = NULL;
		last = temp;
		head->next = last;
		count = 2;
	}
	else
	{
		temp1 = head;
		while(temp1->next != last)
			temp1 = temp1->next;
		temp = new node;
		cout<<"\nEnter PRN of member: ";
		cin>>temp->PRN;
		cout<<"\nEnter name of member: ";
		cin>>temp->name;
		temp->next = NULL;
		temp1->next = temp;
		temp->next = last;
		count++;
	}
	cout<<"\nYour List of Members: "; display();
}
void pClub::reverse()
{
	node *prev, *curr, *next1;
	prev = NULL; curr = head;
	while(curr!=NULL)
	{
		next1 = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next1;
	}
	head = prev;
	cout<<"\nReversed List of Members: "; display();
}
void pClub::remove()
{
	int ch, pos;
	string data;
	temp = head;
	if(count == 0)
	{
		cout<<"Create a linked list first!"<<endl;
		return;
	}
	cout<<"How would you like to remove a member from the club?"<<endl;
	cout<<"1. By Position"<<endl;
	cout<<"2. By PRN"<<endl;
	cout<<"3. By name"<<endl;
	cin>>ch;
	cout<<endl;
	switch(ch)
	{
		case 1: cout<<"Enter the position of node you want to delete: ";
		cin>>pos;
		if(pos<0 || pos>count)
		{
            cout<<"Invalid Entry"<<endl;
            return;
		}
		if(pos == 1 || pos == count)
		{
			cout<<"You are supposed to delete the members, not the president or secretary"<<endl;
			return;
		}
		else
		{
			for(int i=0; i<pos-2; i++)
				temp = temp->next;
			temp1 = temp->next;
			temp->next = temp1->next;
			delete(temp1);
			count--;
		}
		break;
		case 2: cout<<"Enter PRN of the member you want to delete: ";
		cin>>data;
		if(data == head->PRN || data == last->PRN)
		{
			cout<<"You are supposed to delete the members, not the president or secretary"<<endl;
			return;
		}
		if(head->PRN == data)
		{
			head = temp->next;
			temp->next = NULL;
			delete(temp);
			count--;
			if(count<0) count = 0;
		}
		else
		{
			node *pnode;
			pnode = head;
			while(pnode->next!=NULL && pnode->next->PRN!=data)
				pnode = pnode->next;
			if(pnode->next == NULL)
			{
				cout<<"Entered PRN is not present in the linked list"<<endl;
				return;
			}
			temp = pnode->next;
			pnode->next = temp->next;
			delete(temp);
			count--;
		}
		break;
		case 3: cout<<"Enter name of the member you want to delete: ";
		cin>>data;
		if(data == head->name || data == last->name)
		{
			cout<<"You are supposed to delete the members, not the president or secretary"<<endl;
			return;
		}
		if(head->name == data)
		{
			head = temp->next;
			temp->next = NULL;
			delete(temp);
			count--;
		}
		else
		{
			node *pnode;
			pnode = head;
			while(pnode->next!=NULL && pnode->next->name!=data)
				pnode = pnode->next;
			if(pnode->next == NULL)
			{
				cout<<"Entered name is not present in the linked list"<<endl;
				return;
			}
			temp = pnode->next;
			pnode->next = temp->next;
			delete(temp);
			count--;
			if(count<0) count = 0;
		}
		break;
	}
	cout<<"\nYour List of Members: "; display();
}
int main()
{
	pClub P;
	int ch;
	while(1)
	{
		cout<<"\n1. Add Members"<<endl;
		cout<<"2. Display Members"<<endl;
		cout<<"3. No. of Members"<<endl;
		cout<<"4. Delete Member"<<endl;
		cout<<"5. Reverse List"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: P.add(); break;
			case 2: P.display(); break;
			case 3: cout<<"Total no. of members: "<<count<<endl; break;
			case 4: P.remove(); break;
			case 5: P.reverse(); break;
			case 6: exit(0); break;
			default: cout<<"\nInvalid choice"; break;
		}
	}
	return 0;
}
