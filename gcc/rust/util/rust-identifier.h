// Copyright (C) 2020-2025 Free Software Foundation, Inc.

// This file is part of GCC.

// GCC is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3, or (at your option) any later
// version.

// GCC is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.

// You should have received a copy of the GNU General Public License
// along with GCC; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#ifndef RUST_IDENTIFIER
#define RUST_IDENTIFIER

#include "rust-canonical-path.h"
#include "rust-location.h"

namespace Rust {

struct RustIdent
{
  Resolver::CanonicalPath path;
  location_t locus;

  RustIdent (const Resolver::CanonicalPath &path, location_t locus)
    : path (path), locus (locus)
  {}

  RustIdent (const RustIdent &other) : path (other.path), locus (other.locus) {}

  RustIdent &operator= (const RustIdent &other)
  {
    path = other.path;
    locus = other.locus;

    return *this;
  }
};

} // namespace Rust

#endif // RUST_IDENTIFIER
