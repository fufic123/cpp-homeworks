//
//  main.cpp
//  cpp_homework_37
//
//  Created by Mark Semenov on 22.12.2022.
//

#include <iostream>
using namespace std;

#define RUN int main(int argc, const char * argv[])
#define BEGIN {
#define END }
#define PRINT cout <<
#define SET_RANDOM srand(time(NULL));
#define RAND_NUM rand() % 100
#define TAB << "\t"
#define ENDL << endl
#define FOR_I for (int i = 0; i < size; i++)
#define FOR_J for (int j = 0; j < size; j++)
#define FOR_A for (int a = j; a < size; a++)
#define SWAP swap(arr[i][j], arr[i][tmp]);
#define INFINITY_LOOP while (true)
#define elif else if


int linearSearch(double arr[], int size, int key) BEGIN
    FOR_I BEGIN
        if (arr[i] == key) return i;
    END
    return -1;
END

int binarySearch(double arr[], int size, int key) BEGIN
    int midd = 0, left = 0, right = size - 1;
    INFINITY_LOOP BEGIN
        midd = (left + right) / 2;
        if (key < arr[midd]) right = midd - 1;
        elif (key > arr[midd]) left = midd + 1;
        else return midd;
        if (left > right) return -1;
    END
END


int** createMatrix(int size) BEGIN
    int** arr = new int* [size];
    FOR_I arr[i] = new int[size] {0};
    return arr;
END

void matrixInitialization(int** arr, int size) BEGIN
    SET_RANDOM
    FOR_I FOR_J arr[i][j] = RAND_NUM;
END

void printMatrix(int** arr, int size) BEGIN
    FOR_I BEGIN
        FOR_J PRINT arr[i][j] TAB;
        PRINT endl;
    END
END

void sortMatrix(int** arr, int size) BEGIN
    FOR_I BEGIN
        for (int j = 0; j < size - 1; j++) BEGIN
            int tmp = j;
            int min = arr[i][j];
            FOR_A BEGIN
                if (min > arr[i][a]) BEGIN
                    tmp = a;
                    min = arr[i][a];
                END
            END
            SWAP
        END
    END
END

int diagonalMatrixMin(int** arr, int size) BEGIN
    int min = arr[0][0];
    FOR_I FOR_J if (i == j) if (arr[i][j] < min) min = arr[i][j];
    return min;
END

int diagonalMatrixMax(int** arr, int size) BEGIN
    int max = arr[0][0];
    FOR_I FOR_J if (i == j) if (arr[i][j] > max) max = arr[i][j];
    return max;
END


double** createDoubleMatrix(int size) BEGIN
    double** arr = new double* [size];
    FOR_I arr[i] = new double[size] {0};
    return arr;
END

void matrixInitialization(double** arr, int size) BEGIN
    SET_RANDOM
    FOR_I FOR_J arr[i][j] = RAND_NUM / 10;
END

void printMatrix(double** arr, int size) BEGIN
    FOR_I BEGIN
        FOR_J PRINT arr[i][j] TAB;
        PRINT endl;
    END
END

void sortMatrix(double** arr, int size) BEGIN
    FOR_I BEGIN
        for (int j = 0; j < size - 1; j++) BEGIN
            int tmp = j;
            double min = arr[i][j];
            FOR_A BEGIN
                if (min > arr[i][a]) BEGIN
                    tmp = a;
                    min = arr[i][a];
                END
            END
            SWAP
        END
    END
END

double diagonalMatrixMin(double** arr, int size) BEGIN
    double min = arr[0][0];
    FOR_I FOR_J if (i == j) if (arr[i][j] < min) min = arr[i][j];
    return min;
END

double diagonalMatrixMax(double** arr, int size) BEGIN
    double max = arr[0][0];
    FOR_I FOR_J if (i == j) if (arr[i][j] > max) max = arr[i][j];
    return max;
END


char** createCharMatrix(int size) BEGIN
    char** arr = new char* [size];
    FOR_I arr[i] = new char[size] {0};
    return arr;
END

void matrixInitialization(char** arr, int size) BEGIN
    SET_RANDOM
    FOR_I FOR_J arr[i][j] = char(RAND_NUM);
END

void printMatrix(char** arr, int size) BEGIN
    FOR_I BEGIN
        FOR_J PRINT arr[i][j] TAB;
        PRINT endl;
    END
END

void sortMatrix(char** arr, int size) BEGIN
    FOR_I BEGIN
        for (int j = 0; j < size - 1; j++) BEGIN
            int tmp = j;
            char min = arr[i][j];
            FOR_A BEGIN
                if (min > arr[i][a]) BEGIN
                    tmp = a;
                    min = arr[i][a];
                END
            END
            SWAP
        END
    END
END

char diagonalMatrixMin(char** arr, int size) BEGIN
    char min = arr[0][0];
    FOR_I FOR_J if (i == j) if (arr[i][j] < min) min = arr[i][j];
    return min;
END

char diagonalMatrixMax(char** arr, int size) BEGIN
    char max = arr[0][0];
    FOR_I FOR_J if (i == j) if (arr[i][j] > max) max = arr[i][j];
    return max;
END


RUN BEGIN
    double arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    PRINT linearSearch(arr, 20, 14) ENDL ENDL;
    PRINT binarySearch(arr, 20, 9) ENDL ENDL;
    int** int_mat = createMatrix(5);
    matrixInitialization(int_mat, 5);
    printMatrix(int_mat, 5);
    sortMatrix(int_mat, 5);
    PRINT endl;
    printMatrix(int_mat, 5);
    PRINT endl;
    PRINT diagonalMatrixMin(int_mat, 5) ENDL ENDL;
    PRINT diagonalMatrixMax(int_mat, 5) ENDL ENDL;
END

