#include <iostream>
using namespace std;
#include <iomanip>
void insertion_sort(int arr[], int l)
{
	int temp,i,j;
	for (i = 1; i < l; ++i)
	{
		temp=arr[i];
		j=i-1;
		while( j >= 0 && temp < arr[j] )     //don't use for loop here
		{
            arr[j+1]=arr[j];
            j--;
		}
		arr[j+1]=temp;
	}

}
int main()
{
	int arr[]={20,30,40,10,50};

	int l= sizeof(arr)/sizeof(arr[0]);

	cout<<"array before sort:"<<endl;
	for(int i=0;i<l;++i)
	{
		cout<<setw(4)<<arr[i];
	}
	insertion_sort(arr,l);
	cout<<endl;
	cout<<"array after sort:"<<endl;
	for(int j=0;j<l;++j)
	{
		cout<<setw(4)<<arr[j];
	}
	return 0;
}
