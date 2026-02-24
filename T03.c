#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Asrama {
    char nama[50];
    char hari_jemput[20];
    char hari_antar[20];
};

void formatHari(char hari[]) {
    int i;
    hari[0] = toupper(hari[0]);
    for(i = 1; hari[i] != '\0'; i++) {
        hari[i] = tolower(hari[i]);
    }
}

int main() {

    struct Asrama data[] = {
        {"Simon Laplace", "Selasa", "Rabu"},
        {"Lovelace", "Rabu", "Kamis"},
        {"Louis Pasteur", "Minggu", "Senin"},
        {"Archimedes", "Kamis", "Jumat"}
    };

    int jumlah_asrama = 4;
    char hari[20];
    int i;
    int ada_jemput = 0;
    int ada_antar = 0;

    printf("=== SISTEM JADWAL LAUNDRY IT DEL ===\n");
    printf("Masukkan hari (Senin-Minggu): ");
    scanf("%19s", hari);

    formatHari(hari);

    printf("\nJadwal Hari %s\n", hari);
    printf("-----------------------------\n");

    printf("Jemput:\n");
    for(i = 0; i < jumlah_asrama; i++) {
        if(strcmp(hari, data[i].hari_jemput) == 0) {
            printf("- %s\n", data[i].nama);
            ada_jemput = 1;
        }
    }

    if(!ada_jemput) {
        printf("Tidak ada jadwal jemput.\n");
    }

    printf("\nAntar:\n");
    for(i = 0; i < jumlah_asrama; i++) {
        if(strcmp(hari, data[i].hari_antar) == 0) {
            printf("- %s\n", data[i].nama);
            ada_antar = 1;
        }
    }

    if(!ada_antar) {
        printf("Tidak ada jadwal antar.\n");
    }

    printf("\nProgram selesai.\n");

    return 0;
}
