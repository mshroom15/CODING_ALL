#include<iostream>
#include <string>
using namespace std;

class stdnt{
    private:
     int regis;
     float cgpa;
     void showgpa(){
        cout<<"student cgpa is"<<cgpa;
     }
    void showregis(){
       cout<<"student regis is"<<regis;
    }
     
    public:
     string name;
     int roll;
    protected:
     int ct;
     int tf;
     
};
class ID : public stdnt {
    public:
     void show(){
        cout<<"student name is"<<name<<endl;
        cout<<"student roll is"<<roll<<endl;
        cout<<"student ct is"<<ct<<endl;
        cout<<"student tf is"<<tf<<endl;
     }
};
int main(){
    ID s;
    s.name="sachin";
    s.roll=123;
    s.ct=10;
    s.tf=20;
    s.show();
    return 0;
}