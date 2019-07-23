#ifndef PROFILEIO_H

#include <fstream>
#include <string>

#define PROFILEIO_H
class ProfileIO
{
public:
	ProfileIO();
	~ProfileIO();

	void setProfile(std::string name);
	void setPath(std::string _path);
	std::string getPath();

	void save_bool(bool var, std::string varname);
	void save_string(std::string var, std::string varname);
	void save_int(int var, std::string varname);
	void save_float(float var, std::string varname);


	void load_bool(std::string varname, bool& targetvar);
	void load_string(std::string varname, std::string& targetvar);
	void load_int(std::string varname, int& targetvar);
	void load_float(std::string varname, float& targetvar);
private:
	std::string profile;
	std::string path;

	void crypt(std::string &str);
	void create_directory(std::string dir);	
};
#endif

