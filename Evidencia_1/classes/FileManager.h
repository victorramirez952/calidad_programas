#include <string>
#include <fstream>
#include <map>

#include "./File.h"
using namespace std;

class FileManager {
    private:
        File file;
        bool valExistingFile(string fileName){
            ifstream readingFile;
            readingFile.open(fileName);
            if(!readingFile.is_open()){
                cout << "El archivo no existe\n";
                return false;
            };
            readingFile.close();
            return true;
        };
        bool valNonEmptyFile(string fileName){
            ifstream readingFile;
            string strAux = "", content = "";
            readingFile.open(fileName);
            while(getline(readingFile, strAux)){
                content += strAux;
            }
            readingFile.close();
            if(content.length() == 0){
                cout << "El archivo está vacío\n";
                return false;
            }
            return true;
        };
    public:
        // Constructor para inicializar las variables
        FileManager(): file() { };

        File& getFile() {
            return this->file;
        };

        // Establece el contenido de un archivo
        // regresando true/false según si la operación es exitosa
        bool setFile(string fileName){
            ifstream readingFile;
            string strAux = "", content = "";
            if(!this->valExistingFile(fileName)){ // Si el archivo no existe
                return false;
            }
            if(!this->valNonEmptyFile(fileName)){ // Si el archivo está vacío
                return false;
            }
            readingFile.open(fileName);
            while(getline(readingFile, strAux)){
                content += strAux + "\n";
            }
            // Si strAux quedó vació, es necesario agregar un salto de línea
            // Para aquellos archivos que terminan en una línea vacía
            if(strAux.empty()){
                content += "\n";
            }
            readingFile.close();
            this->file.setFileName(fileName);
            this->file.setContent(content);
            return true;
        };
};