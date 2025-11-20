#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while(left < right) {
        int minIdx = left;
        int maxIdx = right;

        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[minIdx])
                minIdx = i;
            if(arr[i] > arr[maxIdx])
                maxIdx = i;
        }

        swap(arr[left], arr[minIdx]);
        if(maxIdx == left)
            maxIdx = minIdx;
        swap(arr[right], arr[maxIdx]);

        left++;
        right--;
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = 6;

    improvedSelectionSort(arr, n);

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
