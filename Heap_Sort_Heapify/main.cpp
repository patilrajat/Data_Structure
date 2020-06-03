#include <iostream>
using namespace std;
#include <iomanip>
void heapify(int arr[], int n, int i)  //n-no.of element i=index on which heapify called
{
	int largest=i;
	int l=2*i+1;    //left child
	int r=2*i+2;    //right child

	//checking left is less than size and greater than called index
	if((l<n) && (arr[l]>arr[largest]))
	{
		largest=l;
	}

	//checking right is less than size and greater than called index
	if((r<n) && (arr[r]>arr[largest]))
	{
		largest=r;
	}
	if(largest != i)
	{
		int temp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		heapify(arr,n,largest);
	}

}
void heap_sort(int arr[], int n)
{
	for (int i = n/2-1; i>=0; --i)   //here i should reach to 0 (not=>1)
	{
		heapify(arr,n,i);
	}
	for (int i=n-1 ;i>=0 ;--i)   //deleting from 0 index element
	{
		int temp=arr[0];         //swap first(0 index) and last(size-1 index)
		arr[0]=arr[i];
		arr[i]=temp;
		heapify(arr,i,0);        //always call heapify on 0 index
	}
}

int main()
{
	int arr[]={20,50,40,30,10};

	int n= sizeof(arr)/sizeof(arr[0]);  //no. of element
	cout<<"array before sort:"<<endl;
	for(int i=0;i<n;++i)
	{
		cout<<setw(4)<<arr[i];
	}

	heap_sort(arr,n);

	cout<<endl;
	cout<<"array after sort:"<<endl;
	for(int j=0;j<n;++j)
	{
		cout<<setw(4)<<arr[j];
	}
	return 0;
}

