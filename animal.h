
#ifndef _ANIMAL_H
#define _ANIMAL_H

struct AnimalVTable;

typedef struct{
    struct AnimalVTable* vptr;
    int age;
    int weihgt;
}Animal;

struct AnimalVTable{
    void (*say)(Animal* this) //虚函数指针
}

//父类构造函数
void Animal_Ctor(Animal* this, int age, int weight);

//父类操作声明
int Animal_GetAge(Animal* this);
int Animal_GetWeight(Animal* this);

void _Animal_Say(Animal* this);
#endif

#ifndef _ANIMAL_H
#define _ANIMAL_H

struct AnimalVTable;

//定义父类结构
typedef struct{
    struct AnimalVTable* vptr; //父类的虚表指针
    int age;
    int weight;
}Animal;

//定义父类的虚函数表
struct AnimalVTable{
    void (*say)(Animal* this);  //虚函数指针
}


//父类构造声明
void Animal_Ctor(Animal* this, int age, int weight);

//父类操作声明
int Animal_GetAge(Animal* this);
int Animal_GetWeight(Animal* this);

//父类中实现的虚函数
void Animal_Say(Animal* this);

#endif