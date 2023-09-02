#include <iostream>
#include <vector>
using namespace std;

template <typename T>

int findSmall(vector<T> arr) {
  // stores smallest value 
  T small = arr[0];
  // stores de index of the smallest value 
  int small_index = 0;

  for(int i = 0; i < arr.size(); i++){
    if(arr[i] < small){
      small = arr[i];
      small_index = i;
    }
  }
  return small_index;
}

template <typename T>
vector<T> selection_sort(vector<T> arr){
  vector<T> sorted;

  while (!arr.empty())
  {
    int smallest_index = findSmall(arr);
    sorted.push_back(arr[smallest_index]);


    arr.erase(arr.begin()+smallest_index);
  }
  return sorted;
}

int main() {
  vector<int> arr = {1,5,22,2,4,78,100,700,500,200,55};
  vector<int> sorted = selection_sort(arr);

  cout <<"Sorted array: ";

  for(int i = 0 ; i < sorted.size();i++){
    cout<<sorted[i]<<" ";
  }
  return 0;
}