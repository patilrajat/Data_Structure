/*
 * main.cpp
 *
 *  Created on: 14-May-2020
 *      Author: sunbeam
 */
#include <iomanip>
#include <iostream>
using namespace std;
#define SIZE 5
class circular_queue
{
private:
	int rear;
	int front;
	int arr[SIZE];
	int itemcount;
public:
	circular_queue(){
		rear=-1;
		front=-1;
		itemcount=0;
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
		if((rear+1)%SIZE == front)  //1st change fron linear queue
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
			itemcount++;
		}
		else{
			rear=(rear+1)%SIZE;
			arr[rear]=val;
			itemcount++;
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
			arr[front]=0;
			front=-1;
			rear=-1;
			itemcount--;
			return temp;
		}
		else{
			int temp;
			temp=arr[front];
			arr[front]=0;
			front=(front+1)%SIZE;  // 2nd change from linear queue
			itemcount--;
			return temp;
		}
	}
	int count(){
		return itemcount;         //3rd change from linear queue
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
	circular_queue s;
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

