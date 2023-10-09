#include <iostream>
#include <unordered_map> 

using namespace std;

int main() {

    unordered_map<string,int> umap ={
        {"Renankton",7},
        {"Mimije",10},
        {"Samuel",5}
    };

    unordered_map<string,int> map;

    //inserindo valores usando o []
    map["Renankton"] = 7;
    map["Mimije"] = 10;
    map["Samuel"] = 5;

    for (auto x:map){
        cout << x.first << ": "<< x.second << endl;
    }
    cout << "------" << endl;
    for (auto x:umap){
        cout << x.first << ": "<< x.second << endl;
    }
}