//
//  checkthrownull.cpp
//  Cppcheck
//
//  Created by  yanzhensong on 4/5/16.
//
//

#include "checkthrownull.hpp"

namespace {
    CheckThrowNull checkThrowNull;
}

void CheckThrowNull:: solve(){
    for(const Token *tok = _tokenizer->tokens(); tok; tok = tok->next()){
        if(Token:: Match(tok, "throw 0")){
            reportError(tok, Severity:: error, "throw NULL", "Don't allow to throw NULL.");
        }
    }
}