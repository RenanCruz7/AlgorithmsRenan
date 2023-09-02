#include <iostream>
#include <vector>
using namespace std;

int fat (int num){
    if(num ==1){
        return 1;
    }
    else{
        return num * fat(num - 1);
    }
}

int main() {
  int num = 5;
  cout<< fat(num)<<"";
  return 0;
}