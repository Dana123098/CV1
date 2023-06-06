#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//Stwórz strukturę Element zawierającą wskaźnik na kolejny element kolejki oraz liczbę całkowitą.
struct Element {
    int value;
    Element* next;
};
//strukturę Single_list zawierającą wskaźniki na początek i koniec listy: head oraz tail.
struct Single_list {
    Element* head;
    Element* tail;
    int counter;
};
//ustawia początkowy stan listy.
void initializeList(Single_list* list) {
    list->head = nullptr;//ustawia wskaźnik head na wartość nullptr, co oznacza, że lista jest pusta.
    list->tail = nullptr;
    list->counter = 0;//ustawia licznik counter na 0, ponieważ lista jest pusta, więc nie ma żadnych elementów.
}
//sprawdza, czy lista jednokierunkowa 
bool isListEmpty(Single_list* list) {
    return list->head == nullptr;
    //porównuje wskaźnik head listy do wartości nullptr. Jeśli wskaźnik head ma wartość nullptr, oznacza to, że lista jest pusta.
    //Jeśli lista jest pusta , funkcja zwraca true.
	//W przeciwnym przypadku, funkcja zwraca false.
}
//dodaje nowy element na koniec listy jednokierunkowej (Single_list)
void addElementAtEnd(Single_list* list, int value) {
    // Tworzenie nowego elementu
    Element* newElement = new Element;
    // Przypisanie wartości do pola 'value' nowego elementu
    newElement->value = value;
    // Ustawienie wskaźnika 'next' nowego elementu na nullptr
    newElement->next = nullptr;
    // Sprawdzenie, czy lista jest pusta
    if (isListEmpty(list)) {
        // Jeśli lista jest pusta, ustawienie wskaźników 'head' i 'tail' na nowy element
        list->head = newElement;
        list->tail = newElement;
    } else {
        // Jeśli lista nie jest pusta, ustawienie wskaźnika 'next' ostatniego elementu na nowy element
        list->tail->next = newElement;
        // Aktualizacja wskaźnika 'tail', aby wskazywał na nowy element jako ostatni element
        list->tail = newElement;
    }
    // Zwiększenie licznika elementów w liście
    list->counter++;
    // Wyświetlenie komunikatu o dodaniu elementu na koniec listy
    cout << "Dodano element " << value << " na koniec listy.\n";
}

//dodanie nowego elementu na początek listy jednokierunkowej.
void addElementAtBeginning(Single_list* list, int value) {
    // Tworzenie nowego elementu
    Element* newElement = new Element;
    // Przypisanie wartości do pola 'value' nowego elementu
    newElement->value = value;
    // Ustawienie wskaźnika 'next' nowego elementu na obecny początek listy
    newElement->next = list->head;
    // Aktualizacja wskaźnika 'head', aby wskazywał na nowy element jako nowy początek listy
    list->head = newElement;
    // Sprawdzenie, czy lista jest pusta
    if (isListEmpty(list)) {
        // Jeśli lista jest pusta, ustawienie wskaźnika 'tail' na nowy element
        list->tail = newElement;
    }
    // Zwiększenie licznika elementów w liście
    list->counter++;
    // Wyświetlenie komunikatu o dodaniu elementu na początek listy
    cout << "Dodano element " << value << " na początek listy.\n";
}

//dodanie nowego elementu na określoną pozycję w liście jednokierunkowej.
void addElementAtPosition(Single_list* list, int value, int position) {
    if (position < 1 || position > list->counter + 1) {
        cout << "Nieprawidłowa pozycja.\n";
        return;
    }

    if (position == 1) {
        addElementAtBeginning(list, value);
    } else if (position == list->counter + 1) {
        addElementAtEnd(list, value);
    } else {
        Element* newElement = new Element;
        newElement->value = value;

        Element* current = list->head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }

        newElement->next = current->next;
        current->next = newElement;

        list->counter++;
        cout << "Dodano element " << value << " na pozycję " << position << " w liście.\n";
    }
}
//sunięcie ostatniego elementu z listy jednokierunkowej.
void removeElementFromEnd(Single_list* list) {
    if (isListEmpty(list)) {
        cout << "Lista jest pusta, nie można usunąć elementu.\n";
        return;
    }

    if (list->head == list->tail) {
        delete list->head;
        list->head = nullptr;
        list->tail = nullptr;
    } else {
        Element* current = list->head;
        while (current->next != list->tail) {
            current = current->next;
        }

        delete list->tail;
        current->next = nullptr;
        list->tail = current;
    }

    list->counter--;
    cout << "Usunięto element z końca listy.\n";
}


