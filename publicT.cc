#include<iostream>
using namespace std;
template<typename T>
class Animal:public T{
   
};
class Cat{
    public:
    void talk(){
        cout<<"miao miao"<<endl;
    }
};
class Dog{
    public:
    void talk(){
        cout<<"wang wang"<<endl;
    }
};
class Programer{
    public:
    void talk(){
        cout<<"Hello world"<<endl;
    }
};
template<typename T>
void LetAnimalTalk(Animal<T>& animal){
    animal.talk();
}

int main(int argc, char const *argv[])
{
    Animal<Cat> cat;
    Animal<Dog> dog;
    Animal<Programer> programmer;
    LetAnimalTalk(cat);
    LetAnimalTalk(dog);
    LetAnimalTalk(programmer);
    return 0;
}

