#include<iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot && n == 1) {
            i++;
            swap(arr[i], arr[j]);
        }
        if (arr[j] > pivot && n == 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);
        quicksort(arr, low, pi - 1, n);
        quicksort(arr, pi + 1, high, n);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Chọn tăng nhập 0, chọn giảm nhập 1: ";
    int x;
    cin >> x;
    cout << endl;
    quicksort(arr, 0, n - 1, x);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
