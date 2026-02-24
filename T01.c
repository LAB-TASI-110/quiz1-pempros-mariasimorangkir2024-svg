#include <stdio.h>
#include <string.h>

int main() {

    // Data menu
    char kode[10][5] = {"NGS","AP","SA","BU","MAP","GG","SAM","RD","IB","NUK"};
    char nama[10][30] = {
        "Nasi Goreng Spesial",
        "Ayam Penyet",
        "Sate Ayam (10 Tusuk)",
        "Bakso Urat",
        "Mie Ayam Pangsit",
        "Gado-Gado",
        "Soto Ayam",
        "Rendang Daging",
        "Ikan Bakar",
        "Nasi Uduk Komplit"
    };
    int harga[10] = {15000,20000,25000,18000,15000,15000,17000,25000,35000,20000};

    // Penyimpanan pesanan
    char namaPesan[100][30];
    int porsiPesan[100];
    int hargaPesan[100];
    int totalPesan[100];

    int jumlah = 0;
    int totalSemua = 0;

    char inputKode[10];

    // Input pesanan
    while (1) {

        printf("Masukkan kode menu (END untuk selesai): ");
        scanf("%s", inputKode);

        if (strcmp(inputKode, "END") == 0) {
            break;
        }

        int ditemukan = -1;

        for (int i = 0; i < 10; i++) {
            if (strcmp(inputKode, kode[i]) == 0) {
                ditemukan = i;
                break;
            }
        }

        if (ditemukan == -1) {
            printf("Kode tidak ditemukan!\n");
            continue;
        }

        int porsi;
        printf("Masukkan jumlah porsi: ");
        scanf("%d", &porsi);

        int total = harga[ditemukan] * porsi;

        strcpy(namaPesan[jumlah], nama[ditemukan]);
        porsiPesan[jumlah] = porsi;
        hargaPesan[jumlah] = harga[ditemukan];
        totalPesan[jumlah] = total;

        totalSemua += total;
        jumlah++;
    }

    // Hitung diskon
    double persenDiskon = 0;

    if (totalSemua >= 500000) persenDiskon = 0.25;
    else if (totalSemua >= 400000) persenDiskon = 0.20;
    else if (totalSemua >= 300000) persenDiskon = 0.15;
    else if (totalSemua >= 200000) persenDiskon = 0.10;
    else if (totalSemua >= 100000) persenDiskon = 0.05;

    int diskon = totalSemua * persenDiskon;
    int totalAkhir = totalSemua - diskon;

    // Cetak struk
    printf("\n=========== STRUK PEMBAYARAN ===========\n");
    printf("%-25s %-8s %-10s %-10s\n", "Menu", "Porsi", "Harga", "Total");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < jumlah; i++) {
        printf("%-25s %-8d %-10d %-10d\n",
               namaPesan[i],
               porsiPesan[i],
               hargaPesan[i],
               totalPesan[i]);
    }

    printf("---------------------------------------------------\n");
    printf("Total Pembayaran : %d\n", totalSemua);
    printf("Diskon           : %d\n", diskon);
    printf("Total Akhir      : %d\n", totalAkhir);

    return 0;
}