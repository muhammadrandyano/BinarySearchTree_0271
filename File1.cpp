#include <iostream>
using namespace std;

class Node {
    public:
    int info;
    Node *leftchild;
    Node *rightchild;

    // Constructor for the node class
    Node()
    {
        info = 0;
        leftchild = nullptr; // Initialize left child to null
        rightchild = nullptr; // Initialize right child to null
    }
};

class BinaryTree
{
public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // Initialize root to null
    }

    void insert()
    {
        int x;
        cout << "Masukan nilai: ";
        cin >> x;

        // step 1: Allocate memory for a new node
        Node *newNode = new Node();

        // step 2: Assign value to the data field of the new node
        newNode->info = x;

        // step 3: Make the left and right child of the new node point to null
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        // step 4: Locate the node which will be the parent of the node to be inserted
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);
        
        //step 5: if parent is NULL (Tree is empty)
        if (parent == nullptr)
        {
            // 5a: mark the new node as root
            ROOT = newNode;

            // 5b: Exit
            return;
        }

        // tep 6: if the value in the data field of new node is less than that of parent
        if (x < parent->info)
        {
            // 6a: make the left child of parent point to new node
            parent->leftchild = newNode;

            // 6b: Exit
            return;
        }
        // step 7: if the value in the data field of the new node is greater than that of the parent 
        else if (x > parent->info)
        {
            // 7a: make the right child of parent point to new node
            parent->rightchild = newNode;

            // 7b: Exit
            return;
        }

    }

    void search(int element, Node *&parent, Node *&currentNode)
    {
    //this function searches the currenNode of the specified Node as well as the current Node of its parent
    currentNode = ROOT;
    parent = nullptr;
    while ((currentNode != nullptr) && (currentNode->info != element))
    {
        parent = currentNode;
        if (element < currentNode->info)
            currentNode = currentNode->leftchild;
        else
            currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;
            
        inorder(ptr->leftchild); // Traverse left subtree
        cout << ptr->info << " "; // Visit node
        inorder(ptr->rightchild); // Traverse right subtree
    }

       void preorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;
        
        cout << ptr->info << " "; // Visit node
        inorder(ptr->leftchild); // Traverse left subtree
        inorder(ptr->rightchild); // Traverse right subtree
    }


        void postorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;
        
     
        inorder(ptr->leftchild); // Traverse left subtree
        inorder(ptr->rightchild); // Traverse right subtree
        cout << ptr->info << " "; // Visit node
    }

    bool isEmpty()
    {
        return ROOT == nullptr; // Check if the root is null
    }
};


int main()
{
BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}