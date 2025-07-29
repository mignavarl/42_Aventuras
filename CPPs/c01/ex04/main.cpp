#include "File.hpp"
#include <bits/stdc++.h>

int	main(int argc, char **argv)
{
	File	copy;
	std::ifstream arg(argv[1]);
	if (argc != 4)
	{
		std::cout << "No hay 3 argumentos\nPrueba otra vez\n";
		return (0);
	}
	if (!arg.is_open())
	{
		std::cout << "No se pudo leer el archivo\n";
		return(1);
	}
	std::string r_name = argv[1];
	r_name += ".replace";
	std::ofstream new_file;
	new_file.open(r_name.c_str());
	std::string to_erase = argv[2];
	size_t	pos;
	while (std::getline(arg, copy._file))
	{
		pos = 0;
		while (pos <= 0)
		{
			pos = copy._file.find(argv[2]);
			if (pos >= 0 && pos < copy._file.length())
			{
				copy._file.erase(pos, to_erase.length());
				copy._file.insert(pos, argv[3]);
			}
		}
		new_file << copy._file;
		new_file << "\n";
	}	
	arg.close();
	new_file.close();
	return (0);
}