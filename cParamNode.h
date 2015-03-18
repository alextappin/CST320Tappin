#pragma once
//*******************************************************
// Purpose: A list of actual params passed to a function
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
// Edited-By:   Alexander Tappin
// Date: 2/20/2015
//
//*******************************************************

#include <string>
#include <list>

#include "cAstNode.h"
#include "cExprNode.h"
#include "cAstList.h"

using std::list;

class cParamNode: public cAstNode
{
  public:
    // place the first param in the list
    cParamNode(cExprNode *param) : cAstNode()
    {
        mList = new list<cExprNode *>();
        if (param != NULL) mList->push_back(param);
    }

    // place the next param in the list
    void AddNode(cExprNode *param) 
    {
        mList->push_back(param);
    }

    // return a specific param
    cExprNode *GetParam(int index)
    {
        return ListGetItem(mList, index);
    }

    int NumParams()
    { 
        return mList->size(); 
    }

    virtual std::string toString()
    {
        std::string result("(PARAM:");
        result += ListToString(mList, false);
        result += ")\n";

        return result;
    }
    
    int GetSize()
    {
        return mSize;
    }
    
    virtual int Computeoffsets(int base)
    {
        int offset;
        for(auto &it: *mList)
            offset = it->Computeoffsets(base);
        mSize = offset;
        
        return base;
    }

    void GenerateCode()
    {
        list<cExprNode *>::iterator it = mList->begin();
      
        for(;it != mList->end(); it++)
        {
            if ((*it)->GetType()->IsFloat())
            {   
                EmitString("*(double*)(&Memory[Stack_Pointer]) = ");
            }
            else
            {
                EmitString("*(int*)(&Memory[Stack_Pointer]) = ");
            }
            
            (*it)->GenerateCode();
            EmitString(";\n");
            EmitString("Stack_Pointer += 4;\n");
        }
    }
    
  protected:
    list<cExprNode *> *mList;       // list of parameters
    int mSize;
};

