//
// Created by stas_malikov on 03.09.2020.
//

#ifndef NEWTASK2_LIST_H
#define NEWTASK2_LIST_H


class List {
protected:
    const double resizeMultiplier = 1.5;
    unsigned int lastItemIndex;
    unsigned int count;

    virtual void resize(int newSize) = 0;

public:
    virtual unsigned int getCount() {return count;}
    virtual unsigned int getLastItemIndex() {return lastItemIndex;}
    virtual int remove(unsigned int itemId) = 0;

    virtual ~List(){};
};


#endif //NEWTASK2_LIST_H
