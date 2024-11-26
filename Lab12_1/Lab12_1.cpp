#include <iostream>
#include <fstream>
#include <cctype>
#include <Windows.h> 

using namespace std;

void createSourceFile(const char* filename) {
    fstream file(filename, ios::binary | ios::out);
    if (!file) {
        cerr << "Помилка створення файлу: " << filename << endl;
        return;
    }

    char data[] = { 'A', '5', 'B', '1', 'C', '9', 'D', 'E', '0', 'F' };
    file.write(data, sizeof(data));
    file.close();
}

void filterFile(const char* source, const char* destination) {
    fstream inFile(source, ios::binary | ios::in );
    if (!inFile) {
        cerr << "Помилка відкриття файлу " << source << endl;
        return;
    }

    fstream outFile(destination, ios::binary | ios::out);
    if (!outFile) {
        cerr << "Помилка створення файлу " << destination << endl;
        inFile.close();
        return;
    }

    char ch;
    while (inFile.read(&ch, sizeof(ch))) {
        if (!isdigit(ch)) {
            outFile.write(&ch, sizeof(ch));
        }
    }

    inFile.close();
    outFile.close();
}

void displayFileContent(const char* filename) {
    fstream file(filename, ios::binary | ios::in);
    if (!file) {
        cerr << "Помилка відкриття файлу " << filename << endl;
        return;
    }

    char ch;
    cout << "Вміст файлу " << filename << ": ";
    while (file.read(&ch, sizeof(ch))) {
        cout << ch << ' ';
    }
    cout << endl;

    file.close();
}

int main() {
    const char* sourceFile = "source.dat";
    const char* destinationFile = "result.dat";

    createSourceFile(sourceFile);               
    filterFile(sourceFile, destinationFile);    
    displayFileContent(destinationFile);     

    return 0;
}
