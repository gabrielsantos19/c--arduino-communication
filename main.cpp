#include <string>
#include <iostream>
#include "serial/serial.h"


int main(int argc, char* argv[]) {
	std::cout << "[Ports]" << std::endl;
	auto ports = serial::list_ports();
	for (auto port : ports) {
		std::cout << port.port;
		std::cout << "\t" << port.hardware_id;
		std::cout << '\t' << port.description;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	serial::Serial my_serial("/dev/ttyUSB0", 16000, serial::Timeout::simpleTimeout(250));

	std::string send_buffer;
	std::string receive_buffer;
	std::cout << ">> Enter a message: " << std::endl;
	std::getline(std::cin, send_buffer);
	my_serial.write(send_buffer);
	receive_buffer = my_serial.read(send_buffer.size());
	std::cout << ">> Received message: (length: " << receive_buffer.length() << ")" << std::endl;
	std::cout << receive_buffer << std::endl;
	std::cout << std::endl;

	my_serial.close();

	return 0;
}
