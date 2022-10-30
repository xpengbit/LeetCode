#ifndef _DOG_H
#define _DOG_H
#include "animal.h"

typedef struct {
    Animal parent;
    int legs;
}Dog;

void Dog_Ctor(Dog* this, int age, int weight, int legs);

int Dog_GetAge(Dog* this);
int Dog_GetWeight(Dog* this);
int Dog_GetLegs(Dog* this);

#endif
#ifndef _DOG_H
#define _DOG_H

#include "animal.h"

typedef struct{
    Animal* parent;
    int legs;
}Dog;

void Dog_Ctor(Dog* this, int age, int weight, int legs);

int Dog_GetAge(Dog* this);
int Dog_GetWeight(Dog* this);
int Dog_GetLegs(Dog* this);

#endif