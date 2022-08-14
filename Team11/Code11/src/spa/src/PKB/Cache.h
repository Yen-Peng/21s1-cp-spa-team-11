//
// Created by Yen Peng Yip on 24/10/21.
//

#ifndef AUTOTESTER_CACHE_H
#define AUTOTESTER_CACHE_H
#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include "StatementTypes.h"
#include "Definitions.h"
#include "NextStarCache.h"
#include "AffectsCache.h"
#include "Hasher.h"

class Cache {

private:
    static NextStarCache nextStarCache;
    static AffectsCache affectsCache;
public:
    Cache() {};

    /////////////////////// NEXTBIP ///////////////////////
    /*

    bool addNextBip(int stmt1, StatementTypes type1, int stmt2, StatementTypes type2);

    LIST_OF_INT_PAIRS getNextBipNN(int stmt1, int stmt2);
    LIST_OF_INT_PAIRS getNextBipTT(StatementTypes type1, StatementTypes type2);
    LIST_OF_INT_PAIRS getNextBipNT(int stmt1, StatementTypes type2);
    LIST_OF_INT_PAIRS getNextBipTN(StatementTypes type1, int stmt2);*/

    /////////////////////// NEXTSTAR ///////////////////////

    bool addNextStar(int stmt1, StatementTypes type1, int stmt2, StatementTypes type2);
    bool addNextStarNNCalled(int stmt1, int stmt2);
    bool isNextStarNNCalled(int stmt1, int stmt2);

    // populates and checks by (type1, _)
    bool addNextStarTTCalled(StatementTypes type1);
    bool isNextStarTTCalled(StatementTypes type1);

    bool addNextStarNTCalled(int stmt1, StatementTypes type2);
    bool isNextStarNTCalled(int stmt1, StatementTypes type2);

    bool addNextStarTNCalled(StatementTypes type1, int stmt2);
    bool isNextStarTNCalled(StatementTypes type1, int stmt2);

    LIST_OF_INT_PAIRS getNextStarNN(int stmt1, int stmt2);
    LIST_OF_INT_PAIRS getNextStarTT(StatementTypes type1, StatementTypes type2);
    LIST_OF_INT_PAIRS getNextStarNT(int stmt1, StatementTypes type2);
    LIST_OF_INT_PAIRS getNextStarTN(StatementTypes type1, int stmt2);

    /////////////////////// AFFECTS ///////////////////////

    bool addAffects(int stmt1, StatementTypes type1, int stmt2, StatementTypes type2);
    bool addAffectsNNCalled(int stmt1, int stmt2);
    bool isAffectsNNCalled(int stmt1, int stmt2);

    bool addAffectsNTCalled(int stmt1, StatementTypes type2);
    bool isAffectsNTCalled(int stmt1, StatementTypes type2);

    bool addAffectsTTCalled(StatementTypes type1, StatementTypes type2);
    bool isAffectsTTCalled(StatementTypes type1, StatementTypes type2);

    bool addAffectsTNCalled(StatementTypes type1, int stmt2);
    bool isAffectsTNCalled(StatementTypes type1, int stmt2);

    LIST_OF_INT_PAIRS getAffectsNN(int stmt1, int stmt2);
    LIST_OF_INT_PAIRS getAffectsTT(StatementTypes type1, StatementTypes type2);
    LIST_OF_INT_PAIRS getAffectsNT(int stmt1, StatementTypes type2);
    LIST_OF_INT_PAIRS getAffectsTN(StatementTypes type1, int stmt2);

    /////////////////////// AFFECTSSTAR ///////////////////////

    bool addAffectsStar(int stmt1, StatementTypes type1, int stmt2, StatementTypes type2);

    bool addAffectsStarNNCalled(int stmt1, int stmt2);
    bool isAffectsStarNNCalled(int stmt1, int stmt2);

    bool addAffectsStarNTCalled(int stmt1, StatementTypes type2);
    bool isAffectsStarNTCalled(int stmt1, StatementTypes type2);

    bool addAffectsStarTTCalled(StatementTypes type1, StatementTypes type2);
    bool isAffectsStarTTCalled(StatementTypes type1, StatementTypes type2);

    bool addAffectsStarTNCalled(StatementTypes type1, int stmt2);
    bool isAffectsStarTNCalled(StatementTypes type1, int stmt2);

    LIST_OF_INT_PAIRS getAffectsStarNN(int stmt1, int stmt2);
    LIST_OF_INT_PAIRS getAffectsStarTT(StatementTypes type1, StatementTypes type2);
    LIST_OF_INT_PAIRS getAffectsStarNT(int stmt1, StatementTypes type2);
    LIST_OF_INT_PAIRS getAffectsStarTN(StatementTypes type1, int stmt2);

    /////////////// CLEAR ///////////////

    void clear();
};


#endif //AUTOTESTER_CACHE_H
