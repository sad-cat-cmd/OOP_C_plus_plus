#pragma once
#include <stdexcept> 
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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
    void operator + (const Set& _Set) {
        if (this->Size_Plenty == 0 || _Set.Size_Plenty == 0) {throw runtime_error ("Exception: one of the plentes is empty\n");}
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
        
        // Заменяем текущее множество на результат
        delete[] plenty;
        plenty = result.plenty;
        Size_Plenty = result.Size_Plenty;
        
        // Чтобы result не удалил память в деструкторе
        result.plenty = nullptr;
        result.Size_Plenty = 0;
    }
    void operator () (const vector <Type> & temp_vector){
        int max_value =100;
        if (temp_vector.empty()) {throw runtime_error ("Exception: this vector is empty\n");}
        if (temp_vector.size() > max_value) {throw runtime_error ("Exception: the size of this vector is larger than necessary\n");}
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
    bool operator<=(const Set& _Set) const {
        if (this->Size_Plenty == 0) {
            return true;
        }
        for (int i = 0; i < this->Size_Plenty; i++) {
            bool found = false;
            for (int j = 0; j < _Set.Size_Plenty; j++) {
                if (this->plenty[i] == _Set.plenty[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};

void Enter_Plenty(vector <int>& temp_vector, int number) {
    const int count = 5;
    int temp_value;
    cout << " ENTER " << number << " PLANTY:" << endl;
    // size + 1 in for
    if (number == 1){
        for (int i = 0; i < count + 1; i++) {
            if (i >= count) {throw runtime_error("Exception: iterator > size your vector");}
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
void Operation_Plenty(vector <int> temp_1, vector<int> temp_2, vector <int> temp_3, vector <int> temp_4){
    Set <int> Set_1, Set_2, Set_3, Set_4, Set_5;
    vector <int> oferflow_vector(102);
    Set_1(temp_1);
    Set_2(temp_2);
    Set_3(temp_3);
    try {Set_4(temp_4);}
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
    try {Set_5(oferflow_vector);}
    catch (const std::exception& e) {std::cerr << e.what() << '\n';}
    Print_Plenty(Set_1, "Set_1 operator () ");
    Print_Plenty(Set_2, "Set_2 operator () ");
    Print_Plenty(Set_3, "Set_3 operator () ");

    Set_1 + Set_2;
    Print_Plenty (Set_1, "Set_1 operator (+) Set_2");
    // Exception: one of the vectors is empty\n
    try {Set_3 + Set_4;}
    catch(const std::exception& e) {std::cerr << e.what() << '\n';}
    if (Set_1 <= Set_2 == true) {cout << "sets are equal"<< endl;}
    else {cout << "sets are not equal"<< endl;}
}

int eighteen_digit_to_decimal(const string& eig) {
    return stoi(eig, nullptr, 18);
}

string decimal_to_duodecimal(int decimal) {
    if (decimal == 0) return "0";

    string base_12 = "";
    while (decimal > 0) {
        int remainder = decimal % 12;
        if (remainder < 10) {
            base_12 += (char)('0' + remainder);
        } else {
            base_12 += (char)('A' + (remainder - 10));
        }
        decimal /= 12;
    }
    reverse(base_12.begin(), base_12.end());
    return base_12;
}

bool is_valid_eighteen_base(const string& str) {
    for (char c : str) {
        c = toupper(c);
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'H'))) {
            return false;
        }
    }
    return true;
}

// Функция для выполнения преобразования
void Сonversion_eighteen_digit_system_to_duodecimal() {
    cout << endl;
    string temp_value;
    cout << "ENTER VALUE IN 18-BASE SYSTEM (0-9, A-H): ";
    cin >> temp_value;

    try {
        if (!is_valid_eighteen_base(temp_value)) {
            throw runtime_error("Exception: invalid characters in input (use 0-9, A-H)");
        }
        int decimal_value = eighteen_digit_to_decimal(temp_value);
        string duodecimal_value = decimal_to_duodecimal(decimal_value);

        cout << "DUODECIMAL VALUE: " << duodecimal_value << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
}

// bool, все элементы a есть в b
// исключение к символам 