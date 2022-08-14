//
// Created by Xuan Zhi on 6/11/21.
//

#ifndef AUTOTESTER_AFFECTSBIPEXTRACTOR_H
#define AUTOTESTER_AFFECTSBIPEXTRACTOR_H
#include<stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <utility>
#include "StatementTypes.h"

class AffectsBipExtractor {

public:
    static std::vector<std::pair<int, int>> getAffectsNN(int stmt1, int stmt2);
    static std::vector<std::pair<int, int>> getAffectsNT(int stmt1, StatementTypes stmt2Type);
    static std::vector<std::pair<int, int>> getAffectsTN(StatementTypes stmt1Type, int stmt2);
    static std::vector<std::pair<int, int>> getAffectsTT(StatementTypes stmt1Type, StatementTypes stmt2Type);

    static std::vector<std::pair<int, int>> getAffectsStarNN(int stmt1, int stmt2);
    static std::vector<std::pair<int, int>> getAffectsStarNT(int stmt1, StatementTypes stmt2Type);
    static std::vector<std::pair<int, int>> getAffectsStarTN(StatementTypes stmt1Type, int stmt2);
    static std::vector<std::pair<int, int>> getAffectsStarTT(StatementTypes stmt1Type, StatementTypes stmt2Type);
};


#endif //AUTOTESTER_AFFECTSBIPEXTRACTOR_H
