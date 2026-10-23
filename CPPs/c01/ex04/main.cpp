#include "File.hpp"

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
	copy.replacing(&arg, argv, &new_file);
	arg.close();
	new_file.close();
	return (0);
}
