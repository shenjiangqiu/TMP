#include<iostream>
#include<tuple>
using namespace std;
template<typename T>
class Animal:private T{
    public:
    void talk(){
        T::talk_impl();
    }
};
class Cat{
    public:
    void talk_impl(){
        cout<<"miao miao"<<endl;
    }
};
class Dog{
    public:
    void talk_impl(){
        cout<<"wang wang"<<endl;
    }
};
class Programer{
    public:
    void talk_impl(){
        cout<<"Hello world"<<endl;
    }
};
template<typename T>
void LetAnimalTalk(Animal<T>& animal){
    animal.talk();
}


template<typename T,int N=tuple_size<T>::value-1>
struct PrintAnimals
{
    
    static void print(T& animals){
        PrintAnimals<T,N-1>::print(animals);
        get<N>(animals).talk();
    }
    /* data */
};
template<typename T>
struct PrintAnimals<T,0>
{
    static void print(T& animals){
        get<0>(animals).talk();
    }
};
template<typename T>
void print_animals(T &t){
    PrintAnimals<T>::print(t);
}



int main(int argc, char const *argv[])
{
    Animal<Cat> cat;
    Animal<Dog> dog;
    Animal<Programer> programmer;
    LetAnimalTalk(cat);
    LetAnimalTalk(dog);
    LetAnimalTalk(programmer);

    auto animal_family=make_tuple(cat,dog,programmer);
    get<0>(animal_family).talk();
    get<1>(animal_family).talk();
    get<2>(animal_family).talk();

    print_animals(animal_family);
    return 0;
}

