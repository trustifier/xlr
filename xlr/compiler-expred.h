#ifndef COMPILER_EXPRED_H
#define COMPILER_EXPRED_H
// ****************************************************************************
//  compiler-expred.h                                               XLR project
// ****************************************************************************
// 
//   File Description:
// 
//    Information required by the compiler for expression reduction
// 
// 
// 
// 
// 
// 
// 
// 
// ****************************************************************************
// This document is released under the GNU General Public License.
// See http://www.gnu.org/copyleft/gpl.html and Matthew 25:22 for details
//  (C) 1992-2010 Christophe de Dinechin <christophe@taodyne.com>
//  (C) 2010 Taodyne SAS
// ****************************************************************************

#include "compiler.h"

XL_BEGIN

struct ExpressionReduction
// ----------------------------------------------------------------------------
//   Record compilation state for a specific expression reduction
// ----------------------------------------------------------------------------
//   Expression reduction is the name given to the process of transforming
//   a given expression into another tree using the -> operators. For example,
//   if we have A+B*C -> mla(A,B,C), we will "reduce" 2+3*5 into mla(2,3,5).
//   This process may involve multiple rewrites if there is some pattern
//   matching involved, for example if we reduce N! with two rewrite rules,
//   one for 0!, one for N! when N is not 0.
{

    ExpressionReduction(CompiledUnit &unit, Tree *source);
    ~ExpressionReduction();

    void                NewForm();
    void                Succeeded();
    void                Failed();

public:
    CompiledUnit &      unit;           // Compilation unit we use
    Tree *              source;         // Tree we build (mostly for debugging)
    llvm::LLVMContext * context;        // Inherited context

    llvm::Value *       storage;        // Storage for expression value
    llvm::Value *       computed;       // Flag telling if value was computed

    llvm::BasicBlock *  savedfailbb;    // Saved location of failbb

    llvm::BasicBlock *  entrybb;        // Entry point to subcase
    llvm::BasicBlock *  savedbb;        // Saved position before subcase
    llvm::BasicBlock *  successbb;      // Successful completion of expression

    value_map           savedvalue;     // Saved compile unit value map
};

XL_END

#endif // COMPILER_EXPRED_H
