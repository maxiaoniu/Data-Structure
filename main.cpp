#include <iostream>
#include "binarysearchtree.h"
using namespace std;

int main()
{
    BinarySearchTree bst;
    bst.insert(3);
    bst.insert(2);
    bst.insert(4);
    cout<<"The size of the tree is: "<<bst.size();
    return 0;
}

