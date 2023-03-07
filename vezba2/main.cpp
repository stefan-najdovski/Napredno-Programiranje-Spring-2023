/**
 *
 *  Laboratoriska vezba 2
* Напаствие:
1. Кодот да се ископира и внесе во околина локално на компјутер, да се компајлира
со зададените дифолтни податоци за проверка интерна .
2. Задачата да се подигне на jdoodle акаунтите креирани минатиот семестар.
4. Секој студент да го именува проектот, согласно примерот погоре INKI987.lab.02., и да го
сочува.
НАПОМЕНА! Сите дадени линкови и примерите на нив се проверени, компајлирани и
функционални.
Иако се подразбитра, еве, допојаснување, за оваа задача, групирањето Ви е по два индекси
со иста активност, значи индекси кои завршуваат со 0 и 9 ги извршуваат двата линка, а со 1
и 2 зададрната задача за енумерација.
*/

/* difftime example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>

/*
frequency_of_primes  zema cel broj n kako vlez.
    Ja presmetuva frekvencijata na prosti broevi pomali ili ednakvi na n.
    Toa go pravi so povtoruvanje preku celi broevi od 2 do n, proveruvajḱi dali sekoj cel broj e prost i namaluvajki go brojačot na frekvencija ako ne e.
    Funkcijata ja vraḱa frekvencijata na prosti broevi pomali ili ednakvi na n.
 */
int frequency_of_primes (int n) {
    int i,j;
    int freq=n-1;
    for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
    return freq;
}

int main ()
{
    //ja povikuva funkcijata vreme od bibliotekata time.h
    // za da go dobie tekovnoto vreme i da go skladira vo promenlivata now.
    time_t now;
    struct tm newyear;
    //Gi postavuva polinjata za čas, minuta
    // i vtora godina na 0, a polinjata za mesec i den na 1 januari.
    double seconds;
    //Go presmetuva brojot na sekundi od sega do
    // početokot na godinata koristejḱi ja funkcijata difftime i go skladira vo promenlivata sekundi.

    time(&now);  /* get current time; same as: now = time(NULL)  */

    newyear = *localtime(&now);//dereferenciranje

    //inicijalizacija na struktura newyear
    newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
    newyear.tm_mon = 0;  newyear.tm_mday = 1;

    //Go presmetuva brojot na sekundi od sega do početokot na godinata koristejḱi j
    // a funkcijata difftime i go skladira vo promenlivata sekundi.
    seconds = difftime(now,mktime(&newyear));

    // pecati kolku sekundi se pominati od pocetokot na godinata
    printf ("%.f seconds since new year in the current timezone.\n", seconds);

    //t e promenliva od tipot clock_t, koja go čuva brojot na taktovi od početokot na programot.
    clock_t t;
    int f;
    //f e promenliva od tipot int, koja go čuva rezultatot od funkcijata frequency_of_primes.
    t = clock();
    printf ("Calculating...\n");
    f = frequency_of_primes (99999);// 99999 e argumentot na funkcijata frequency_of_primes.
    printf ("The number of primes lower than 100,000 is: %d\n",f);
    t = clock() - t;//Go presmetuva brojot na taktovi od početokot na programot do krajot na funkcijata frequency_of_primes.
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);


    return 0;
}