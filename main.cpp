#include <iostream>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[]) {

    cout << "Linked List v1.0\n\n\n" ;
#if 1 
    LinkedList *list = new LinkedList();
    list->push_back(1, "AAAAA") ;
    list->push_back(2, "BBBBB") ;
    list->push_back(3, "CCCCC") ;
    list->push_back(4, "DDDDD") ;
    list->push_front(0, "FIRST") ;
    list->push_back(9, "LAST") ;
    list->dump();

    Node *n = list->find(9) ;
    cout << "\tSearch(9) -> " << n << endl;

    n = list->find("CCCCC") ;
    cout << "\tSearch(CCCCC) -> " << n << endl;

    n = (*list)[2] ;
    cout << "\tIndis(2) -> " << n << endl;

    
    cout << "\nTO_STRING:\n" << list->to_string() << endl ;
    cout << "\nTO_JSONSTRING:\n" << list->to_jsonstring() << endl ;
    cout << "\nTO_XMLSTRING:\n" << list->to_xmlstring() << endl ;

    delete list ;
#else

    LinkedList list ;

    list.push_back(1, "AAAAA") ;
    list.push_back(2, "BBBBB") ;
    list.push_back(3, "CCCCC") ;
    list.push_back(4, "DDDDD") ;
    list.push_front(0, "FIRST") ;
    list.push_back(9, "LAST") ;
    list.dump();

    Node *n = list.find(9) ;
    cout << "\tSearch(9) -> " << n << endl;

    n = list.find("CCCCC") ;
    cout << "\tSearch(CCCCC) -> " << n << endl;

    n = list[2] ;
    cout << "\tIndis(2) -> " << n << endl;

    
    cout << "\nTO_STRING:\n" << list.to_string() << endl ;
    cout << "\nTO_JSONSTRING:\n" << list.to_jsonstring() << endl ;
    cout << "\nTO_XMLSTRING:\n" << list.to_xmlstring() << endl ;

#endif
    cout << "--------FINISHED------\n";


    return EXIT_SUCCESS ;
} 