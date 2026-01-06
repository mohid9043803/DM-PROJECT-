Project Title :            Sort Master ---- Visual Analyzer of Sorting Algorithms

Description:

The provided C++ program implements a Sorting Algorithm Visualizer that demonstrates the working of multiple sorting algorithms while measuring their execution time. The program begins by generating a random dataset based on user-defined size constraints. A menu-driven interface allows the user to select one of five sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, or Quick Sort.

Each sorting algorithm is implemented as a separate function and is designed to display the array after each significant step, such as comparisons, swaps, or merges. This step-by-step output serves as a textual visualization, helping users understand how the algorithms progressively transform the unsorted array into a sorted one.

For performance analysis, the program uses the C++ chrono library to measure execution time with nanosecond precision. This enables a practical comparison of algorithm efficiency under the same dataset conditions. Recursive techniques are used for Merge Sort and Quick Sort, demonstrating divide-and-conquer strategies, while the remaining algorithms use iterative approaches.

Overall, the code is modular, well-structured, and educational in nature. It combines algorithmic logic, discrete mathematics concepts, and performance measurement into a single application aimed at improving conceptual understanding of sorting algorithms.

Installation Instructions:


Follow the steps below to compile and run the Sorting Algorithm Visualizer on your system:

1) Install a C++ Compiler

Ensure that a C++ compiler supporting modern C++ standards is installed.

Recommended: GCC (g++), Clang, or MSVC

Verify installation by running:
g++ --version

2) Set Up the Development Environment
You may use any IDE or editor, such as:

Code::Blocks

Dev-C++

Visual Studio

Visual Studio Code

3) Download the Source Code

Clone the GitHub repository or download the .cpp file directly.

git clone <https://github.com/mohid9043803/DM-PROJECT->

4) Compile the Program

Navigate to the project directory and compile using:

g++ code.cpp -o code

6) Run the Program
   
Execute the compiled file:

./code

7) Input Requirements

Enter a dataset size between 1 and 1000 when prompted.
Select a sorting algorithm from the menu to begin visualization.
Once compiled and executed, the program will display step-by-step sorting behavior along with execution time, confirming successful installation.

Usage Examples:

Below are example scenarios demonstrating how to use the Sorting Algorithm Visualizer after successful installation.

Example 1: Visualizing Bubble Sort



User Interface:


============================================================
        SORTING ALGORITHM VISUALIZER
============================================================
Course  : Discrete Mathematics
Authors : Awais Afzal & Mohid Sadiq
------------------------------------------------------------
Algorithms Implemented:
 - Bubble Sort
 - Selection Sort
 - Insertion Sort
 - Merge Sort
 - Quick Sort
------------------------------------------------------------
Features:
 * Step-by-step visualization
 * Execution time in nanoseconds
 * Random dataset generation
============================================================
Press ENTER to continue...


Enter dataset size (max 1000): 8

Original (Unsorted) List:
41 67 34 0 69 24 78 58 

Choose Sorting Algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
Enter choice : 1

Program Output :

Bubble Sort Visualization:
41 67 34 0 69 24 78 58
41 34 67 0 69 24 78 58 
41 34 0 67 69 24 78 58
41 34 0 67 69 24 78 58
41 34 0 67 24 69 78 58
41 34 0 67 24 69 78 58 
41 34 0 67 24 69 58 78
34 41 0 67 24 69 58 78
34 0 41 67 24 69 58 78
34 0 41 67 24 69 58 78
34 0 41 24 67 69 58 78 
34 0 41 24 67 69 58 78
34 0 41 24 67 58 69 78
0 34 41 24 67 58 69 78
0 34 41 24 67 58 69 78
0 34 24 41 67 58 69 78
0 34 24 41 67 58 69 78 
0 34 24 41 58 67 69 78
0 34 24 41 58 67 69 78
0 24 34 41 58 67 69 78
0 24 34 41 58 67 69 78
0 24 34 41 58 67 69 78
0 24 34 41 58 67 69 78 
0 24 34 41 58 67 69 78
0 24 34 41 58 67 69 78
0 24 34 41 58 67 69 78
0 24 34 41 58 67 69 78
0 24 34 41 58 67 69 78 

Sorted List:
0 24 34 41 58 67 69 78

Execution Time: 92745000 ns
Sorting Completed Successfully!

Example 2: Using Merge Sort for Efficient Sorting

User Input:

Press ENTER to continue...

Enter dataset size (max 1000): 8


Select Sorting Algorithm: 4


Program Output :

41 67
41 67
41 67 0 0
41 67 0 34
0 67 0 34
0 34 0 34
0 34 41 34
0 34 41 67
0 34 41 67 24 24
0 34 41 67 24 69
0 34 41 67 24 69 58 58
0 34 41 67 24 69 58 78 
0 34 41 67 24 69 58 78
0 34 41 67 24 58 58 78
0 34 41 67 24 58 69 78
0 34 41 67 24 58 69 78 
0 34 41 67 24 58 69 78
0 24 41 67 24 58 69 78 
0 24 34 67 24 58 69 78
0 24 34 41 24 58 69 78 
0 24 34 41 58 58 69 78
0 24 34 41 58 67 69 78
0 24 34 41 58 67 69 78
0 24 34 41 58 67 69 78

Sorted List:
0 24 34 41 58 67 69 78 

Execution Time: 125174000 ns
Sorting Completed Successfully!

Example 3: Invalid Input Handling

User Input:

Enter dataset size (max 1000): 1500


Program Output:

Invalid size. 

Dependencies:

The Sorting Algorithm Visualizer has minimal dependencies and relies primarily on standard C++ libraries. This ensures portability and ease of compilation across different platforms.

1) C++ Compiler : g++

2) Standard C++ Libraries
   
The project uses the following built-in C++ libraries:

                      <iostream> for input and output operations

                       <cstdlib> for random number generation using rand()

                       <chrono>  for high-resolution execution time measurement

                       <fstream> 	Used for file handling; in particular to generate input and output files as code is executed.

3) Operating System

Compatible with Windows, Linux, and macOS

4) Development Environment (Optional):

IDE "VS Code" is used for easier compilation and debugging

This lightweight dependency setup makes the project easy to install, compile, and run on any standard system with a C++ compiler.




