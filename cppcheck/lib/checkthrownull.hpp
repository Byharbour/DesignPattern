//
//  checkthrownull.hpp
//  Cppcheck
//
//  Created by  yanzhensong on 4/5/16.
//
//

#ifndef checkthrownull_hpp
#define checkthrownull_hpp

#include <stdio.h>
#include <string>
#include <iostream>

#include "check.h"


class CheckThrowNull: public Check{
private:
    std::string myName() const{
        return "Check throw null";
    }
public:
    CheckThrowNull(): Check(myName()){}
    
    CheckThrowNull(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger): Check(myName(), tokenizer, settings, errorLogger){}
    
    void solve();
    
    void runSimplifiedChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger){
        CheckThrowNull checkThrowNull(tokenizer, settings, errorLogger);
        checkThrowNull.solve();
    }
    
    void getErrorMessages(ErrorLogger *errorLogger, const Settings *settings) const{}
    
    std::string classInfo() const{
        return myName();
    }
};
#endif /* checkthrownull_hpp */
