#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int interpolationSearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target)
                return left;
            return -1;
        }

        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1;
}

void printSearchResult(int result, const std::string& algorithm) {
    if (result != -1)
        std::cout << "Element found at index " << result << " using " << algorithm << " search.\n";
    else
        std::cout << "Element not found using " << algorithm << " search.\n";
}

int main() {
    std::vector<int> arr = {10, 20, 30, 40, 50, 60, 70};

    std::cout << "Array: ";
    for (int value : arr)
        std::cout << value << " ";
    std::cout << "\n";

    int target = 50;

    // Linear Search
    int linearResult = linearSearch(arr, target);
    printSearchResult(linearResult, "Linear");

    // Binary Search (Array must be sorted)
    std::sort(arr.begin(), arr.end());
    int binaryResult = binarySearch(arr, target);
    printSearchResult(binaryResult, "Binary");

    // Interpolation Search (Array must be sorted)
    int interpolationResult = interpolationSearch(arr, target);
    printSearchResult(interpolationResult, "Interpolation");

    return 0;
}
