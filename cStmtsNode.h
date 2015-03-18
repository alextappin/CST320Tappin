#pragma once
//*******************************************************
// Purpose: Class for a list of statements
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>
#include <list>
using std::list;

#include "cAstNode.h"
#include "cAstList.h"

class cStmtsNode : public cAstNode
{
  public:
    // create the list and insert the first statement
    cStmtsNode(cStmtNode *stmt) : cAstNode()
    {
        mList = new list<cStmtNode *>();
        mList->push_back(stmt);
    }

    // add a statement to the list
    void AddNode(cStmtNode *stmt) 
    {
        mList->push_back(stmt);
    }

    virtual std::string toString()
    {
        std::string result("STMTS:\n{\n");
        result += ListToString(mList, true);
        result += "}\n";

        return result;
    }
    
    virtual int Computeoffsets(int base)
    {
        int offset = base;
      
        for (auto &it: *mList)
        {
          offset = it->Computeoffsets(offset);
        }
        
        mSize = offset - base;
        return offset;
    }
    
    void GenerateCode()
    {
        list<cStmtNode *>::iterator it = mList->begin();
      
        for(;it != mList->end(); it++)
        {
            (*it)->GenerateCode();
        }
    }
    
  protected:
    list<cStmtNode *> *mList;   // list of statements
    int mSize;
};

