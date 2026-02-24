#include <stdio.h>

int main() {
    int N;

    // Input jumlah data
    printf("Masukkan jumlah data: ");
    scanf("%d", &N);

    int nilai[N];

    // Input deret nilai
    printf("Masukkan %d nilai:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &nilai[i]);
    }

    int kodeKelompok;

    // Input kode kelompok
    printf("Masukkan kode kelompok (1 - %d): ", N);
    scanf("%d", &kodeKelompok);

    // Cek valid atau tidak
    if (kodeKelompok >= 1 && kodeKelompok <= N) {
        printf("Total nilai kelompok %d adalah: %d\n",
               kodeKelompok, nilai[kodeKelompok - 1]);
    } else {
        printf("Kode kelompok tidak valid.\n");
    }

    return 0;
}