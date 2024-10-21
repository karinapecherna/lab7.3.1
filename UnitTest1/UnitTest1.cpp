#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.3.01/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyProgramTests
{
    TEST_CLASS(MyProgramTests)
    {
    public:

        TEST_METHOD(TestAverageOfElementsLessThan)
        {
            
            const int rowCount = 3;
            const int colCount = 3;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
            {
                matrix[i] = new int[colCount];
            }

            
            matrix[0][0] = 1;   matrix[0][1] = 2;   matrix[0][2] = 3;
            matrix[1][0] = 4;   matrix[1][1] = 5;   matrix[1][2] = 6;
            matrix[2][0] = 7;   matrix[2][1] = 8;   matrix[2][2] = 9;

            double threshold = 5.0;

            
            double result = AverageOfElementsLessThan(matrix, rowCount, colCount, threshold);

            
            Assert::AreEqual(2.5, result, 0.01);  

            
            for (int i = 0; i < rowCount; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    };
}
