#include<iostream>
using namespace std;
template<typename T>
class Animal{
    public:
    T id_;
    Animal(T t):id_(t){}
    virtual void talk()=0;
};
template<typename T>
class Cat:public Animal<T>{
    public:
    Cat(T t):Animal<T>(t){}
    virtual void talk() override{
        cout<<"miao miao "<<Animal<T>::id_<<endl;
    }
};
template<typename T>
class Dog:public Animal<T>{
    public:
    Dog(T t):Animal<T>(t){}

    virtual void talk() override{
        cout<<"wang wang "<<Animal<T>::id_<<endl;
    }
};
template<typename T>
class Programer:public Animal<T>{
    public:
    Programer(T t):Animal<T>(t){}

    virtual void talk() override{
        cout<<"Hello world "<<Animal<T>::id_<<endl;
    }
};
template<typename T>
void LetAnimalTalk(Animal<T>* animal){
    animal->talk();
}

int main(int argc, char const *argv[])
{
    Cat<int> cat(1);
    Dog<int> dog(2);
    Programer<int> programmer(3);
    LetAnimalTalk(&cat);
    LetAnimalTalk(&dog);
    LetAnimalTalk(&programmer);
    return 0;
}

