#pragma once

#include <iostream>
#include <string>

using namespace std;
class Product {
    private:
        string Id;
        string Name;
    public:
        void set_id(string _Id){Id = _Id;}
        void set_name(string _Name){Name = _Name;}

        string get_id(){return Id;}
        string get_name(){return Name;}

};
class Toy : public Product{
    private:
        string Color;
    public:
        void set_color(string _Color){Color = _Color;}
        string get_color(){return Color;}

};
class Produce : public Product{
    private:
        string Expiration_Date;
    public:
        void set_Expiration_Date (string _Exapiration_Date) {Expiration_Date = _Exapiration_Date;}
        string get_Expiration_Date () {return Expiration_Date;}
};
class Dairy_Produce : public Produce {
    private:
        string Name_Farm;
    public:
        void set_Name_Farm(string _Name_Farm){ Name_Farm = _Name_Farm;}
        string get_Name_Farm() {return Name_Farm;}
};

void Enter_Sting(string Input_Info, string &Temp_String) {
    cout << Input_Info << ":  ";
    cin >> Temp_String;
}
void Set_Info(vector <Toy>& temp_Toy, vector <Produce>& temp_Produce, vector <Dairy_Produce>& temp_Daire_Produce, unsigned int Count_Object){
    string ID, Name, Expiration_Date, Color, Name_Farm;

    for (int i = 0; i < Count_Object; i++) {
        cout << "ENTER TOY-OBJECT:" << endl;
        Enter_Sting("ENTER ID:", ID);
        Enter_Sting("ENTER Name_Product: " , Name);
        Enter_Sting("ENTER Color: " , Color);

        Toy temp_Object;
        temp_Object.set_name(Name);
        temp_Object.set_id(ID);
        temp_Object.set_color(Color);

        temp_Toy.push_back(temp_Object);
    }
    for (int i = 0; i < Count_Object; i++) {
        cout << "ENTER PRODUCE-OBJECT:" << endl;
        Enter_Sting("ENTER ID:", ID);
        Enter_Sting("ENTER Name_Product: " , Name);
        Enter_Sting("ENTER Expiration_Date: " , Expiration_Date);

        Produce temp_Object;
        temp_Object.set_id(ID);
        temp_Object.set_name(Name);
        temp_Object.set_Expiration_Date(Expiration_Date);

        temp_Produce.push_back(temp_Object);
    }
    for (int i = 0; i < Count_Object; i++) {
        cout << "ENTER DAIRE_PRODUCE-OBJECT:" << endl;
        Enter_Sting("ENTER ID:", ID);
        Enter_Sting("ENTER Name_Product: " , Name);
        Enter_Sting("ENTER Expiration_Date: " , Expiration_Date);
        Enter_Sting("ENTER Name_Farm: " , Name_Farm);
        
        Dairy_Produce temp_Object;
        
        temp_Object.set_id(ID);
        temp_Object.set_name(Name);
        temp_Object.set_Expiration_Date(Expiration_Date);
        temp_Object.set_Name_Farm(Name_Farm);

        temp_Daire_Produce.push_back(temp_Object);
    }
}
void Print_Info(vector <Toy> temp_Toy, vector <Produce> temp_Produce, vector <Dairy_Produce> temp_Daire_Produce, unsigned int Count_Object) {
    cout << "TOYVECTOR: "<< endl;
    for (int i = 0; i < Count_Object; i++) {
        cout << i << ": " << temp_Toy[i].get_id() << ", " << temp_Toy[i].get_name() << ", " << temp_Toy[i].get_color() << endl;
    }
    cout << "PRODUCE VECTOR:"<< endl;
    for (int i = 0; i < Count_Object; i++) {
        cout << i << ": " << temp_Produce[i].get_id() <<", "<< temp_Produce[i].get_name() << ", " << temp_Produce[i].get_Expiration_Date() << endl;
    }
    cout << "DAIRE PRODUCE VECTOR:" << endl;
    for (int i = 0; i < Count_Object; i++) {
        cout << i << ": "<< temp_Daire_Produce[i].get_id()<< ", " << temp_Daire_Produce[i].get_name() << ", "<< temp_Daire_Produce[i].get_Expiration_Date() << ", "<< temp_Daire_Produce[i].get_Name_Farm()<< endl;
    }
}

