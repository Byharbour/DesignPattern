//
//  checkfuncparam.cpp
//  Cppcheck
//
//  Created by  yanzhensong on 4/7/16.
//
//

#include "checkfuncptrparam.hpp"
#include <set>
#include <string>

namespace  {
    CheckFuncPtrParam checkFuncPtrParam;
}

void CheckFuncPtrParam:: solve(){
    int len = symbolDatabase->functionScopes.size();
    for(int i=0; i<len; i++){
        const Scope *scope = symbolDatabase->functionScopes[i];
        const Function *func = scope->function;
        std::set<std::string> var;
        for(auto it = func->argumentList.begin(); it != func->argumentList.end(); it++){
            if(it->isPointer()){
                var.insert(it->name());
            }
        }
        for(const Token *tok = scope->classStart->next(); tok; tok = tok->next()){
            
            if(Token::Match(tok, "%name% =|+=|-=|*=|/=|++|--") && var.find(tok->str()) != var.end()){
                reportError(tok, Severity::warning, "1", "Suggest not changing the parameter pointer.");
            }
        }
    }
}
