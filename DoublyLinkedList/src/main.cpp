
#include <iomanip>
#include <iostream>
using namespace std;

class Node
{
public:
	int key;
	int data;
	Node *previous;
	Node *next;
	Node()
	{
		key=0;
		data=0;
		previous = NULL;
		next = NULL;
	}
	Node(int k,int d)
	{
		key=k;
		data=d;
	}
};
class DoublyLinkedList
{
public:
	Node* head;
	DoublyLinkedList()
	{
		head=NULL;
	}
	DoublyLinkedList(Node* n)
	{
		head=n;
	}

	Node* nodeExists(int k)    //check if node exist or not using key value
	{
		Node* temp=NULL;
		Node* ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->key==k)
				temp=ptr;

			ptr=ptr->next;
		}
		return temp;
	}

	void appendNode(Node* n)          //add node at end
	{
		if(nodeExists(n->key)!=NULL)    //check if node already exist with key passed
		{
			cout<<"Node already exist with key : "<<n->key<<endl;
		}
		else
		{
			if(head==NULL)         //if there is no node previously
			{
				head=n;
				cout<<"Node appended as Head"<<endl;
			}
			else
			{
				Node* ptr;
				ptr=head;
				while(ptr->next!=NULL)        //travers until last node
				{
					ptr=ptr->next;
				}
				ptr->next=n;
				n->previous=ptr;
				cout<<"Node appended"<<endl;
			}
		}
	}

	void prependNode(Node* n)                //add node at 1st position
	{
		if(nodeExists(n->key)!=NULL)    //check if node already exist with key passed
		{
			cout<<"Node already exist with key : "<<n->key<<endl;
		}
		else
		{
			head->previous=n;
			n->next=head;

			head=n;
			cout<<"Node appended"<<endl;
		}
	}

	void insertNodeAfter(int k,Node* n)       //add node after perticular key
	{
		Node* ptr=nodeExists(k);
		if(ptr==NULL)
		{
			cout<<"key not exist to add after"<<endl;
		}
		else
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<"Node already exist with key : "<<n->key<<endl;
			}
			else
			{
				Node* nextNode = ptr->next;
				if(nextNode==NULL)             //if key node at last
				{
					ptr->next=n;
					n->previous=ptr;
					cout<<"Node inserted at end"<<endl;
				}
				else
				{
					n->previous=ptr;
					ptr->next=n;
					n->next=nextNode;
					nextNode->previous=n;

					cout<<"node inserted in between"<<endl;
				}
			}
		}
	}

	void deleteNodeByKey(int k)       //delete node with perticular key
	{
		Node* ptr=nodeExists(k);
		if(ptr==NULL)                //check key present or not
		{
			cout<<"Key not present in doubly linked list"<<endl;
		}
		else
		{
			if(head->key==k)         //if key present in head
			{
				head=head->next;
				head->previous = NULL;
				cout<<"Unlinked Node with key : "<<k<<endl;
			}
			else                     //if key not present in head
			{

				Node* prevNode=ptr->previous;      //point previous node of key node
				Node* nextNode=ptr->next;      //point next node of key node

				if(nextNode==NULL)        //if key node is last node
				{
					prevNode->next = NULL;          //deleting last node
				}
				else                      //if node in between
				{
					prevNode->next=nextNode;
					nextNode->previous=prevNode;
					cout<<"Node deleted in between"<<endl;
				}


			}
		}
	}

	void updateNodeByKey(int k, int d)   //it takes data and update at given key
	{
		Node* temp=nodeExists(k);
		if(temp==NULL)
		{
			cout<<"No node found for key : "<<k<<endl;
		}
		else
		{
			temp->data=d;
			cout<<"Updated successfull"<<endl;
		}
	}

	void printList()
	{
		if(head==NULL)
		{
			cout<<"No nodes in List"<<endl;
		}
		else
		{
			cout<<"Doubly Linked List is :"<<endl;
			Node* ptr=head;
			while(ptr!=NULL)
			{
				cout<<"("<<ptr->key<<","<<ptr->data<<")"<<"<-->";
				ptr=ptr->next;
			}
			cout<<endl;
		}
	}
};
int menu(){
	int choice;
	cout<<"Enter choice"<<endl;
	cout<<"1. appendNode"<<endl;
	cout<<"2. prependNode"<<endl;
	cout<<"3. insertNodeAfter"<<endl;
	cout<<"4. deleteNode"<<endl;
	cout<<"5. updateNodeByKey"<<endl;
	cout<<"6. Display List"<<endl;
	cin>>choice;
	return choice;
}
int main()
{
	DoublyLinkedList s;
	int choice;
	int d1,k1,k2;
	while((choice=menu())!=0)
	{
		Node* n1=new Node();
		switch(choice)
		{
		case 1://appendNode
			cout<<"Enter details to add at last"<<endl;
			cout<<"Key : ";
			cin>>k1;
			n1->key=k1;
			cout<<endl;
			cout<<"Data : ";
			cin>>d1;
			n1->data=d1;
			cout<<endl;
			s.appendNode(n1);
			break;
		case 2://prependNode
			cout<<"Enter details to add at first"<<endl;
			cout<<"Key : ";
			cin>>k1;
			n1->key=k1;
			cout<<endl;
			cout<<"Data : ";
			cin>>d1;
			n1->data=d1;
			cout<<endl;
			s.prependNode(n1);
			break;
		case 3://insertNodeAfter
			cout<<"Enter details to add"<<endl;
			cout<<"Key after add : ";
			cin>>k2;
			cout<<endl;
			cout<<"Key : ";
			cin>>k1;
			n1->key=k1;
			cout<<endl;
			cout<<"Data : ";
			cin>>d1;
			n1->data=d1;
			cout<<endl;
			s.insertNodeAfter(k2,n1);
			break;
		case 4://deleteNode
			cout<<"Enter details to delete"<<endl;
			cout<<"Key : ";
			cin>>k1;
			cout<<endl;
			s.deleteNodeByKey(k1);
			break;
		case 5://updateNodeByKey
			cout<<"Enter details to delete"<<endl;
			cout<<"Key : ";
			cin>>k1;
			cout<<endl;
			cout<<"Data : ";
			cin>>d1;
			cout<<endl;
			s.updateNodeByKey(k1,d1);
			break;
		case 6://Display List
			s.printList();
			break;
		default:
			cout<<"Enter appropriate choice"<<endl;
			break;
		}
	}
	return 0;

}

