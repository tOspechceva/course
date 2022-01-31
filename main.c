# include <assert.h>
# include <stdbool.h>
# include "c:/course/libs/algorithms/array/array.h"
# include "c:/course/libs/algorithms/algorithm.c"
#include <stdio.h>
void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
void selectionSort(int *a, const size_t n) {
    if (n > 1) {
        for (int k = 0; k < n; k++) {
            int min = a[k];
            int count = k;
            for (int i = k; i < n; i++) {
                if (a[i] < min) {
                    min = a[i];
                    count = i;
                }
            }
            a[count] = a[k];
            a[k] = min;
        }
    }
}

int searchUnseenSeries(const int *a, const size_t n) {
    if (a[0]!=1)
        return  1;
    int i=0;
    while (i<=n && a[i]==i+1){
        i++;
    }
    return i+1;
}

main() {
    int n;
    scanf("%d", &n);
    size_t numberEpisodes = n - 1;
    int a[numberEpisodes];
    inputArray_(a, numberEpisodes);

    selectionSort(a, numberEpisodes);


    printf("%d\n",searchUnseenSeries(a, numberEpisodes) );


    return 0;
}