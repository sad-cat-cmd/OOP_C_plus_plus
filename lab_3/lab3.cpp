#include <iostream>
#include <vector>

#include "header.h"

using namespace std;

int main (){
    cout << "lab_3" << endl;

    vector <Product> Product_vector;

    vector <Toy> Toy_Vector;
    vector <Produce> Produce_Vector;
    vector <Dairy_Produce> Dairy_Produce_Vector;
    
    Set_Info(Product_vector, Toy_Vector, Produce_Vector, Dairy_Produce_Vector, 2);
    Print_Info(Product_vector, Toy_Vector, Produce_Vector, Dairy_Produce_Vector, 2);
    Print_All_Object(Product_vector);
}