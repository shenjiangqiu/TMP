#include<iostream>
using namespace std;

class Animal{
    public:
    virtual void talk()=0;
};
class Cat:public Animal{
    public:
    virtual void talk() override{
        cout<<"miao miao"<<endl;
    }
};
class Dog:public Animal{
    public:
    virtual void talk() override{
        cout<<"wang wang"<<endl;
    }
};
class Programer:public Animal{
    public:
    virtual void talk() override{
        cout<<"Hello world"<<endl;
    }
};
void LetAnimalTalk(Animal* animal){
    animal->talk();
}

int main(int argc, char const *argv[])
{
    Cat cat;
    Dog dog;
    Programer programmer;
    LetAnimalTalk(&cat);
    LetAnimalTalk(&dog);
    LetAnimalTalk(&programmer);
    return 0;
}

