#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
  public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);

  private:
	typedef void (Harl::*ptr)(void);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};


#endif