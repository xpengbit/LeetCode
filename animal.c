#include "Animal.h"
#include <assert.h>

void _Animal_Say(Animal* this){
    assert(0);
}

void Animal_Ctor(Animal*this, int age, int weight){
    static struct AnimalVTalbe animal_vtable = {_Animal_Say};
    this->vptr = &animal_vtable;
    this->age = age;
    this->weight = weight;
}

int Animal_GetAge(Animal* this){
    return this->age;
}

int Animal_GetWeight(Animal* this){
    return this->weight;
}

int Animal_Say(Animal* this){
    return this->vptr->say(this);
}
#include "animal.h"
#include <assert.h>

//父类中虚函数的具体实现
void _Animal_say(Animal* this){
    //父类Animal是一个抽象，不应该被实例化
    //父类中这个函数不应该被调用，子类必须实现这个函数
    //类似c++中的纯虚函数
    assert(0);
}

void Animal_Ctor(Animal* this, int age, int weight){
    static struct AnimalVTable animal_vtable = {_Animal_say}; 
    this->vptr = &animal_vtable;
    this->age = age;
    this->weight = weight;
}

int Animal_GetAge(Animal* this){
    return this->age;
}

int Animal_GetWeight(Animal* this){
    return this->weight;
}

void Animal_Say(Animal* this){
    this->vptr->say(this);
}