/*
Project Title : Sorting Algorithm Visualizer
Course        : Discrete Mathematics
Authors       : Awais Afzal & Mohid Sadiq
*/

#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace chrono;

int GLOBAL_SIZE;

// Manual swap (no algorithm library)
void swapValues(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Print full array
void printArray(int arr[])
{
    for (int i = 0; i < GLOBAL_SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Bubble Sort
void bubbleSort(int arr[])
{
    for (int i = 0; i < GLOBAL_SIZE - 1; i++)
        for (int j = 0; j < GLOBAL_SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swapValues(arr[j], arr[j + 1]);
            printArray(arr);
        }
}

// Selection Sort
void selectionSort(int arr[])
{
    for (int i = 0; i < GLOBAL_SIZE - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < GLOBAL_SIZE; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swapValues(arr[i], arr[minIndex]);
        printArray(arr);
    }
}

// Insertion Sort
void insertionSort(int arr[])
{
    for (int i = 1; i < GLOBAL_SIZE; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printArray(arr);
    }
}

// Merge function
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[1000], R[1000];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
        printArray(arr);
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Partition for Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
            swapValues(arr[++i], arr[j]);
        printArray(arr);
    }

    swapValues(arr[i + 1], arr[high]);
    printArray(arr);
    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Random data generation
void generateRandomData(int arr[])
{
    for (int i = 0; i < GLOBAL_SIZE; i++)
        arr[i] = rand() % 100;
}

// Main
int main()
{
    cout << "Sorting Algorithm Visualizer\n";
    cout << "Enter dataset size (max 1000): ";
    cin >> GLOBAL_SIZE;

    if (GLOBAL_SIZE <= 0 || GLOBAL_SIZE > 1000)
    {
        cout << "Invalid size.\n";
        return 0;
    }

    int data[1000];
    generateRandomData(data);

    cout << "\nOriginal Array:\n";
    printArray(data);

    cout << "\nSelect Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n";
    cout << "4. Merge Sort\n5. Quick Sort\n";
    cout << "Enter choice : ";
    int choice;
    cin >> choice;

    int temp[1000];
    for (int i = 0; i < GLOBAL_SIZE; i++)
        temp[i] = data[i];

    auto start = high_resolution_clock::now();

    switch (choice)
    {
        case 1: bubbleSort(temp); break;
        case 2: selectionSort(temp); break;
        case 3: insertionSort(temp); break;
        case 4: mergeSort(temp, 0, GLOBAL_SIZE - 1); break;
        case 5: quickSort(temp, 0, GLOBAL_SIZE - 1); break;
        default:
            cout << "Invalid choice.\n";
            return 0;
    }

    auto end = high_resolution_clock::now();
    cout << "\nExecution Time: "
         << duration_cast<nanoseconds>(end - start).count()
         << " ns\n";

    cout << "\nSorted Array:\n";
    printArray(temp);

    return 0;
}
