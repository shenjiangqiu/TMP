#include<iostream>
using namespace std;
template<typename T>
class Animal{
    public:
    void talk(){
        static_cast<T*>(this)->talk_impl();
    }
};
class Cat:public Animal<Cat>{
    public:
     void talk_impl() {
        cout<<"miao miao"<<endl;
    }
};
class Dog:public Animal<Dog>{
    public:
     void talk_impl() {
        cout<<"wang wang"<<endl;
    }
};
class Programer:public Animal<Programer>{
    public:
     void talk_impl() {
        cout<<"Hello world"<<endl;
    }
};
template<typename T>
void LetAnimalTalk(Animal<T>& animal){
    animal.talk();
}

int main(int argc, char const *argv[])
{
    Cat cat;
    Dog dog;
    Programer programmer;
    LetAnimalTalk(cat);
    LetAnimalTalk(dog);
    LetAnimalTalk(programmer);
    return 0;
}

