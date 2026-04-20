/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2
 *   Hari dan Tanggal    : 20 April 2026
 *   Nama (NIM)          : Christian Jonathan Hutajulu (13224108)
 *   Nama File           : Soal1.c
 *   Deskripsi           : Program pemulihan array lalu menghitung jumlah subarray maksimum
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) {
            int left = -1, right = -1;
            for(int j = i - 1; j >= 0; j--) {
                if(arr[j] != -1) {
                    left = arr[j];
                    break;
                }
            }
            for(int j = i + 1; j < n; j++) {
                if(arr[j] != -1) {
                    right = arr[j];
                    break;
                }
            }
            if(left != -1 && right != -1) {
                arr[i] = (left + right) / 2;
            } else if(left != -1) {
                arr[i] = left;
            } else if(right != -1) {
                arr[i] = right;
            } else {
                arr[i] = 0;
            }
        }
    }

    int max_sum = arr[0];
    int cur = arr[0];
    for(int i = 1; i < n; i++) {
        cur = (arr[i] > cur + arr[i]) ? arr[i] : cur + arr[i];
        max_sum = (max_sum > cur) ? max_sum : cur;
    }

    printf("RECOVERED");
    for(int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\nMAX_SUM %d\n", max_sum);

    return 0;
}
