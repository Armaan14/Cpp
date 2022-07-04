#include<iostream>
#include <conio.h>

void swap (int *a ,int *b) {

  int c;
  c=*a ;
  *a=*b;
  *b=c;
}
void swap(float*a ,float *b) {
  float c;
  c=*a;
  *a=*b;
  *b=c;
}
void swap (double *a ,double *b){
  double c;
  c=*a;
  *a=*b;
  *b=c;
}

void main () {

 int a,b;
 float c,d ;
 double e,f ;
 clrscr ();
 cout<<"Enter the values of a,b for integer ";
 cin >>a>>b;
 cout <<"Enter the values for c,d ";
 cin >>c>>d;
 cout <<"Enter the values for e,f ";
 cin >>e>>f;
 void swap (int *,int *);
 void swap (float *,float *);
 void swap (double *,double *);

 swap(&a,&b);
 swap (&c,&d);
 swap (&e,&f);

 cout <<"\nafter swaping: ";
 cout <<"\nvalues of a,b"<<a<<"\t"<<b;
 cout <<"\nvalues of c,d"<<c<<"\t"<<d;
 cout <<"\nvalues of e,f"<<e<<"\t"<<f;

return 0;
}
