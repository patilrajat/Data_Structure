#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#include <iomanip>
int makinganagram(string a,string b)
{
	int count1[26]={0},count2[26]={0};
	for(int i=0;a[i]!='\0';i++)
		count1[a[i]-'a']++;
	for(int i=0;b[i]!='\0';i++)
			count2[b[i]-'a']++;
	int result=0;
	for(int i=0;i<26;i++)
		result += abs(count1[i]-count2[i]);
	return result;
}
int main()
{
	string a="rajat";
	string b="rajatp";
    	cout<<makinganagram(a,b);
	return 0;
}
