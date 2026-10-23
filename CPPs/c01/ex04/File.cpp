#include "File.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
File::File(void)
{
}


File::~File(void)
{
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

bool searchWord(std::string line, char *word)
{
	if (line.find(word) == (size_t)-1)
		return (false);
	return (true);
}

void	File::replacing(std::ifstream *arg, char **argv, std::ofstream *new_file)
{
	size_t pos;
	std::string to_erase = argv[2];
	
	while (std::getline(*arg, this->_line))
	{
		while (searchWord(this->_line, argv[2]))
		{
			pos = this->_line.find(argv[2]);
			this->_line.erase(pos, to_erase.length());
			this->_line.insert(pos, argv[3]);
		}
		*new_file << this->_line;
		*new_file << "\n";
	}
}