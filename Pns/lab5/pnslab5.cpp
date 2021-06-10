#include <iostream>
#include <fstream>

using namespace std;

int main(){

  ifstream ip("file.csv");

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  string firstname;
  string lastname;
  string age;
  string weight;
  float x,y,sum=0;
  string X,Y;
 // vector<float> vy;
int f=0;
  while(ip.good()){
    //f=0;
    getline(ip,X,',');
    if(X=="-1")
    {
      std::cout << "\nFinal Sum(Meu-y): "<<sum<< '\n';
      cout<<endl;
      sum=0;
      f=1;
      //continue;
    }
    if(X=="-2")
    {
      std::cout << "\nFinal Sum(Meu-x): "<<sum<< '\n';
      cout<<endl;
      sum=0;
      f=0;
      //continue;
    }
    getline(ip,Y,'\n');
    x=std::stof(X);
    y=std::stof(Y);
    sum+=x*y;

    if(f==0)
    std::cout << "g(y): "<<y << '\n';
    else
    std::cout << "g(x): "<<y << '\n';
    std::cout << "Sum: "<<sum<< '\n';
    std::cout << "-------------------" << '\n';
  }
  //std::cout << "Final Sum(Meu-y): "<<sum<< '\n';
  ip.close();
}