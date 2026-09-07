/*
   ASSIGNMENT 4: RECURSIVE PROGRAMS

   This program implements four recursive algorithms:
   (a) Binary Search - searches an element in a sorted array by repeatedly
       dividing the search range into half.
   (b) Merge Sort - recursively divides the array into two halves, sorts them,
       and merges the sorted halves.
   (c) Sum of First N Factorials - calculates 1! + 2! + ... + N! recursively.
   (d) Sum of First N Fibonacci Numbers - calculates F1 + F2 + ... + FN using
       plain recursive Fibonacci with two recursive calls.

   The assignment also requires mathematical analysis of each algorithm,
   including its recurrence relation, recursive calls, work outside recursion,
   applicability of the Master Theorem, and theoretical time complexity.
*/

#include <iostream>
using namespace std;


// (a) Binary Search

int binarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    return binarySearch(arr, mid + 1, high, key);
}


// (b) Merge Sort

void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

// (c) Sum of First N Factorials

long long factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

long long sumFactorials(int n)
{
    if (n <= 1)
        return 1;

    return factorial(n) + sumFactorials(n - 1);
}


// (d) Sum of First N Fibonacci Numbers

long long fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long sumFibonacci(int n)
{
    if (n <= 0)
        return 0;

    return fibonacci(n) + sumFibonacci(n - 1);
}


// Display Array

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}


// Main Function

int main()
{
    // (a) Binary Search

    int n1, key;
    int arr1[100];

    cout << "========== (a) Binary Search ==========" << endl;

    cout << "Enter number of elements: ";
    cin >> n1;

    cout << "Enter " << n1 << " elements in sorted order: ";
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr1, 0, n1 - 1, key);

    cout << "Array: ";
    displayArray(arr1, n1);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;


    // (b) Merge Sort

    int n2;
    int arr2[100];

    cout << endl;
    cout << "========== (b) Merge Sort ==========" << endl;

    cout << "Enter number of elements: ";
    cin >> n2;

    cout << "Enter " << n2 << " elements: ";
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    cout << "Before sorting: ";
    displayArray(arr2, n2);

    mergeSort(arr2, 0, n2 - 1);

    cout << "After sorting: ";
    displayArray(arr2, n2);


    // (c) Sum of First N Factorials

    int N1;

    cout << endl;
    cout << "========== (c) Sum of First N Factorials ==========" << endl;

    cout << "Enter N: ";
    cin >> N1;

    cout << "Sum of first " << N1 << " factorials = "
         << sumFactorials(N1) << endl;


    // (d) Sum of First N Fibonacci Numbers

    int N2;

    cout << endl;
    cout << "========== (d) Sum of First N Fibonacci Numbers ==========" << endl;

    cout << "Enter N: ";
    cin >> N2;

    cout << "Sum of first " << N2 << " Fibonacci numbers = "
         << sumFibonacci(N2) << endl;


    return 0;
}
