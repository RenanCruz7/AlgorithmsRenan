#include <iostream>
#include <set>


int main(){
   std:: set<int> conjunto;

    conjunto.insert(10);
    conjunto.insert(5);
    conjunto.insert(15);
    conjunto.insert(1);
    conjunto.insert(3);
    conjunto.insert(50);
    conjunto.insert(10);

    for(int elemento: conjunto){
        std:: cout << elemento<< " ";
    }

}