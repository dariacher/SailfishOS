#include "counter.h"
/*
Counter::Counter():QObject()
{
  //  count = 0;
}*/


void Counter::increment(){
    count++;
    emit countChange();
}


void Counter::toNull(){
    count = 0;
    emit countChange();
}

int Counter::getCount(){
    return count;
}


