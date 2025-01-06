# include "clases.hpp"

int main(){
    Biblioteca bibliotecaTest("Biblioteca Test");
    Libro libro1("Libro1", "Pepe", "1234567890", true);
    Libro libro2("Don Quijote de la Mancha", "Miguel de Cervantes", "0987654321", true);
    Libro libro3("HarryPotter", "autor", "1122334455", true);
    Libro libro4("a", "Juan","2233445566",true);
    Libro libro5("b", "Filiberto","3344556677", true);
    Usuario usuario1("Juan Perez",1);
    Usuario usuario2("Maria Lopez", 2);
    Usuario usuario3("Carlos Sanchez",3);
    Usuario usuario4("Ana Gomez", 4);
    Usuario usuario5("Valeria", 5);
    bibliotecaTest.addBook(libro1);
    bibliotecaTest.addBook(libro2);
    bibliotecaTest.addBook(libro3);
    bibliotecaTest.addBook(libro4);
    bibliotecaTest.addBook(libro5);
    bibliotecaTest.addUser(usuario1);
    bibliotecaTest.addUser(usuario2);
    bibliotecaTest.addUser(usuario3);
    bibliotecaTest.addUser(usuario4);
    bibliotecaTest.addUser(usuario5);
    bibliotecaTest.showCat();
    cout << endl;
    bibliotecaTest.showUser();
    // Prestar libro
    cout << endl;
    Fecha fechaPrestamo(1, 7, 2024);
    bibliotecaTest.pLibro(1, "1234567890", fechaPrestamo);
    bibliotecaTest.pLibro(2, "0987654321", fechaPrestamo);
    //Verd isponiblidad
    cout << endl << "Disponibilidad de 'Libro1': " << bibliotecaTest.verDisp("Libro1") << endl;
    //Devolverlibro
    Fecha fechaDevolucion(8, 7, 2024);
    bibliotecaTest.dLibro(1, "1234567890", fechaDevolucion);
    //Ver si está disponible otra vez
    cout << endl << "Disponibilidad de 'Libro1' después de la devolución: " << bibliotecaTest.verDisp("Libro1") << endl;
    //Mostraracatalogo
    cout << endl; 
    bibliotecaTest.showCat();
    //Mosrtrarmembresias
    cout << endl;
    bibliotecaTest.showUser();
    cout << endl; 
    return 0;
}