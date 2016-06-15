/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#pragma once

/**
 * @file CanonicSCellEmbedder.h
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5127), University of Savoie, France
 *
 * @date 2012/02/28
 *
 * Header file for module CanonicSCellEmbedder.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(CanonicSCellEmbedder_RECURSES)
#error Recursive header files inclusion detected in CanonicSCellEmbedder.h
#else // defined(CanonicSCellEmbedder_RECURSES)
/** Prevents recursive inclusion of headers. */
#define CanonicSCellEmbedder_RECURSES

#if !defined CanonicSCellEmbedder_h
/** Prevents repeated inclusion of headers. */
#define CanonicSCellEmbedder_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/base/ConstAlias.h"
#include "DGtal/topology/CPreCellularGridSpaceND.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

/////////////////////////////////////////////////////////////////////////////
// class CanonicSCellEmbedder
/**
   Description of class 'CanonicSCellEmbedder' <p>

   \brief Aim: A trivial embedder for signed cell, which
   corresponds to the canonic injection of cell centroids into Rn.

   Model of CSCellEmbedder.

   @tparam TKSpace the type of cellular grid space where the embedder works, a model of CPreCellularGridSpaceND.
 */
  template <typename TKSpace>
  struct CanonicSCellEmbedder
  {
  public:
    typedef CanonicSCellEmbedder<TKSpace> Self;
    BOOST_CONCEPT_ASSERT(( concepts::CPreCellularGridSpaceND<TKSpace> ));

    typedef TKSpace KSpace;
    typedef typename KSpace::SCell SCell;
    typedef typename KSpace::Space Space;
    typedef typename Space::RealPoint RealPoint;
    typedef SCell Argument;
    typedef RealPoint Value;

    typedef typename Space::Integer Integer;
    typedef typename Space::Point Point;

    // ----------------------- Standard services ------------------------------
  public:
    /**
       Destructor. Nothing special.
    */
    ~CanonicSCellEmbedder();

    /**
       Default constructor. The object is not valid.
    */
    CanonicSCellEmbedder();

    /**
       Constructor from space.
    */
    CanonicSCellEmbedder( ConstAlias<KSpace> aKSpace );

    /**
       Copy constructor.
       @param other the object to clone.
    */
    CanonicSCellEmbedder( const Self & other );

    /**
       Assignment.
       @param other the object to clone.
       @return a reference to 'this'.
    */
    Self & operator=( const Self & other );

    /**
       @return the cellular grid space.
    */
    const KSpace & space() const;

    /**
       Map a signed cell to its corresponding point in the Euclidean
       space.

       @param cell any signed cell in the digital space.
       @return its canonical embedding in the Euclidean space.
    */
    RealPoint embed( const SCell & cell ) const;

    /**
       Map a signed cell to its corresponding point in the Euclidean
       space.

       @param cell any signed cell in the digital space.
       @return its canonical embedding in the Euclidean space.
    */
    RealPoint operator()( const SCell & cell ) const;

    // ----------------------- Interface --------------------------------------
public:

    /*
     * Writes/Displays the object on an output stream.
     * @param out the output stream where the object is written.
     */
    //void selfDisplay ( std::ostream & out ) const;

    /**
     * Checks the validity/consistency of the object.
     * @return 'true' if the object is valid, 'false' otherwise.
     */
    bool isValid() const;

    // ------------------------- Protected Datas ------------------------------
  protected:
    const KSpace* myKSpace;

    // ------------------------- Private Datas --------------------------------
private:

    // ------------------------- Hidden services ------------------------------
protected:


    // ------------------------- Internals ------------------------------------
private:

}; // end of class CanonicSCellEmbedder


/**
 * Overloads 'operator<<' for displaying objects of class 'CanonicSCellEmbedder'.
 * @param out the output stream where the object is written.
 * @param object the object of class 'CanonicSCellEmbedder' to write.
 * @return the output stream after the writing.
 */
  template <typename TKSpace>
  std::ostream&
  operator<< ( std::ostream & out, const CanonicSCellEmbedder<TKSpace> & object );


} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#include "DGtal/topology/CanonicSCellEmbedder.ih"


//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined CanonicSCellEmbedder_h

#undef CanonicSCellEmbedder_RECURSES
#endif // else defined(CanonicSCellEmbedder_RECURSES)
