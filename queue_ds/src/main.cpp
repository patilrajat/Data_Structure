/*
 Main reason that we choose circular queue
 Main problem with linear queue is --
     if queue is full
     when we deque element 1st element becomes zero
     then also it will show queue is full untill we dequeue all elements
     and then rear and front will made -1 and then it will show empty
 */



#include <iomanip>
#include <iostream>
using namespace std;
#define SIZE 5
class queue
{
private:
	int rear;
	int front;
	int arr[SIZE];
public:
	queue(){
		rear=-1;
		front=-1;
		for(int i=0;i<SIZE;++i){
			arr[i]=0;
		}
	}
	bool isEmpty(){
		if(rear==-1 && front==-1)
			return true;
		else
			return false;
	}
	bool isFull(){
		if(rear==(SIZE-1))
			return true;
		else
			return false;
	}
	void enqueue(int val){
		if(isFull()){
			cout<<"queue is full"<<endl;
			return;
		}
		else if(isEmpty()){
			front=0;        //this is wrong == front++
			rear=0;         //this is wrong == rear++
			arr[rear]=val;
		}
		else{
			rear++;
			arr[rear]=val;
		}

	}
	int dequeue(){
		if(isEmpty()){
			cout<<"queue is empty"<<endl;
			return 0;
		}
		else if(rear==front){
			int temp;
			temp=arr[front];
			arr[front]=0;         //deque means deleting always from front
			front=-1;
			rear=-1;
			return temp;
		}
		else{
			int temp;
			temp=arr[front];
			arr[front]=0;         //deque means deleting always from front
			front++;              //wrong code is rear-- (decreasing rear)
			return temp;
		}
	}
	int count(){
		return (rear-front)+1;   //wrong == rear+1 ,if starting 3 are zero it will give also 5
	}
	void display(){
		cout<<endl<<"all values in Queue are :"<<endl;
		for(int i=0;i<SIZE;++i){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
int menu(){
	int choice;
	cout<<"Enter choice"<<endl;
	cout<<"1.Enqueue"<<endl;
	cout<<"2.Dequeue"<<endl;
	cout<<"3.isEmpty"<<endl;
	cout<<"4.isFull"<<endl;
	cout<<"5.Count"<<endl;
	cout<<"6.Display"<<endl;
	cin>>choice;
	return choice;
}
int main()
{
	queue s;
	int choice,val;
	while((choice=menu())!=0)
	{
		switch(choice)
		{
		case 1://Enqueue
			cout<<"enter to enqueue"<<endl;
			cin>>val;
			s.enqueue(val);
			cout<<endl;
			break;
		case 2://Dequeue
			val=s.dequeue();
			cout<<"value dequeued :"<<val<<endl;
			break;
		case 3://isEmpty
			if(s.isEmpty())
				cout<<"Queue is Empty"<<endl;
			else
				cout<<"Queue is not Empty"<<endl;
			break;
		case 4://isFull
			if(s.isFull())
				cout<<"Queue is Full"<<endl;
			else
				cout<<"Queue is not Full"<<endl;
			break;
		case 5://Count
			cout<<"Number of elements in queue :"<<s.count()<<endl;
			break;
		case 6://Display
			s.display();
			break;
		default:
			cout<<"enter proper option"<<endl;
			break;
		}
	}
	return 0;

}

