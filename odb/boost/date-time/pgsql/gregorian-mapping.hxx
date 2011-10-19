// file      : odb/boost/date-time/pgsql/gregorian-mapping.hxx
// author    : Constantin Michael <constantin@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_BOOST_DATE_TIME_PGSQL_GREGORIAN_MAPPING_HXX
#define ODB_BOOST_DATE_TIME_PGSQL_GREGORIAN_MAPPING_HXX

#include <boost/date_time/gregorian/gregorian_types.hpp>

// By default map boost::gregorian::date to PostgreSQL DATE. We use the
// NULL value to represent not_a_date_time.
//
#pragma db value(boost::gregorian::date) type("DATE") null

#endif // ODB_BOOST_DATE_TIME_PGSQL_GREGORIAN_MAPPING_HXX