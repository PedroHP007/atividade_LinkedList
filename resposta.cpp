#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;
};

int encontrarMeio(No* inicio) {
    int tamanho = 0;
    No* atual = inicio;

    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }

    int meio = tamanho / 2;

    atual = inicio;

    for (int i = 0; i < meio; i++) {
        atual = atual->proximo;
    }

    return atual->valor;
}

bool procurarElemento(No* inicio, int valor) {
    No* atual = inicio;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return true;
        }

        atual = atual->proximo;
    }

    return false;
}

int main() {

    No* inicio = new No{1, NULL};

    inicio->proximo = new No{2, NULL};
    inicio->proximo->proximo = new No{3, NULL};
    inicio->proximo->proximo->proximo = new No{4, NULL};
    inicio->proximo->proximo->proximo->proximo = new No{5, NULL};
    inicio->proximo->proximo->proximo->proximo->proximo = new No{6, NULL};

    cout << "Valor do meio: " << encontrarMeio(inicio) << endl;

    cout << "Elemento 4: " << procurarElemento(inicio, 4) << endl;

    cout << "Elemento 10: " << procurarElemento(inicio, 10) << endl;

    return 0;
}