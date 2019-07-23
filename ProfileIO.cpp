#include "ProfileIO.h"
#include <sstream> //std::stringstream
#include <experimental/filesystem>

ProfileIO::ProfileIO()
{
}


ProfileIO::~ProfileIO()
{
}

void ProfileIO::setProfile(std::string name)
{
	profile = name;
}

void ProfileIO::setPath(std::string _path)
{
	path = _path;
}

std::string ProfileIO::getPath()
{
	return path;
}

void ProfileIO::save_bool(bool var, std::string varname)
{
	std::string targetdir = path + profile + "\\bool\\";
	create_directory(targetdir);

	std::ofstream output(targetdir + varname + ".fsf");
	if (output.is_open())
	{
		std::string newstring = std::to_string(var);
		crypt(newstring);
		output.write(newstring.c_str(), newstring.size());
		output.close();
	}
}

void ProfileIO::save_string(std::string var, std::string varname)
{
	std::string targetdir = path + profile + "\\string\\";
	create_directory(targetdir);

	std::ofstream output(targetdir + varname + ".fsf");
	if (output.is_open())
	{
		std::string newstring = var;
		crypt(newstring);
		output.write(newstring.c_str(), newstring.size());
		output.close();
	}
}

void ProfileIO::save_int(int var, std::string varname)
{
	std::string targetdir = path + profile + "\\int\\";
	create_directory(targetdir);

	std::ofstream output(targetdir + varname + ".fsf");
	if (output.is_open())
	{
		std::string newstring = std::to_string(var);
		crypt(newstring);
		output.write(newstring.c_str(), newstring.size());
		output.close();
	}
}

void ProfileIO::save_float(float var, std::string varname)
{
	std::string targetdir = path + profile + "\\float\\";
	create_directory(targetdir);

	std::ofstream output(targetdir + varname + ".fsf");
	if (output.is_open())
	{
		std::string newstring = std::to_string(var);
		crypt(newstring);
		output.write(newstring.c_str(), newstring.size());
		output.close();
	}
}

void ProfileIO::load_bool(std::string varname, bool& targetvar)
{
	std::string targetdir = path + profile + "\\bool\\";

	std::ifstream input(targetdir + varname + ".fsf");
	if (input.is_open())
	{
		std::string readstr;
		std::stringstream ss;

		ss << input.rdbuf();

		readstr = ss.str();

		crypt(readstr);
		
		if (std::stoi(readstr) > 0)
			targetvar = true;
		else
			targetvar = false;
		
		input.close();
	}
}

void ProfileIO::load_string(std::string varname, std::string& targetvar)
{
	std::string targetdir = path + profile + "\\string\\";

	std::ifstream input(targetdir + varname + ".fsf");
	if (input.is_open())
	{
		std::string readstr;
		std::stringstream ss;

		ss << input.rdbuf();

		readstr = ss.str();

		crypt(readstr);

		targetvar = readstr;

		input.close();
	}
}

void ProfileIO::load_int(std::string varname, int& targetvar)
{
	std::string targetdir = path + profile + "\\int\\";

	std::ifstream input(targetdir + varname + ".fsf");
	if (input.is_open())
	{
		std::string readstr;
		std::stringstream ss;

		ss << input.rdbuf();

		readstr = ss.str();

		crypt(readstr);

		targetvar = std::stoi(readstr);

		input.close();
	}
}

void ProfileIO::load_float(std::string varname, float& targetvar)
{
	std::string targetdir = path + profile + "\\float\\";

	std::ifstream input(targetdir + varname + ".fsf");
	if (input.is_open())
	{
		std::string readstr;
		std::stringstream ss;

		ss << input.rdbuf();

		readstr = ss.str();

		crypt(readstr);

		targetvar = std::stof(readstr);

		input.close();
	}
}

void ProfileIO::crypt(std::string &str)
{
	static std::string key = "a";
	for (int i = 0; i < str.size(); i++)
	{
		str[i] ^= key[0];
	}
}

void ProfileIO::create_directory(std::string dir)
{
	// If directory does not exit create.
	if(!std::experimental::filesystem::is_directory(dir))
	{
		std::experimental::filesystem::create_directories(dir);
	}
}
