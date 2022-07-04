#include <iostream>

using namespace std;

class parson {

public:
  string name ;

private:
  int age ;

protected:
  string gender ;


};

class Student : public person {
   void setInfo () {
    age="20";
    name= "Armaan" ;
    gender= "male ";

   }


};

int main () {
  student st;


  cout <<st.age<<endl
        <<st.name<<endl
        <<st.gender<<endl ;

}
