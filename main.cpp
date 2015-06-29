#include <iostream>
#include "node.h"
using namespace std;

int main()
{
    shared_ptr<Node> root = make_shared<Node>(1);
    if(isRoot(*root))
        cout<<"This is a root node"<<endl;
    return 0;
}

