// file      : odb/boost/exceptions.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/boost/exceptions.hxx>

using namespace std;

namespace odb
{
  namespace boost
  {
    const char* dummy_exception::
    what () const throw ()
    {
      return "dummy exception";
    }
  }
}
