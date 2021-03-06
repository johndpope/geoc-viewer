// Copyright (c) 1997-2001  ETH Zurich (Switzerland).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Approximate_min_ellipsoid_d/include/CGAL/Approximate_min_ellipsoid_d_traits_3.h $
// $Id: Approximate_min_ellipsoid_d_traits_3.h 37176 2007-03-17 08:35:57Z afabri $
// 
//
// Author(s)     : Kaspar Fischer <fischerk@inf.ethz.ch>

#ifndef CGAL_APPROX_MIN_ELL_D_TRAITS_3_H
#define CGAL_APPROX_MIN_ELL_D_TRAITS_3_H

namespace CGAL {

  template<typename K_, typename ET_>    // kernel and exact number-type
  struct Approximate_min_ellipsoid_d_traits_3 {
    typedef double               FT;     // number type (must be double)
    typedef ET_                  ET;     // number type used for exact
                                         // computations (like i.e. computing
                                         // the exact approximation ratio
                                         // in achieved_epsilon())
    typedef typename K_::Point_3 Point;  // point type
    typedef typename K_::Cartesian_const_iterator_3 Cartesian_const_iterator;
                                         // iterator over point coordinates
    
    static int dimension(const Point& )
    {
      return 3;
    }
    
    static Cartesian_const_iterator cartesian_begin(const Point& p)
    {
      return p.cartesian_begin();
    }
  };

} // namespace CGAL

#endif // CGAL_APPROX_MIN_ELL_D_TRAITS_3_H
