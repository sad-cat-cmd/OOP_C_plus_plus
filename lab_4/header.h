#pragma once

#include <string>
using namespace std;

template <typename Type>

class Set{
    private:
        Type *plenty;
        unsigned int Size_Plenty;

    public:
    Set() : plenty(nullptr), Size_Plenty(0) {}
    Set(const Set& other) {
        Size_Plenty = other.Size_Plenty;
        if (Size_Plenty > 0) {
            plenty = new Type[Size_Plenty];
            for (unsigned int i = 0; i < Size_Plenty; i++) {
                plenty[i] = other.plenty[i];
            }
        } else {
            plenty = nullptr;
        }
    }
    Set& operator=(const Set& other) {
        if (this != &other) {
            delete[] plenty;
            Size_Plenty = other.Size_Plenty;
            if (Size_Plenty > 0) {
                plenty = new Type[Size_Plenty];
                for (unsigned int i = 0; i < Size_Plenty; i++) {
                    plenty[i] = other.plenty[i];
                }
            } else {
                plenty = nullptr;
            }
        }
        return *this;
    }
    unsigned int get_size_plenty() {
        return Size_Plenty;
    }
    Type* get_Plenty_elements() {
        return plenty;
    }
    void operator - (const Set& _Set) {
        Set<Type> result;

        for (unsigned i = 0; i < Size_Plenty; ++i) {
            bool found = false;
            for (unsigned j = 0; j < result.Size_Plenty; ++j) {
                if (plenty[i] == result.plenty[j]) {
                    found = true;
                    break;
                }
            }
            for (unsigned h = 0; h < _Set.Size_Plenty ; ++h){
                if (plenty[i] == _Set.plenty[h]){
                    found = true;
                    break;
                }
            }
            if (!found) {
                // Добавляем элемент в result
                Type* temp = new Type[result.Size_Plenty + 1];
                for (unsigned k = 0; k < result.Size_Plenty; ++k) {
                    temp[k] = result.plenty[k];
                }
                temp[result.Size_Plenty] = plenty[i];
                delete[] result.plenty;
                result.plenty = temp;
                result.Size_Plenty++;
            }
        }

        delete[] plenty;
        plenty = result.plenty;
        Size_Plenty = result.Size_Plenty;
        
        result.plenty = nullptr;
        result.Size_Plenty = 0;
    }
    void operator + (const Set& _Set) {
        Set<Type> result;
        
        // Добавляем все уникальные элементы из текущего множества
        for (unsigned i = 0; i < Size_Plenty; ++i) {
            bool found = false;
            for (unsigned j = 0; j < result.Size_Plenty; ++j) {
                if (plenty[i] == result.plenty[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                // Добавляем элемент в result
                Type* temp = new Type[result.Size_Plenty + 1];
                for (unsigned k = 0; k < result.Size_Plenty; ++k) {
                    temp[k] = result.plenty[k];
                }
                temp[result.Size_Plenty] = plenty[i];
                delete[] result.plenty;
                result.plenty = temp;
                result.Size_Plenty++;
            }
        }
        
        // Добавляем все уникальные элементы из второго множества
        for (unsigned i = 0; i < _Set.Size_Plenty; ++i) {
            bool found = false;
            for (unsigned j = 0; j < result.Size_Plenty; ++j) {
                if (_Set.plenty[i] == result.plenty[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                // Добавляем элемент в result
                Type* temp = new Type[result.Size_Plenty + 1];
                for (unsigned k = 0; k < result.Size_Plenty; ++k) {
                    temp[k] = result.plenty[k];
                }
                temp[result.Size_Plenty] = _Set.plenty[i];
                delete[] result.plenty;
                result.plenty = temp;
                result.Size_Plenty++;
            }
        }
        
        delete[] plenty;
        plenty = result.plenty;
        Size_Plenty = result.Size_Plenty;
        
        result.plenty = nullptr;
        result.Size_Plenty = 0;
    }
    void operator () (const vector <Type> & temp_vector){
        this->plenty = new Type[temp_vector.size()];
        Size_Plenty = temp_vector.size();
        for (int i = 0; i < Size_Plenty; i++) {
            plenty[i] = temp_vector[i];
        }

    }
    ~Set () {
        delete[] plenty;
        plenty = nullptr;
    }
    int operator <= (const Set& _Set){
        if (this->Size_Plenty == _Set.Size_Plenty) {
            for (int i = 0; i < Size_Plenty; i++) {
                if (this->plenty[i] != _Set.plenty[i]) {return -1;}
            }
            return 0;
        }
        else {return -1;}
    }
};

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
void Print_Plenty(Set <int> _Set , string Name_Set){
    int *temp_plenty;
    unsigned int temp_Size;
    temp_plenty = _Set.get_Plenty_elements();
    temp_Size = _Set.get_size_plenty();

    cout << Name_Set<< ":  ";
    for (int i = 0; i < temp_Size; i++) {
        cout << temp_plenty[i] << ", ";
    }
    cout << endl;

}
void Operation_Plenty(vector <int> temp_1, vector<int> temp_2, vector <int> temp_3){
    Set <int> Set_1, Set_2, Set_3;
    
    Set_1(temp_1);
    Set_2(temp_2);
    Set_3(temp_3);

    Print_Plenty(Set_1, "Set_1 operator () ");
    Print_Plenty(Set_2, "Set_2 operator () ");
    Print_Plenty(Set_3, "Set_3 operator () ");

    Set_1 + Set_2;

    Print_Plenty (Set_1, "Set_1 operator (+) Set_2");

    Set_2 - Set_3;

    Print_Plenty(Set_2, "Set_1 operator (-) Set_3");
    if (Set_1 <= Set_2 == 0) {cout << "sets are equal"<< endl;}
    else {cout << "sets are not equal"<< endl;}
}


