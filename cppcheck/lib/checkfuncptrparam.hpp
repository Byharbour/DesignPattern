//
//  checkfuncparam.hpp
//  Cppcheck
//
//  Created by  yanzhensong on 4/7/16.
//
//

#ifndef checkfuncparam_hpp
#define checkfuncparam_hpp

#include <stdio.h>
#include <string>
#include <iostream>

#include "check.h"
#include "symboldatabase.h"
#include "config.h"

class Scope;
class Function;

class CheckFuncPtrParam: public Check{
private:
    std::string myName() const{
        return "Check function pointer parameter";
    }
    const SymbolDatabase *symbolDatabase;
public:
    CheckFuncPtrParam(): Check(myName()){}
    
    CheckFuncPtrParam(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger): Check(myName(), tokenizer, settings, errorLogger){
        if(tokenizer) symbolDatabase = tokenizer->getSymbolDatabase();
        else symbolDatabase = 0;
    }
    
    void solve();
    
    void runChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger){
        CheckFuncPtrParam checkFuncPtrParam(tokenizer, settings, errorLogger);
        checkFuncPtrParam.solve();
    }
    
    void runSimplifiedChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger){
    }
    
    void getErrorMessages(ErrorLogger *errorLogger, const Settings *settings) const{}
    
    std::string classInfo() const{
        return myName();
    }
};


#endif /* checkfuncparam_hpp */
