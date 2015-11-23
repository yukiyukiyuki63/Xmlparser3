#ifndef _INC_GENERAL_INFO
#define _INC_GENERAL_INFO
#include "session_info.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace boost::property_tree;
using namespace std;

class General_info :public Session_info
{
private:

	typedef struct {
		string mode;
		string gametype;
		string tablename;
		string tablecurrency;
		string duration;
		int gamecount;
		string startdate;
		string currency;
		string nickname;
		string bets;
		string wins;
		string chipsin;
		string chipsout;
		double ipoints;
		double statuspoints;
		double awardpoints;
	}general_info_t;

public:
	void general_info(string filename);
};
#endif
