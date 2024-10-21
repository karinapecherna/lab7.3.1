#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//метод Гауса
void ToTriangularForm(int** a, int rowCount, int colCount) {
    for (int k = 0; k < rowCount; k++) {
        
        if (a[k][k] == 0) {
            cout << "Неможливо виконати перетворення: ділення на нуль!" << endl;
            return;
        }

        for (int i = k + 1; i < rowCount; i++) {
            double factor = static_cast<double>(a[i][k]) / a[k][k];  
            for (int j = k; j < colCount; j++) {
                a[i][j] -= factor * a[k][j];
            }
        }
    }
}


double AverageOfElementsLessThan(int** a, int rowCount, int colCount, double threshold) {
    int count = 0;
    int sum = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] < threshold) {
                sum += a[i][j];
                count++;
            }
        }
    }
    return (count > 0) ? static_cast<double>(sum) / count : 0.0;  
}

void GenerateRandomMatrix(int** a, int rowCount, int colCount, int lowerBound, int upperBound) {
    cout << "START M :" << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = rand() % (upperBound - lowerBound + 1) + lowerBound;
            cout << setw(5) << a[i][j] << " ";
        }
        cout << endl;
    }
}

void PrintMatrix(int** a, int rowCount, int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(5) << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); 

    int rowCount, colCount;
    double threshold;
    int lowerBound = -30, upperBound = 70;

    cout << "row: ";
    cin >> rowCount;
    cout << "col: ";
    cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    
    GenerateRandomMatrix(a, rowCount, colCount, lowerBound, upperBound);

   
    ToTriangularForm(a, rowCount, colCount);
    cout << "TRIANGLE M: " << endl;
    PrintMatrix(a, rowCount, colCount);

    
    cout << "X = ";
    cin >> threshold;

    
    double average = AverageOfElementsLessThan(a, rowCount, colCount, threshold);
    cout << "Y = "  << average << endl;

    
    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

