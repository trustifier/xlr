// ****************************************************************************
//  xl.optimizer.xs                 (C) 1992-2003 Christophe de Dinechin (ddd) 
//                                                                 XL2 project 
// ****************************************************************************
// 
//   File Description:
// 
//     An optimizer that works on XL bytecode
// 
// 
// 
// 
// 
// 
// 
// 
// ****************************************************************************
// This document is released under the GNU Genral Public License.
// See http://www.gnu.org/copyleft/gpl.html for details
// ****************************************************************************
// * File       : $RCSFile$
// * Revision   : $Revision$
// * Date       : $Date$
// ****************************************************************************

import BC = XL.BYTECODE

module XL.OPTIMIZER with

    // Perform various optimizations
    function Optimize(input : BC.bytecode) return BC.bytecode