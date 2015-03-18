#pragma once
//*******************************************************
// Purpose: Base class for all expressions
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
// Edited-By:   Alexander Tappin
// Date: 2/20/2015
//
//*******************************************************

#include <string>

#include "cAstNode.h"

class cExprNode : public cAstNode
{
  public:
    cExprNode() : cAstNode()
    {}
    
    // return the type of the expression
    virtual cDeclNode *GetType() =  0;
    
    virtual void GenerateCode() 
    {}
};

