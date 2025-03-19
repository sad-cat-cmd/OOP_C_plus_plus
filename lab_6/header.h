#pragma once

#include <string>
#include <queue>
using namespace std;

class Car {
    private: 
    string Brand;
    string Status;
    unsigned int Number;
    public:
    Car (string _Brand, string _Status, unsigned int _Number) {
        Brand = _Brand;
        Status = _Status;
        Number = _Number;
    }
    string get_Brand () {return Brand;}
    string get_Status () {return Status;}
    unsigned int get_Number () {return Number;}
};
void Enter_value(string& _Brand, string& _Status, unsigned int& _Number){
    cout << "ENTER VALUE:" << endl;
    cout << "Enter Brand: ";
    cin >> _Brand;
    cout << "Enter Status: ";
    cin >> _Status;
    cout << "Enter Number: ";
    cin >> _Number;
    cout << "----"<< endl;
}
void Print_queue(queue <Car> temp_queue){
    cout << "Size: " << temp_queue.size() << endl;
    cout << "First: "<<temp_queue.front().get_Brand()<< ", " << temp_queue.front().get_Status() <<", "<<  temp_queue.front().get_Number()<< endl;
    cout << "End:" << temp_queue.back().get_Brand()<< ", " << temp_queue.back().get_Status() <<", "<< temp_queue.back().get_Number()<< endl;
    cout << "----"<< endl;
}
void Remove_front_N(queue <Car>& temp_queue, unsigned int COUNT) {
    for (int i = 0; i < COUNT; i++) {
        if (temp_queue.empty()) return; 
        temp_queue.pop();
    }
}
void Add_elements(queue<Car>& temp_queue, unsigned int count){
    string Brand, Status;
    unsigned int Number;
    
    for (int i = 0; i < count; i++) {
        Enter_value(Brand, Status, Number);
        Car object(Brand, Status, Number);
        temp_queue.push(object);
    }
}
void Add_elements_from_queue(queue<Car>& temp_queue_1, queue<Car>& temp_queue_2){
    while (!temp_queue_2.empty()){
        temp_queue_1.push(temp_queue_2.front());
        temp_queue_2.pop();
    }
}
void Print_queue_with_pop(queue<Car>& temp_queue){
    while (!temp_queue.empty()){
        cout <<temp_queue.front().get_Brand()<< ", " << temp_queue.front().get_Status() <<", "<<  temp_queue.front().get_Number()<< endl;
        temp_queue.pop();
    }
    cout << "----"<< endl;
}

void Complex_operations(){
    queue <Car> queue_1;
    queue <Car> queue_2;
    Add_elements(queue_1, 5);
    Remove_front_N(queue_1, 2);
    
    Add_elements(queue_2, 5);

    Remove_front_N(queue_1, 1);
    Add_elements_from_queue(queue_1, queue_2);

    cout << "queue_1: " << endl;
    Print_queue_with_pop(queue_1);
    cout << "queue_2: " << endl;
    Print_queue_with_pop(queue_2);
    return;
}
