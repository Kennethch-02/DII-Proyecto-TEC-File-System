#ifndef THREAD_READ_H
#define THREAD_READ_H
#include <QThread>

class thread_read :public QThread
{
    Q_OBJECT
public:
    thread_read(QObject *parent = nullptr); //Inicializacion dela interfaz grafica
    void start(int mseg, Priority p); //Metodo sobreescrito de Thread
    bool isRunning(); //Retorna la condicion de ejecucion del Thread
    void stop(); //Detine el Thread
    int Msegs(); //Retorna el Entero que contine los ms de ejecucion del Thread
signals:
    void do_read(); //Señal emitida por el Thread
protected:
    void run(); // Metodo protegido sobreescrito para ejecutar el Thread
private:
    QString to_byte(QString str);
    QString to_string(QString binary);
    bool running; //Boleado para correr el Thread
    int Mseg; // Entero que contine los ms de ejecucion del Thread
};

#endif // THREAD_READ_H
