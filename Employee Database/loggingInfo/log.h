#ifndef log0
#define log0 

#include <iostream>
#include<string>
#include "fileDump.h"
#include<fstream>
#include<chrono>

namespace systemLog {

	class Log
	{
	public:
		enum  Level
		{
			LevelDebug,
			LevelInfo,
			LevelWarning,
			LevelError,
			LevelCritical
		};


		Log(const std::string& name = "Logger") : m_LogLevel{ LevelDebug }, m_name{ name } {
			dumpInFile = { true };
		}

		~Log() {
			if (dumpInFile && count < 5) {
				fileDump f;
				f.flush1(m_buffer);
				m_buffer = "";
				count = 0;
			}
		}
		void setLogLevel(const Level& level)
		{
			m_LogLevel = level;
		}

		Level getLogLevel() {
			return m_LogLevel;
		}

		template <typename ...Args >
		void log(const Level& l, const std::string& msg, Args ...args);


	private:
		std::string m_name;
		Level m_LogLevel;
		short int count{0};
		std::string m_buffer = "";
		bool dumpInFile = false;

		std::string localTime() {
			auto now = std::chrono::system_clock::now();
			std::time_t time = std::chrono::system_clock::to_time_t(now); // to_time_t is a method for converting chrono::time in to time_t(ctime)

			//Now time_t is in non readable formate so we have to conver it into redable formate 
			std::tm tmLocal; // tm is a structure which stores the values in its variables 
			localtime_s(&tmLocal, &time); //now we store time_t into tm

			char buffer[20];
			std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", &tmLocal); //formatting tm and stores it into buffer

			return std::string(buffer);
		}

		std::string stringFLevel(const Level& l) {
			switch (l) {
			case LevelCritical:
				return  "[ CRITICAL ]";
			case LevelWarning:
				return "[ WARNING ]";
			case LevelError:
				return "[ ERROR ]";
			case LevelInfo:
				return "[ INFO ]";
			case LevelDebug:
				return "[ DEBUG ]";
			}
			return "";
		}

		void bufferAppend() { m_buffer.append("\n\n"); }
		template<typename T, typename ...Args>
		void bufferAppend(T value , Args ...args) {
			m_buffer.append(value).append(" ");
			bufferAppend(args...);
		}
	public:
		template <typename ...Args >
		void Debug(const std::string& message, Args ...args);
		template <typename ...Args >
		void Info(const std::string& message, Args ...args);
		template <typename ...Args >
		void Error(const std::string& message, Args ...args);
		template <typename ...Args >
		void Warn(const std::string& message, Args ...args);
		template <typename ...Args >
		void Critical(const std::string& message, Args ...args);
	};
	template <typename ...Args>
	void Log::Critical(const std::string& message, Args ...args)
	{
		log(Log::LevelCritical, message, args...);

	}
	template <typename ...Args >
	void Log::Warn(const std::string& message, Args ...args)
	{
		log(LevelWarning, message, args...);
	}

	template <typename ...Args>
	void Log::Error(const std::string& message, Args ...args)
	{
		log(Log::LevelError, message, args...);
	}

	template <typename ...Args>
	void Log::Info(const std::string& message, Args ...args)
	{
		log(Log::LevelInfo, message, args...);

	}
	template <typename ...Args>
	void Log::Debug(const std::string& message, Args ...args)
	{
		log(Log::LevelDebug, message, args...);

	}

}

#endif 