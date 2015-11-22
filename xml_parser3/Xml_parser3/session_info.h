#ifndef _INC_SESSION_INFO
#define _INC_SESSION_INFO
#include <iostream>
#include <stdio.h>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace boost::property_tree;
using namespace std;

class Session_info
{
private:

	boost::optional<int> sessioncode;
	typedef struct  {
		string sessoincode;
	} session_info_value_t;

protected:
	ptree pt;

public:
	void Sessioncode(string Filename);
};
#endif
