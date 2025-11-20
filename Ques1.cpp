#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++){
        int minIdx = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++){
        bool swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break; 
    }
}

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int a[n1], b[n2];

    for(int i = 0; i < n1; i++) a[i] = arr[l + i];
    for(int j = 0; j < n2; j++) b[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(a[i] <= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    while(i < n1) arr[k++] = a[i++];
    while(j < n2) arr[k++] = b[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int partitionArr(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partitionArr(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 9};
    int n = 6;

    cout << "Original Array: ";
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
