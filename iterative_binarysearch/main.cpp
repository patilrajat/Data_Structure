#include <iostream>
using namespace std;
#include <iomanip>
int iterative_binarySearch(int arr[], int l, int r, int x)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(arr[mid]==x)
			return mid;

		if(arr[mid]<x)
			l=mid+1;
		else
			r=mid-1;
	}
	return -1;
}
int main()
{
	int arr[]={10,20,30,40,50};
	int length= sizeof(arr)/sizeof(arr[0]);
	int x,res;
	cout<<"enter number to search"<<endl;
	cin>>x;
	res=iterative_binarySearch(arr, 0,length-1, x);
(res==-1) ? cout<<"element not found"
            :cout<<"element found at index :"<<res;
	return 0;
}

