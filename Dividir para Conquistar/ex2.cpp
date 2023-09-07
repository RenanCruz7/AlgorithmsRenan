#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T sum(vector<T>arr){
    if(arr.empty()) return 0;

    T num = arr.back();
    arr.pop_back();
    return num + sum(arr);
}

int main() {
  vector<int> arr = {1,2,3,4,5};
  cout<< sum(arr) << endl;
  return 0;
}