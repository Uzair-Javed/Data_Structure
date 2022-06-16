#include <iostream>
#include <memory>
class Node
{
    int value;
    public:
    std::shared_ptr<Node> leftPtr;
    std::shared_ptr<Node> rightPtr;
    Node(int val) : value(val) {
         
    }
    ~Node() {
       
    }
};
int main()
{
    std::shared_ptr<Node> ptr = std::make_shared<Node>(100);
    ptr->leftPtr = std::make_shared<Node>(200);
    ptr->rightPtr = std::make_shared<Node>(300);
    return 0;
}
