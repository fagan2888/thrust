/*
 *  Copyright 2008-2012 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in ctbbliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include <thrust/detail/config.h>
#include <thrust/system/cpp/detail/tag.h>
#include <thrust/iterator/detail/any_system_tag.h>

namespace thrust
{
namespace system
{
// put the canonical tag in the same ns as the backend's entry points
namespace tbb
{
namespace detail
{

// tbb inherits cpp's functionality
struct tag : thrust::system::cpp::tag {};

// select_system overloads
template<typename Tag>
__host__ __device__
inline Tag select_system(Tag, Tag)
{
  return Tag();
} // end select_system()


template<typename Tag>
__host__ __device__
inline Tag select_system(Tag, thrust::any_system_tag)
{
  return Tag();
} // end select_system()


template<typename Tag>
__host__ __device__
inline Tag select_system(thrust::any_system_tag, Tag)
{
  return Tag();
} // end select_system()


template<typename Tag>
__host__ __device__
inline Tag select_system(Tag, thrust::system::cpp::tag)
{
  return Tag();
} // end select_system()


template<typename Tag>
__host__ __device__
inline Tag select_system(thrust::system::cpp::tag, Tag)
{
  return Tag();
} // end select_system()


} // end detail

// alias the tag here
using thrust::system::tbb::detail::tag;

} // end tbb
} // end system

// alias tbb's tag at top-level
namespace tbb
{

using thrust::system::tbb::tag;

} // end tbb
} // end thrust

