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
    matrix ms[3] = {
            createMatrix(2, 2),
            createMatrix(1, 1),
            createMatrix(1, 1),

    };
    inputMatrices(ms,3);
    outputMatrices(ms,3);
    return 0;
}