#define _CRT_SECURE_NO_WARNINGS

#include "Logger.h"


namespace SDL_Game
{
	std::string Logger::GetTimeFormat()
	{
		time_t rawtime;
		struct tm* timeinfo;
		char buffer[18];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, 18, "[%F %T]", timeinfo);

		return std::string(buffer);
	}

	void Logger::CommonLog(std::string message)
	{
		std::cout << GetTimeFormat() << " " << message << std::endl;
	}

	Logger::Logger()
	{
		debugEnabled = true;
		infoEnabled = true;
		errorEnabled = true;
	}


	Logger::~Logger()
	{}

	void Logger::Debug(std::string message)
	{
		if (debugEnabled)
		{
			CommonLog("[DEBUG] " + message);
		}
	}

	void Logger::Info(std::string message)
	{
		if (infoEnabled)
		{
			CommonLog("[INFO] " + message);
		}
	}

	void Logger::Error(std::string message)
	{
		if (errorEnabled)
		{
			CommonLog("[ERROR] " + message);
		}
	}
}
