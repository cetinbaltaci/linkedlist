#include <iostream>
#include <iomanip>

#include "LinkedList.h"
using namespace std;


#define TYPE_NAME(var) #var

///////////////////// Node ////////////////////
Node::Node(int id, string name) {
    this->id = id ;
    this->name = name ;
    prev = next = NULL ;
}

int Node::getId() {
    return id ;
}

string Node::getName() {
    return name ;
}

string Node::to_string() {
    stringstream ss; 
    ss << TYPE_NAME(id) << "=" << id << "\t" << TYPE_NAME(name) << "=" << name;
    return  ss.str();
}

string Node::to_jsonstring() {
    stringstream ss; 
    ss << "{" << "\n" 
        << "\t" << "\"" << TYPE_NAME(id) << "\"" << ": " << id << ",\n" 
        << "\t" << "\"" << TYPE_NAME(name) << "\"" << ": \"" << name <<"\"" << "\n"
        << "}";
    return  ss.str();
}

string Node::to_xmlstring() {
    stringstream ss; 
    ss << "<Node>\n" 
        << "<" << TYPE_NAME(id) << ">" << id << "</" << TYPE_NAME(id) << ">" << "\n" 
        << "<" << TYPE_NAME(name) << ">" << name << "</" << TYPE_NAME(name) << ">\n"  
        << "</Node>";
    return  ss.str();
}

///////////////////// LinkedList ////////////////////

LinkedList::LinkedList() {
    mCount = 0 ;
    head = tail = NULL ;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push_front(int id, string name) {
    Node *node = new Node(id, name);
    node->next = head ;
    if (head) head->prev = node ;
    head = node ;
    if ( !tail) tail = head;
    //cout << "push_front -> " << node << endl; 
    mCount++; 
}

void LinkedList::push_back(int id, string name) {
    Node *node = new Node(id, name);
    node->prev = tail ;
    if (tail) tail->next = node ;
    tail = node ;
    if (!head) head = tail;
    //cout << "push_back -> " << node << endl; 
    mCount++   ;
}

void LinkedList::pop_front() {
    Node *node = head;
    if (!node) return ;
    head = node->next ;

    if (head) 
        head->prev = NULL;
    else 
        tail = NULL;

    //cout << "pop_front-> " << node << endl;
    delete node ;
    mCount--;
}

void LinkedList::pop_back() {
    Node *node = tail;
    if (!node) return ;
    tail = node->prev ;
    if (tail) 
        tail->next = NULL ;
    else 
        head = NULL;
    //cout << "pop_back-> " << node << endl ;
    delete node ;
    mCount-- ;  
}

void LinkedList::deleteNode(Node *n) {
    if (n) {
        Node *next = n->next;
        Node *prev = n->prev;
        if (next == NULL && prev == NULL) {
            head = tail = NULL ;
        } else if (next == NULL && prev != NULL) {
            prev->next = NULL ;
            tail = prev ;
        } else if (next != NULL && prev == NULL) {
            next->prev = NULL ;
            head = next ;
        } else {
            prev->next = next ;
            next->prev = prev ;
        }
        delete n ;
    }    
}

void LinkedList::clear(){
    while(tail) {
        pop_back();
    }
}

int LinkedList::size(){
    return mCount;
}

Node *LinkedList::find(int id) {
    Node *node = head;
    while(node) {
        if (node->id == id) break ;
        node = node->next;
    }
    return node ;
}

Node *LinkedList::find(string name){
    Node *node = head;
    while(node) {
        if (node->name == name) break ;
        node = node->next;
    }
    return node ;
}

void LinkedList::dump() {
    Node *tmp = head ;
    cout << "Linked list dump:\n" ;
    if (!tmp) 
        cout << "\tEmpty List\n" ;
    else {
        cout << "\tCount: " << mCount << endl ;
        while(tmp != NULL) {
            cout << "\t\t" << tmp << endl ;
            tmp = tmp->next ;
        } 
    }
}

Node* LinkedList::at(int i) {
    Node *tmp = NULL;
    if (i < mCount && i > 0 ){
       for(tmp = head; tmp && i > 0 ; i--, tmp = tmp->next);
    } 

    return tmp;  
}

Node* LinkedList::operator[] (int i)  {
    return at(i);
}

string LinkedList::to_string() {
    stringstream ss ;
    Node *tmp = head ;

    while(tmp != NULL) {
        ss <<  tmp->to_string() << endl ;
        tmp = tmp->next ;
    } 
    return ss.str();
}

string LinkedList::to_jsonstring() {
    stringstream ss ;
    Node *tmp = head ;
    ss << "{\"linkedList\":[" << endl ;
    while(tmp != NULL) {
        ss << tmp->to_jsonstring() ;
        tmp = tmp->next ;
        if (tmp != NULL)
            ss << ","  ;
        ss << endl ;
    }
    ss << "]}" << endl ;
    return ss.str();
}

string LinkedList::to_xmlstring() {
    stringstream ss ;
    Node *tmp = head ;
    ss << "<linkedList>" << endl ;
    while(tmp != NULL) {
        ss << tmp->to_xmlstring() <<  endl ;
        tmp = tmp->next ;
    }
    ss << "</linkedList>" << endl ;
    return ss.str();
}

