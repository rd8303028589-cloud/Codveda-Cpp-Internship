#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Display Array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, choice, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n1. Bubble Sort";
    cout << "\n2. Quick Sort";
    cout << "\n3. Linear Search";
    cout << "\n4. Binary Search";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            cout << "Sorted Array (Bubble Sort): ";
            display(arr, n);
            break;

        case 2:
            quickSort(arr, 0, n - 1);
            cout << "Sorted Array (Quick Sort): ";
            display(arr, n);
            break;

        case 3:
            cout << "Enter element to search: ";
            cin >> key;
            if (linearSearch(arr, n, key) != -1)
                cout << "Element Found.";
            else
                cout << "Element Not Found.";
            break;

        case 4:
            quickSort(arr, 0, n - 1); // Binary Search requires sorted array
            cout << "Enter element to search: ";
            cin >> key;
            if (binarySearch(arr, n, key) != -1)
                cout << "Element Found.";
            else
                cout << "Element Not Found.";
            break;

        default:
            cout << "Invalid Choice!";
    }

    return 0;
}