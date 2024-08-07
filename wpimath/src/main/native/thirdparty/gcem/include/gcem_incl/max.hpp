/*################################################################################
  ##
  ##   Copyright (C) 2016-2024 Keith O'Hara
  ##
  ##   This file is part of the GCE-Math C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

#ifndef _gcem_max_HPP
#define _gcem_max_HPP

#include <algorithm>
#include <type_traits>

namespace gcem
{

/**
 * Compile-time pairwise maximum function
 *
 * @param x a real-valued input.
 * @param y a real-valued input.
 * @return Computes the maximum between \c x and \c y, where \c x and \c y have the same type (e.g., \c int, \c double, etc.)
 */

template<typename T1, typename T2>
constexpr
common_t<T1,T2>
max(const T1 x, const T2 y)
noexcept
{
  if (std::is_constant_evaluated()) {
    return( y < x ? x : y );
  } else {
    return std::max(x, y);
  }
}

}

#endif
