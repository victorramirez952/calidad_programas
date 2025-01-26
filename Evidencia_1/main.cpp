#include <iostream>
#include <string>
#include <map>
#include <Windows.h>

#include "./classes/FileManager.h"
#include "./classes/Reader.h"
using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    while(true){
        string fileName = "", content = "", userInput = "";
        FileManager fileManager;
        Reader reader;
        map<string, int> data; // "Diccionario" con los datos de interes
        while(fileName.length() == 0){ // Mientras el usuario no ingrese nada
            cout << "Ingresa el nombre del archivo: ";
            getline(cin, fileName);
        }
        if(!fileManager.setFile(fileName)){ // Si la carga del archivo no fue exitosa
            continue;
        }
        content = fileManager.getFile().getContent();
        data = reader.analyzeContent(content);
        fileManager.getFile().updateData(data);
        fileManager.getFile().showData();
        // Mientras la entrada del usuario sea una opción inválida
        while(userInput != "S" && userInput != "s" && userInput != "N" && userInput != "n"){
            cout << "Desea continuar? (S/N): ";
            getline(cin, userInput);
        }
        // Si el usuario decide no continuar
        if(userInput == "N" || userInput == "n"){
            break;
        }
    }
    return 0;
}