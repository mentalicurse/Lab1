#include <iostream>
#include <locale.h>
#include <memory>
using namespace std;

class ILogger {
public:
    ILogger() { //cout << "C" << endl; 
    }
    ~ILogger() { //cout << "D" << endl; 
    }
    virtual void SaveLog(string& logText) = 0;
};

class Logger :public ILogger
{
public:
    void SaveLog(string& logText) override {
        cout << "cохранение лога в файле" << endl;
    }
};

class DatabaseLogger :public ILogger
{
public:
    void SaveLog(string& logText) override {
        cout << "cохранение лога в базе данных" << endl;
    }
};

class SmtpMailer
{
private:
    ILogger* ilogger;
public:
    SmtpMailer(ILogger* logger) {
        ilogger = logger;
    }
    void SetLog(ILogger* logger) {
        ilogger = logger;
    }
    void SendMessage(string message)
    {
        cout << "отправка сообщения" << endl;
    }
};

int main() {
    setlocale(LC_ALL,"Rus");
    string message = "message1";
    Logger logger;
    DatabaseLogger databaseLogger;

    SmtpMailer smtp1(&logger);
    SmtpMailer smtp2(&databaseLogger);
    smtp1.SetLog(&databaseLogger);

    smtp1.SendMessage(message);
    smtp2.SendMessage(message);

    logger.SaveLog(message);
    databaseLogger.SaveLog(message);
    return 0;
}
