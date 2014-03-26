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
 * @file LinearOperator.h
 * @author Pierre Gueth (\c pierre.gueth@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systemes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2014/03/26
 *
 * Header file for module LinearOperator.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(LinearOperator_RECURSES)
#error Recursive header files inclusion detected in LinearOperator.h
#else // defined(LinearOperator_RECURSES)
/** Prevents recursive inclusion of headers. */
#define LinearOperator_RECURSES

#if !defined LinearOperator_h
/** Prevents repeated inclusion of headers. */
#define LinearOperator_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/dec/KForm.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // template class LinearOperator
  /**
   * Description of template class 'LinearOperator' <p>
   * \brief Aim:
   * LinearOperator represents linear operator between kforms in the dec package.
   *
   * @tparam Calculus should be DiscreteExteriorCalculus.
   * @tparam order_in is the input order of the linear operator.
   * @tparam duality_in is the input duality of the linear operator.
   * @tparam order_out is the output order of the linear operator.
   * @tparam duality_out is the output duality of the linear operator.
   */
template <typename C, Order order_in, Duality duality_in, Order order_out, Duality duality_out>
  class LinearOperator
  {
    // ----------------------- Standard services ------------------------------
  public:
    typedef C Calculus;

    BOOST_STATIC_ASSERT(( order_in >= 0 ));
    BOOST_STATIC_ASSERT(( order_in <= Calculus::dimension ));
    BOOST_STATIC_ASSERT(( order_out >= 0 ));
    BOOST_STATIC_ASSERT(( order_out <= Calculus::dimension ));

    typedef typename Calculus::Matrix Container;
    typedef typename Calculus::Scalar Scalar;
    typedef KForm<Calculus, order_in, duality_in> InputKForm;
    typedef KForm<Calculus, order_out, duality_out> OutputKForm;

    /**
     * Constructor.
     * @param calculus the discrete exterior calculus to use.
     */
    LinearOperator(const Calculus& calculus);

    /**
     * Constructor.
     * @param calculus the discrete exterior calculus to use.
     * @param container the container to copy.
     */
    LinearOperator(const Calculus& calculus, const Container& container);

    /**
     * Assignment.
     * @param other the object to copy.
     * @return a reference on 'this'.
     */
    LinearOperator& operator=(const LinearOperator& other);

    // ----------------------- Interface --------------------------------------
  public:

    /**
     * Container used to actually hold the kform data.
     */
    Container container;

    /**
     * Const reference to calculus
     */
    const Calculus& calculus;

    /**
     * Writes/Displays the object on an output stream.
     * @param out the output stream where the object is written.
     */
    void selfDisplay(std::ostream& out) const;

    /**
     * Clear current kform.
     */
    void clear();

    /**
     * Checks the validity/consistency of the object.
     * @return 'true' if the object is valid, 'false' otherwise.
     */
    bool isValid() const;

    // ------------------------- Private Datas --------------------------------
  private:

    // ------------------------- Hidden services ------------------------------
  protected:

    /**
     * Constructor.
     * Forbidden by default (protected to avoid g++ warnings).
     */
    LinearOperator();

    // ------------------------- Internals ------------------------------------
  private:

  }; // end of class LinearOperator


  /**
   * Overloads 'operator<<' for displaying objects of class 'LinearOperator'.
   * @param out the output stream where the object is written.
   * @param object the object of class 'LinearOperator' to write.
   * @return the output stream after the writing.
   */
  template <typename Calculus, Order order_in, Duality duality_in, Order order_out, Duality duality_out>
  std::ostream&
  operator<<(std::ostream& out, const LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>& object);

  /**
   * Overloads 'operator+' for adding objects of class 'LinearOperator'.
   * @return linear_operator_a + linear_operator_b.
   */
  template <typename Calculus, Order order_in, Duality duality_in, Order order_out, Duality duality_out>
  LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>
  operator+(const LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>& linear_operator_a, const LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>& linear_operator_b);

  /**
   * Overloads 'operator-' for substracting objects of class 'LinearOperator'.
   * @return linear_operator_a - linear_operator_b.
   */
  template <typename Calculus, Order order_in, Duality duality_in, Order order_out, Duality duality_out>
  LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>
  operator-(const LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>& linear_operator_a, const LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>& linear_operator_b);

  /**
   * Overloads 'operator*' for scalar multiplication of objects of class 'LinearOperator'.
   * @return scalar * linear_operator.
   */
  template <typename Calculus, Order order_in, Duality duality_in, Order order_out, Duality duality_out>
  LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>
  operator*(const typename Calculus::Scalar& scalar, const LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>& linear_operator);

  /**
   * Overloads 'operator*' for internal multiplication of objects of class 'LinearOperator'.
   * @return linear_operator_left * linear_operator_right.
   */
  template <typename Calculus, Order order_in, Duality duality_in, Order order_fold, Duality duality_fold, Order order_out, Duality duality_out>
  LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>
  operator*(const LinearOperator<Calculus, order_fold, duality_fold, order_out, duality_out>& operator_left, const LinearOperator<Calculus, order_in, duality_in, order_fold, duality_fold>& operator_right);

  /**
   * Overloads 'operator*' for application of objects of class 'LinearOperator' on objects of class 'KForm'.
   * @return linear_operator_left * linear_operator_right.
   */
  template <typename Calculus, Order order_in, Duality duality_in, Order order_out, Duality duality_out>
  KForm<Calculus, order_out, duality_out>
  operator*(const LinearOperator<Calculus, order_in, duality_in, order_out, duality_out>& linear_operator, const KForm<Calculus, order_in, duality_in>& input_form);

} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#include "DGtal/dec/LinearOperator.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined LinearOperator_h

#undef LinearOperator_RECURSES
#endif // else defined(LinearOperator_RECURSES)
