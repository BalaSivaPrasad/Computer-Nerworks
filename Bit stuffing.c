#include <stdio.h>
int main() {
    int a[20], b[30];
    int i, j = 0, k, count = 0, n;
    printf("Enter frame length: ");
    scanf("%d", &n);
    printf("Enter input frame (0's & 1's only):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        b[j++] = a[i];

        if (a[i] == 1) {
            count++;
        } else {
            count = 0;
        }
        if (count == 5) {
            b[j++] = 0;
            count = 0;
        }
    }
    printf("After stuffing, the frame is:\n");
    for (i = 0; i < j; i++) {
        printf("%d", b[i]);
    }
    printf("\n");
    return 0;
}
