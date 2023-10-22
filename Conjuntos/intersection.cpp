#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

int main(){
    std::set<int> conjunto1 = {1,2,3,4,5};
    std::set<int> conjunto2 = {3,4,5,6,7};

    std::set<int> intersecao;

    set_intersection(conjunto1.begin(),conjunto1.end(),conjunto2.begin(),conjunto2.end(),inserter(intersecao,intersecao.begin()));

    for (int elemento : intersecao) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;


}