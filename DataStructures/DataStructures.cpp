/*
Starting the class structure given in the previous slides

Implement the push_back function:
void push_back (const int &value) {...}
Implement the insert function:
void insert (unsigned int position, const int &value) {...}
Implement the print function. It prints the whole list from beginning to end:
void print () {...}
From the main function, insert 5 elements in different positions and print the whole list after each insertion

*/

#include <iostream>
using namespace std;

// Declaration of a doubly-linked list
class List {
private:
    // struct interna para los nodos, como se van a enlazar los elementos que le damos durante el programa
    struct Node {
        int value;
        Node* next;
        Node* prev;
    };

    // Atributos de la clase
    Node* first = nullptr; // puntero al primer nodo de la lista
    Node* last = nullptr; // puntero al último nodo de la lista 
    unsigned int num_elems = 0; // número de elementos en la lista, luego este va a ir augmentando

public:
	// Constructor and destructor
	//List();
    ~List() {
        clear();
    };

    //Funciones de inserción
    
    void push_front(const int& value) // poner delante 
    {
        if (num_elems == 0) //Si la lista está vacía:
        {
            first = last = new Node; // tanto el primero como el ultimo apuntan al nuevo nodo
            first->value = value;
            first->prev = nullptr;
            first->next = nullptr;
        }
        else //si la lista contene elementos:
        {
            Node* node = new Node; //creamos nuevo nodo donde va a ir la información delante de la que había
            node->value = value;
            node->prev = nullptr;
            node->next = first; //organizamos el nodo que tendra elemento
            first->prev = node; // ahora prev apunta al nodo anterior
            first = node; // ahora first apunta al nuevo nodo
        }
        num_elems++; // incrementamos elemento para que se pueda sumar una siguiente oeración
    }
    
    void push_back(const int& value) { // poner atras

        if (num_elems == 0) // si la lista está vacía
        { 
            first = last = new Node;
            first->value = value;
            first->prev = nullptr;
            first->next = nullptr;
        }
        else // si la lista contiene elementos
        {
            Node* node = new Node; // creamos un nuevo nodo donde va a ir la información 
            node->value = value;
            node->prev = last; //organizamos el nodo que tendra elemento
            node->next = nullptr;
            last->next = node; // ahora es el ultimo nodo es el nuevo nodo
            last = node; // aqui el puntero last apunta al nuevo nodo
        }
        num_elems++; //incrementamos elemento para que se pueda sumar una siguiente oeración
    }

    //inserta un nuevo nodo en una posición específica

    void insert(unsigned int position, const int& value) {
        
        if (position > num_elems) {
            cout << "Invalid position! Cannot insert.\n";
            return;
        }
        if (position == 0) //si la posición es 0 llama a la funcion para escribir delante
        {
            push_front(value);
            return;
        }
        if (position == num_elems) // si el numero es igual a elementos que ya hay llama a la funcion de escribir detras
        {
            push_back(value);
            return;
        }
        // se actualizan los punteros del nodo anterior y del nodo actual para incluir el nuevo nodo
        Node* current = first;
        for (unsigned int i = 0; i < position; i++) {
            current = current->next;
        }

        Node* node = new Node{ value, current, current->prev };
        current->prev->next = node;
        current->prev = node;
        num_elems++;
    }

    // funcion para imprimir
    void print() const {
        Node* current = first;
        cout << "[";
        while (current != nullptr)// recorre la lista desde el primer nodo (first) al ultimo (nullptr)
        {
            cout << current->value;// imprime el valor de cada nodo
            if (current->next != nullptr) cout << ", ";
            current = current->next;
        }
        cout << "]\n";
    }

    // función de limpieza
    void clear() {
        while (first != nullptr) // recorre la lista desde el primer nodo (first) al ultimo (nullptr)
        {
            Node* temp = first;
            first = first->next;
            delete temp;// elimina cada uno de los nodos uno por uno
        }
        first = last = nullptr; // reinicia los punteros
        num_elems = 0; // pone el contador a 0
    }
};



int main() {
    List list;

    // Insertar 5 elementos en diferentes posiciones
    list.push_back(10);
    cout << "After push_back(10): ";
    list.print();

    list.push_back(20);
    cout << "After push_back(20): ";
    list.print();

    list.insert(1, 15);  // Insertar en la posición 1
    cout << "After insert(1, 15): ";
    list.print();

    list.insert(0, 5);   // Insertar al principio
    cout << "After insert(0, 5): ";
    list.print();

    list.insert(4, 25);  // Insertar al final
    cout << "After insert(4, 25): ";
    list.print();

    return 0;
}


