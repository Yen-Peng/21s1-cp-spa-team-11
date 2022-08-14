#pragma once
#include <iostream>
#include "TestWrapper.h"
#include "Parser/Parser.h"
#include "Parser/Tokeniser.h"
#include "Parser/AssignmentParser.h"
#include "PKB/PKB.h"
#include "QueryPreprocessor.h"
#include "ParserException.h"

// implementation code of WrapperFactory - do NOT modify the next 5 lines
AbstractWrapper* WrapperFactory::wrapper = 0;
AbstractWrapper* WrapperFactory::createWrapper() {
  if (wrapper == 0) wrapper = new TestWrapper;
  return wrapper;
}
// Do not modify the following line
volatile bool AbstractWrapper::GlobalStop = false;

// a default constructor
TestWrapper::TestWrapper() {
  // create any objects here as instance variables of this class
  // as well as any initialization required for your spa program
	_parser = new Parser();
	_sharedPkb = new PKB();
    _de = new DesignExtractor();
    _qe = new QueryEvaluator();
    _resultProjector = new QueryResultProjector();
}

// method for parsing the SIMPLE source
void TestWrapper::parse(std::string filename) {
	// call your parser to do the parsing
    std::string fileString = _parser->fileToString(filename);
    try
    {
        _parser->Parse(fileString);
        _de->populateAssignmentSubExpressions();
        _de->populateDesignAbstractions();
    } catch (exception& e)
    {
        cout << "Exception: " << e.what() << endl;
        std::exit(1);
    }

  // ...rest of your code...
}

// method to evaluating a query
void TestWrapper::evaluate(std::string query, std::list<std::string>& results){
// call your evaluator to evaluate the query here
  // ...code to evaluate query...
    _qe->reset();
    QueryPreprocessor::parse(query);
    
    cout << endl;
    _qe->getInstance().evaluate();
    list<string>* queryResult = _resultProjector->getInstance().getProcessedResult();
    results = *queryResult;
    _resultProjector->getInstance().resetResultProjector();
    cout << "TestWrapper evaluate result size: " << "\n";

    for (auto a : _sharedPkb->getNextStarTT(CALL, PRINT)) {
        cout << "get from pkb " << a.first << " " << a.second << endl;
    }
    cout << endl;
    _sharedPkb->clearCache();
}
