// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#define BOOST_TEST_MODULE Tests
#define BOOST_TEST_INCLUDED
#pragma warning (disable: 4996)
#include <boost/test/unit_test.hpp>
#define BOOST_AUTO_TEST_MAIN