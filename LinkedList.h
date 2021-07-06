#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iomanip>

using namespace std ;

class Node {
private:
    int id;
    string name;
    Node *next;
    Node *prev;  
    friend class LinkedList; 
public:
    Node(int id, string name) ;
    int getIndex();
    int getId();
    string getName();
    string to_string();
    string to_jsonstring();
    string to_xmlstring();    
    friend ostream& operator<< (ostream &out, const Node *node) {
        if (!node){
            out << "<NULL>";
        }else {
            out << "0x" << std::setw(16) << std::setfill('0') <<  std::hex << (std::uintptr_t)&node->id
                << " \tid:" << node->id << "\tname:" << node->name 
                << "\tprev:" << "0x" << std::setw(16) << std::setfill('0') <<  std::hex << (std::uintptr_t)node->prev 
                << "\tnext: " <<  "0x" << std::setw(16) << std::setfill('0') <<  std::hex <<  (std::uintptr_t)node->next;
        }
        return out ;
    }
};

class LinkedList {
private:
    int mCount ;
    Node *head ;
    Node *tail ;
public:
    LinkedList();
    ~LinkedList();
    void push_front(int id, string name) ;
    void push_back(int id, string name) ;
    void pop_front() ;
    void pop_back() ;
    void deleteNode(Node *n) ;
    void clear();
    int size();
    Node* find(int id) ;
    Node* find(string name);
    void dump();
    Node* at(int i);
    
    Node* operator[] (int i);
    string to_string();
    string to_jsonstring();
    string to_xmlstring();       

};

#endif //  LINKEDLIST_H