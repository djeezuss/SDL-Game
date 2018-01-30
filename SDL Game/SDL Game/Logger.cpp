#include "Logger.h"


namespace SDL_Game
{
	std::string Logger::GetTimeFormat()
	{
		time_t rawtime = time(NULL);
		struct tm timeinfo;
		std::stringstream buffer;

		localtime_s(&timeinfo, &rawtime);

		buffer << std::put_time(&timeinfo ,"[%T]");

		return buffer.str();
	}

	void Logger::CommonLog(std::string message)
	{
		std::cout << GetTimeFormat() << " " << message << std::endl;
		filelog << GetTimeFormat() << " " << message << std::endl;
	}

	Logger::Logger()
	{
		debugEnabled = true;
		infoEnabled = true;
		errorEnabled = true;

		filelog.open("log.txt", std::ios::out);

		Info("Logger initialised.");
	}


	Logger::~Logger()
	{
		filelog.close();
	}

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
