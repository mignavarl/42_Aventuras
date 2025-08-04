#ifndef _COLORS
# define _COLORS

# define BLACK   "\033[1;30m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define WHITE   "\033[1;37m"
# define NC      "\033[0m"

#endif // !_COLORS

// File declaration --------------------------------------------------------

#ifndef _FILE_HPP
# define _FILE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <strings.h>
#include <bits/stdc++.h>

class File {
	private:
		std::string _line;
	public:
		File(void);
		~File(void);
		void	replacing(std::ifstream *arg, char **argv, std::ofstream *new_file);
};

#endif // !_FILE_HPP

