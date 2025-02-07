#pragma once

#include <iostream>
#include <string>

using namespace std;

unsigned int Set_Count_ClassObject(){
    unsigned int temp_value {0} ;
    cout<<  "ENTER COUNT CLASS OBJECT:  ";
    cin >>  temp_value;
    return temp_value;
}
void Set_Values_For_Values_In_ClassObject() {
    cout << "ENTER VALUES";
    
}

class Bus {
    private:
        string Name_Driver;
        unsigned int Number_Path;
        string Brand_Bus;
        string Year_Beginning_Start;
        unsigned int Mileage;
    
    public:
        Bus (){
            Name_Driver = "No name";
            Brand_Bus = "No Brand";
            Year_Beginning_Start = "Void Info";
        }
        ~Bus(){

        }
        
        void set_Name_Driver(string _Name) {Name_Driver = _Name;}
        void set_Number_Path(const int _Number_Path){Number_Path = _Number_Path;}
        void set_Brand_Bus(string _Brand_Bus){Brand_Bus = _Brand_Bus;}
        void set_Year_Begginning_Start(string _Year_Beginning_Start){Year_Beginning_Start = _Year_Beginning_Start;}
        void set_Mileage(const int _Mileage){Mileage = _Mileage;}

        string get_Name_Driver() {return Name_Driver;}
        unsigned int get_Number_Path(){return Number_Path;}
        string get_Brand_Bus(){return Brand_Bus;}
        string get_Year_Begginning_Start(){return Year_Beginning_Start;}
        unsigned int get_Mileage(){return Mileage;}



};
