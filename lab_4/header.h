#pragma once

#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

template <typename Type>

class Set{
    private:
        vector <Type> plenty;
        
        void Remove_Duplicates(vector <Type>& this_vector) {
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
        this->plenty = temp_vector;
    }
    void operator + (const Set& _Set) {
        this->plenty.insert(plenty.end(), _Set.plenty.begin(), _Set.plenty.end());
        this->Remove_Duplicates(this->plenty);
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
    for (int i = 0; i < count; i++) {
        cout << i << ": ";
        cin >> temp_value;
        temp_vector.push_back(temp_value);
    }
}
void Operation_Planty(vector <int> temp_1, vector<int> temp_2, vector <int> temp_3){
    Set <int> Set_1, Set_2, Set_3;
    Set_1(temp_1);
    Set_2(temp_2);
    Set_3(temp_3);
    Print_Plenty(Set_1, Set_2, Set_3);
    
    cout << "\n" << endl;
    Set_1 + Set_2;
    if (Set_1 <= Set_2) cout << "Set_1 <= Set_2"<<endl;
    else cout << "Set_1 > Set_2";
    cout << "\n" << endl;

    Print_Plenty(Set_1, Set_2, Set_3);
}


