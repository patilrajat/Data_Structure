#include <iostream>
using namespace std;
#include <iomanip>
void bubble_sort(int arr[], int l)
{
	int round;
	for (round = 1; round < l; ++round)
	{
		bool flag=false;     //flag is for best case
		for (int i = 0; i < l-round; ++i)
		{
			if(arr[i]>arr[i+1])
			{
				flag=true;
				int temp;
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}

		}
		if(flag==false)
		{
			cout<<endl<<"round:"<<round<<endl;  //it shows how many rounds taken
			return;

		}

	}

}
int main()
{
	int arr[]={50,40,30,20,10};

	int l= sizeof(arr)/sizeof(arr[0]);

	cout<<"array before sort:"<<endl;
	for(int i=0;i<l;++i)
	{
		cout<<setw(4)<<arr[i];
	}
	bubble_sort(arr,l);
	cout<<endl;
	cout<<"array after sort:"<<endl;
	for(int j=0;j<l;++j)
	{
		cout<<setw(4)<<arr[j];
	}
	return 0;
}

