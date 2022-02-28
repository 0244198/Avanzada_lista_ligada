#include <iostream>

using namespace std;

class Alumno{
    public:
        string Nombre;
        string Carrera;
        string Id;
        int Semestre;
        Alumno(string nombre, string carrera, string id, int semestre) {
            Nombre = nombre;
            Carrera = carrera;
            Id = id;
            Semestre = semestre;
        }
};

class Node{
    public:
        Node *Next;
        Alumno Alumno;
        Node(class Alumno alumno, Node *next_item = nullptr) : Alumno(alumno) {
            Alumno = alumno;
            Next = next_item;
        }
};

class Lista{
    public:
        Node *Head;
        Node *Last;
        int Tamano;
        Lista(class Node *head){
            Head = head;
            Last = head;
            Tamano = 1;

        }

        void AgregarNodo(class Node *nodo){
            Last -> Next = nodo;
            Last = nodo;
            Tamano += 1;
        }

        void imprimir(){
            Node *ptr = Head;
            bool start = true;
            while(start){
                cout << (*ptr).Alumno.Nombre << " ";
                cout << (*ptr).Alumno.Id << " ";
                cout << (*ptr).Alumno.Carrera << " ";
                cout << (*ptr).Alumno.Semestre << "\n";
                if(ptr->Next == nullptr){
                    start = false;
                }
                else{
                    ptr = ptr->Next;
                }
            }
        }

//        void eliminarNodo(int numero){
//            Node *ptr = Head;
//            Node *nodo_previo = nullptr;
//            Node *nodo_posterior;
//
//            for(int i = 1; i < Tamano+1; i++){
//                if(i != 1){
//                    ptr = ptr->Next;
//                }
//                if(i == (numero-1)){
//                    nodo_previo = ptr;
//                }
//                else if (i == (numero+1)){
//                    nodo_posterior = ptr;
//                }
//            }
//            nodo_previo->Next = nodo_posterior;
//        }
};

void ingresar_alumnos(int num_alumnos){
    Alumno *alumno = new Alumno("Miggers", "ISGC", "0244198",3);
    Node *node = new Node(*alumno);
    Lista *lista = new Lista(node);
    Lista prueba = *lista;
    string nombre, carrera, id;
    int semestre;
    for (int i = 0; i < 2; i++){
        cin >> nombre >> carrera >> id >> semestre;
        prueba.AgregarNodo(new Node(Alumno(nombre,carrera,id,semestre)));
    }
    prueba.imprimir();
}


int main() {
//    Alumno *ptr  = (Alumno*)malloc(sizeof(Alumno));
//    *ptr = Alumno("Miguel", "ISGC", "0244198", 3);
    ingresar_alumnos(5);
}