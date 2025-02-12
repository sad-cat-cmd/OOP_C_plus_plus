#include <iostream>
#include <vector>

#include "header.h"
using namespace std;

int main (){
    unsigned int count_objects {3};
    vector <Bus> objects;
    
    cout << "lab_2" << endl;

    for (int i = 0; i< count_objects; i++) {
        if (i == 0) Set_Values_For_ClassObject(1, objects, i);
        if (i == 1) Set_Values_For_ClassObject(2, objects, i);
        if (i == 2) Set_Values_For_ClassObject(3, objects, i);
    }
    //Find_in_vector(objects);
    //lab2 added
    Compraing_ClassObjects(objects);
    Print_Full_String(objects);
}