// Copyright (c) 2000  Max-Planck-Institute Saarbruecken (Germany).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Partition_2/include/CGAL/Partition_2/Partition_opt_cvx_vertex.h $
// $Id: Partition_opt_cvx_vertex.h 31311 2006-05-29 08:30:22Z wein $
// 
//
// Author(s)     : Susan Hert <hert@mpi-sb.mpg.de>

#ifndef CGAL_PARTITION_OPT_CVX_VERTEX_H
#define CGAL_PARTITION_OPT_CVX_VERTEX_H

#include <list>
#include <CGAL/Partition_2/Partition_opt_cvx_diagonal_list.h>

namespace CGAL {

class Partition_opt_cvx_stack_record 
{
public:

   Partition_opt_cvx_stack_record() {}

   Partition_opt_cvx_stack_record(unsigned int old,  int value) : 
       _old(old), _value(value), _solution(Partition_opt_cvx_diagonal_list()) 
   {}

   Partition_opt_cvx_stack_record(unsigned int old,  int value, 
                            const Partition_opt_cvx_diagonal_list& solution) : 
       _old(old), _value(value), _solution(solution) 
   {}

   unsigned int vertex_num() { return _old; }

   int value() {return _value; }

   Partition_opt_cvx_diagonal_list solution() { return _solution; }

private:
   unsigned int _old;
   int _value;
   Partition_opt_cvx_diagonal_list _solution;
};

class Partition_opt_cvx_vertex 
{
public:

   Partition_opt_cvx_vertex() {}

   Partition_opt_cvx_vertex(unsigned int v_num): _v_num(v_num), 
                      _stack(std::list<Partition_opt_cvx_stack_record>()),
                      _best_so_far(Partition_opt_cvx_stack_record(0, 0))
   {}

   unsigned int vertex_num( ) { return _v_num; }

   Partition_opt_cvx_stack_record best_so_far( ) 
   { 
      return _best_so_far;
   }

   bool stack_empty() { return _stack.empty(); }

   // Pre:  stack is not empty
   Partition_opt_cvx_stack_record stack_top()
   {
      return _stack.back();
   }

   void stack_push(unsigned int vertex, int value, 
                   const Partition_opt_cvx_diagonal_list& diag_list) 
   {
      _best_so_far = Partition_opt_cvx_stack_record(vertex, value, diag_list);
      _stack.push_back(_best_so_far);
   }
   
   // Pre:  stack is not empty
   void stack_pop() 
   {
       _best_so_far = _stack.back();
       _stack.pop_back();
   }

private:
   unsigned int                               _v_num;
   std::list<Partition_opt_cvx_stack_record>  _stack;
   Partition_opt_cvx_stack_record             _best_so_far;
};

}

#endif // CGAL_PARTITION_OPT_CVX_VERTEX_H
