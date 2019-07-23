#ifndef PROFILESYSTEM_H
#include <string>
#include <vector>
#include "ProfileIO.h"
#define PROFILESYSTEM_H

template <class T>

struct saveVar {
	T& var;
	std::string varname;
	std::string vartype;
};

class ProfileSystem
{
public:
	ProfileSystem();
	ProfileSystem(std::string profile_directory);
	~ProfileSystem();

	// setDirectory(std::string) | Note: The directory has to end with two double slashes.
	void setDirectory(std::string profile_directory);

	void SaveAll(std::string profile);
	void LoadAll(std::string profile);


	void reg_bool(bool& var, std::string varname);
	void reg_string(std::string& var, std::string varname);
	void reg_int(int& var, std::string varname);
	void reg_float(float& var, std::string varname);

	std::vector<std::string> GetProfileDirs();
	void debug_print_vars();
private:
	std::vector<saveVar<bool>>			boolVars;
	std::vector<saveVar<std::string>>	stringVars;
	std::vector<saveVar<int>>			intVars;
	std::vector<saveVar<float>>			floatVars;

	ProfileIO io;
};

#endif