//odpowiada za usunięcie pierwszego elementu z listy jednokierunkowej.
void removeElementFromBeginning(Single_list* list) {
    if (isListEmpty(list)) {
        cout << "Lista jest pusta, nie można usunąć elementu.\n";
        return;
    }

    Element* temp = list->head;
    list->head = list->head->next;
    delete temp;

    list->counter--;
    cout << "Usunięto element z początku listy.\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Inicjalizacja generatora liczb pseudolosowych

    Single_list list;
    initializeList(&list);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Sprawdź, czy lista jest pusta.\n";
        cout << "2. Dodaj element na koniec listy.\n";
        cout << "3. Dodaj element na początek listy.\n";
        cout << "4. Dodaj element na określoną pozycję.\n";
        cout << "5. Usuń element z końca listy.\n";
        cout << "6. Usuń element z początku listy.\n";
        cout << "7. Pobierz pierwszy element z listy.\n";
        cout << "8. Pobierz ostatni element z listy.\n";
        cout << "9. Wyświetl ostatni element w liście.\n";
        cout << "10. Policzenie średniej arytmetycznej elementów w liście.\n";
        cout << "11. Znalezienie elementu maksymalnego w liście.\n";
        cout << "12. Wyświetl całą listę.\n";
        cout << "13. Usuń całą listę.\n";
        cout << "14. Wyjście z programu.\n";
        cout << "Wybierz opcję: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (isListEmpty(&list)) {
                    cout << "Lista jest pusta.\n";
                } else {
                    cout << "Lista nie jest pusta.\n";
                }
                break;
            case 2:
                {
                    int value = rand() % 50 + 1;
                    addElementAtEnd(&list, value);
                }
                break;
            case 3:
                {
                    int value = rand() % 50 + 1;
                    addElementAtBeginning(&list, value);
                }
                break;
            case 4:
                {
                    int value, position;
                    cout << "Podaj wartość elementu: ";
                    cin >> value;
                    cout << "Podaj pozycję elementu: ";
                    cin >> position;
                    addElementAtPosition(&list, value, position);
                }
                break;
            case 5:
                removeElementFromEnd(&list);
                break;
            case 6:
                removeElementFromBeginning(&list);
                break;
            case 7:
                if (isListEmpty(&list)) {
                    cout << "Lista jest pusta.\n";
                } else {
                    cout << "Pierwszy element w liście: " << list.head->value << endl;
                }
                break;
            case 8:
                if (isListEmpty(&list)) {
                    cout << "Lista jest pusta.\n";
                } else {
                    cout << "Ostatni element w liście: " << list.tail->value << endl;
                }
                break;
            case 9:
                if (isListEmpty(&list)) {
                    cout << "Lista jest pusta.\n";
                } else {
                    cout << "Ostatni element w liście: " << list.tail->value << endl;
                }
                break;
            case 10:
                	if (isListEmpty(&list)) {
                    cout << "Lista jest pusta.\n";
                } else {
                    int sum = 0;
                    Element* current = list.head;
                    while (current != nullptr) {
                        sum += current->value;
                        current = current->next;
                    }
                    double average = static_cast<double>(sum) / list.counter;
                    cout << "Średnia arytmetyczna elementów w liście: " << average << endl;
                }
                break;
            case 11:
                if (isListEmpty(&list)) {
                    cout << "Lista jest pusta.\n";
                } else {
                    Element* current = list.head;
                    int maxElement = current->value;
                    int maxPosition = 1;
                    int currentPosition = 1;

                    while (current != nullptr) {
                        if (current->value > maxElement) {
                            maxElement = current->value;
                            maxPosition = currentPosition;
                        }
                        current = current->next;
                        currentPosition++;
                    }

                    cout << "Element maksymalny w liście: " << maxElement << endl;
                    cout << "Pozycja elementu maksymalnego: " << maxPosition << endl;
                }
                break;
            case 12:
                if (isListEmpty(&list)) {
                    cout << "Lista jest pusta.\n";
                } else {
                    Element* current = list.head;
                    while (current != nullptr) {
                        cout << current->value << " ";
                        current = current->next;
                    }
                    cout << endl;
                }
                break;
            case 13:
                while (!isListEmpty(&list)) {
                    removeElementFromBeginning(&list);
                }
                cout << "Usunięto całą listę wraz ze zwolnieniem pamięci.\n";
                break;
            case 14:
                cout << "Wyjście z programu.\n";
                break;
            default:
                cout << "Nieprawidłowa opcja. Wybierz ponownie.\n";
                break;
        }
    } while (choice != 14);

    return 0;
}

