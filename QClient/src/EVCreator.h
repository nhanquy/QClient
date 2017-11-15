/*
 * EVCreator.h
 *
 *  Created on: Nov 15, 2017
 *      Author: nhanquy
 */

#ifndef EVCREATOR_H_
#define EVCREATOR_H_
// stringstreams
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class EVCreator
{
	static const int 	_len = 6;
	const char* _prompt_name[_len]={"id", "demand","power", "phase", "departure","priority"};
	std::string _json;
	std::string _now;
	std::string _msg;
	std::string _event;
	char _buffer[256];
public:
	void ev_wizard();
	void wizard();
	void get_event();
	std::string jsonline()
	{
		return _json;
	}
	EVCreator();
	virtual ~EVCreator();
private:
	bool adding_more();
};

#endif /* EVCREATOR_H_ */
