#include "pch.h" // Підключається автоматично у Visual Studio для модульних тестів
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include "../Lab12_1/Lab12_1.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        TEST_METHOD(TestFilterFile)
        {
            const char* sourceFile = "test_source.dat";
            const char* resultFile = "test_result.dat";

            createSourceFile(sourceFile);

            filterFile(sourceFile, resultFile);

            std::ifstream file(resultFile, std::ios::binary);
            Assert::IsTrue(file.good(), L"Результуючий файл не створений.");

            char expectedData[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
            char buffer[sizeof(expectedData)] = {};
            file.read(buffer, sizeof(buffer));
            Assert::AreEqual(0, memcmp(buffer, expectedData, sizeof(expectedData)), L"Вміст результуючого файлу не відповідає очікуваному.");
            file.close();
        }
    };
}
