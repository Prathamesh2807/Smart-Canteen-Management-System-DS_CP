#ifndef Menu_Linked_List_H
#define Menu_Linked_List_H

#include <iostream>
#include <string>
using namespace std ;

class MenuLinkedList{
    private : 
    struct Node{
        int id ;
        string name ;
        string category ;
        double price  ;
        Node* next ;
        Node(int id , string n ,string c ,double p);

    };

    Node* head ;

    
    public :
    MenuLinkedList();

    void insert(int id,string name , string category , double price);
    void deleteItem(int id);
    void updateItem(int id, string name, string category, double price);
    void searchItem(int id);
    void displayMenu();

};

#endif