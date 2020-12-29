#ifndef TERMOMETRO_H
#define TERMOMETRO_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Termometro; }
QT_END_NAMESPACE

class Termometro : public QWidget
{
    Q_OBJECT

public:
    Termometro(QWidget *parent = nullptr);
    ~Termometro();

public slots:
    float cent2Fahr(int valor);
    float cent2Kel(int valor);
    float fahr2Cent(int valor);
    float fahr2Kel(int valor);
    float kel2Cent(int valor);
    float kel2Fahr(int valor);
    void dialPresionado();
    void dialRelajado();

private:
    Ui::Termometro *ui;
};
#endif // TERMOMETRO_H
