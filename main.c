# include <assert.h>
# include <stdbool.h>
# include <stdio.h >
# include <stdint.h >

# include "libs/data_structures/matrix/matrix.h"

void test_inputMatrix(){
    matrix m;
    inputMatrix(&m);
    outputMatrix(m);

}

void test(){
   test_inputMatrix();


}

int main() {
    //test();
    //matrix ms[3] = {
    //        createMatrix(2, 2),
    //        createMatrix(1, 1),
    //        createMatrix(1, 1),
//
    //};
    //inputMatrices(ms,3);
    //outputMatrices(ms,3);
    matrix m1= createMatrix(3,3);
    //matrix m2= createMatrix(2,3);
    inputMatrix(&m1);
    //inputMatrix(&m2);
    if (isSymmetricMatrix(m1))
        printf("Yes");
    else
        printf("No");
    outputMatrix(m1);
    //outputMatrix(m2);
    return 0;
}