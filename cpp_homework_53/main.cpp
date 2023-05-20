#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

static int a;
using namespace std;


struct Node
{
    char fullName[50];
    double average;

    Node* Parent;
    Node* Left;
    Node* Right;

    char* GetFullName();
    double GetAverage();
};

class Tree
{
    Node* Root;
    unsigned int Size;
public:
    Tree();
    ~Tree();

    Node* GetRoot() const;
    void Insert(Node* el);
    Node* Max(Node* el) const;
    Node* Min(Node* el) const;
    Node* Next(const Node* el) const;
    Node* Previous(const Node* el) const;
    void Print(const Node* el) const;
    void Remove(Node* el);
    Node* Search(Node* el, const char* key) const;
};

void Insert(Tree& tree);
void Print(const Tree& tree);
void PrintMenu();
void Remove(Tree& tree);
void Search(const Tree& tree);

int main()
{
    cout << a;

    Tree tree;

    bool exit = false;

    for (;;)
    {
        PrintMenu();

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            Insert(tree);
            break;
        case 2:
            Remove(tree);
            break;
        case 3:
            Print(tree);
            break;
        case 4:
            Search(tree);
            break;
        case 5:
            exit = true;
            break;
        }

        if (exit)
        {
            break;
        }
    }

    return 0;
}

char* Node::GetFullName()
{
    return fullName;
}

double Node::GetAverage()
{
    return average;
}

Tree::Tree() : Root(nullptr), Size(0U)
{
}

Tree::~Tree()
{
    while (Root != nullptr)
        Remove(Root);
}

Node* Tree::GetRoot() const
{
    return Root;
}

void Tree::Insert(Node* newNode)
{
    newNode->Left = nullptr;
    newNode->Right = nullptr;

    Node* el = Root;
    Node* temp = nullptr;

    while (el != nullptr)
    {
        temp = el;

        if (strcmp(newNode->fullName, el->fullName) < 0)
        {
            el = el->Left;

        }
        else
        {
            el = el->Right;
        }
    }

    newNode->Parent = temp;

    if (temp == nullptr)
    {
        Root = newNode;
    }
    else if (strcmp(newNode->fullName, temp->fullName) < 0)
    {
        temp->Left = newNode;
    }
    else
    {
        temp->Right = newNode;
    }

    ++Size;
}

Node* Tree::Max(Node* el) const
{
    if (el != nullptr)
    {
        while (el->Right != nullptr)
        {
            el = el->Right;
        }
    }

    return el;
}

Node* Tree::Min(Node* el) const
{
    if (el != nullptr)
    {
        while (el->Left != nullptr)
        {
            el = el->Left;
        }
    }

    return el;
}

Node* Tree::Next(const Node* el) const
{
    Node* next = nullptr;

    if (el != nullptr)
    {
        if (el->Right != nullptr)
        {
            next = Min(el->Right);
        }
        else
        {
            next = el->Parent;

            while (next != nullptr && el == next->Right)
            {
                el = next;
                next = next->Parent;
            }
        }
    }

    return next;
}

Node* Tree::Previous(const Node* el) const
{
    Node* previous = nullptr;

    if (el != nullptr)
    {
        if (el->Left != nullptr)
        {
            previous = Max(el->Left);
        }
        else
        {
            previous = el->Parent;

            while (previous != nullptr && el == previous->Left)
            {
                el = previous;
                previous = previous->Parent;
            }
        }
    }

    return previous;
}

void Tree::Print(const Node* el) const
{
    if (el != nullptr)
    {
        Print(el->Left);

        cout << el->fullName << '\t' << el->average << endl;

        Print(el->Right);
    }
}

void Tree::Remove(Node* removeNode)
{
    if (removeNode != nullptr)
    {
        Node* el = nullptr;
        Node* temp = nullptr;

        if (removeNode->Left == nullptr || removeNode->Right == nullptr)
        {
            temp = removeNode;
        }
        else
        {
            temp = Next(removeNode);
        }

        if (temp->Left != nullptr)
        {
            el = temp->Left;
        }
        else
        {
            el = temp->Right;
        }

        if (el != nullptr)
        {
            el->Parent = temp->Parent;
        }

        if (temp->Parent == nullptr)
        {
            Root = el;
        }

        else if (temp == temp->Parent->Left)
        {
            temp->Parent->Left = el;
        }

        else
        {
            temp->Parent->Right = el;
        }

        if (temp != removeNode)
        {
            strcpy(removeNode->fullName, temp->fullName);
            removeNode->average = temp->average;
        }

        delete temp;

        --Size;
    }
}

Node* Tree::Search(Node* el, const char* key) const
{
    while (el != nullptr && strcmp(key, el->fullName) != 0)
    {
        if (strcmp(key, el->fullName) < 0)
        {
            el = el->Left;
        }
        else
        {
            el = el->Right;
        }
    }
    return el;
}

void Insert(Tree& tree)
{
    cout << "Enter a quantity of Nodeents to add: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i)
    {
        Node* temp = new Node;

        cout << endl << "Enter a fullname " << i + 1 << endl;
        cin >> temp->GetFullName();

        cout << endl << "Enter an average " << i + 1 << endl;
        cin >> temp->average;

        tree.Insert(temp);
    }
}

void Print(const Tree& tree)
{
    tree.Print(tree.GetRoot());
}

void PrintMenu()
{
    char menu[] = "1. Insert Node\n2. Remove Node\n3. Print Node\n4. Search Node\n5. Exit\n";

    cout << menu;
}

void Remove(Tree& tree)
{
    cout << "Enter an fullname to remove:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{
    cout << "Enter a fullname to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        cout << node->GetAverage();
    }
    else
    {
        cout << "Name not found" << endl;
    }
}
