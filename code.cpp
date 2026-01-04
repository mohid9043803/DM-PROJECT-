/*
Project Title : Sort Master ---- Visual Analyzer of Sorting Algorithms
Course        : Discrete Mathematics
Authors       : Awais Afzal & Mohid Sadiq
*/

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>   // For file handling

using namespace std;
using namespace chrono;

/* ========== ANSI COLORS ========== */
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

/* ================= OPENING PAGE ================= */
void openingPage() {
    cout << CYAN << BOLD;
    cout << "============================================================\n";
    cout << "        SORTING ALGORITHM VISUALIZER\n";
    cout << "============================================================\n";
    cout << GREEN;
    cout << "Course  : Discrete Mathematics\n";
    cout << "Authors : Awais Afzal & Mohid Sadiq\n";
    cout << CYAN;
    cout << "------------------------------------------------------------\n";
    cout << YELLOW;
    cout << "Algorithms Implemented:\n";
    cout << " - Bubble Sort\n";
    cout << " - Selection Sort\n";
    cout << " - Insertion Sort\n";
    cout << " - Merge Sort\n";
    cout << " - Quick Sort\n";
    cout << CYAN;
    cout << "------------------------------------------------------------\n";
    cout << GREEN;
    cout << "Features:\n";
    cout << " * Step-by-step visualization\n";
    cout << " * Execution time in nanoseconds\n";
    cout << " * Random dataset generation\n";
    cout << CYAN;
    cout << "============================================================\n";
    cout << RED << "Press ENTER to continue..." << RESET << endl;

    cin.ignore();
    cin.get();
}

/* ================= SORTING LOGIC ================= */

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int arr[], int size) {
    cout << CYAN << "\nBubble Sort Visualization:\n" << RESET;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
            printArray(arr, size);
        }
}

void selectionSort(int arr[], int size) {
    cout << CYAN << "\nSelection Sort Visualization:\n" << RESET;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
        printArray(arr, size);
    }
}

void insertionSort(int arr[], int size) {
    cout << CYAN << "\nInsertion Sort Visualization:\n" << RESET;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            printArray(arr, size);
        }
        arr[j + 1] = key;
        printArray(arr, size);
    }
}

void merge(int arr[], int l, int m, int r) {
    int L[1000], R[1000];
    int n1 = m - l + 1, n2 = r - m;

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        printArray(arr, r + 1);
    }
    while (i < n1) {
        arr[k++] = L[i++];
        printArray(arr, r + 1);
    }
    while (j < n2) {
        arr[k++] = R[j++];
        printArray(arr, r + 1);
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
        printArray(arr, high + 1);
    }
    swap(arr[i + 1], arr[high]);
    printArray(arr, high + 1);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomData(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}

/* ================= MAIN ================= */

int main() {
    openingPage();

    int size;
    cout << YELLOW << "Enter dataset size (max 1000): " << RESET;
    cin >> size;

    if (size <= 0 || size > 1000) {
        cout << RED << "Invalid size.\n" << RESET;
        return 0;
    }

    int data[1000];
    generateRandomData(data, size);

    // Write input file
    ofstream inputFile("input.txt");
    inputFile << size << "\n";
    for (int i = 0; i < size; i++)
        inputFile << data[i] << " ";
    inputFile.close();

    // Print original list
    cout << CYAN << "\nOriginal (Unsorted) List:\n" << RESET;
    printArray(data, size);

    // Menu
    cout << CYAN << "\nChoose Sorting Algorithm:\n" << RESET;
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "Enter choice : ";

    int choice;
    cin >> choice;

    auto start = high_resolution_clock::now();

    switch (choice) {
        case 1: bubbleSort(data, size); break;
        case 2: selectionSort(data, size); break;
        case 3: insertionSort(data, size); break;
        case 4: mergeSort(data, 0, size - 1); break;
        case 5: quickSort(data, 0, size - 1); break;
        default:
            cout << RED << "Invalid choice.\n" << RESET;
            return 0;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);

    // Print final sorted list
    cout << GREEN << "\nSorted List:\n" << RESET;
    printArray(data, size);

    // Write output file
    ofstream outputFile("output.txt");
    outputFile << size << "\n";
    for (int i = 0; i < size; i++)
        outputFile << data[i] << " ";
    outputFile.close();

    cout << GREEN << "\nExecution Time: " << duration.count() << " ns\n";
    cout << "Sorting Completed Successfully!\n" << RESET;

    return 0;
}

