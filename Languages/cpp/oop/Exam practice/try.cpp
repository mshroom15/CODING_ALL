#include <bits/stdc++.h>
using namespace std;

class Door{
     public:
          string Color;
          string Material;

          void Open(){
               cout << "The door is open! Monster coming!\n";
          }
          void Close(){
               cout << "The door is closed. You're safe for now!\n";
          }
};

int main()
{
     Door door1;
     door1.Color = "Brown";
     door1.Material = "Wood";

     cout << "The door is " << door1.Color << "\n";   // " " or ' ' works
     cout << "The door is made out of " << door1.Material << '\n';

     door1.Open();
     door1.Close();
     
}