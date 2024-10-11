# Dynamic Array

Welcome to the **Dynamic Array** project! This repository contains a C implementation of a dynamic array that allows for flexible manipulation of integer elements. The dynamic array automatically resizes itself as elements are added or removed, providing a robust solution for handling collections of integers.

## Features

- **Dynamic Resizing**: Automatically adjusts size based on the number of elements.
- **Element Manipulation**: Functions to add, remove, and access elements.
- **Searching and Counting**: Easily find elements and count occurrences.
- **Reversing and Sorting**: Reverse the order of elements and sort them.
- **Memory Management**: Efficiently manages memory allocation and deallocation.

## Getting Started

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/RamazanovTs/DynamicArray.git
   cd DynamicArray
   ```

2. Compile the code:
   ```bash
   gcc -o dynamic_array dynamic_array.c
   ```

3. Run the executable:
   ```bash
   ./dynamic_array
   ```

## Functions Overview

Here’s a brief overview of the key functions available:

| Function               | Description                                                  |
|------------------------|--------------------------------------------------------------|
| `CreateArray()`        | Initializes a new dynamic array.                            |
| `freeArray()`          | Frees memory allocated for the dynamic array.              |
| `expandArray()`        | Doubles the capacity of the array when needed.              |
| `shrinkArray()`        | Halves the capacity of the array if the size is much smaller.|
| `addElement()`         | Adds a new element to the array.                            |
| `removeElement()`      | Removes an element at the specified index.                 |
| `getElement()`         | Retrieves an element by index.                              |
| `setElement()`         | Sets an element at the specified index.                     |
| `findElement()`        | Finds the index of a specific element.                      |
| `printArray()`         | Displays the contents of the array.                         |
| `countElement()`       | Counts occurrences of a specific element.                   |
| `getSize()`            | Returns the current number of elements in the array.       |
| `getCapacity()`        | Returns the current capacity of the array.                  |
| `copyArray()`          | Copies data from one array to another.                      |
| `reverseArray()`       | Reverses the order of elements in the array.               |
| `sortArray()`          | Sorts the elements in ascending order.                      |

---

Thank you for checking out the **Dynamic Array** project! If you have any questions or feedback, feel free to reach out.
