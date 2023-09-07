#include <iostream>
#include <vector>
using namespace std;

void sum(vector<int>arr){
    int num = 0;
    for(int i = 0; i <arr.size(); i++){
        num += arr[i];
    }
    cout <<num<<' ';
}


int main() {
  vector<int> arr = {1,2,3,4,5};
  sum(arr);
  return 0;
}