/*     -----------------QUESTION------------------
--> if given array is [5,2,3,4,1] , arrange in ascending [1,2,3,4,5] 
    find all pairs who have minimum difference,          
    here minimum diff is 1: {(1,2),(2,3),(3,4),(4,5)}
    there for print 1,2,2,3,3,4,4,5
--> Sample Input 1
    12    // number of input
    -20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854 -520 -470 
    Sample Output 1
    -520 -470 -20 30    // all have minimum diff 50
    Explanation 1
    (-470) - (-520) = 30 - (-20) = 50, which is the smallest difference.    
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void closestnumbers(vector<int> arr) {
    int l=arr.size();
    int diff[l];
    sort(arr.begin(), arr.end());
    int min = arr[1]-arr[0];
    for(int i=1; i < arr.size(); i++) {
        diff[i] = arr[i]- arr[i-1];
        if(min > diff[i])
             min = diff[i];
    }
    for(int i=1; i < arr.size(); i++) {
        if(diff[i] == min)
           cout << arr[i-1] << " " << arr[i] << " ";
    }
}

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }
    closestnumbers(arr);
    return 0;
}
