/* Linked list 
   @laffeyyfrederica & @greezed ver.
*/
#include <iostream>
using namespace std;

template <typename T, typename N>
struct Node {
    Node<T, N>* next;
    Node<T, N>* prev;
    T value;
    N name;
};

template <typename T, typename N>
int length(Node<T, N>* head) {
    Node<T, N>* current_node = head;

    int l{0};
    do {
        l++;
        current_node = current_node->next;
    } while (current_node != nullptr);

    return l;
}

// add to the end of `head`
template <typename T, typename N>
void addNode(T value, Node<T, N>* head) {
    Node<T, N>* current_node = head;
    Node<T, N>* new_node = new Node<T, N>();

    while (current_node->next != nullptr) current_node = current_node->next;
    
    current_node->next = new_node;
    new_node->value = value;
    new_node->next = nullptr;
    new_node->prev = current_node;
}

// add to the end of `head` with non-null `name`
template <typename T, typename N>
void addNode(T value, Node<T, N>* head, N name) {
    Node<T, N>* current_node = head;
    Node<T, N>* new_node = new Node<T, N>();

    while (current_node->next != nullptr) current_node = current_node->next;
    
    current_node->next = new_node;
    new_node->value = value;
    new_node->name = name;
    new_node->next = nullptr;
    new_node->prev = current_node;
}

// some guy wanted to overload a function called addNode but its functionality is actually to 
// MERGE THE FUCKING NODES. goddamnit.
// now its called `mergeNode`
// the 2nd args will be the head while the 1st args will follow
template <typename T, typename N>
void mergeNode(Node<T, N>* merge, Node<T, N>* head, bool name = false) {

    // displayIterator(merge);
    // displayIterator(head);

    if (name) addNode(merge->value, head, N(merge->name));
    else addNode(merge->value, head);
    
    // displayIterator(head);
}

// insert node before `search`
template <typename T, typename N>
void insertNode(T value, T search, Node<T, N>* head) {
    Node<T, N>* current_node = head;
    Node<T, N>* new_node = new Node<T, N>();

    while (current_node->value != search) current_node = current_node->next;
    
    new_node->value = value;

    // JUJUR JANGGAL (@laffeyyfrederica)
    // current_node->prev->next = current_node->next->prev;

    current_node->prev->next = new_node;
    new_node->next = current_node;
    new_node->prev = current_node->prev;
    current_node->prev = new_node;
}

// insert node before `search` with non-null `name`
template <typename T, typename N>
void insertNode(T value, string search, Node<T, N>* head, N name) {
    Node<T, N>* current_node = head;
    Node<T, N>* new_node = new Node<T, N>();

    while (current_node->name != search) current_node = current_node->next;
    
    new_node->value = value;

    // JUJUR JANGGAL (@laffeyyfrederica)
    // current_node->prev->next = current_node->next->prev;

    // 👅👅👅👅, chris suka ini
    current_node->prev->next = new_node;
    new_node->next = current_node;
    new_node->name = name;
    new_node->prev = current_node->prev;
    current_node->prev = new_node;
}

template <typename T, typename N>
void deleteNode(T value, Node<T, N>* head) {
    Node<T, N>* current_node = head;

    while (current_node->value != value) current_node = current_node->next;

    Node<T, N>* prev = current_node->prev;
    Node<T, N>* next = current_node->next;

    if (prev == nullptr) return;
    prev->next = next; 
    if (next == nullptr) return;
    next->prev = prev;
}

// delete the node at `search`
// delete node by name
template <typename T, typename N>
void deleteNode(N search, Node<T, N>* head) {
    Node<T, N>* current_node = head;

    while (current_node->name != search) current_node = current_node->next;

    Node<T, N>* prev = current_node->prev;
    Node<T, N>* next = current_node->next;

    if (prev == nullptr) return;
    prev->next = next; 
    if (next == nullptr) return;
    next->prev = prev;
}

template <typename T, typename N>
void display(Node<T, N>* head) {
    Node<T, N>* current_node = head;
    do {
        cout << current_node->value << " ";
        current_node = current_node->next;
    } while (current_node != nullptr);
}

template <typename T, typename N>
void displayIterator(Node<T, N>* head) {
    Node<T, N>* current_node = head;
    do {
        cout << current_node->name << " : ";
        for (auto a : current_node->value)
            cout << a << " ";
        // cout << "\n";
        current_node = current_node->next;
    } while (current_node != nullptr);

    cout << "\n";
}