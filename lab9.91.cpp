#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktura elementu stosu
struct StackNode {
    int data;// Przechowuje wartość elementu na stosie
    struct StackNode* next;// Wskaźnik na kolejny element stosu
};

// Inicjalizacja pustego stosu
void initialize(struct StackNode** top) {
    *top = NULL;// Ustawienie wskaźnika na NULL oznacza pusty stos
}

// Sprawdzenie, czy stos jest pusty
bool isEmpty(struct StackNode* top) {
    return top == NULL;// Jeśli wskaźnik na wierzchołek stosu jest NULL, to stos jest pusty
}

// Dodanie elementu na stos
void push(struct StackNode** top) {
    int data = rand() % 10 + 1;// Generowanie losowej liczby z zakresu 1-10
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));   // Alokacja pamięci dla nowego elementu
    newNode->data = data;// Przypisanie wylosowanej wartości do elementu
    newNode->next = *top;// Nowy element staje się nowym wierzchołkiem, a poprzedni wierzchołek staje się drugim elementem
    *top = newNode;//Aktualizacja wskaźnika na wierzchołek stosu
    printf("Dodano element %d na stos.\n", data);
    
}

// Usunięcie elementu ze stosu
void pop(struct StackNode** top) {
    if (isEmpty(*top)) {// Sprawdzenie, czy stos jest pusty
        printf("Stos jest pusty.\n");// Wyświetlenie komunikatu o pustym stosie
        return;
    }
    struct StackNode* temp = *top;// Przechowanie wskaźnika na wierzchołek w pomocniczej zmiennej
    *top = (*top)->next;// Przesunięcie wskaźnika na wierzchołek na drugi element stosu
    printf("Usunięto element %d ze stosu.\n", temp->data);// Wyświetlenie usuniętego elementu
    free(temp);// Zwolnienie pamięci zajmowanej przez usunięty element
}

// Pobranie elementu ze stosu
void peek(struct StackNode* top) {
    if (isEmpty(top)) {   // Sprawdzenie, czy stos jest pusty
        printf("Stos jest pusty.\n");   // Wyświetlenie komunikatu o pustym stosie
        return;
    }
    printf("Ostatni element na stosie: %d\n", top->data);   // Wyświetlenie wartości ostatniego elementu
}

// Usunięcie wszystkich elementów ze stosu
void clear(struct StackNode** top) {
    while (!isEmpty(*top)) {   // Powtarzaj dopóki stos nie jest pusty
        pop(top);   // Usuń kolejne elementy ze stos

    }
    printf("Wyczyszczono stos.\n");
}

int main() {
    struct StackNode* top;
    initialize(&top);
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Sprawdź, czy stos jest pusty\n");
        printf("2. Dodaj element na stos\n");
        printf("3. Usuń element ze stosu\n");
        printf("4. Pobierz element ze stosu\n");
        printf("5. Usuń wszystkie elementy ze stosu\n");
        printf("6. Wyjdź z programu\n");
        printf("Wybierz opcję: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isEmpty(top))
                    printf("Stos jest pusty.\n");
                else
                    printf("Stos nie jest pusty.\n");
                break;
            case 2:
                push(&top);
                break;
            case 3:
                pop(&top);
                break;
            case 4:
                peek(top);
                break;
            case 5:
                clear(&top);
                break;
            case 6:
                printf("Program zakończony.\n");
                break;
            default:
                printf("Nieprawidłowa opcja. Wybierz ponownie.\n");
        }
    } while (choice != 6);

    return 0;
}
