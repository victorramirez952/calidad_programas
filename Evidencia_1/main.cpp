#include <iostream>
#include <string>
#include <map>
#include <Windows.h>

#include "./classes/FileManager.h"
#include "./classes/Reader.h"
using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    string fileName = "", content = "";
    bool validFile = false;
    FileManager fileManager;
    Reader reader;
    map<string, int> data; // "Diccionario" con los datos de interes
    while(!validFile){
        while(fileName.length() == 0){ // Mientras el usuario no ingrese nada
            cout << "Ingresa el nombre del archivo: ";
            getline(cin, fileName);
        }
        if(!fileManager.setFile(fileName)){ // Si la carga del archivo no fue exitosa
            fileName = "";
            continue;
        }
        validFile = true;
    }
    content = fileManager.getFile().getContent();
    data = reader.analyzeContent(content);
    fileManager.getFile().updateData(data);
    fileManager.getFile().showData();
    return 0;
}