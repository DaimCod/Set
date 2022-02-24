#ifndef INFO_H
#define INFO_H

#include <QDialog>

namespace Ui {
class info;
}

class info : public QDialog
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = nullptr, int parole=0, int caratteri=0, int frasi=0, int paragrafi=0,
                  int senzaSpazi=0);
    ~info();

private:
    Ui::info *ui;

};

#endif // INFO_H
