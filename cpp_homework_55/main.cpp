#include "MyArray.h"
#include "Point.h"
using namespace std;

string TextEditing(string text);

int main() {
    srand(time(0));

    MyArray<int> arr(5);
    arr.Input();
    cout << "Array 1: ";
    arr.PrintDev();

    MyArray<int> arr2(3);
    arr2.Input();
    cout << "Array 2 ";
    arr2.PrintDev();

    //IsEmpty
    cout << "\n" << boolalpha << "Array 1: " << arr.IsEmpty() << "\n" << "Array 2 " << arr2.IsEmpty() << "\n";

    //SetSize
    arr.SetSize(3);
    cout << "Array 1: ";
    arr.PrintDev();

    arr2.SetSize(4);
    cout << "Array 2 ";
    arr2.PrintDev();

    //GetAt
    cout << "\n" << "Array 1: " << arr.GetAt(2) << "\n" << "Array 2 " << arr2.GetAt(2) << "\n";

    //SetAt
    cout << "\n" <<"Array 1: ";
    arr.SetAt(6, 2);
    arr.PrintDev();

    cout << "Array 2 ";
    arr2.SetAt(14, 1);
    arr2.PrintDev();

    //Add
    cout << "\n" << "Array 1: ";
    arr.Add(54);
    arr.PrintDev();

    cout << "Array 2 ";
    arr2.Add(45);
    arr2.PrintDev();

    //SetSize
    arr.SetSize(8, 4);
    cout << "Array 1: ";
    arr.PrintDev();

    arr2.SetSize(5, 3);
    cout << "Array 2 ";
    arr2.PrintDev();

    //Add
    arr.Add(20);
    cout << "\n" << "Array 1: ";
    arr.PrintDev();

    arr2.Add(29);
    cout << "Array 2 ";
    arr2.PrintDev();

    //Sum
    cout << "\n" << "Sum of Array 1: " << arr.Sum() << "\n";
    cout << "Sum of Array 2 " << arr2.Sum() << "\n";

    //Append
    arr.Append(arr2);
    cout << "\n" << "Array: ";
    arr.PrintDev();

    //InsertAt
    arr.InsertAt(25, 3);
    cout << "\n" << "Array: ";
    arr.PrintDev();

    const int SIZE = 4;
    int* ar = new int[SIZE];
    for (int i = 0; i < SIZE; i++) ar[i] = rand() % 20;

    arr.InsertAt(ar, SIZE, 3);
    cout << "\n" << "Array: ";
    arr.PrintDev();

    //RemoteAt
    arr.RemoveAt(2);
    cout << "\n" << "Array: ";
    arr.PrintDev();

    arr.RemoveAt(2, 5);
    cout << "\n" << "Array: ";
    arr.PrintDev();

    //FreeExtra
    arr.FreeExtra();
    cout << "\n" << "Array: ";
    arr.PrintDev();

    //RemoveAll
    arr.RemoveAll();
    cout << "\n" << "Array: ";
    arr.PrintDev();

    delete[] ar;

    cout << "\n" << "\n" << "\n";

    MyArray<double> doubleArray(7);
    MyArray<char> charArray(6);
    MyArray<Point<int>> pointIntArray(5);
    MyArray<Point<double>> pointDoubleArray(4);
    MyArray<Point<char>> pointCharArray(3);

    doubleArray.Input(); 
    for (int i = 0; i < doubleArray.GetSize(); i++) doubleArray[i] /= 10;
    cout << "Array double: ";
    doubleArray.PrintDev();

    charArray.Input();
    cout << "Array char: ";
    charArray.PrintDev();

    pointIntArray.Input();
    cout << "Array point-int: ";
    pointIntArray.PrintDev();

    pointDoubleArray.Input();
    cout << "Array point-double: ";
    pointDoubleArray.PrintDev();

    pointCharArray.Input(); 
    cout << "Array point-char: ";
    pointCharArray.PrintDev();

    cout << "Array double sum: " << doubleArray.Sum() << "\n";

    cout << "Array char sum: " << charArray.Sum() << " (" << (int)charArray.Sum() << ")" << "\n";

    cout << "Array point-int sum: " << pointIntArray.Sum() << "\n";

    cout << "Array double-point sum: " << pointDoubleArray.Sum() << "\n";
    
    cout << "Array char-point sum: " << pointCharArray.Sum() << "\n";

    MyArray<Point<int>> testArr{Point<int>(1, 2, 3), Point<int>(4, 5, 6), Point<int>(7, 8, 9)};
    testArr.PrintDev();
    cout << "\n" << "\n";

    string text = "    This     is    my    text    ";
    string editingText = TextEditing(text);
    cout << "\"" << text << "\"" << "\n" << "\"" << editingText << "\"" << "\n";
}

string TextEditing(string text) {
    string editingText;
    bool encounteredSpace = false;
    int j = 0, count = 0;

    while (text[j] == ' ') {
        count++;
        j++;
    }
    for (int i = 0; i < count - 1; i++) editingText += ' ';

    for (char symbol : text) {
        if (symbol == ' ') encounteredSpace = true;
        else {
            if (encounteredSpace) {
                editingText += ' ';
                encounteredSpace = false;
            }
            editingText += symbol;
        }
    }
    if (encounteredSpace) editingText += ' ';

    j = text.size() - 1;
    count = 0;

    while (text[j] == ' ') {
        count++;
        j--;
    }
    for (int i = 0; i < count - 1; i++) editingText.push_back(' ');

    return editingText;
}
