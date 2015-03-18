#pragma once
//*******************************************************
// Purpose: Class for a while statement
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>

#include "cStmtNode.h"
#include "cExprNode.h"

class cWhileNode : public cStmtNode
{
  public:
    cWhileNode(cExprNode *expr, cStmtNode *stmt) : cStmtNode()
    {
        mExpr = expr;
        mStmt = stmt;
    }

    virtual std::string toString()
    {
        std::string result("(WHILE: ");
        result += mExpr->toString();
        result += "\n" + mStmt->toString();
        result += "\n)";
        return result;
    }
    
    int Computeoffsets(int base)
    {
        mExpr->Computeoffsets(base);
        mStmt->Computeoffsets(base);
        
        return base;
    }
    
    void GenerateCode()
    {
        EmitString("while (");
        mExpr->GenerateCode();
        EmitString(")\n{\n");
        mStmt->GenerateCode();
        EmitString("\n}");
    }
    
  protected:
    cExprNode *mExpr;       // conditional expression
    cStmtNode *mStmt;       // statement to execute while true
};

