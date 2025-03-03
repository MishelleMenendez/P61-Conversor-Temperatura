#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Conversor; }
QT_END_NAMESPACE

class Conversor : public QDialog
{
    Q_OBJECT

public:
    Conversor(QWidget *parent = nullptr);
    ~Conversor();

public slots:
    void cent2fahr(int grados);
    void fahr2cent(int grados);
    void cent2Kelv(int grados);
    void Kelv2cent(int grados);
    void fahr2Kelv(int grados);
    void Kelv2fahr(int grados);


private:
    Ui::Conversor *ui;
};
#endif // CONVERSOR_H
