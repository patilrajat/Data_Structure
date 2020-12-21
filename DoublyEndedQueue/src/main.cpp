#include<iostream>
#include<string>
using namespace std;
namespace collection
{
	class Exception
	{
	private:
		string message;
	public:
		Exception( string message ) throw( ) : message( message )
		{	}
		string getMessage( void )const throw( )
		{
			return this->message;
		}
	};
	class Queue
	{
	private:
		int rear;
		int front;
		int size;
		int *arr;
	public:
		Queue( void ) throw( bad_alloc ) : rear( -1 ), front( -1 ) , size( 5 )
		{
			this->arr = new int[ this->size ];
		}
		Queue( int size ) throw( bad_alloc ) : rear( -1 ), front( -1 ) , size( size )
		{
			this->arr = new int[ this->size ];
		}
		bool empty( void )const throw( )
		{
			return this->rear == -1;
		}
		bool full( void )const throw( )
		{
			return ( this->rear + 1 ) % this->size == this->front;
		}
		void enqueueFront( int element )throw( Exception )
		{
			if( this->full( ) )
				throw Exception("Queue is full");
			if( this->rear == -1 )
				this->rear = this->front = 0;
			else
				this->rear = ( this->rear + 1 ) % this->size;
			this->arr[ this->rear ] = element;
		}
		void enqueueBack( int element )throw( Exception )
		{
			if( this->full( ) )
				throw Exception("Queue is full");
			if( this->rear == -1 )
				this->rear = this->front = 0;
			else
				this->front = ( this->front - 1 + this->size ) % this->size;   //Chance of mistake
			this->arr[ this->front ] = element;
		}
		int peekFront( void )const throw( Exception )
		{
			if( this->empty( ) )
				throw Exception("Queue is empty");
			return this->arr[ this->front ];
		}
		int peekBack( void )const throw( Exception )
		{
			if( this->empty( ) )
				throw Exception("Queue is empty");
			return this->arr[ this->rear ];
		}
		void dequeueFront( void )
		{
			if( this->empty( ) )
				throw Exception("Queue is empty");
			if( this->rear == this->front )
				this->rear = -1;
			else
				this->front = ( this->front + 1 ) % this->size;
		}
		void dequeueBack( void )
		{
			if( this->empty( ) )
				throw Exception("Queue is empty");
			if( this->rear == this->front )
				this->rear = -1;
			else
				this->rear = ( this->rear - 1 + this->size ) % this->size;     //Chance of mistake
		}
		~Queue( void )
		{
			if( this->arr != NULL )
			{
				delete[] this->arr;
				this->arr = NULL;
			}
		}
	};
}
void accept_record( int &element )
{
	cout<<"Enter element	:	";
	cin>>element;
}
void print_record( const int &element )
{
	cout<<"Popped element is	:	"<<element<<endl;
}
int menu_list( void )
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.EnqueueFront"<<endl;
	cout<<"2.DequeueFront"<<endl;
	cout<<"3.EnqueueBack"<<endl;
	cout<<"4.DequeueBack"<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{
	int choice, element;
	using namespace collection;
	Queue que;
	while( ( choice = ::menu_list( ) ) != 0 )
	{
		try
		{
			switch( choice )
			{
			case 1:
				::accept_record(element);
				que.enqueueFront(element);
				break;
			case 2:
				element = que.peekFront();
				::print_record(element);
				que.dequeueFront();
				break;
			case 3:
				::accept_record(element);
				que.enqueueBack(element);
				break;
			case 4:
				element = que.peekBack();
				::print_record(element);
				que.dequeueBack();
				break;
			}
		}
		catch( Exception &ex )
		{
			cout<<ex.getMessage( )<<endl;
		}
	}
	return 0;
}
