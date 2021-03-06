// Copyright (c) 2005  Tel-Aviv University (Israel).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Arrangement_on_surface_2/include/CGAL/IO/Qt_widget_Linear_object_2.h $
// $Id: Qt_widget_Linear_object_2.h 56667 2010-06-09 07:37:13Z sloriot $
// $Date: 2010-06-09 09:37:13 +0200 (Wed, 09 Jun 2010) $
// 
//
// Author(s)     : Ron Wein  <wein@post.tau.ac.il>
//                 Efi Fogel <efif@post.tau.ac.il>

#ifndef CGAL_QT_WIDGET_LINEAR_OBJECT_2_H
#define CGAL_QT_WIDGET_LINEAR_OBJECT_2_H

#include <CGAL/IO/Qt_widget.h>
#include <CGAL/Arr_linear_traits_2.h>

namespace CGAL {

/*!
 * Export a polyline to a window stream 
 */
template <class K>
Qt_widget & operator<<(Qt_widget & ws, const Arr_linear_object_2<K> & o)
{
  if(o.is_segment())
  {
    ws << o.segment();
    return ws;
  }
  if(o.is_ray())
  {
    ws << o.ray();
    return ws;
  }

  CGAL_assertion(o.is_line());
  ws << o.line();
  return ws;
}

} //namespace CGAL

#endif
