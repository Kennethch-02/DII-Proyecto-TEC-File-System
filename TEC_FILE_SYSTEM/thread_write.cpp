#include "thread_write.h"
#include <dirent.h>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QDir>

thread_write::thread_write(QObject *parent)
    : QThread(parent)
{
    running = true;
    Mseg = 0;
}
/**
* \brief Metodo que da inicio al Thread con la fracuencia en mili segundos y
* su prioridad.
* @param QThread
*/
void thread_write::start(int mseg, QThread::Priority p)
{
    Mseg = mseg;
    QThread::start(p);
}
/**
* \brief Retorna el estado de ejecucion del Thread
* @param QThread
*/
bool thread_write::isRunning()
{
    return running;
}
/**
* \brief Detiene la ejecucion del Thread
* @param QThread
*/
void thread_write::stop()
{
    running = false;
}
/**
* \brief Retorna el valor entero de los milisegundos
* @param Int
*/
int thread_write::Msegs()
{
    return Mseg;
}

/**
* \brief Metodo Run del Thread, implementa la frecuencia de actualizacion
* @param QThread
*/
void thread_write::run(){
    while (running){

    }
}
QString thread_write::to_byte(QString str)
{
    QByteArray b = str.toUtf8().toHex();
    str.clear();
    for ( const auto& c : b  ){
        str.append(c);
    }
    bool ok;
    QString binary = QString::number(str.toLongLong(&ok, 16),2);
    return binary;
}

QString thread_write::to_string(QString binary)
{
    ;
}

