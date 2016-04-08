//
//  checkassignmentinbool.hpp
//  Cppcheck
//
//  Created by  yanzhensong on 4/7/16.
//
//

#ifndef checkassignmentinbool_hpp
#define checkassignmentinbool_hpp

#include <stdio.h>
#include <string>
#include <iostream>

#include "check.h"

class CheckAssignmentInBool: public Check{
private:
    std::string myName() const{
        return "Check assignment in bool";
    }
public:
    CheckAssignmentInBool(): Check(myName()){}
    
    CheckAssignmentInBool(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger): Check(myName(), tokenizer, settings, errorLogger){}
    
    void solve();
    
    void runChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger){
        CheckAssignmentInBool checkAssignmentInBool(tokenizer, settings, errorLogger);
        checkAssignmentInBool.solve();
    }
    
    void runSimplifiedChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger){
    }
    
    void getErrorMessages(ErrorLogger *errorLogger, const Settings *settings) const{}
    
    std::string classInfo() const{
        return myName();
    }
};

#endif /* checkassignmentinbool_hpp */
