#ifndef _INC_GAME_INFO
#define _INC_GAME_INFO
#include "session_info.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace boost::property_tree;
using namespace std;

class Game_info:public Session_info
{
private:

	typedef struct {
		string startdate;
		int seat;
		string name;
		string chips;
		string dealer;
		string win;
		string addon;
		string reg_code;
	} player_t;

	typedef struct {
		int no;
		string player;
		string type;
		string sum;
		string cards;
	} action_t;

	typedef struct {
		string type;
		string player;
	} cards_t;

	typedef struct {
		action_t a;
		cards_t c;
		int no;
	} round_t;

	typedef struct {
		player_t p;
		round_t r;
		string gamecode;
	} gamecode_t;

public:
	void Gamecode_info(string Filename);
};
#endif
