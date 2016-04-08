//
//  checkassignmentinbool.cpp
//  Cppcheck
//
//  Created by  yanzhensong on 4/7/16.
//
//

#include "checkassignmentinbool.hpp"

namespace {
    CheckAssignmentInBool checkAssignmentInBool;
    
}

void CheckAssignmentInBool::solve(){
    for (const Token *tok = _tokenizer->tokens(); tok; tok = tok->next()){
        if(Token::Match(tok, "while|if (")){
            tok = tok->tokAt(2);
            int cnt = 1;
            for (; tok; tok = tok->next()) {
                if(tok->str() == ")") cnt--;
                if(tok->str() == "(") cnt++;
                if(Token::Match(tok, "%name% = %num%|%name%")){
                    reportError(tok, Severity::warning, "1", "There is assignment in bool expression.");
                }
                if(!cnt) break;
            }
        }
    }
}