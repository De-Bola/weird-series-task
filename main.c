#include <stdio.h>

float getPowerVal(float input, int power);

int doFactorial(int n);

float getAbsoluteVal(float val);

void seriesEquations(float X, float* arr, int count, float E, int i);

int main() {

    // Taking input values for "X" and "E"
    float X, E;
    do{
        printf("Please enter the value of X: ");
        scanf("%f", &X);
    }while (getAbsoluteVal(X) > 1);

    do{
        printf("Please enter the value of E: ");
        scanf("%f", &E);
    }while (E < 0 || E > 1);


    float* arr[150];

    int i = 2, count = 0;

    seriesEquations(X, arr, count, E, i);
/*    // Writing Array to file

    FILE *f = fopen("output.txt", "wb");
    fprintf(f, "No. of elements in the array: %d\n", count + 1);

    for (int i = 0; i <= count; i++) {
        fprintf(f, "%d  %f\n", i + 1, arr[i]);
    }
    //fwrite(arr, sizeof(float), sizeof(arr), f);
    fclose(f);*/

    return 0;
}

void seriesEquations(float X, float* arr, int count, float E, int i) {
    if (getAbsoluteVal(arr[count] - arr[count - 1]) > E) return;
        // Calculation part
    if(count == 0){
        arr[count] = 1;
    }else if (count % 2 == 0) {
        arr[count] = getPowerVal(X, i) / (float) (doFactorial(i));
        i *= i;
    }
    else{
        arr[count] = (-1) * getPowerVal(X, i) / (float) (doFactorial(i));
        i *= i;
    }

    printf("\n[%d]  %f\n", count, arr[count]);

    count++;

    if(count > 15) {
        return;
    } else {
        seriesEquations(X, arr, count, E, i);
    }
}

float getPowerVal(float input, int power) {
    float output = 1;
    for (int i = 0; i < power; i++) {
        output *= input;
    }
    return output;
}

int doFactorial(int n) {
    if (n == 0) // Base case
        return 1;
    else
        return (n * doFactorial(n - 1));
}

float getAbsoluteVal(float val) {
    if (val < 0) {
        val = val * -1;
    }
    return val;
}