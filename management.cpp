#include<iostream>
using namespace std;
//  Each patient has a name, ID, age, and medical history (a list of past visits)
class Patient{
private:
// Attribute
string name; // Tên
int id; // ID
int age; // Tuổi
string medical_history; // Tiền sử bệnh án
public:
    Patient(){
        name="Unknown";
        id=0;
        age=0;
        medical_history="Unknown";
    }
    Patient(string name, int id, int age, string medical_history){
        this->name=name;
        this->id=id;
        this->age=age;
        this->medical_history=medical_history;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name=n;
    }
    int getId(){
        return id;
    }
    void setId(int i){
        id=i;
    }
    int getAge(){
        return age;
    }
    void setAge(int a){
        age=a;
    }
    string getMedical_history(){
        return medical_history;
    }
    void setMedical_history(string m){
        medical_history=m;
    }
    void displayInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Medical history: "<<medical_history<<endl;
    }
};
int main () {
    Patient p("Truong", 24110042, 19, "Khong co benh");
    p.displayInfo();
    return 0;
}