//
// Created by engin on 22.11.2017.
//

#ifndef UBERGAME_LOGGER_H
#define UBERGAME_LOGGER_H

//THIS FILE SHOULD NOT INCLUDE ANY LOCAL CLASSES
#include <string>
#include <deque>
#include <SDL_timer.h>

class Logger {
public:
    enum Subsystem {RENDER, MODEL, INPUT, SETTINGS };
    enum Level {TRACE, DEBUG, INFO, WARN, ERROR };

    struct LogLine {
        Subsystem subsystem;
        Level level;
        std::string text;
        long time;

        LogLine(Subsystem subsystem, Level level, const std::string &text, long time) : subsystem(subsystem), level(level), time(time), text(text) {};
    };

private:
    std::deque<LogLine*> logQueue;
public:


    void log(Subsystem subsystem, Level level, const std::string &text) {
        logQueue.push_back(new LogLine(subsystem, level, text, SDL_GetTicks()));//SDL_GETTicks is used because we want real time, not game time
    };

    /**
     * This method returns a pointer to a single line of log, in order of it
     * received. Removing the object is the callers responsibility.
     *
     * @return single line of log
     */
    LogLine* getLog() {
        if(logQueue.size() == 0 ) {
            return NULL;
        }
        LogLine* temp = logQueue.front();
        logQueue.pop_front();
        return temp;
    }
};



#endif //UBERGAME_LOGGER_H