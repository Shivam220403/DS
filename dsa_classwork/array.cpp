#include <iostream>
using namespace std;

// Function to insert an element at a specified position
void insertElement(int arr[], int& size, int capacity, int element, int position) {
    if (size >= capacity) {
        cout << "Array is full. Cannot insert element." << endl;
        return;
    }

    if (position < 0 || position > size) {
        cout << "Invalid position. Please enter a position between 0 and " << size << "." << endl;
        return;
    }

    // Shift elements to the right to create space for the new element
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element at the specified position
    arr[position] = element;
    size++;

    cout << "Element inserted successfully." << endl;
}

// Function to delete an element at a specified position
void deleteElement(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position. Please enter a position between 0 and " << size - 1 << "." << endl;
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    cout << "Element deleted successfully." << endl;
}

// Function to display the array
void displayArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function to test the insertion and deletion functions
int main() {
    int capacity = 10; // Maximum size of the array
    int arr[capacity] = {10, 20, 30, 40, 50}; // Initial array
    int size = 5; // Current size of the array

    displayArray(arr, size);

    // Insert an element
    int element = 25;
    int position = 2; // Insert at index 2
    insertElement(arr, size, capacity, element, position);
    displayArray(arr, size);

    // Delete an element
    position = 4; // Delete the element at index 4
    deleteElement(arr, size, position);
    displayArray(arr, size);

    return 0;
}
