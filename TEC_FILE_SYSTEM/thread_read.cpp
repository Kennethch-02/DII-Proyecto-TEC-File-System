#include "thread_read.h"
#include <dirent.h>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QDir>
thread_read::thread_read(QObject *parent)
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
void thread_read::start(int mseg, QThread::Priority p)
{
    Mseg = mseg;
    QThread::start(p);
}
/**
* \brief Retorna el estado de ejecucion del Thread
* @param QThread
*/
bool thread_read::isRunning()
{
    return running;
}
/**
* \brief Detiene la ejecucion del Thread
* @param QThread
*/
void thread_read::stop()
{
    running = false;
}
/**
* \brief Retorna el valor entero de los milisegundos
* @param Int
*/
int thread_read::Msegs()
{
    return Mseg;
}
/**
* \brief Metodo Run del Thread, implementa la frecuencia de actualizacion
* @param QThread
*/
void thread_read::run(){
    while (running){

    }
}
QString thread_read::to_byte(QString str)
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

QString thread_read::to_string(QString binary)
{
    bool ok;
    int iValue = binary.toInt(&ok, 2);
    QString Hex = QString::number(iValue, 16);
    QString str = QString::fromUtf8(QByteArray::fromHex(Hex.toUtf8()));
    return str;
}

