// file      : odb/boost/date-time/exceptions.cxx
// copyright : Copyright (c) 2005-2012 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/boost/date-time/exceptions.hxx>

namespace odb
{
  namespace boost
  {
    namespace date_time
    {
      const char* special_value::
      what () const throw ()
      {
        return "unrepresentable date/time special value";
      }

      const char* value_out_of_range::
      what () const throw ()
      {
        return "date/time value out of range";
      }
    }
  }
}
