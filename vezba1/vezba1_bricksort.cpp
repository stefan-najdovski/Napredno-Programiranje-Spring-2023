/**
 *
 * Brick Sort Algorithm vo c++ 17
 * STEFAN NAJDOVSKI
 * Brick Sort Algorithm e varijacija na Bubble Sort Algorithmot
 *
 */


#include <iostream>


// Funkcija za zamena na dva elementi so pomos na pointeri (dereferenciranje)
// Zamena na dva elementi vo niza
void swap(int *xp, int *yp) {
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}

// Funkcija za generiranje na random niza, so elementi od 0 do 100
// koristi rand() funkcija od bibliotekata cstdlib
void randomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Funkcija za pecatenje na niza
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Brick Sort Algorithm
// implementiran vo funkcija brickSort()
// za input zema niza i n (dolzina na niza)
// koristi dva for ciklusi, za parni i neparni indeksi

//Algoritmot sortira niza od celi broevi vo rastečki redosled so sporeduvanje i zamena
// na sosednite elementi vo parovi od dva, prvo so parni indeksi, a potoa so neparni indeksi.
// Procesot se povtoruva dodeka nizata ne se podredi po rastecki redosled.

void brickSort(int arr[], int n) {
    bool isSorted = false;
    // Dokolku nizata ne e sortirana (isSorted == false)
    while (!isSorted) {
        isSorted = true;
        // Parni indeksi
        for (int i = 1; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                isSorted = false;
            }
        }
        // Neparni indeksi
        for (int i = 0; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

int main() {
    int arr[100];
    printf("Pecatenje na niza pred sortiranje: ");
    randomArray(arr, 100);
    printArray(arr, 100);

    //vremenska slozenost na Brick Sort Algorithm e O(n^2) (kvadratna)
    brickSort(arr, 100);
    printf("Pecatenje na niza posle sortiranje: ");
    printArray(arr, 100);

//puts (""); za oddeluvanje oti se mn elementi vo prasanje
    puts ("");
    //so 1000 elementi
    int arr1[1000];
    printf("Pecatenje na niza pred sortiranje: ");
    randomArray(arr1, 1000);
    printArray(arr1, 1000);
    printf("Pecatenje na niza posle sortiranje: ");
    brickSort(arr1, 1000);
    printArray(arr1, 1000);


    return 0;
}
