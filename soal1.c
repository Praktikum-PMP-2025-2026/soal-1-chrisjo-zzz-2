/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2
 *   Hari dan Tanggal    : 20 April 2026
 *   Nama (NIM)          : Christian Jonathan Hutajulu (13224108)
 *   Nama File           : Soal1.c
 *   Deskripsi           : Program pemulihan array lalu menghitung jumlah subarray maksimum
 */

#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf ("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++){
        scanf ("%d", &array[i]);
    }

    for (int i = 0; i < n; i++){
        if(array[i] == -1){
            int left = -1, right = -1;
            for (int j = i - 1; j >= 0; j--){
                if(array[j] != -1){
                    left = array[j];
                    break;
                }
            }
            for (int j = i + 1; j < n; j++){
                if(array[j] != -1){
                    right = array[j];
                    break;
                }
            }
            if (left != -1 && right != -1){
                double num = (left + right)/2;
                if (num < 0){
                    if (fmod(num, 1.0) == 0.0){
                    array[i] = num;
                    } else{
                    array[i] = num -1;
                    }
                }       
            } else if (left != -1){
                array[i] = left;
            } else if (right != -1){
                array[i] = right;
            } else{
                array[i] = 0;
            }
        }
    }

    int jumlah_max = 0;
    printf("RECOVERED");
    for(int i = 0; i < n; i++){
        printf(" %d", array[i]);
        jumlah_max += array[i];
    }
    printf("\nMAX_SUM %d\n", jumlah_max);
    return 0;
}
