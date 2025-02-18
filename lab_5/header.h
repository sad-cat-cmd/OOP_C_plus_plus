#pragma once

#include <string>
#include <algorithm>
#include <unordered_set>
#include <stdexcept> 
//#include <exception>

using namespace std;

template <typename Type>
class Set{
    private:
        vector <Type> plenty;
        
        void Remove_Duplicates(vector <Type>& this_vector) {
            // check zero
            if (this_vector.empty()) {throw runtime_error("Exception: vector passed to the funtion <Remove_Duplicates> is empty\n");}
            //
            unordered_set <Type> s;
            vector <Type> result;
            for (Type value : this_vector){
                if(s.find(value) == s.end()){
                    s.insert(value);
                    result.push_back(value);
                }
            }
            this_vector.clear();
            this_vector = result;
        }
    public:
    void Print_Vector(string Out_Info) {
        cout << Out_Info<< endl;
        for (int num : plenty) {
            cout << num << "\t";
        }
        cout << endl;
    }
    void operator () (const vector <Type>& temp_vector) {
        if (temp_vector.empty()) throw runtime_error ("Exception: this vector is empty\n");
        this->plenty = temp_vector;
    }
    void operator + (const Set& _Set) {
        this->plenty.insert(plenty.end(), _Set.plenty.begin(), _Set.plenty.end());
        try { this->Remove_Duplicates(this->plenty);}
        catch (const exception & ex){cout << ex.what();}
        //
    }
    bool operator <= (const Set& _Set) {
        if (this->plenty.size() > _Set.plenty.size()) return false;
        else return true;
    }
};
void Print_Plenty (Set<int> set_1, Set<int> set_2, Set<int> set_3) {
    set_1.Print_Vector("SET1 :");
    set_2.Print_Vector("SET2 :");
    set_3.Print_Vector("SET3 :");
}
void Enter_Plenty(vector <int>& temp_vector, int number) {
    const int count = 5;
    int temp_value;
    cout << " ENTER " << number << " PLANTY:" << endl;
    // size + 1 in for
    if (number == 1){
        for (int i = 0; i < count + 1; i++) {
            if (i >= count) {throw runtime_error("Exception: iterator >= size your vector");}
            cout << i << ": ";
            cin >> temp_value;
            temp_vector.push_back(temp_value);
        }
    }
    for (int i = 0; i < count; i++) {
        cout << i << ": ";
        cin >> temp_value;
        temp_vector.push_back(temp_value);
    }
}
void Operation_Planty(vector <int> temp_1, vector<int> temp_2, vector <int> temp_3, vector <int> temp_4){
    Set <int> Set_1, Set_2, Set_3, Set_4;
    Set_1(temp_1);
    Set_2(temp_2);
    Set_3(temp_3);

    // Check exception with empty vector
    try{Set_4(temp_4); }
    catch(const std::exception& ex){std::cerr << ex.what() << '\n';}
    
    Print_Plenty(Set_1, Set_2, Set_3);
    
    cout << "\n" << endl;
    Set_1 + Set_2;
    //operator with exception
    try {Set_4 + Set_4;}
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
    
    if (Set_1 <= Set_2) cout << "Set_1 <= Set_2"<<endl;
    else cout << "Set_1 > Set_2";
    cout << "\n" << endl;

    Print_Plenty(Set_1, Set_2, Set_3);
}

int eighteen_digit_to_decimal(const string& eig){return stoi(eig, nullptr, 18);}
string decimal_To_doudecimal (int decimal) {
    string base_12 = "";
    while (decimal > 0) {
        int remainder = decimal % 12;
        if (remainder < 10) base_12 += (char)('0' +remainder);
        else base_12 += char('A' + (remainder - 10));
        decimal /=12;
    }
    reverse(base_12.begin(), base_12.end());
    if (base_12.empty()) return "0";
    else return base_12;

}
void Conversion_eighteen_digit_systeme_to_duodecimal(){
    cout << endl;
    string temp_value;
    cout << "ENTER VALUE IN HEXANDEMICAL SYSTEM: ";
    cin >> temp_value;
    temp_value = decimal_To_doudecimal(eighteen_digit_to_decimal(temp_value));
    cout << "DUOCIMAL VALUE: " << temp_value << endl;
}

