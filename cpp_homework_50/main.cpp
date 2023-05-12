#include <iostream>
using namespace std;

struct node{
    char data;
    node* next;
};

class List{
private:
    node* head;
    node* tail;
    int count;

public:
    List();
    ~List();

    void Add(char data);
    void AddToHead(char data);
    void Insert(char data, int index);

    void Delete();
    void DeleteByIndex(int index);
    void DeleteAll();

    int Search(char data);

    void Print();
    void Print(int index);
    void PrintHead();
    int GetCount();
};

List::List(){
    head = nullptr;
    tail = nullptr;
    count = 0;
}

List::~List(){
    DeleteAll();
}

int List::GetCount(){
    return count;
}

void List::Add(char data){
    node* temp = new node;

    temp->data = data;
    temp->next = nullptr;

    if (head != nullptr)
    {
        tail->next = temp;
        tail = temp;
    }
    else head = tail = temp;
    count++;
}

void List::AddToHead(char data){
    node* temp = head;
    head = new node;

    head->data = data;
    head->next = temp;
}

void List::Insert(char data, int index){
    if (index > count || index < 1) return;

    if (index == 1){
        node* temp = head;
        head = new node;

        head->data = data;
        head->next = temp;
    }
    else if (index == count){
        node* temp = tail;
        tail = new node;

        tail->data = data;
        tail->next = nullptr;

        temp->next = tail;
    }
    else{
        node* temp = head;
        for (int i = 1; i < index - 1; i++) temp = temp->next;

        node* prev = temp;
        node* next = temp->next;
        node* cur = new node;

        prev->next = cur;
        cur->data = data;
        cur->next = next;
    }
    count++;
}

void List::Delete(){
    node* temp = head;
    head = head->next;
    delete temp;
}

void List::DeleteByIndex(int index){
    if (index > count || index < 1) return;

    if (index == 1){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    else if (index == count){
        node* temp = head;
        for (int i = 1; i < count - 1; i++) temp = temp->next;
        tail = temp;
        delete tail->next;
        tail->next = nullptr;
    }
    else{
        node* temp = head;
        for (int i = 1; i < count - 1; i++) temp = temp->next;

        node* prev = temp;
        node* current = temp->next;
        node* next = current->next;

        prev->next = next;
        delete current;
    }
    count--;
}

void List::DeleteAll(){
    while (head != 0) Delete();
}

void List::Print(){
    for (node* temp = head; temp != nullptr; temp = temp->next) cout << temp->data << " ";
    cout << std::endl << std::endl;
}

void List::Print(int index){
    if (index > count || index < 1) return;
    node* temp = head;
    for (int i = 1; i < index; i++) temp = temp->next;
    cout << temp->data << "\n\n";
}

void List::PrintHead(){
    cout << head->data << "\n\n";
}

int List::Search(char data){
    node* temp = head;
    for (int i = 1; temp != nullptr; temp = temp->next, i++){
            if (temp->data == data){
                return i;
            }
        }
    return 0;
}

int main() {
    List list;
    list.Add('1');
    list.Add('2');
    list.Add('3');
    list.Add('4');
    list.Print();

    list.Insert('r', 3);
    list.Print();

    list.DeleteByIndex(5);
    list.Print();
    list.Print(2);
    list.PrintHead();

    list.AddToHead('M');
    list.Print();

    cout << list.Search('c') << "\n";
}
