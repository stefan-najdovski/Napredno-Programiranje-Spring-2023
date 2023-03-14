/**
 * Domasno 1 Stefan Najdovski
 * Kje ispecati:
 * Vo ASCII kod ime i prezime: 83 116 101 102 97 110 32 78 97 106 100 111 118 115 107 105 
 * Vo ASCII kod indeksot: 73 78 75 73 45 54 52 56
 * Testirano so kompajlerot:
 * Apple clang version 14.0.0 (clang-1400.0.29.202)
 *Target: x86_64-apple-darwin22.2.0
 *Thread model: posix
 *InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
 * 
 **/
#include <stdio.h>
#include <string.h>

int main() {
   // char name[50];//do 50 karakteri
    char name[] = "Stefan Najdovski";
    char index_number[] = "INKI-648";//do 10 karakteri
    int name_ascii[50]; // vo int char e 8 bytes
    int index_ascii[10];
    int i;

    //printf("Vnesete go vaseto ime i prezime: ");
   // fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // vo C standardot se dodava \0 pa treba da go otstranime

   // printf("Vnesete indeks ");
  //  fgets(index_number, sizeof(index_number), stdin);
    index_number[strcspn(index_number, "\n")] = '\0'; // isto kako pogore

    // Vaseto ime i prezime so ascii kodovi
    for (i = 0; i < strlen(name); i++) {
        name_ascii[i] = (int) name[i];
    }

    // Undex vo ascii (int) eksplictno "go terame" da gi tretira karakterite kako int
    for (i = 0; i < strlen(index_number); i++) {
        index_ascii[i] = (int) index_number[i];
    }

    // Ciklusi za Peactenje na nizite

    printf("Vo ASCII kod ime i prezime: ");
    for (i = 0; i < strlen(name); i++) {
        printf("%d ", name_ascii[i]);
    }
    printf("\n");//poarno e vo puts(""); oti kompajlerot istoto kje go stori za nas kje go ostavam

    printf("Vo ASCII kod indeksot: ");
    for (i = 0; i < strlen(index_number); i++) {
        printf("%d ", index_ascii[i]);
    }
    printf("\n");

    return 0;
}
