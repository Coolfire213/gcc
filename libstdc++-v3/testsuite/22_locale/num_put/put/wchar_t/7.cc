// 2003-06-30 peturr02@ru.is

// Copyright (C) 2003 Free Software Foundation
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

#include <sstream>
#include <iostream>
#include <locale>
#include <testsuite_hooks.h>

// libstdc++/9828
void test01()
{
  using namespace std;
  bool test = true;

  typedef num_put<wchar_t> npw_t;

  wostringstream stream;
  const npw_t& npw = use_facet<npw_t>(stream.getloc());

  npw.put(stream, cout, L' ', static_cast<long>(10));
  VERIFY( stream.str() == L"10" );
}

int main()
{
  test01();
  return 0;
}
