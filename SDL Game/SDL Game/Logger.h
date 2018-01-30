#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>

namespace SDL_Game
{
	class Logger
	{
	private:
		std::ofstream filelog;

		bool debugEnabled;
		bool infoEnabled;
		bool errorEnabled;

		std::string GetTimeFormat();
		void CommonLog(std::string message);
	public:
		Logger();
		~Logger();

		void Debug(std::string message);
		void Info(std::string message);
		void Error(std::string message);
	};
}
