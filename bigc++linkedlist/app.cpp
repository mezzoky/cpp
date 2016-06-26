#include <cstdio>
#include <string>
#include <iostream>
#include "linkedlist.cpp"
using namespace std;


template <class Any>
void iter_print(List<Any>& items);
List<string> init();
List<int> init_int();


template <class Any>
void iter_print(List<Any>& items) {
    Iterator<Any> iter = items.begin();
    cout << "======\n";
    for (; !iter.equals(items.end()); iter.next()) {
        cout << iter.get() << endl;
    }
    cout << "======\n";
}


List<string> init() {
    List<string> items;
    items.push_back("item A");
    items.push_back("item B");
    items.push_back("item C");
    items.push_back("item D");
    iter_print(items);
    return items;
}


List<int> init_int() {
    List<int> items;
    items.push_back(123);
    items.push_back(321);
    items.push_back(555);
    items.push_back(111);
    iter_print(items);    
    items.clear();
    items.push_back(222);
    items.push_back(111);
    iter_print(items);
    items.clear();
    items.push_back(111);
    items.push_back(222);
    items.push_back(333);
    Iterator<int> iter = items.begin();
    iter.next().next().next();
    items.insert(iter, 555);
    items.insert(iter, 999);
    iter_print(items);
    return items;
} 


int main() {
    freopen("app.log", "w", stdout);
    List<string> items = init();
    List<int> item2s = init_int();
    return 0;
}
