#ifndef Order_Queue_H
#define Order_Queue_H
#include <iostream>
#include <string>
using namespace std ;

class OrderQueue{
    private :
        struct Node {
            int orderId ;
            string studentName ;
            string itemName;
            int quantity;
            double totalPrice ;
            Node* next ;
            Node(int id , string student , string item , int qty , double price);

        };

        Node* front ;
        Node* rear ;

        public :

        OrderQueue();

        void enqueue(int orderId , string studentName , string itemName , int quantity , double totalPrice);

        void dequeue();

        void peek();

        void displayOrders();

        bool isEmpty();
};

#endif


