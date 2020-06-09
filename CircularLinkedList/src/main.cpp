
#include <iomanip>
#include <iostream>
using namespace std;

class Node
{
public:
	int key;
	int data;
	Node *next;
	Node()
	{
		key=0;
		data=0;
		next = NULL;
	}
	Node(int k,int d)
	{
		key=k;
		data=d;
	}
};
class CircularLinkedList
{
public:
	Node* head;
	CircularLinkedList()
	{
		head=NULL;
	}
	CircularLinkedList(Node* n)
	{
		head=n;
	}

	Node* nodeExists(int k)    //check if node exist or not using key value
	{
		Node* temp=NULL;
		Node* ptr=head;
		if(ptr==NULL)
		{
			return temp;
		}
		else
		{
			do                //if we would have kept while loop, it could not have checked head
			{
				if(ptr->key==k)
				{
					temp=ptr;
				}

				ptr=ptr->next;
			}while(ptr!=head);      //this condition is imp b'coz we cant find end
			//if we write while(ptr!=NULL) it will infinite loop
			return temp;
		}

	}

	void appendNode(Node* n)          //add node at end
	{
		if(nodeExists(n->key)!=NULL)    //check if node already exist with key passed
		{
			cout<<"Node already exist with key : "<<n->key<<endl;
			cout<<"Try with another key"<<endl;
		}
		else
		{
			if(head==NULL)         //if there is no node previously
			{
				head=n;
				n->next=head;
				cout<<"Node appended at first"<<endl;
			}
			else
			{
				Node* ptr;
				ptr=head;
				while(ptr->next!=head)        //travers until last node
				{
					ptr=ptr->next;
				}
				ptr->next=n;
				n->next=head;
				cout<<"Node appended"<<endl;
			}
		}
	}

	void prependNode(Node* n)                //add node at 1st position
	{
		if(nodeExists(n->key)!=NULL)    //check if node already exist with key passed
		{
			cout<<"Node already exist with key : "<<n->key<<endl;
			cout<<"Try with another key"<<endl;
		}
		else
		{
			if (head == NULL) {
				head = n;
				n-> next = head;
				cout << "Node Prepended"<<endl;
			}
			else
			{
				Node* ptr = head;
				while(ptr->next!=head)
				{
					ptr=ptr->next;
				}
				ptr->next = n;
				n->next = head;
				head = n;
				cout<<"Node appended"<<endl;
			}
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
				cout<<"Try with another key"<<endl;
			}
			else
			{
				if(ptr->next==head)  //checking if key is in last node
				{
					n->next=head;
					ptr->next=n;     //this is wrong....(head->next=n)
					cout<<"Inserted at end"<<endl;
				}
				else
				{
					n->next=ptr->next;
					ptr->next=n;
					cout<<"Inserted in between"<<endl;
				}
			}
		}

	}

	void deleteNodeByKey(int k)       //delete node with perticular key
	{
		Node* ptr = nodeExists(k);
		if(ptr==NULL)                //check key exists or not
		{
			cout<<"No node present with key : "<<k<<endl;
		}
		else
		{
			if(ptr==head)         //if key present in head
			{
				if(head->next==head)              //key present in head but only one node present
				{
					head = NULL;
					cout<<"Node unlinked....List Empty"<<endl;
				}
				else              //key present in head but further nodes are present
				{
					Node* temp = head;   //this is only for find last node
					while(temp->next!=head)
					{
						temp=temp->next;
					}
					ptr->next = head->next;
					head = head->next;
					cout<<"Node unlinked....With key : "<<k<<endl;
				}
			}
			else                     //if key not present in head
			{
				Node* temp=NULL;
				Node* prevptr=head;               //point head
				Node* currentptr=head->next;      //point next to head
				while(currentptr!=NULL)           //until currentptr NULL
				{
					if(currentptr->key==k)        //find node with key
					{
						temp=currentptr;          //take that node in temp
						currentptr=NULL;          //it is for ending loop
					}
					else
					{
						prevptr=prevptr->next;
						currentptr=currentptr->next;
					}
				}

				prevptr->next=temp->next;
				cout<<"Unlinked Node with key : "<<k<<endl;


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
			cout<<"Head address : "<<head;
			cout<<"Circular Linked List is :"<<endl;
			Node* ptr=head;
			do
			{
				cout<<"("<<ptr->key<<","<<ptr->data<<","<<ptr->next<<")"<<"-->";
				ptr=ptr->next;
			}while(ptr!=head);           //this condition is for checking end
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
	CircularLinkedList s;
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

