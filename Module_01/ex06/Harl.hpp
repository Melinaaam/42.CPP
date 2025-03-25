#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

enum Level 
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNKNOWN
};
class Harl
{
  public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);
	int GetStringLevel(const std::string& str);
  private:
	typedef void (Harl::*ptr)(void);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};


#endif