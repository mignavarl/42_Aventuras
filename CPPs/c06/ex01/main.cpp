#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	data->name = "Aitor";
	data->age = 33;


	uintptr_t raw = Serializer::serialize(data);
	Data* new_data = Serializer::deserialize(raw);
	
	std::cout << new_data->name << std::endl;
	std::cout << new_data->age << std::endl;
	
	std::cout << YELLOW "--------------------------------------\n" NC;
	
	std::cout << "raw = " << raw << std::endl;
	std::cout << "ptr = " << reinterpret_cast<uintptr_t>(data) << std::endl;
	std::cout << "des = " << reinterpret_cast<uintptr_t>(new_data) << std::endl;
	delete data;
	return 0;
}