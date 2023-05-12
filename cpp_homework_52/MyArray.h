#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray {
    T* array;
    int count;
public:
    MyArray();
    MyArray(int size);
    MyArray(const MyArray<T>& ar);

    void Input();
    void Print();
    void Add(T el);
    void Delete();
    
    int GetSize()const;

    MyArray<T>& operator++();
    MyArray<T>& operator--();
    MyArray<T> operator++(int);
    MyArray<T> operator--(int);

    MyArray<T> operator+(int n);
    MyArray<T> operator+(const MyArray<T>& obj);
    MyArray<T> operator-(int n);

    MyArray<T>& operator=(const MyArray<T>& obj);
    T& operator[](int index);
    T operator[](int index)const;

    ~MyArray();
};

template<class T>
MyArray<T>::MyArray(){
    array = nullptr;
    count = 0;
}

template<class T>
MyArray<T>::MyArray(int size){
    count = size;
    array = new T[count];
}

template<class T>
MyArray<T>::MyArray(const MyArray<T>& obj){
    count = obj.count;
    array = new T[count];
    for (int i = 0; i < count; i++)
    {
        array[i] = obj.array[i];
    }
}

template<class T>
void MyArray<T>::Input(){
    for (int i = 0; i < count; i++)
    {
        array[i] = rand() % 100;
    }
}

template<class T>
void MyArray<T>::Print(){
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

template<class T>
void MyArray<T>::Add(T el){
    T* tmp = new T[++count];
    for (int i = 0; i < count - 1; i++)
    {
        tmp[i] = array[i];
    }
    tmp[count - 1] = el;

    delete[] array;
    array = tmp;
}

template<class T>
void MyArray<T>::Delete(){
    T* tmp = new T[--count];
    for (int i = 0; i < count; i++)
    {
        tmp[i] = array[i];
    }

    delete[] array;
    array = tmp;
}

template<class T>
MyArray<T>& MyArray<T>::operator++(){
    T* tmp = new T[++count];
    for (int i = 0; i < count - 1; i++)
    {
        tmp[i] = array[i];
    }
    tmp[count - 1] = 0;

    delete[] array;
    array = tmp;

    return *this;
}

template<class T>
MyArray<T>& MyArray<T>::operator--(){
    T* tmp = new T[--count];
    for (int i = 0; i < count; i++)
    {
        tmp[i] = array[i];
    }

    delete[] array;
    array = tmp;

    return *this;
}

template<class T>
MyArray<T> MyArray<T>::operator++(int){
    MyArray obj(*this);

    T* tmp = new T[++count];
    for (int i = 0; i < count - 1; i++)
    {
        tmp[i] = array[i];
    }
    tmp[count - 1] = 0;

    delete[] array;
    array = tmp;

    return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator--(int){
    MyArray obj(*this);

    T* tmp = new T[--count];
    for (int i = 0; i < count; i++)
    {
        tmp[i] = array[i];
    }

    delete[] array;
    array = tmp;

    return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator+(int n){
    MyArray<T> obj(count + n);

    for (int i = 0; i < count; i++)
    {
        obj.array[i] = array[i];
    }
    for (int i = count; i < obj.count; i++)
    {
        obj.array[i] = 0;
    }
    return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right){
    MyArray<T> obj(count + right.count);

    for (int i = 0; i < count; i++)
    {
        obj.array[i] = array[i];
    }
    for (int i = count, j = 0; i < obj.count; i++, j++)
    {
        obj.array[i] = right.array[j];
    }
    return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator-(int n){
    if (count - n < 1)
        return MyArray<T>();

    MyArray<T> obj(count - n);

    for (int i = 0; i < obj.count; i++)
    {
        obj.array[i] = array[i];
    }
    return obj;
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& obj){
    if (&obj != this){
        if (array != nullptr)
            delete[] array;

        count = obj.count;
        array = new T[count];
        for (int i = 0; i < count; i++){
            array[i] = obj.array[i];
        }
        cout << "\n";
    }
    return *this;
}

template<class T>
T& MyArray<T>::operator[](int index){
    return array[index];
}

template<class T>
T MyArray<T>::operator[](int index) const{
    return array[index];
}

template<class T>
int MyArray<T>::GetSize() const{
    return count;
}

template<class T>
MyArray<T>::~MyArray(){
    delete[] array;
}
