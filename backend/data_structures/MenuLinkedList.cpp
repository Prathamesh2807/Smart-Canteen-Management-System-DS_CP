#include <iostream>
#include "MenuLinkedList.h"
#include <iomanip>
using namespace std;

MenuLinkedList::Node::Node(int id, string name, string category, double price){
    this->id = id;
    this->name = name ;
    this->category = category;
    this->price = price ;
    this->next = NULL;
}

MenuLinkedList::MenuLinkedList(){
    head = NULL;
}


void MenuLinkedList::insert(int id, string name, string category, double price){
    Node* newNode = new Node(id,name,category,price);

    if(head == NULL){
        head = newNode;
        return ;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = newNode ;
}



void MenuLinkedList::deleteItem(int id){
    if(head == NULL){
        cout<<"Menu is empty"<<endl;
        return ;
    }
    if(head->id == id){
        Node* temp = head ;
        head = head->next ;
        delete temp ;

        cout<<"deleted the item"<<endl;
        return ;
    }
    Node* temp = head ;
    while(temp->next != NULL && temp->next->id != id){
        temp = temp->next ;
    }
    if(temp->next ==NULL){
        cout<<"item not found"<<endl;
        return ;
    }
    Node* deleteNode = temp->next ;
    temp->next = deleteNode->next ;
    delete deleteNode;

    cout<<"item deleted succesfully"<<endl;

}


void MenuLinkedList::updateItem(int id, string name, string category, double price){
    Node* temp = head ;

    while(temp != NULL){
        if(temp->id == id){
            temp->name = name ;
            temp->category = category;
            temp->price = price ;

            cout<<"your item  is now updated"<<endl;
            return ;
        }
        temp = temp->next; 
    }
    cout<<"items not found"<<endl;
}


void MenuLinkedList::searchItem(int id){
    Node* temp = head ;
    while(temp != NULL){
        if(temp->id == id){
            cout << "\nItem Found" << endl;
            cout << "ID       : " << temp->id << endl;
            cout << "Name     : " << temp->name << endl;
            cout << "Category : " << temp->category << endl;
            cout << "Price    : Rs." << temp->price << endl;
            return ;
        }
        temp = temp->next ;
    }
    cout<<"items not found "<<endl;
}


void MenuLinkedList::displayMenu()
{
    if (head == NULL)
    {
        cout << "Menu is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "\n==================== CANTEEN MENU ====================\n";
    cout << left
         << setw(5)<<"ID"
         << setw(25)<<"Item"
         << setw(20) << "Category"
         << setw(10) << "Price" << endl;


    cout << "-------------------------------------------------------\n";

    while (temp != NULL)
    {
        cout << left
             << setw(5) << temp->id
             << setw(25) << temp->name
             << setw(20) << temp->category
             << "Rs." << temp->price << endl;

        temp = temp->next;
    }

    cout << "=======================================================\n";
}

