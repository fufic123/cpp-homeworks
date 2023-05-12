#include "MyArray.h"

int main(){
    srand(time(0));
    
    MyArray<int> array(5);
    MyArray<int> array2(5);
    MyArray<int> array3;
    
    array.Input();
    array.Print();
    array2.Input();
    array2.Print();
    
    array3 = array + array2;
    array3.Print();
    
    array3 = array3 - 2;
    array3.Print();
    
    array3 = array3 + 2;
    array3.Print();
    
    array3++;
    array3.Print();
    
    array3--;
    array3.Print();
    
    array.Add(4);
    array.Print();
    array.Delete();
    array.Print();
    
    cout << array3[5] << "\n";
}
