#include <stdio.h>
#include <stdbool.h>

struct zespolona {
	double re;
	double im;
}; //pamietamy o sredniku

struct zespolona dodaj(struct zespolona x, struct zespolona y){
	struct zespolona wynik;

	wynik.re = x.re + y.re;
	wynik.im = x.im + y.im;

	return wynik;
}

struct zespolona odejmij(struct zespolona x, struct zespolona y){
        struct zespolona wynik;

        wynik.re = x.re - y.re;
        wynik.im = x.im - y.im;

        return wynik;
}

struct zespolona mnoz(struct zespolona x, struct zespolona y){
        struct zespolona wynik;

        wynik.re = (x.re * y.re) - (x.im * y.im);
        wynik.im = (x.im * y.re) + (x.re * y.im);

        return wynik;
}

struct zespolona dziel(struct zespolona x, struct zespolona y,
                       bool *blad) {
        struct zespolona wynik = {0.0, 0.0};

	double k = y.re * y.re + y.im * y.im;
	if( k != 0.0){
	        wynik.re = (x.re * y.re + x.im * y.im) / k;
        	wynik.im = (x.im * y.re - x.re * y.im) / k;
		*blad = false;
        	return wynik;
	}else{
		*blad = true;
		return wynik;
	}
}

int main(){
	struct zespolona a = {1.3, 4.2}, b = {1.0, -0.5}, wynik;
	bool blad;

	wynik = dziel(a, b, &blad);
	if(!blad){
		printf("a(%.2lf, %.2lf) / b(%.2lf, %.2lf) = \
w(%.2lf, %.2lf)\n",
		a.re, a.im, b.re, b.im, wynik.re, wynik.im);
	}else{
		printf("Dzielenie przez zero!\n");
	}

	return 0;
}
