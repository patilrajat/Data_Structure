#include <iostream>
using namespace std;
#include <iomanip>
int partition(int arr[], int l,int u);
void quick_sort(int arr[], int l,int u);

int partition(int arr[], int l,int u)
{
	int pivot=arr[l];
	int i=l;
	int j=u;
	if(i<j)
	{
		while(arr[i]<=pivot)
		{
			++i;
		}
		while(arr[j]>pivot)
		{
			--j;
		}
		if(i<j)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp=arr[l];
	arr[l]=arr[j];
	arr[j]=temp;

	return j;
}
void quick_sort(int arr[], int l,int u)
{

	if(l<u)
	{
		int loc=partition(arr,l,u);
		quick_sort(arr,l,loc);      //not working if used (arr,l,loc-1)
		quick_sort(arr,loc+1,u);
	}
}

int main()
{

	int arr[]={10,16,8,12,15,6,3,9,5};

	int len= sizeof(arr)/sizeof(arr[0]);

   	cout<<"array before sort:"<<endl;
	for(int i=0;i<len;++i)
	{
		cout<<setw(4)<<arr[i];
	}

	quick_sort(arr,0,len-1);
	cout<<endl;
	cout<<"array after sort:"<<endl;
	for(int j=0;j<len;++j)
	{
		cout<<setw(4)<<arr[j];
	}
	return 0;
}

