
#include <iostream>
using namespace std;
#include <iomanip>
void merge_sort(int arr[], int l,int u);
void merge(int arr[], int l,int mid,int u);

void merge(int arr[],int l,int mid,int u)
{
	int i=l;
	int j=mid+1;
	int k=l;
	int temp[u+1];      //temperary array is necessary
	while(i<=mid && j<=u)
	{
	if(arr[i]<=arr[j])
		temp[k++]=arr[i++];
	else
		temp[k++]=arr[j++];
	}
	if(j>u)
	while(i<=mid)
		temp[k++]=arr[i++];
	else
	while(j<=u)
		temp[k++]=arr[j++];
	for(int a=l;a<=u;a++)   //chance of mistake don't start from 0
		arr[a]=temp[a];

}
void merge_sort(int arr[], int l,int u)
{

	if(l<u)
	{
		int mid=(l+u)/2;
		merge_sort(arr,l,mid);
		merge_sort(arr,mid+1,u);
		merge(arr,l,mid,u);
	}
}

int main()
{

	int arr[]={10,16,8,12,15,3,9,5};

	int len= sizeof(arr)/sizeof(arr[0]);

   	cout<<"array before sort:"<<endl;
	for(int i=0;i<len;++i)
	{
		cout<<setw(4)<<arr[i];
	}

	merge_sort(arr,0,len-1);
	cout<<endl;
	cout<<"array after sort:"<<endl;
	for(int j=0;j<len;++j)
	{
		cout<<setw(4)<<arr[j];
	}
	return 0;
}
