# SaveProfileSystem
Simple, small and easy to use save system to store variable data localy in C++.

## Why should you use this?
You don't have to, it's just a small simple system to save variables in files locally. 
The reason for me to write this small class was because i was saving some variables on an other project localy but by time i had to save more and more variables it was not efficient and everytime increasing the code size too much which made it harder to overlook the code.

## Features
- Supports bool variables.
- Supports std::string variables.
- Supports int variables.
- Supports float variables.
- Encrypts the local files with an simple single char XOR Encryption which you should modify.

## How to use?
Actually there is a [PlayZone.cpp](PlayZone.cpp) file where you can see the example but in case you don't want to check.
```cpp
void Example()
{
  // First you have to initialize the class default directory for profiles getting saved is "C:\\ProfileSystem\\"
  // You can change this while initializing the class or by setDirectory.
  ProfileSystem ps;

  std::string mystring = "Hello world.";

  // Register the string variable, first argument the variable itself second argument a local name for the variable.
  ps.reg_string(mystring, "mystring");

  // Save or Load the variable now.
  // SaveAll variables registered locally, the argument is the profile name that you want to use.
  ps.SaveAll("Default"); 

  // Load variables from the local files.
  ps.LoadAll("Default");
}
```

### Can i use this on my own projects?
Of course you can, you are free to use or modify this code but i would find it cool if you give me credits.
