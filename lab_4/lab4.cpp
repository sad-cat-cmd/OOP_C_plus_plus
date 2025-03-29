#include <iostream>
#include <vector>

#include "header.h"

using namespace std;
int main (){
    cout << "lab4" << endl;

    vector <int> plenty_1;
    vector <int> plenty_2;
    vector <int> plenty_3;

    Enter_Plenty(plenty_1, 1);
    Enter_Plenty(plenty_2, 2);
    Enter_Plenty(plenty_3, 3);

    Operation_Plenty(plenty_1, plenty_2, plenty_3);
}