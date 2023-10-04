#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> left_arr(n1);
    std::vector<int> right_arr(n2);

    for (int i = 0; i < n1; ++i)
        left_arr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        right_arr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            ++i;
        } else {
            arr[k] = right_arr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = left_arr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void radixSort(std::vector<int>& arr) {
    int max = *std::max_element(arr.begin(), arr.end());

    for (int exp = 1; max / exp > 0; exp *= 10) {
        std::vector<int> output(arr.size());
        std::vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); ++i)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; ++i)
            count[i] += count[i - 1];

        for (int i = arr.size() - 1; i >= 0; --i) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); ++i)
            arr[i] = output[i];
    }
}

void printArray(const std::vector<int>& arr) {
    for (int value : arr)
        std::cout << value << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original array: ";
    printArray(arr);

    // Bubble Sort
    bubbleSort(arr);
    std::cout << "Array after Bubble Sort: ";
    printArray(arr);

    // Selection Sort
    selectionSort(arr);
    std::cout << "Array after Selection Sort: ";
    printArray(arr);

    // Insertion Sort
    insertionSort(arr);
    std::cout << "Array after Insertion Sort: ";
    printArray(arr);

    // Merge Sort
    mergeSort(arr, 0, arr.size() - 1);
    std::cout << "Array after Merge Sort: ";
    printArray(arr);

    // Quick Sort
    quickSort(arr, 0, arr.size() - 1);
    std::cout << "Array after Quick Sort: ";
    printArray(arr);

    // Radix Sort
    radixSort(arr);
    std::cout << "Array after Radix Sort: ";
    printArray(arr);

    return 0;
}
