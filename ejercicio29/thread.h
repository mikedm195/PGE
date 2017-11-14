#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QDebug>
#include <fstream>

class Thread : public QThread
{
private:
    void run()
    {
        qDebug()<<"ThreadId: "<<currentThreadId();
        std::ofstream fs("qThread.txt",std::ios::app);
        for(int j = 0;j<999;j++)
            for(int i = 0;i<999999;i++)
                fs << (char)i%255;
    }
};

#endif // THREAD_H
