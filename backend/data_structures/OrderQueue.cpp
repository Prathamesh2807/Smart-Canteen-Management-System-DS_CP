#include <iostream>
#include <iomanip>
#include "OrderQueue.h"

using namespace std ;


OrderQueue::Node::Node(int  id , string student , string item , int qty , double price){
    this->orderId = id ;
    this->studentName = student ;
    this->itemName = item ;
    this->quantity = qty;
    this->totalPrice = price ;
    next = NULL;

}

OrderQueue::OrderQueue(){
    front = NULL;
    rear = NULL;
}

// add order at rear 
void OrderQueue::enqueue(int orderId , string studentName , string itemName , int quantity , double totalPrice){
    Node* newNode = new Node(orderId , studentName , itemName , quantity , totalPrice);

    if(rear == NULL){
        front = rear = newNode ;
        return ;
    }

    // add at rear
    rear->next = newNode ;
    rear = newNode ;
}

//remove order
void OrderQueue::dequeue(){
    if(front == NULL){
        cout<<"order queue is empty "<<endl;
        return ;
    }

    Node* temp = front ;
    cout << "\n processing order id :"<<temp->orderId<<endl;
    cout<<"student : "<<temp->studentName<<endl;

    front = front->next ;

    if(front == NULL){
        rear = NULL;
    }
    delete temp ;
}



void OrderQueue::peek(){
    if(front==NULL){
        cout<<"order queue is empty"<<endl;
        return ;
    }

    cout << "\n========== NEXT ORDER ==========\n";
    cout << "Order ID     : " << front->orderId << endl;
    cout << "Student      : " << front->studentName << endl;
    cout << "Item         : " << front->itemName << endl;
    cout << "Quantity     : " << front->quantity << endl;
    cout << "Total Price  : Rs." << front->totalPrice << endl;
    cout << "================================\n";
}


void OrderQueue::displayOrders(){
    if(front == NULL){
        cout<< "dont have any order yet "<<endl;
        return ;
    }

    Node* temp = front ;
    
     cout << "\n========================= ORDER QUEUE =========================\n";

    cout << left
         << setw(10) << "Order ID"
         << setw(20) << "Student"
         << setw(22) << "Item"
         << setw(10) << "Qty"
         << "Total" << endl;

    cout << "---------------------------------------------------------------\n";


    while(temp !=NULL){
        cout << left
             << setw(10) << temp->orderId
             << setw(20) << temp->studentName
             << setw(22) << temp->itemName
             << setw(10) << temp->quantity
             << "Rs." << temp->totalPrice << endl;

        temp = temp->next;
    }

    cout << "===============================================================\n";

}


bool OrderQueue::isEmpty(){
    return front == NULL;
}