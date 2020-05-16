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
class stack
{
private:
	int arr[SIZE];
	int top;
public:
	stack(){
		top=-1;
		for(int i=0;i<SIZE;++i)
		{
			arr[i]=0;
		}
	}
	bool isFull(){
		if(top==(SIZE-1))
			return true;
		else
			return false;
	}
	bool isEmpty(){
		if(top==-1)
			return true;
		else
			return false;
	}
	void push(int val){
		if(isFull())
			cout<<"stack is full"<<endl;
		else
		{
			top++;
			arr[top]=val;
		}
	}
	int pop(){
		if(isEmpty())
		{
			cout<<"stack is empty"<<endl;
			return 0;
		}
		else
		{
			int temp;
			temp=arr[top];
			arr[top]=0;
			top--;
			return temp;
		}
	}
	int seek(int pos){
		if(isEmpty())
		{
			cout<<"stack is empty"<<endl;
			return 0;
		}
		else
		{
			return arr[pos];
		}
	}
	int count(){
		return top+1;
	}
	void change(int pos,int val){
		if(isEmpty())
		{
			cout<<"stack is empty"<<endl;
		}
		else
		{
			arr[pos]=val;
		}
	}
	void display(){
		cout<<"pos "<<":"<<" val"<<endl;
		for(int i=(SIZE-1);i>=0;i--)
		{
			cout<<setw(4)<<i<<":"<<setw(4)<<arr[i]<<endl;
		}
	}
};
int menu(){
	int choice;
	cout<<"Enter choice"<<endl;
	cout<<"1.Push"<<endl;
	cout<<"2.Pop"<<endl;
	cout<<"3.Display"<<endl;
	cout<<"4.count"<<endl;
	cout<<"5.Is Full"<<endl;
	cout<<"6.Is Empty"<<endl;
	cout<<"7.Seek"<<endl;
	cout<<"8.Change"<<endl;
	cin>>choice;
	return choice;
}
int main()
{
	stack s;
	int choice,pos,val;
	while((choice=menu())!=0)
	{
		switch(choice)
		{
		case 1://push
			cout<<"enter to push"<<endl;
			cin>>val;
			s.push(val);
			cout<<endl;
			break;
		case 2://pop
			val=s.pop();
			cout<<"value poped :"<<val<<endl;
			break;
		case 3://display
			s.display();
			break;
		case 4://count
			cout<<"count is :"<<s.count()<<endl;
			break;
		case 5://infull
			if(s.isFull())
				cout<<"stack is full"<<endl;
			else
				cout<<"stack is not full"<<endl;
			break;
		case 6://isempty
			if(s.isEmpty())
				cout<<"stack is empty"<<endl;
			else
				cout<<"stack is not empty"<<endl;
			break;
		case 7://seek
			cout<<"enter pos :";
			cin>>pos;
			val=s.seek(pos);
			cout<<"value at"<<pos<<" is "<<val<<endl;
			break;
		case 8://change
			s.display();
			cout<<"enter pos :";
			cin>>pos;
			cout<<endl;
			cout<<"enter val :";
			cin>>val;
			s.change(pos,val);
			cout<<endl;
			break;
		}
	}
	return 0;

}

