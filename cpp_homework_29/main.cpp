//
//  main.cpp
//  cpp_homework_29
//
//  Created by Mark Semenov on 29.11.2022.
//

#include <iostream>
using namespace std;

void add_width(int** example, int which)
{
    example[which] = new int[10];
}


void delete_width(int** example, int which)
{
    delete[] example[which];
}


int pres = 0;
auto create_arr(string** third_example, int allcontacts, int i = 0)
{
    for (; i < allcontacts; i++)
        third_example[i] = new string[2];
}


auto input_arr(string** third_example)
{
    string name, number;
    cout << "Name : ";
    cin >> name;
    cout << "Number : ";
    cin >> number;

    third_example[pres][0] = name;
    third_example[pres++][1] = number;
}


auto search_arr(std::string** third_example)
{
    int which;
    cout << "What do you want to search ?\n";
    cout << "1.Name\n";
    cout << "2.Number\n";


    if (which == 1)
    {
        cout << "Enter a name : ";
    }
    else if (which == 2)
    {
        cout << "Enter a number : ";
    }
}


auto delete_arr(std::string** third_example)
{
    int which;
    cout << "Which name and number do you want to delete ?\n";
    cout << "Index of name or number which you remeber : ";
    cin >> which;
    delete[] third_example[which];
}


void showarray(std::string** third_example, int allcontacts);
{
    for (int i = 0; i < allcontacts; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << third_example[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //Task 1
    int** example = new int*[10];
    add_width(example, 5);



    //Task 2
    int** second_example = new int* [10];
    delete_width(second_example, 6);



    //Task 3
    int allcontacts;
    cout << "How many will people ?\n";
    cin >> allcontacts;
    string** third_example = new string *[allcontacts];
    create_arr(third_example, allcontacts);


    int move;
    while (true)
    {
        cout << "What do you want to do?\n";
        cout << "1.Input name and number\n2.Search name or number\n3.Delete name with number\n4.Show array\n";
        cin >> move;


        if (move == 1)
        {
            input_arr(third_example);
        }
        else if (move == 2)
        {
            search_arr(third_example);
        }
        else if (move == 3)
        {
            delete_arr(third_example);
        }
        else if (move == 4)
        {
            showarray(third_example, allcontacts);
        }
        else
        {
            cout << "Not correct\n\n";
        }
    }
}
