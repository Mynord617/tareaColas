#include <iostream>

using namespace std;

struct Nodo
{
    string dato, genero;
    int NumeroId, edad;

    Nodo *siguientePtr;
};

void menu();
void agregarCola(Nodo *&, Nodo *&, string, int, int, string);
void eliminarCola(Nodo *&, Nodo *&, string &, int &, int &, string &);
bool colaVacia(Nodo *);

int main()
{
    menu();

    return 0;
}

void menu()
{
    int opcion, NumeroId, edad;
    string dato, genero;
    Nodo *frente = NULL;
    Nodo *final = NULL;

    do
    {
        cout << "*********************************************************\n"
             << "***                  MENU DE COLAS                    ***\n"
             << "*** Tarea: Algoritmo de colas                         ***\n"
             << "*** NOMBRE: MYNOR ARNALDO DOMINGUEZ MEZA              ***\n"
             << "*** NUMERO DE CUENTA: 61641352                        ***\n"
             << "***                                                   ***\n"
             << "*********************************************************\n"
             << "***                                                   ***\n"
             << "*** 1. Agregar Usuario a la Cola                      ***\n"
             << "*** 2. Eliminar Usuario de la cola                    ***\n"
             << "*** 3. Salir del Programa                             ***\n"
             << "*********************************************************" << endl;
        cout << "***  Elija una opción: ";
        cin >> opcion;
         cout<<endl;
        // cout<<"*********************************************************"<<endl;
        switch (opcion)
        {
        case 1:
            cout << "Inserte Un nuevo usuario a la cola: " << endl;
            cout << "Nombre: ";cin >> dato;
            cout << "Numero de Identidad: ";cin >> NumeroId;
            cout << "Edad: ";cin >> edad;
            cout << "Genero: ";cin >> genero;
            agregarCola(frente, final, dato, NumeroId, edad, genero);
            break;
        case 2: //cout << "Mostrando los Usuarios de la cola: "<<endl;
            while (frente != NULL){
                eliminarCola(frente, final, dato, NumeroId, edad, genero);
                if (frente != NULL)
                {

                    cout << "\nNombre: " << dato <<" , "<< endl;
                    cout << "Numero de Cedula: " <<NumeroId <<" , "<< endl;
                    cout << "Edad: " <<edad <<" , "<< endl;
                    cout << "Genero: " << genero <<" , "<< endl; 
               
                } 
                else
                {
                    cout<<"\nMostrando datos del usuario eliminado "<<endl;
                    cout << "Nombre: " << dato <<"."<< endl;
                    cout << "Numero de Cedula: " << NumeroId <<"."<< endl;
                    cout << "Edad: " << edad <<"."<< endl;
                    cout << "Genero: " << genero <<"."<< endl;
               
                }
            }

            break;
            case 3: break;
        }

        // METODO UTILIZADO PARA MAC. ESO ES PARA EL USO DE getch();  ya que no es permitido en mac
         system ("\nread -n 1 -s -p \" Presione cualquier tecla para continuar. . \" \n");
         system("clear"); // Este se usa para limpiar la pantalla en vez de system("cls");
    } while (opcion != 3);
}

void agregarCola(Nodo *&frente, Nodo *&final, string nDato, int nNumeroId, int nEdad, string nGenero)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = nDato;
    nuevo_nodo->NumeroId = nNumeroId;
    nuevo_nodo->edad = nEdad;
    nuevo_nodo->genero = nGenero;
    nuevo_nodo->siguientePtr = NULL;

    if (colaVacia(frente))
    {
        frente = nuevo_nodo;
    }
    else
    {
        final->siguientePtr = nuevo_nodo;
    }
    final = nuevo_nodo;

    cout << "El Usuario " << nDato << " Se agrego a la cola Correctamente" << endl;
    cout<<endl;
}

bool colaVacia(Nodo *frente)
{
    return (frente == NULL) ? true : false;
}

void eliminarCola(Nodo *&frente, Nodo *&final, string &nDato, int &nNumeroId, int &nEdad, string &nGenero)
{
    nDato = frente->dato;
    nNumeroId = frente->NumeroId;
    nEdad = frente->edad;
    nGenero = frente->genero;
    Nodo *auxiliar = frente;
    if (frente == final)
    {
        frente = NULL;
        final = NULL;
    }
    else
    {
        frente = frente->siguientePtr;
    }

    delete auxiliar;
    cout << "El Usuario " << nDato << " Se Elimino correctamente " << endl;
    cout<<endl;
   
}