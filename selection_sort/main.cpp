#include <iostream>
using namespace std;
#include <iomanip>
void selection_sort(int arr[], int l)
{
	for (int i = 0; i < l-1; ++i)
	{
		for (int j = i+1; j < l; ++j)
		{
			if(arr[j]<arr[i])
			{
				int temp;
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}

	}

}
int main()
{
	int arr[]={20,50,40,30,10};

	int l= sizeof(arr)/sizeof(arr[0]);

	cout<<"array before sort:"<<endl;
	for(int i=0;i<l;++i)
	{
		cout<<setw(4)<<arr[i];
	}
	selection_sort(arr,l);
	cout<<endl;
	cout<<"array after sort:"<<endl;
	for(int j=0;j<l;++j)
	{
		cout<<setw(4)<<arr[j];
	}
	return 0;
}

