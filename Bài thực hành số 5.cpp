
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int random_pivot(int arr[], int left, int right) {
    int pivot_index = left + rand() % (right - left + 1);
    int pivot_value = arr[pivot_index];
    swap(arr[pivot_index], arr[right]);
    return pivot_value;
}

int partition(int arr[], int left, int right, int n) {
    int pivot_value = random_pivot(arr, left, right);
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot_value && n == 1) {
            i++;
            swap(arr[i], arr[j]);
        }
        if (arr[j] > pivot_value && n == 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quicksort(int arr[], int left, int right, int n) {
    if (left < right) {
        int pivot = partition(arr, left, right, n);
        quicksort(arr, left, pivot - 1, n);
        quicksort(arr, pivot + 1, right, n);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int vtd, vtc;
    cout << "Vị trí đầu: ";
    cin >> vtd;
    cout << endl << "Vị trí cuối: ";
    cin >> vtc;
    cout << endl << "Chọn tăng nhập 0, chọn giảm nhập 1: ";
    int x;
    cin >> x;
    cout << endl;
    quicksort(arr, vtd - 1, vtc - 1, x);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
