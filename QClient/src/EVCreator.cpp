/*
 * EVCreator.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: nhanquy
 */

#include "EVCreator.h"

EVCreator::EVCreator()
{
}

EVCreator::~EVCreator()
{
}

void EVCreator::get_event()
{
	int choice;
	cout<<"Please chose event to create:\n"
		<<"[1] plugged (default) - [2] start - [3] end - [4] modification: ";
	cin>>choice;
	cin.ignore(1,'\n');
	switch (choice)
	{
		case 2: _event = "start";
				break;
		case 3: _event = "end";
				break;
		case 4: _event = "modification";
				break;
		default: _event = "plugged";
				break;
	}
}

void EVCreator::ev_wizard()
{
	//clear _msg
	_msg.clear();
	string str;
	get_event();
	_msg = std::string("\"event\":\"")+_event+std::string("\"");
	for(int i=0;i<_len;i++)
	{
		cout<<"Please enter "<<_prompt_name[i]<<": ";
		getline (cin, str);
		if(!str.empty())
			_msg+=string(",\"")+string(_prompt_name[i])+std::string("\":")+str;
	}
}
bool EVCreator::adding_more()
{
	int choice;
	cout<<"Do you want to add new event? [1] Yes - [2] No (default): ";
	cin>>choice;
	cin.ignore(1,'\n');
	if(choice == 1)
		return true;
	return false;
}
void EVCreator::wizard()
{

	//clear json
	_json.clear();
	string str;
	cout<<"Please enter the now time: ";
	getline (cin, str);
	_json=string("{\n");
	_json+=string("\"Now\":")+str+",\n";
	_json+=string("\"EV_Events\":\n[");
	bool first = true;
	while (adding_more())
	{
		ev_wizard();
		if (first)
		{
			_json+=string("\n{");
			first = false;
		}
		else
		{
			_json+=string(",\n{");
		}
		_json+=_msg+string("}");
	}
	_json+=string("\n]");
	_json+=string("\n}");
}
