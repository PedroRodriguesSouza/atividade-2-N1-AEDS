#include <iostream>

using namespace std;

struct No{
   char Info;
   No *Lig;
};

typedef No *NoPtr;

struct Fila{
   NoPtr Com;
   int Nro;
   NoPtr Fim;
};

void IniciaFila(Fila& F){
   F.Nro = 0;
   F.Com = NULL;
   F.Fim = NULL;
}

bool FilaVazia(Fila F){
   return !F.Nro;
}

void InsereFila(Fila& F, char Novo){
   NoPtr P = new No;
   P->Info = Novo;
   P->Lig = NULL;
   if (F.Nro == 0)
        F.Com = F.Fim = P;
   else {
         F.Fim->Lig = P;
         F.Fim = P;
   }
   F.Nro++;
}

bool RetiraFila(Fila& F, char& Valor){
   if (FilaVazia(F))
       return false;
   else {
       NoPtr P = F.Com;
       Valor = P->Info;
       F.Com = P->Lig;
       F.Nro--;
       if (F.Nro == 0)
           F.Fim = NULL;
      delete P;
   }
   return true;
}

NoPtr Primeiro(Fila& F){
   NoPtr P = F.Com;
   return P;
}

void ImprimeFilaInvertida (Fila & F){
    NoPtr aux2;
    for(int i = F.Nro; i > 0; i--){
        aux2 = F.Com;
        for(int j = i-1; j > 0; j--){
            NoPtr aux1 = aux2->Lig;
            aux2 = aux1;
        }
        cout << aux2->Info;
    }
}

int main (){

   Fila F;
   IniciaFila(F);

   InsereFila (F, 'a');
   InsereFila (F, 'b');
   InsereFila (F, 'c');
   InsereFila (F, 'd');
   InsereFila (F, 'e');
   InsereFila (F, 'f');

   ImprimeFilaInvertida(F);

 return 0;
}
