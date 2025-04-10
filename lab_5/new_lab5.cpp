#include <iostream>
#include <vector>

#include "new_header.h"

using namespace std;
int main (){
    cout << "lab4" << endl;

    vector <int> plenty_1;
    vector <int> plenty_2;
    vector <int> plenty_3;
    //vector for exception without initialization
    vector <int> plenty_4;

    // Check exception for iterator > max_size_vector;
    try {Enter_Plenty(plenty_1, 1);}
    catch(const exception& ex){cerr << ex.what() << '\n';}
    
    Enter_Plenty(plenty_2, 2);
    Enter_Plenty(plenty_3, 3);

    Operation_Plenty(plenty_1, plenty_2, plenty_3, plenty_4);

    Сonversion_eighteen_digit_system_to_duodecimal();
}