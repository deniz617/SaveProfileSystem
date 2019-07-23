// PlayZone.cpp : Example demo

#include <iostream>
#include "ProfileSystem.h"

// Random vars.
static std::string s1 = "t";
std::string s2 = "1 ";
bool state = false;
float pi = 3.14;
int nnummm = 602;

int main()
{
	ProfileSystem ps;
	ps.setDirectory("C:\\Profiles\\");

	ps.reg_string(s1, "var1");
	ps.reg_string(s2, "var2");
	ps.reg_bool(state, "bool1");
	ps.reg_float(pi, "pi");
	ps.reg_int(nnummm, "nnummm");

	ps.debug_print_vars();

	ps.SaveAll("Default");

	std::vector<std::string> profiles(ps.GetProfileDirs());
	for (int i = 0; i < profiles.size(); i++)
	{
		std::cout << "Profile[" << i << "]: " << profiles[i] << std::endl;
	}

	getchar();
}