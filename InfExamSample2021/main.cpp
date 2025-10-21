#include <iostream>
#include "book.h"
#include "library.h"
int main() {
    Book b1("J.R.R. Tolkien", "A Gyuruk Ura", 1954, 456);
    Book b2("Jokai Mor", "Egri csillagok", 1980, 300);
    Book b3("Jokai Mor", "A koszivu ember fiai", 1967, 400);
    Book b4("Murakami Haruki", "Sotetedes utan", 2004, 250);
    Book b5("Murakami Haruki", "A norveg erdo", 1987, 420);
    Book b6("Murakami Haruki", "1Q84", 1987, 800);
    Book b7("Knausgard Karl Ove", "Harcom", 2009, 1000);
    Library l("Konyvtar");
    l.addBook(b1);
    l.addBook(b2);
    l.addBook(b3);
    l.addBook(b4);
    l.addBook(b5);
    l.addBook(b6);
    l.addBook(b7);
    l.printbooks();
    try {
        cout<<"A keresett konyv:" << l.findBook("Stetedes") << endl;
    }catch(invalid_argument i){
        i.what();
    }
    cout<<"Murakami konyveinek szama:"<<l.countBook("Murakami")<<endl;
    l.sortBooks();
    l.printbooks();
    l.removeBook(b2);
    return 0;
}
