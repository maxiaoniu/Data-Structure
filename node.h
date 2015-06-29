#ifndef NODE_H
#define NODE_H

#include <memory>
class Node
{
public:
    int data;
    std::shared_ptr<Node> lc;
    std::shared_ptr<Node> rc;
    std::weak_ptr<Node> parent;
    Node(int data);
    ~Node();
};

//some functions to detect node
#define isRoot(x) !((x).parent.lock()) //x should be have (x) because if (*x)
#define hasParent(x) ((x).parent)
#define hasLChild(x) ((x).lc)
#define hasRChild(x) ((x).rc)
#define hasChild(x)  (hasLChild(x) || hasRChild(x))
#define hasBothChild(x) (hasLChild(x) && hasRChild(x))
#define isLeaf(x) (!hasChild(x))
#endif // NODE_H
