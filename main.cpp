#include <iostream>

using namespace std;

int * decimal_binario(int decimal, int & tam);

int main(){
    int decimal, tam;
    cout << "Digite o decimal que deseja converter: " << endl;
    cin >> decimal;

    int *bin = decimal_binario(decimal, tam);

    for(int i = 0; i < tam; i++){//imprime vetor
        cout << bin[i];
    }
    return 0;
}

 int* decimal_binario(int decimal, int & tam){
    int aux, decimal_aux, *bin;
    tam = 0;

    decimal_aux = decimal;

    while(decimal_aux){//converte para binario apenas contando a quantidade de bits
        aux = decimal_aux % 2;
        decimal_aux = decimal_aux / 2;
        tam++;
    }
    bin = new int[tam];//usando a quantidade de bits para criar um vetor para a palavra binaria

    for(int i = tam-1; i >= 0; i--){//converte em binario salvando no vetor
        bin[i] = decimal % 2;
        decimal /= 2;
    }
    return bin;
 }
