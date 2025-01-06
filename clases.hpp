# include <iostream>
using namespace std;

class Fecha{ 
    private: 
        //atributos
        int dia, mes, year;
    public: 
        //constructor default
        Fecha(){};
        //constructor parametrizado
        Fecha(int a, int b, int c){dia = a; mes = b; year = c;}
        //destructor
        ~Fecha(){};
        //setters
        void setDia(int valor){
            dia = valor;
        }
        void setMes(int valor){
            mes = valor;
        }
        void setYear(int valor){
            year = valor;
        }
        //getters
        int getDia(){
            return dia;
        }
        int getMes(){
            return mes;
        }
        int getYear(){
            return year;
        }
        //Funciones
        void showFecha(){
           cout << " |" << getDia() << "/" << getMes() << "/" << getYear() << "| " << endl;
        }     
};

class Libro{
    private: 
        string title, autor, ISBN;
        bool status;
    public:
        Libro(){};
        Libro(string vTitle, string vAuth, string vISBN, bool vStatus){title = vTitle; autor = vAuth; ISBN = vISBN; status = vStatus;}
        ~Libro(){};
    //setters
    void setTitle(string valor){
        title = valor;
    }
    void setAuth(string valor){
        autor = valor;
    }
    void setISBN(string valor){
        ISBN = valor;
    }
    void setStatus(bool valor){
        status = valor;
    }
    //getters
    string getTitle(){
        return title;
    }
    string getAuth(){
        return autor;
    }
    string getISBN(){
        return ISBN;
    }
    bool getStatus(){
        return status;
    }  
};


int const cantLib = 5;
class Usuario{
    private:   
        string nombre;
        int ID;
        Libro prestamos[cantLib];
    public: 
        Usuario(){};
        Usuario(string vNom, int vID){nombre = vNom; ID = vID;}
        ~Usuario(){}
        //setters
        void setNom(string valor){
            nombre = valor;
        }
        void setID(int valor){
            ID = valor;
        }
        void setPrest(Libro valor[cantLib]){
            for (int i = 0; i < cantLib; i++){
                prestamos[i] = valor[i];
            }
        }
        //getters
        string getNom(){
            return nombre;
        }
        int getID(){
            return ID;
        }
        Libro* getPrest(){
            return prestamos;
        }
};

class Registro{
    private:    
        Usuario user;
        Libro libro; 
        Fecha fPrest;
        Fecha fDev;
    public: 
        Registro(){}
        Registro(Usuario vUser, Libro vLibro, Fecha vFPrest, Fecha vFDev){user = vUser; libro = vLibro; fPrest = vFPrest; fDev = vFDev;}
        ~Registro(){}
        //setters
        void setUser(Usuario valor){
            user = valor;
        }  
        void setLibro(Libro valor){
            libro = valor;
        }
        void setFPrest(Fecha valor){
            fPrest = valor;
        }
        void setFDev(Fecha valor){
            fDev = valor;
        }
        //getters
        Usuario getUser(){
            return user;
        } 
        Libro getLibro(){
            return libro;
        }
        Fecha getFPrest(){
            return fPrest;
        }
        Fecha getFDev(){
            return fDev;
        }
};

