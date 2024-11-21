#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int insertionSort(vector<int>& arr) {
    int moves = 0;
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            moves++;
        }
        arr[j + 1] = key;
        moves++;
    }
    return moves;
}

int selectionSort(vector<int>& arr) {
    int moves = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            moves += 2; 
        }
    }
    return moves;
}

int bubbleSort(vector<int>& arr) {
    int moves = 0;
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                moves += 2; 
            }
        }
    }
    return moves;
}

int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, moves = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
        moves++;
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
        moves++;
    }

    while (j <= right) {
        temp[k++] = arr[j++];
        moves++;
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return moves;
}

int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    int moves = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        moves += mergeSortAndCount(arr, temp, left, mid);
        moves += mergeSortAndCount(arr, temp, mid + 1, right);
        moves += mergeAndCount(arr, temp, left, mid, right);
    }
    return moves;
}

int mergeSort(vector<int>& arr) {
    vector<int> temp(arr.size());
    return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
}

void displayChart(const vector<pair<string, int>>& results) {
    cout << "\nNumber of Moves for Each Algorithm:\n";
    cout << endl ;
    for (const auto& result : results) {
        cout << left << setw(15) << result.first << ": ";
        int moves = result.second;
        
        cout << moves << " moves" << endl;
    }
}

int main() {
    vector<int> data = {6, 1, 13, 7, 11, 9, 2, 8, 15, 5, 3, 4, 12, 10, 14};
    vector<pair<string, int>> movementCounts;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Bubble Sort\n";
        cout << "5. Show Chart and Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cout << endl;

        if (choice == 5) {
            displayChart(movementCounts);
            break;
        }

        vector<int> tempData = data;
        int moves = 0;

        switch (choice) {
            case 1:
                moves = insertionSort(tempData);
                movementCounts.push_back({"Insertion Sort", moves});
                break;
            case 2:
                moves = selectionSort(tempData);
                movementCounts.push_back({"Selection Sort", moves});
                break;
            case 3:
                moves = mergeSort(tempData);
                movementCounts.push_back({"Merge Sort", moves});
                break;
            case 4:
                moves = bubbleSort(tempData);
                movementCounts.push_back({"Bubble Sort", moves});
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                continue;
        }

        cout << "Sorted Data: ";
        for (int num : tempData) {
            cout << num << " ";
        }
        cout << "\nTotal Moves: " << moves << endl;
    }

    return 0;
}
