//
//  checkconstnumber.hpp
//  Cppcheck
//
//  Created by  yanzhensong on 3/31/16.
//
//

#ifndef checkconstnumber_hpp
#define checkconstnumber_hpp

#include <stdio.h>
#include <iostream>
#include "check.h"
#include "config.h"
#include "mathlib.h"

class CPPCHECKLIB CheckConstNumber: public Check{
private:
    static std::string myName(){
        return "Const number checking";
    }
    std::string classInfo() const{
        return "Const number checking";
    }
public:
    /**@brief This constructor is used when registering the CheckClass*/
    CheckConstNumber(): Check(myName()){}
    
    /**@brief This constructor is used when running checks.*/
    CheckConstNumber(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger): Check(myName(), tokenizer, settings, errorLogger){}
    
    void runChecks(const Tokenizer *, const Settings *, ErrorLogger *);
    
    void runSimplifiedChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger){}
    
    /**@brief Check for const number*/
    void constNumber();
    
    void getErrorMessages(ErrorLogger *errorLogger, const Settings *settings) const{
        
    }

};

#endif /* checkconstnumber_hpp */
