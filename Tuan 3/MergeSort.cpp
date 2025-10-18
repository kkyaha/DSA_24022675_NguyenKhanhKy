#include <iostream>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void mergeParts(int *arr, int l, int mid, int r) {
    int temp_size = r - l + 1;
    int *temp = new int[temp_size]; 

    int i = l, j = mid + 1;
    int k = 0;

    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (int idx = 0; idx < temp_size; idx++) {
        arr[l + idx] = temp[idx];
    }
    
    delete[] temp; 

}

// Hàm mergeSort không đổi
void mergeSort(int *arr, int l, int r) {
    if (l >= r) return;

    int mid = l + (r - l) / 2; 
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    mergeParts(arr, l, mid, r);
}

// Hàm main không đổi
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Mang ban dau: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    std::cout << "Mang sau khi sap xep (Merge Sort): ";
    printArray(arr, n);
    return 0;
}