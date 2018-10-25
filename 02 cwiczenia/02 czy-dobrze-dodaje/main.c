#include <stdio.h>

#define TEST

int dodaj(int a, int b) {
    return a + b;
}


#ifdef TEST

void nd(int licznik) { printf("Test nr %i nie działa\n", licznik); }

// tutaj należy umieszczać kolejne testy
void test1_dodaj(int licznik) {
    if (dodaj(3, 6) != 9) nd(licznik);
}

void test2_dodaj(int licznik) {
    if (dodaj(6, 2) != 8) nd(licznik);
}

void run_test_pool() {
    int licznik = 0;
// tutaj wywołujemy testy

    test1_dodaj(++licznik);
    test2_dodaj(++licznik);

}

#endif


int main() {

#ifndef TEST
    // uruchom program


#else
    // uruchom testy
    run_test_pool();

#endif

    return 0;
}
