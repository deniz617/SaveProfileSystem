#include "ProfileSystem.h"
#include <iostream>
#include <experimental/filesystem>

ProfileSystem::ProfileSystem()
{
	io.setPath("C:\\ProfileSystem\\");
}

ProfileSystem::ProfileSystem(std::string profile_directory)
{
	io.setPath(profile_directory);
}

ProfileSystem::~ProfileSystem()
{

}

void ProfileSystem::setDirectory(std::string profile_directory)
{
	io.setPath(profile_directory);
}

void ProfileSystem::SaveAll(std::string profile)
{
	// Set profile
	io.setProfile(profile);

	for (int i = 0; i < boolVars.size(); i++)
	{
		saveVar<bool>& obj = boolVars[i];
		io.save_bool(obj.var, obj.varname);
	}
	for (int i = 0; i < stringVars.size(); i++)
	{
		saveVar<std::string>& obj = stringVars[i];
		io.save_string(obj.var, obj.varname);
	}
	for (int i = 0; i < intVars.size(); i++)
	{
		saveVar<int>& obj = intVars[i];
		io.save_int(obj.var, obj.varname);
		
	}
	for (int i = 0; i < floatVars.size(); i++)
	{
		saveVar<float>& obj = floatVars[i];
		io.save_float(obj.var, obj.varname);
	}
}

void ProfileSystem::LoadAll(std::string profile)
{
	// Set profile
	io.setProfile(profile);

	for (int i = 0; i < boolVars.size(); i++)
	{
		saveVar<bool>& obj = boolVars[i];
		io.load_bool(obj.varname, obj.var);
	}
	for (int i = 0; i < stringVars.size(); i++)
	{
		saveVar<std::string>& obj = stringVars[i];
		io.load_string(obj.varname, obj.var);
	}
	for (int i = 0; i < intVars.size(); i++)
	{
		saveVar<int>& obj = intVars[i];
		io.load_int(obj.varname, obj.var);

	}
	for (int i = 0; i < floatVars.size(); i++)
	{
		saveVar<float>& obj = floatVars[i];
		io.load_float(obj.varname, obj.var);
	}
}

std::vector<std::string> ProfileSystem::GetProfileDirs()
{
	std::vector<std::string> folders;
	folders.clear();

	std::string path = io.getPath();

	for (auto& p : std::experimental::filesystem::recursive_directory_iterator(path))
	{
		std::string dir = p.path().parent_path().string() + "\\";
		if(dir.compare(path) == 0)
		{
			folders.push_back(p.path().filename().string());
			std::cout << "pushing back" << std::endl;
		}
	}
	return folders;
}

void ProfileSystem::reg_bool(bool& var, std::string varname)
{
	boolVars.push_back(saveVar<bool>{var, varname, "bool"});
}

void ProfileSystem::reg_string(std::string& var, std::string varname)
{
	stringVars.push_back(saveVar<std::string>{ var, varname, "std::string" });
}

void ProfileSystem::reg_int(int& var, std::string varname)
{
	intVars.push_back(saveVar<int>{var, varname, "int"});
}

void ProfileSystem::reg_float(float& var, std::string varname)
{
	floatVars.push_back(saveVar<float>{var, varname, "float"});
}

void ProfileSystem::debug_print_vars()
{
	std::cout << "==========================================" << std::endl;
	for (int i = 0; i < boolVars.size(); i++)
	{
		saveVar<bool>& obj = boolVars[i];
		std::cout << "<" << obj.vartype << "> " << &obj.var << "\t" << obj.varname << ": " << obj.var << std::endl;
	}
	for (int i = 0; i < stringVars.size(); i++)
	{
		saveVar<std::string>& obj = stringVars[i];
		std::cout << "<" << obj.vartype << "> " << &obj.var << "\t" << obj.varname << ": " << obj.var << std::endl;
	}
	for (int i = 0; i < intVars.size(); i++)
	{
		saveVar<int>& obj = intVars[i];
		std::cout << "<" << obj.vartype << "> " << &obj.var << "\t" << obj.varname << ": " << obj.var << std::endl;
	}
	for (int i = 0; i < floatVars.size(); i++)
	{
		saveVar<float>& obj = floatVars[i];
		std::cout << "<" << obj.vartype << "> " << &obj.var << "\t" << obj.varname << ": " << obj.var << std::endl;
	}
	std::cout << "==========================================" << std::endl;
}
