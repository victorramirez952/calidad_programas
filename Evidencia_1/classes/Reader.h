#include <string>
#include <sstream>
#include <map>

using namespace std;

class Reader {
    private:
        bool flagMultiLine;
        // Revisa si una línea está vacía
        bool isEmptyLine(string line){
            // Si la línea tiene longitud 0
            if(line.length() == 0){
                return true;
            }
            // Si la línea no tiene mínimo un caracter diferente a " " y "\t"
            if(line.find_first_not_of(" \t") == string::npos){
                return true;
            }
            return false;
        }
        // Revisa si una línea es un comentario simple
        bool isSLC(string line){
            // Si la línea tiene el substring "//"
            if(line.find("//") != string::npos){
                return true;
            }
            return false;
        }
        // Revisa si una línea está abriendo un comentario multilínea
        bool isOpeningMLC(string line){
            // Si la línea tiene el substring "/*"
            if(line.find("/*") != string::npos){
                return true;
            }
            return false;
        }
        // Revisa si una línea está cerrando un comentario multilínea
        bool isClosingMLC(string line){
            // Si la linea tiene el substring "*/"
            if(line.find("*/") != string::npos){
                return true;
            }
            return false;
        }
    public:
        // Constructor para inicializar las variables
        Reader(): flagMultiLine(false){};

        // Analiza un contenido contando los comentarios, líneas vacías y líneas de código
        map<string, int> analyzeContent(string content){
            // Creamos un objeto stringstream a partir de content, para simplificar el recorrido del string 
            stringstream ss(content);
            string line = "";
            int totalComments = 0, totalEmptyLines = 0, totalCode = 0;
            while(getline(ss, line)){
                if(this->flagMultiLine){ // Si la variable bandera flagMultiLine es verdadera
                    if(this->isClosingMLC(line)){
                        this->flagMultiLine = false;
                    }
                    totalComments += 1;
                }
                else {
                    if(this->isEmptyLine(line)){
                        totalEmptyLines += 1;
                        continue;
                    }
                    if(this->isSLC(line)){
                        totalComments += 1;
                        continue;
                    }
                    if(this->isOpeningMLC(line)){
                        totalComments += 1;
                        this->flagMultiLine = true;
                        continue;
                    }
                    totalCode += 1;
                }
            }
            // Declaramos el "diccionario" que tiene que regresar la función con los datos analizados
            const map<string, int> data = {
                {"totalComments", totalComments},
                {"totalEmptyLines", totalEmptyLines},
                {"totalCode", totalCode}
            };
            return data;
        }
};