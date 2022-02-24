#ifndef COUNTER_H
#define COUNTER_H

#include <QMainWindow>
#include "info.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Counter; }
QT_END_NAMESPACE

class Counter : public QMainWindow
{
    Q_OBJECT

public:
    Counter(QWidget *parent = nullptr);
    ~Counter();

private slots:
    void on_buttonOpenFile_clicked();

    void on_buttonAnalize_clicked();

    void on_buttonSave_clicked();

private:
    Ui::Counter *ui;
    info *i = nullptr;
    QString nomeFile;
    int counterCaratteri=0;
    int counterParole=0;
    int counterSenzaSpazi=0;
    int counterParagrafi=1;
    int counterFrasi=0;

    void reset();
};
#endif // COUNTER_H
