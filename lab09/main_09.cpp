#include <iostream>
#include "Directory.h"

int main() {
    Directory root("root");

    Directory document("document");
    root+=document;
    root.display(2);

    return 0;
}