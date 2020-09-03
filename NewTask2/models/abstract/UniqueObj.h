//
// Created by stas_malikov on 19.08.2020.
//

#ifndef NEWTASK2_UNIQUEOBJ_H
#define NEWTASK2_UNIQUEOBJ_H

#include "../../services/Utils.h"

class UniqueObj {
protected:
    unsigned int id;
public:
    UniqueObj() : id(Utils::generateId()) {}
    UniqueObj(unsigned int _id) : id(_id) {}
    unsigned int getId() {return id;}

    const UniqueObj& operator=(const UniqueObj& uObj){
        id = uObj.id;
        return *this;
    }
};

#endif //NEWTASK2_UNIQUEOBJ_H
