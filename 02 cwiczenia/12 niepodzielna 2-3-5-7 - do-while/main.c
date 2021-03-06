#include <stdio.h>

int main() {
    int liczba;
    int licznik_petli = 0;
    char znak = 'n';

    printf("Program liczy największą liczbę mniejszą od\n");
    printf("liczby podanej przez użytkownika, która\n");
    printf("jest niepodzielna przez 2, 3, 5, 7.\n");

    do {
        printf("\nPodaj liczbę: ");
        scanf(" %d", &liczba);

        // zrób nieparzystą
        if (!(liczba % 2)) --liczba;

        for (; !(liczba % 3) || !(liczba % 5) || !(liczba % 7); liczba -= 2) {
            licznik_petli++;
        }
        printf("znaleziona liczba: %d\n", liczba);

        printf("\n");
        printf("liczba pętli wyniosła: %d\n", licznik_petli);

        printf("\nCzy liczyć jeszcze raz? (t/n) ");
        scanf(" %c", &znak);

    } while (znak == 't' || znak == 'T');

    return 0;
}
