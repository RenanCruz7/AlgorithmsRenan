#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<T> quick_sort(vector<T> arr) {
    if (arr.size() < 2) {
        return arr;
    } else {
        T pivo = arr.back();
        vector<T> smallest;
        vector<T> highest;
        
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] <= pivo) {
                smallest.push_back(arr[i]);
            } else {
                highest.push_back(arr[i]);
            }
        }

        vector<T> sorted_less = quick_sort(smallest);
        vector<T> sorted_greater = quick_sort(highest);

        sorted_less.push_back(pivo);
        sorted_less.insert(sorted_less.end(), sorted_greater.begin(), sorted_greater.end());

        return sorted_less;
    }
}

int main() {
    vector<int> arr = {69, 60, 38, 82, 99, 15, 8, 94, 30, 42, 35, 40, 63, 1, 49, 66, 93, 83, 20, 32, 87, 6, 78, 17, 2, 61, 91, 25, 7, 4, 97, 31, 23, 67, 95, 47, 55, 92, 37, 59, 73, 81, 74, 41, 39};
    vector<int> sorted = quick_sort(arr);

    cout << "Sorted array: ";

    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }
    return 0;
}
