#include<iostream>
#include<string>

using namespace std;

class vehicle {
  private :

   string engine ;

  protected :
    double fuelLevel ;
    void setEngineConfig(string enginconf) {engine= enginconf;}

  public :
    void setFuleLevel(double level){fuelLevel[level;}
    double getFuelAmount() {return fuelLebel;}
    string getEngineConfig() {return engine;}


};

 class car: public Vehicle {
   int noOFDoors ;
 public :
  car(int doors) {

  noOFDoors= doors;

  fuelLevel=40.5;
  SetEngineConfig("1500cc");

  }
    int getDoors() {return noOFDoors;}
  };


  int main() {

   car mycar(5);
   cout<<"My car config:"<<endl<<myCar.getDoors()<<endl<<myCar.FuelAmount()<<endl<<myCar.getEmgineConfig();

  }
