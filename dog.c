#include "dog.h"

static void _Dog_say(Dog* this){
    printf("Dog say!\n");
}

void Dog_Ctor(Dog* this, int age, int weight, int legs){
    Animal_Ctor(this->parent, age, weight);
    static AnimalVTable dog_vtable = {_Dog_say};
    this->parent.vptr = &dog_vtable;
    this->legs = legs;
}

int Dog_GetAge(Dog* this){
    return Animal_GetAge(this->parent);
}

int Dog_GetWeight(Dog* this){
    return Animal_GetWeight(this->parent);
}

int Dog_GetLegs(Dog* this){
    return this->legs;
}
#include "dog.h"

static void _Dog_say(Dog* this){
    printf("Dog say!\n");
}

void Dog_Ctor(Dog* this, int age, int weight, int legs){
    Animal_Ctor(this->parent, age, weight);
    //定义子类自己的虚表
    static AnimalVTable dog_vtable = {_Dog_say};
    //父类中继承的虚表指针指向自己的虚表
    this->parent->vptr = &dog_vtable;
    this->legs = legs;
}

int Dog_GetAge(Dog* this){
    return Animal_GetAge(this->parent);
}

int Dog_GetWeight(Dog* this){
    return Animal_GetWeight(this->parent);
}

int Dog_GetAge(Dog* this){
    return this->legs;
}