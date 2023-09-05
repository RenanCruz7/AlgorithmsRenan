#include <iostream>

using namespace std;

void regressive(int num){
    cout<<num<<" ";
    if(num <= 0){
        return ;
    }else{
        regressive(num - 1);
    }

}


int main() {
  int num = 50;
  regressive(num);
  return 0;
}