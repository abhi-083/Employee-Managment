#ifndef logger
#define logger 

#include"log.h"
#include"fileDump.h"
#include<iostream>

using systemLog::Log;

namespace systemLog
{
	auto myLogger = std::make_shared<Log>("Abhi");

	std::shared_ptr<Log> instance() {
		return myLogger;
	}
		
	void setLogger(std::shared_ptr<Log> pointer) {
		myLogger = pointer;
	}

	template <typename ...Args>
	void Log::log(const Level& level, const std::string& msg, Args ...args) {
			if (dumpInFile && level >= m_LogLevel)
			{
				count++;
				m_buffer.append(localTime()).append(" [ ").append(instance()->m_name).append(" ] ").append(stringFLevel(level)).append(" : ").append(msg).append(" ");
				bufferAppend(args...);
				if(count >= 5){
					fileDump f;
					f.flush1(m_buffer);
					m_buffer = "";
					count = 0;
				}
			
			}
	}

	template <typename ...Args >
	void Warn(const std::string& message, Args ...args)
	{
		instance()->log(Log::LevelWarning, message, args...);
	}

	template <typename ...Args>
	void Error(const std::string& message, Args ...args)
	{
		instance()->log(Log::LevelError, message, args...);
	}

	template <typename ...Args>
	void Info(const std::string& message, Args ...args)
	{
		instance()->log(Log::LevelInfo, message, args...);

	}
	template <typename ...Args>
	void Critical(const std::string& message, Args ...args)
	{
		instance()->log(Log::LevelCritical, message, args...);

	}
	template <typename ...Args>
	void Debug(const std::string& message, Args ...args)
	{
		instance()->log(Log::LevelDebug, message, args...);

	}
}

#endif 
