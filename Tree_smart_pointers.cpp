#include <iostream>
#include <memory>
#include <utility>
#include <stack>
#include <queue>

struct Node {
    int data;
    std::unique_ptr<Node> left = nullptr;
    std::unique_ptr<Node> right = nullptr;

    Node(const int& x, std::unique_ptr<Node>&& p = nullptr, std::unique_ptr<Node>&& q = nullptr) :
        data(x),
        left(std::move(p)),
        right(std::move(q)) {}
};
std::unique_ptr<Node> root = nullptr;

void insert(std::unique_ptr<Node>& root, const int& theData) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(theData);

    if (root == nullptr) {
        root = std::move(newNode);
        return;
    }
    else if (theData < root->data) {
        insert(root->left, theData);
    }
    else {
        insert(root->right, theData);
    }
}



void DFS(std::unique_ptr<Node>& root)
{
    if (!root)
        return;

    std::stack<const std::unique_ptr<Node> *> s;
    s.push(&root);

    while (!s.empty())
    {
        auto pp = s.top();
        s.pop();

        if ((*pp)->right)
            s.push(&(*pp)->right);

        if ((*pp)->left)
            s.push(&(*pp)->left);

        std::cout << (*pp)->data << ' ';
    }
}

void populate()
{
    insert(root, 100);
    insert(root, 200);
    insert(root, 300);
    insert(root, 400);
    insert(root, 500);
}
int main() {

    populate();
    DFS(root);
    std::cout << "\n";

    std::cin.get();
}
