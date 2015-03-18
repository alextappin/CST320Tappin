#pragma once
//*******************************************************
// Purpose: Class for a print statement
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
// Edited-By:   Alexander Tappin
// Date: 2/20/2015
//
//*******************************************************

#include <string>

#include "cStmtNode.h"
#include "cExprNode.h"

class cPrintNode : public cStmtNode
{
  public:
    cPrintNode(cExprNode *expr) : cStmtNode()
    {
        mExpr = expr;
    }

    virtual std::string toString()
    {
        std::string result("PRINT: ");
        result += mExpr->toString();
        return result;
    }
    
    virtual int Computeoffsets(int base)
    {
        mExpr->Computeoffsets(base);
        return base;
    }
    
    void GenerateCode()
    {
        if(mExpr->GetType()->IsFloat())
            EmitString("Temp_F = ");
        else
            EmitString("Temp = ");
            
        if(mExpr != nullptr)
        {
            mExpr->GenerateCode();
        }
        
        EmitString(";\n");
        if(mExpr->GetType()->IsFloat())
            EmitPrintTemp_F();
        else
            EmitPrintTemp();
    }
    
  protected:
    cExprNode *mExpr;       // expression to be printed
};

