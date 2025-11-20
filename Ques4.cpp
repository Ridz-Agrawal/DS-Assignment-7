#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int n = 8;

    int even[100], odd[100];
    int e = 0, o = 0;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) even[e++] = arr[i];
        else odd[o++] = arr[i];
    }

    sort(even, even + e);            
    sort(odd, odd + o, greater<int>()); 
    for(int i = 0; i < e; i++) cout << even[i] << " ";
    for(int i = 0; i < o; i++) cout << odd[i] << " ";
}
