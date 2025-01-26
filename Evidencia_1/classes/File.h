#include <string>
#include <fstream>
#include <map>
using namespace std;

class File {
    private:
        string fileName;
        int totalComments;
        int totalEmptyLines;
        int totalCode;
        string content;
    public:
        // Constructor para inicializar las variables
        File(): fileName(""), totalComments(0), totalEmptyLines(0), totalCode(0), content(""){}

        // Obtener el contenido en string del archivo
        string getContent(){
            return this->content;
        }

        // Establecer el contenido del archivo en string
        void setContent(string content){
            this->content = content;
        }

        string getFileName(){
            return this->fileName;
        }

        void setFileName(string fileName){
            this->fileName = fileName;
        }

        // Regresamos los datos del archivo en forma de un diccionario (map<string, int>)
        map<string, int> getData(){
            const map<string, int> data = {
                {"totalComments", this->totalComments},
                {"totalEmptyLines", this->totalEmptyLines},
                {"totalCode", this->totalCode}
            };
            return data;
        }

        // Recibe un diccionario con los datos para actualizar los datos actuales del archivo
        bool updateData(map<string, int> newData){
            try{
                this->totalComments = newData["totalComments"];
                this->totalEmptyLines = newData["totalEmptyLines"];
                this->totalCode = newData["totalCode"];
                cout << this->totalComments << endl;
                return true;
            }
            catch(const exception& e){
                cout << "Ocurrió un error" << '\n';
                cout << e.what() << '\n';
                return false;
            }
            
        }
        
        void showData(){
            cout << "Nombre del archivo: " << this->fileName << '\n';
            cout << "--------------------------------------------" << endl;
            cout << "Cantidad de líneas en blanco: " << this->totalEmptyLines << endl;
            cout << "Cantidad de líneas con comentarios: " << this->totalComments << endl;
            cout << "Cantidad de líneas con código: " << this->totalCode << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Cantidad total de líneas: " << (this->totalEmptyLines + this->totalComments + this->totalCode) << endl;
        }
};