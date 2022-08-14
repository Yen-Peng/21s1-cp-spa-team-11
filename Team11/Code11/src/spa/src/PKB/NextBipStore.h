//
// Created by Yen Peng Yip on 24/10/21.
//

#ifndef AUTOTESTER_NEXTBIPCACHE_H
#define AUTOTESTER_NEXTBIPCACHE_H

#pragma once
#include <vector>
#include "StatementTypes.h"
#include "Relationship.h"
#include "Definitions.h"

class NextBipStore {
public:
    NextBipStore();
    virtual void clear();
    virtual bool add(int stmt1, StatementTypes type1, int stmt2, StatementTypes type2);

    virtual LIST_OF_INT_PAIRS getNN(int stmt1, int stmt2);
    virtual LIST_OF_INT_PAIRS getTT(StatementTypes type1, StatementTypes type2);
    virtual LIST_OF_INT_PAIRS getNT(int stmt1, StatementTypes type2);
    virtual LIST_OF_INT_PAIRS getTN(StatementTypes type1, int stmt2);
    /*
    virtual bool addStar(int stmt1, StatementTypes type1, int stmt2, StatementTypes type2);
    virtual LIST_OF_INT_PAIRS getStarNN(int stmt1, int stmt2);
    virtual LIST_OF_INT_PAIRS getStarTT(StatementTypes type1, StatementTypes type2);
    virtual LIST_OF_INT_PAIRS getStarNT(int stmt1, StatementTypes type2);
    virtual LIST_OF_INT_PAIRS getStarTN(StatementTypes type1, int stmt2);*/

private:
    static Relationship<int, int> nextBip;
};

#endif //AUTOTESTER_NEXTBIPCACHE_H
