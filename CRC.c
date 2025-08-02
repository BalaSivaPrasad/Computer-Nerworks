#include <stdio.h>
int gen[4], genl = 4;
int frl = 8;
void crc_division(int fr[], int totalLen, int rem[]); 
int main() {
    int i, j;
    int fr[8], dupfr[11], recfr[11], rem[4], tlen, flag = 0;
    printf("Enter 8-bit frame (bits 0 or 1):\n");
    for (i = 0; i < frl; i++) {
        scanf("%d", &fr[i]);
        dupfr[i] = fr[i];
    }
    printf("Enter 4-bit generator (bits 0 or 1):\n");
    for (i = 0; i < genl; i++) {
        scanf("%d", &gen[i]);
    }
    tlen = frl + genl - 1;
    for (i = frl; i < tlen; i++) {
        dupfr[i] = 0;
    }
    crc_division(dupfr, tlen, rem); 
    for (i = 0; i < frl; i++) {
        recfr[i] = fr[i];
    }
    for (i = frl, j = 1; j < genl; i++, j++) {
        recfr[i] = rem[j];
    }
    crc_division(recfr, tlen, rem); 
    for (i = 0; i < genl; i++) {
        if (rem[i] != 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Frame received correctly.\n");
    } else {
        printf("The received frame is wrong.\n");
    }
    return 0;
}
void crc_division(int fr[], int totalLen, int rem[]) {
    int temp[20], i, j;

    // Copy input to temp array
    for (i = 0; i < totalLen; i++) {
        temp[i] = fr[i];
    }
    for (i = 0; i <= totalLen - genl; i++) {
        if (temp[i] == 1) {
            for (j = 0; j < genl; j++) {
                temp[i + j] = temp[i + j] ^ gen[j];
            }
        }
    }
    for (i = 0; i < genl; i++) {
        rem[i] = temp[totalLen - genl + i];
    }
}
