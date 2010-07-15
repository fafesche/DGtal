#pragma once

/**
 * @file DigitalSetDomain.h
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5807), University of Savoie, France
 *
 * @date 2010/07/10
 *
 * Header file for module DigitalSetDomain.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(DigitalSetDomain_RECURSES)
#error Recursive header files inclusion detected in DigitalSetDomain.h
#else // defined(DigitalSetDomain_RECURSES)
/** Prevents recursive inclusion of headers. */
#define DigitalSetDomain_RECURSES

#if !defined DigitalSetDomain_h
/** Prevents repeated inclusion of headers. */
#define DigitalSetDomain_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/kernel/sets/SetPredicate.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // template class DigitalSetDomain
  /**
   * Description of template class 'DigitalSetDomain' <p>
   * \brief Aim: Constructs a domain limited to the given digital set.
   */
  template <typename TDigitalSet>
  class DigitalSetDomain
  {
    // ----------------------- associated types -------------------------------
  public:
    typedef TDigitalSet DigitalSet;
    typedef typename DigitalSet::DomainType Domain;
    typedef typename Domain::Space Space;
    typedef typename Domain::Point Point;
    typedef typename Domain::Vector Vector;
    typedef typename Domain::SizeType SizeType;
    typedef typename DigitalSet::ConstIterator ConstIterator;
    typedef SetPredicate<DigitalSet> Predicate;
    // ----------------------- Standard services ------------------------------
  public:

    /**
     * Destructor.
     */
    ~DigitalSetDomain();

    /**
     * Coonstructor from set.
     * @param aSet the digital set.
     */
    DigitalSetDomain ( const DigitalSet & aSet );


    /**
     * Copy constructor.
     * @param other the object to clone.
     */
    DigitalSetDomain ( const DigitalSetDomain & other );

    // ----------------------- Domain services --------------------------------
  public:

    /**
     * @return an iterator on the first element of the domain.
     **/
    ConstIterator begin() const;

    /**
     * @return an iterator on the element after the last of the domain.
     **/
    ConstIterator end() const;

    /**
     * Returns the lowest point of the space diagonal.
     *
     **/
    const Point &lowerBound() const;

    /**
     * Returns the highest point of the space diagonal.
     *
     **/
    const Point &upperBound() const ;

    /**
     * @param p any point.
     * @return 'true' if point [p] is inside this domain.
     */
    bool isInside( const Point & p ) const;

    /**
     * @return a const reference to the "IsInside" predicate.
     */
    const Predicate & predicate() const;


    // ----------------------- Interface --------------------------------------
  public:

    /**
     * Writes/Displays the object on an output stream.
     * @param out the output stream where the object is written.
     */
    void selfDisplay ( std::ostream & out ) const;

    /**
     * Checks the validity/consistency of the object.
     * @return 'true' if the object is valid, 'false' otherwise.
     */
    bool isValid() const;

    // ------------------------- Protected Datas ------------------------------
  private:
    // ------------------------- Private Datas --------------------------------
  private:

    /**
     * The set describing the points of the domain.
     */
    const DigitalSet & mySet;

    /**
     * upper bound of the bounding box.
     */
    Point myUpperBound;

    /**
     * lower bound of the bounding box.
     */
    Point myLowerBound;

    /// The "IsInside" predicate.
    Predicate myPredicate;

    // ------------------------- Hidden services ------------------------------
  protected:

    /**
     * Constructor.
     * Forbidden by default (protected to avoid g++ warnings).
     */
    DigitalSetDomain();

  private:

    /**
     * Assignment.
     * @param other the object to copy.
     * @return a reference on 'this'.
     * Forbidden by default.
     */
    DigitalSetDomain & operator= ( const DigitalSetDomain & other );

    // ------------------------- Internals ------------------------------------
  private:
    

  }; // end of class DigitalSetDomain


  /**
   * Overloads 'operator<<' for displaying objects of class 'DigitalSetDomain'.
   * @param out the output stream where the object is written.
   * @param object the object of class 'DigitalSetDomain' to write.
   * @return the output stream after the writing.
   */
  template <typename T>
  std::ostream&
  operator<< ( std::ostream & out, const DigitalSetDomain<T> & object );

} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#include "DGtal/kernel/sets/DigitalSetDomain.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined DigitalSetDomain_h

#undef DigitalSetDomain_RECURSES
#endif // else defined(DigitalSetDomain_RECURSES)