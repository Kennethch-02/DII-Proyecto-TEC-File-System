#include "thread.h"
/**
* \brief Aplicacion Thread, que emite las señales para actualizar la aplicacion
* segun la frecuencia que se requiera
* @param QThread
*/
Thread::Thread(QObject *parent)
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
void Thread::start(int mseg, QThread::Priority p)
{
    Mseg = mseg;
    QThread::start(p);
}
/**
* \brief Retorna el estado de ejecucion del Thread
* @param QThread
*/
bool Thread::isRunning()
{
    return running;
}
/**
* \brief Detiene la ejecucion del Thread
* @param QThread
*/
void Thread::stop()
{
    running = false;
}
/**
* \brief Retorna el valor entero de los milisegundos
* @param Int
*/
int Thread::Msegs()
{
    return Mseg;
}
/**
* \brief Metodo Run del Thread, implementa la frecuencia de actualizacion
* @param QThread
*/
void Thread::run(){
    while (running){
        emit already();
        msleep(Mseg);
    }
}
