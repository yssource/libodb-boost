// file      : odb/boost/date-time/pgsql/gregorian-traits.hxx
// author    : Constantin Michael <constantin@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_BOOST_DATE_TIME_PGSQL_GREGORIAN_TRAITS_HXX
#define ODB_BOOST_DATE_TIME_PGSQL_GREGORIAN_TRAITS_HXX

#include <odb/pre.hxx>

#include <boost/date_time/gregorian/gregorian_types.hpp>

#include <odb/core.hxx>
#include <odb/pgsql/traits.hxx>
#include <odb/boost/date-time/exceptions.hxx>

namespace odb
{
  namespace pgsql
  {
    template <>
    struct default_value_traits< ::boost::gregorian::date, id_date>
    {
      typedef ::boost::gregorian::date date;

      typedef details::endian_traits endian_traits;

      typedef date value_type;
      typedef date query_type;
      typedef int image_type;

      static void
      set_value (date& v, int i, bool is_null)
      {
        if (is_null)
          v = date (::boost::date_time::not_a_date_time);
        else
          v = date (2000, 1, 1) + ::boost::gregorian::date_duration (
            endian_traits::ntoh (i));
      }

      static void
      set_image (int& i, bool& is_null, const date& v)
      {
        if (v.is_special ())
        {
          if (v.is_not_a_date ())
            is_null = true;
          else
            throw odb::boost::date_time::special_value ();
        }
        else
        {
          is_null = false;
          i = endian_traits::hton (
            static_cast<int> ((v - date (2000, 1, 1)).days ()));
        }
      }
    };

    template <>
    struct default_type_traits< ::boost::gregorian::date>
    {
      static const database_type_id db_type_id = id_date;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_BOOST_DATE_TIME_PGSQL_GREGORIAN_TRAITS_HXX
