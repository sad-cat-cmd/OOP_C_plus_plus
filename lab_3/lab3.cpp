#include <iostream>
#include <vector>

#include "header.h"

using namespace std;

int main (){
    cout << "lab_3" << endl;

    vector <Toy> Toy_Vector;
    vector <Produce> Produce_Vector;
    vector <Dairy_Produce> Dairy_Produce_Vector;
    
    Set_Info(Toy_Vector, Produce_Vector, Dairy_Produce_Vector, 3);
    Print_Info(Toy_Vector, Produce_Vector, Dairy_Produce_Vector, 3);
}