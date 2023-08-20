#include <iostream>
using namespace std;

// se atentar pois a busca binaria so pode ser feita com um array ordenado


void binarySearch(int array[], int element, int length){
  int low = 0;
  int high = length;
    while (low <= high)
    {
      int mid = (low + high)/2;
      int guess = array[mid];

      if(guess == element){
        cout << "Elemento encontrado na posicao "<<mid<< endl;
        return ;
      }
      /*
      O chute foi  muito alto
      */
      else if (guess > element){
        high = mid - 1;
      }
      /*
      O chute foi muito baixo
      caso nenhuma das outras condições forem satisfeita eu sei que o elemento que estou procurando é mais alto 
      sendo assim atualizo o meu valor menor para o valor do meio + 1
      */
      else{
        low = mid + 1;
      }
    }
    cout<<"Elemento nao encontrado"<< endl;
    return ;
}


int main() {
  int array[] = {2,7,10,23,55,66,71,72,73,80,85,100,107};
  int length = sizeof(array) / sizeof(int);

  binarySearch(array, 2, length) ; 
  binarySearch(array, 72, length) ;
  binarySearch(array, 105, length) ; 

  return 0;
}