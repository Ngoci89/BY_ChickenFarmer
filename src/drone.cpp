#include <drones/drone.h>
#include <iostream>
#include <sstream>

struct Position
{
	int x = 0;
	int y = 0;
};

char turnLeft(const char direction)
{
	switch (direction)
	{
	case 'N':
		return 'W';
	case 'W':
		return 'S';
	case 'E':
		return 'N';
	case 'S':
		return 'E';
	default:
		throw std::runtime_error("invalid direction");
	}
};

char turnRight(const char direction)
{
	switch (direction)
	{
	case 'N':
		return 'E';
	case 'W':
		return 'N';
	case 'E':
		return 'S';
	case 'S':
		return 'W';
	default:
		throw std::runtime_error("invalid direction");
	}
};

Position move(Position pos, Position bounds, const char direction)
{
	switch (direction)
	{
	case 'N':
		if (pos.y >= bounds.y) throw std::runtime_error("Drone crashed");
		return { pos.x, pos.y + 1 };
	case 'W':
		if (pos.x <= 0) throw std::runtime_error("Drone crashed");
		return { pos.x - 1, pos.y };
	case 'E':
		if (pos.x >= bounds.x) throw std::runtime_error("Drone crashed");
		return { pos.x + 1, pos.y };
	case 'S':
		if (pos.y <= 0) throw std::runtime_error("Drone crashed");
		return { pos.x, pos.y - 1 };
	default:
		throw std::runtime_error("invalid direction");
	}
};

std::string processCommands(const std::string& input)
{
	std::istringstream is_input{ input };
	Position bounds;
	std::ostringstream os_output;
	std::string eof;

	is_input >> bounds.x >> bounds.y;
	std::getline(is_input, eof, '\n'); // needed because of eol
	is_input.peek();

	while (!is_input.eof() && is_input.good())
	{
		int x, y;
		char direction;
		std::string commands;

		is_input >> x >> y >> direction;

		if (!is_input.good()) throw std::runtime_error("Invalid position.");

		Position pos{ x, y };

		std::getline(is_input, eof, '\n'); // needed
		std::getline(is_input, commands, '\n');

		for (auto cmd : commands)
		{
			if (cmd == 'L') direction = turnLeft(direction);
			else if (cmd == 'R') direction = turnRight(direction);
			else if (cmd == 'M') pos = move(pos, bounds, direction);
			else throw std::runtime_error("Invalid command");
		}

		os_output << pos.x << ' ' << pos.y << ' ' << direction << '\n';

		is_input.peek(); // detect eof
	}
	return os_output.str();
}
