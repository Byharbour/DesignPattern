//
//  checkconstnumber.cpp
//  Cppcheck
//
//  Created by  yanzhensong on 3/31/16.
//
//

#include "checkconstnumber.hpp"

//register the check class
namespace {
    CheckConstNumber checkConstNumber;
}

void CheckConstNumber:: runChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger){
    CheckConstNumber checkConstNumber(tokenizer, settings, errorLogger);
    checkConstNumber.constNumber();
}

void CheckConstNumber:: constNumber(){
    for(const Token *tok = _tokenizer->tokens(); tok; tok = tok->next()){
        if(Token::Match(tok, "const %type% %var% = %num% ;")){
            tok = tok->tokAt(5);
            continue;
        }
        if(Token::Match(tok, "%op%|%comp% %num%")){
            reportError(tok, Severity::warning, "const number", "Suggest using const variable to replace the const number.");
        }
    }
}