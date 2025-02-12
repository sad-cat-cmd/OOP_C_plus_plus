#pragma once

#include <iostream>
#include <string>

using namespace std;
class Bus {
    friend class Observer;
    private:
        string Name_Driver;
        unsigned int Number_Path;
        string Brand_Bus;
        unsigned int Year_Beginning_Start;
        unsigned int Mileage;
    
    public:
        Bus (){
            Name_Driver = "No name";
            Brand_Bus = "No Brand";
            Year_Beginning_Start = 2000;
        }
        Bus (string _Name_Driver, unsigned int _Number_Path, string _Brand_Bus, unsigned int _Year_Start, unsigned int _Mileage) {
            Name_Driver = _Name_Driver;
            Number_Path = _Number_Path;
            Brand_Bus = _Brand_Bus;
            Year_Beginning_Start = _Year_Start;
            Mileage = _Mileage;
        }
        Bus (const Bus& _object_BUS) {
            Name_Driver = _object_BUS.Name_Driver;
            Number_Path = _object_BUS.Number_Path;
            Brand_Bus = _object_BUS.Brand_Bus;
            Year_Beginning_Start = _object_BUS.Year_Beginning_Start;
            Mileage = _object_BUS.Mileage;
            
        }
        ~Bus(){

        }
        // added in lab2
        bool operator == (const Bus & _Bus) { 
            if (this->Brand_Bus == _Bus.Brand_Bus) return true;
            else return false;
        }
        bool operator != (const Bus & _Bus) {
            if (this->Number_Path != _Bus.Number_Path) return true;
            else return false; 
        }
        Bus& operator = (const Bus & _Bus) {
            this->Name_Driver = _Bus.Name_Driver;
            this->Number_Path =_Bus.Number_Path;
            this->Brand_Bus = _Bus.Brand_Bus;
            this->Year_Beginning_Start = _Bus.Year_Beginning_Start;
            this->Mileage = _Bus.Mileage; 
            return *this;   
        }
        //
        void set_Name_Driver(string _Name) {Name_Driver = _Name;}
        void set_Number_Path(unsigned int _Number_Path){Number_Path = _Number_Path;}
        void set_Brand_Bus(string _Brand_Bus){Brand_Bus = _Brand_Bus;}
        void set_Year_Begginning_Start(unsigned int _Year_Beginning_Start){Year_Beginning_Start = _Year_Beginning_Start;}
        void set_Mileage(unsigned int _Mileage){Mileage = _Mileage;}

        string get_Name_Driver() {return Name_Driver;}
        unsigned int get_Number_Path(){return Number_Path;}
        string get_Brand_Bus(){return Brand_Bus;}
        unsigned int get_Year_Begginning_Start(){return Year_Beginning_Start;}
        unsigned int get_Mileage(){return Mileage;}
};
//added in lab2 
class Observer{
    public:
    string Get_Info(const Bus& _Bus){return "" + _Bus.Name_Driver + ", " + to_string(_Bus.Number_Path) + ", " + _Bus.Brand_Bus + ", " + to_string(_Bus.Year_Beginning_Start) + ", " + to_string(_Bus.Mileage);}
        
};
//
void Print_Vulue(Bus temp_object){
    cout << temp_object.get_Name_Driver() << ", "<< temp_object.get_Number_Path()<< ", "<< temp_object.get_Brand_Bus()<< ", "<< temp_object.get_Year_Begginning_Start() <<", "<< temp_object.get_Mileage() << endl;
}
void Enter_Value(string *Name, string *Brand, unsigned int* Year, unsigned int *Number, unsigned int *Milage) {
    cout << "ENTER VALUES: " ;
    cout << "enter Name_Driver: ";
    cin >> *Name;
    cout << "enter Number_Path: ";
    cin >> *Number;
    cout << "enter Brand_Bus: ";
    cin >> *Brand;
    cout << "enter Year_Beginning_Start: ";
    cin >> *Year;
    cout << "enter Mileage: ";
    cin >> *Milage;
}
void Set_Values_For_ClassObject(int value, vector<Bus>& Vector, int ptr_Vector) {
    string Name, Brand;
    unsigned int Number, Milage , Year;
    Enter_Value(&Name, &Brand, &Year, &Number, &Milage);
    switch (value)
    {
    case 1:
    {
        Bus object;
        object.set_Name_Driver(Name);
        object.set_Number_Path(Number);
        object.set_Brand_Bus(Brand);
        object.set_Year_Begginning_Start(Year);
        object.set_Mileage(Milage);

        Vector.push_back(object);
        break;
    }
    case 2:
    {
        Bus object(Name, Number, Brand, Year, Milage);
        Vector.push_back(object);
        break;
    }
    case 3:
    {
        Bus object = Vector[ptr_Vector - 1];
        Vector.push_back(object);
        break;
    }
    default:
        break;
    }
}
void Sorting_by_Number_Path(unsigned int number_path, Bus temp_object){
    cout << "Sortig by number path: " << number_path << endl;
    if (number_path == temp_object.get_Number_Path()) Print_Vulue(temp_object);
    cout << "--------" << endl;
}
void Sorting_by_Year(Bus temp_object){
    unsigned int year_now = 2025;
    cout << "Sortig by bus using more 10 year:" << endl;
    if ((year_now - temp_object.get_Year_Begginning_Start()) >= 10) Print_Vulue(temp_object);
    cout << "--------"<< endl;
}
void Sorting_by_Mileage(Bus temp_object){
    cout << "Sorting by mileage" << endl;
    if (temp_object.get_Mileage() >= 10000) Print_Vulue(temp_object);
    cout << "--------" << endl;
}
void Find_in_vector(vector <Bus> temp_object){
    unsigned int temp_number_path;
    cout << "Enter number path for find: ";
    cin >> temp_number_path; 

    for (int i = 0; i< temp_object.size(); i++) {
        Sorting_by_Number_Path(temp_number_path ,temp_object[i]);
    }
    for (int i = 0; i < temp_object.size(); i++) {
        Sorting_by_Year(temp_object[i]);
    }
    for (int i =0; i < temp_object.size(); i++) {
        Sorting_by_Mileage(temp_object[i]);
    }
}
// FUNCTIONS FOR OPERATOR OVERLORD
void Compraing_ClassObjects(vector <Bus> &temp_objects){
    if (temp_objects[temp_objects.size() - 1] == temp_objects[temp_objects.size() - 2]) cout << "the last two objects-BRAND_BUS are equel\n---------" << endl;
    else cout << "the last two objects-BRAND_BUS are not equel\n---------" << endl;

    if (temp_objects[temp_objects.size() - 1] != temp_objects[temp_objects.size() - 2]) cout << "the last two objects_PATH are not equel\n---------" << endl;
    else cout << "the last two objects_PATH are equel\n---------" << endl;

    temp_objects[temp_objects.size() -1] = temp_objects[temp_objects.size() - 3];
}
void Print_Full_String(vector <Bus> temp_objects){
    Observer TEMP;
    for (int i = 0; i < temp_objects.size(); i++) {
        cout << TEMP.Get_Info(temp_objects[i])<< "\n ----------"<< endl;
    }
}