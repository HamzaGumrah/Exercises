#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//struct all members are public
// struct Rectangle {
//   int length;
//   int breadth;
//   int area(){
//     return length*breadth;
//   }
// };
//class all members are private by default
class Rectangle {
  int length;
  int breadth;
public:
  Rectangle(int length,int breadth){
    this->length = length;
    this->breadth = breadth;
  }
  int area(){
    return length*breadth;
  }
  int perimeter();
  int getLength(){
    return this->length;
  }
  ~Rectangle(){};
};
int Rectangle::perimeter(){
  return 2*(this->length+this->breadth);
}

//Generic Template Class
template<class T>
class Arithametic{
private:
  T a;
  T b;
public:
  Arithametic(T a,T b);
  T add();
  T sub();
};
template<class T>
Arithametic<T>::Arithametic(T a,T b){
  this->a=a;
  this->b=b;
}
template<class T>
T Arithametic<T>::add(){
  return this->a+this->b;
}
template<class T>
T Arithametic<T>::sub(){
  return this->a-this->b;
}

int main() {
  Rectangle r(5,4);
  printf("%d\n",r.area());
  /* code */
  Arithametic<int> ar(10,5);
  cout<<ar.add()<<endl;
  cout<<ar.sub()<<endl;
  Arithametic<char> ar2('A','a');
  cout<<(int)ar2.add()<<endl;
  cout<<(int)ar2.sub()<<endl;
  char b = '5';
  cout<<b<<endl;
  return 0;
}
