#pragma once
//*******************************************************
// Purpose: Base class for all statements
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
// Edited-By:   Alexander Tappin
// Date: 2/20/2015
//
//*******************************************************

#include <string>

#include "cAstNode.h"

class cStmtNode : public cAstNode
{
  public:
    cStmtNode() : cAstNode()
    {}
    
/*    virtual void GenerateCode()
    {}*/
};

