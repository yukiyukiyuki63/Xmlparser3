#include "session_info.h"
#include "general_info.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace boost::property_tree;
using namespace std;

void General_info::general_info(string Filename) {
	general_info_t info;


	read_xml(Filename + ".xml", pt);
	if (boost::optional<std::string> mode = pt.get_optional<std::string>("session.general.mode")) {
		info.mode = mode.get();
	}
	if (boost::optional<std::string> gametype = pt.get_optional<std::string>("session.general.gametype")) {
		info.gametype = gametype.get();
	}
	if (boost::optional<std::string> tablename = pt.get_optional<std::string>("session.general.tablename")) {
		info.tablename = tablename.get();
	}
		
	if (boost::optional<std::string> tablecurrency = pt.get_optional<std::string>("session.general.tablecurrency"))
		info.tablecurrency = tablecurrency.get();
		
	if (boost::optional<std::string> duration = pt.get_optional<std::string>("session.general.duration"))
		info.duration = duration.get();
	if (boost::optional<int> gamecount = pt.get_optional<int>("session.general.gamecount"))
		info.gamecount = gamecount.get();
	if (boost::optional<std::string> startdate = pt.get_optional<std::string>("session.general.startdate"))
		info.startdate = startdate.get();
	if (boost::optional<std::string> currency = pt.get_optional<std::string>("session.general.currency"))
		info.currency = currency.get();
	if (boost::optional<std::string> nickname = pt.get_optional<std::string>("session.general.nickname"))
		info.nickname = nickname.get();
	if (boost::optional<std::string> bets = pt.get_optional<std::string>("session.general.bets"))
		info.bets = bets.get();
	if (boost::optional<std::string> wins = pt.get_optional<std::string>("session.general.wins"))
		info.wins = wins.get();
	if (boost::optional<std::string> chipsin = pt.get_optional<std::string>("session.general.chipsin"))
		info.chipsin = chipsin.get();
	if (boost::optional<std::string> chipsout = pt.get_optional<std::string>("session.general.chipsout"))
		info.chipsout = chipsout.get();
	if (boost::optional<double> ipoints = pt.get_optional<double>("session.general.ipoints"))
		info.ipoints = ipoints.get();
	if (boost::optional<double> statuspoints = pt.get_optional<double>("session.general.statuspoints"))
		info.statuspoints = statuspoints.get();
	if (boost::optional<double> awardpoints = pt.get_optional<double>("session.general.awardpoints"))
		info.awardpoints = awardpoints.get();

	else {
		std::cout << "value not found" << std::endl<< std::endl;
	}

	std::cout << "mode = " << info.mode << ",";
	std::cout << "gametype = " << info.gametype << ",";
	std::cout << "tablename = " << info.tablename << ",";
	std::cout << "tablecurrency = " << info.tablename << ",";
	std::cout << "duration = " << info.duration << ",";
	std::cout << "gamecount = " << info.gamecount << ",";
	std::cout << "startdate = " << info.startdate << ",";
	std::cout << "currency = " << info.currency << ",";
	std::cout << "nickname = " << info.nickname << ",";
	std::cout << "tablename = " << info.tablename << ",";
	std::cout << "wins = " << info.wins << ",";
	std::cout << "chipsin = " << info.chipsin << ",";
	std::cout << "chipsout = " << info.chipsout << ",";
	std::cout << "ipoints = " << info.ipoints << ",";
	std::cout << "statuspoints = " << info.statuspoints << ",";
	std::cout << "awardpoints = " << info.awardpoints << std::endl;

	//ˆÈ‰º‘‚«ž‚Ý
	std::ofstream ofs("test.txt", std::ios::out | std::ios::ate| std::ios::app | std::ios::binary);
	ofs << "mode = " << info.mode << ",";
	ofs << "gametype = " << info.gametype << ",";
	ofs << "tablename = " << info.tablename << ",";
	ofs << "tablecurrency = " << info.tablename << ",";
	ofs << "duration = " << info.duration << ",";
	ofs << "gamecount = " << info.gamecount << ",";
	ofs << "startdate = " << info.startdate << ",";
	ofs << "currency = " << info.currency << ",";
	ofs << "nickname = " << info.nickname << ",";
	ofs << "tablename = " << info.tablename << ",";
	ofs << "wins = " << info.wins << ",";
	ofs << "chipsin = " << info.chipsin << ",";
	ofs << "chipsout = " << info.chipsout << ",";
	ofs << "ipoints = " << info.ipoints << ",";
	ofs << "statuspoints = " << info.statuspoints << ",";
	ofs << "awardpoints = " << info.awardpoints << std::endl;
}