int const cantUser = 5;
int const cantReg = 5;
class Biblioteca{
    private: 
        string nombre;
        Libro catalogo[cantLib];
        Usuario membresia[cantUser];
        Registro historico[cantReg];
    public: 
        Biblioteca(){}
        Biblioteca(string vNombre){nombre = vNombre;}
        ~Biblioteca(){}
        //setters
        void setNombre(string valor){
            nombre = valor;
        }
        void setCatalogo(Libro valor[cantLib]){
            for (int i = 0; i<cantLib; i++){
                catalogo[i]=valor[i];
            }
        }
        void setUsers(Usuario valor[cantUser]){
            for (int i=0; i<cantUser; i++){
                membresia[i] = valor[i];
            }
        }
        void setHist(Registro valor[cantReg]){
            for (int i= 0; i<cantReg; i++){
                historico[i] = valor[i];
            }
        }
        //getters
        string getNombre(){ 
            return nombre; 
        }
        Libro* getCatalogo(){ 
            return catalogo; 
        }
        Usuario* getUsers(){ 
            return membresia; 
        }
        Registro* getHist(){ 
            return historico; 
        }
        void addBook(Libro vLibro){
            for (int i=0; i<cantLib; i++){
                if (catalogo[i].getTitle()== ""){
                    catalogo[i] = vLibro;
                return;
                }
            }
            cout << ">>No hay espacio para más libros en el catálogo." << endl;
        }
        void addUser(Usuario vUser){
            for (int i=0; i<cantLib; i++){
                if (membresia[i].getNom()== ""){
                    membresia[i] = vUser;
                return;
                }
            }
            cout << ">>No hay lugar para más miembros." << endl;
        }
        void addReg(Registro vReg){
            for (int i=0; i<cantLib; i++){
                if (historico[i].getUser().getNom()== ""){
                    historico[i] = vReg;
                return;
                }
            }
            cout << ">>No hay espacio para más registors en el histórico." << endl;
        }
        
    void pLibro(int userID, string ISBN, Fecha fPrest){
        for (int i = 0; i < cantLib; i++){
            if (catalogo[i].getISBN() == ISBN && catalogo[i].getStatus()){
                for (int j = 0; j < cantUser; j++){
                    if (membresia[j].getID() == userID){
                        Libro librosPrestados[cantLib];
                        for (int k = 0; k < cantLib; k++){
                            librosPrestados[k] = membresia[j].getPrest()[k];
                        }
                        librosPrestados[0] = catalogo[i];
                        membresia[j].setPrest(librosPrestados);
                        catalogo[i].setStatus(false);
                        Registro nuevoReg(membresia[j], catalogo[i], fPrest, Fecha());
                        addReg(nuevoReg);
                        cout << "Libro prestado exitosamente." << endl;
                        return;
                    }
                }
            }
        }
        cout << "No se pudo prestar el libro." << endl;
    }

    void dLibro(int userID, string ISBN, Fecha fDev){
        for (int j = 0; j < cantUser; j++){
            if (membresia[j].getID() == userID){
                Libro* librosPrestados = membresia[j].getPrest();
                for (int k = 0; k < cantLib; k++){
                    if (librosPrestados[k].getISBN() == ISBN && !librosPrestados[k].getStatus()){
                        librosPrestados[k].setStatus(true);
                        for (int l = 0; l < cantLib; l++){
                            if (catalogo[l].getISBN() == ISBN){
                                catalogo[l].setStatus(true);
                                break;
                            }
                        }
                        for (int m = 0; m < cantReg; m++){
                            if (historico[m].getUser().getID() == userID && historico[m].getLibro().getISBN() == ISBN){
                                historico[m].setFDev(fDev);
                                cout << "Libro devuelto exitosamente." << endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
        cout << "No se pudo devolver el libro." << endl;
    }

    bool verDisp(string libroTitulo){
        for (int i = 0; i < cantLib; i++){
            if (catalogo[i].getTitle() == libroTitulo){
                return catalogo[i].getStatus();
            }
        }
        return false;
    }

    void showCat(){
        cout << "Catálogo de libros:" << endl;
        for (int i = 0; i < cantLib; i++){
            cout << ">>Título: " << catalogo[i].getTitle() << ", Autor: " << catalogo[i].getAuth()
                 << ", ISBN: " << catalogo[i].getISBN() << ", Estado: " << (catalogo[i].getStatus() ? "Disponible" : "Prestado") << endl;
        }
    }

    void showUser(){
        cout << "Usuarios registrados:" << endl;
        for (int i = 0; i < cantUser; i++){
            cout << ">>Nombre: " << membresia[i].getNom() << "| ID: " << membresia[i].getID();
            Libro* prestamos = membresia[i].getPrest();
            cout << " |   Libros prestados:" << endl;
            for (int j = 0; j < cantLib; j++){
                if (prestamos[j].getTitle() != ""){
                    cout << " -" << prestamos[j].getTitle() << " (" << prestamos[j].getStatus() << ")" << endl;
                }
            }
        }
    }
};