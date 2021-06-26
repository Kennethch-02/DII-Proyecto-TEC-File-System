#ifndef THREAD_H
#define THREAD_H
#include <QThread>
/**
* \brief Aplicacion Thread, que emite las señales para actualizar la aplicacion
* segun la frecuencia que se requiera
* @param QThread
*/
class Thread : public QThread
{
    Q_OBJECT
public:
    Thread(QObject *parent = nullptr); //Inicializacion dela interfaz grafica
    void start(int mseg, Priority p); //Metodo sobreescrito de Thread
    bool isRunning(); //Retorna la condicion de ejecucion del Thread
    void stop(); //Detine el Thread
    int Msegs(); //Retorna el Entero que contine los ms de ejecucion del Thread
signals:
    void already(); //Señal emitida por el Thread
protected:
    void run(); // Metodo protegido sobreescrito para ejecutar el Thread
private:
    bool running; //Boleado para correr el Thread
    int Mseg; // Entero que contine los ms de ejecucion del Thread
};

#endif // THREAD_H
