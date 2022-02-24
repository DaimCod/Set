#include "info.h"
#include "ui_info.h"
#include <QPieSeries>
#include <QChart>
info::info(QWidget *parent, int parole, int caratteri, int frasi, int paragrafi,
           int senzaSpazi) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    //inserisco nella apposita tabella i valori
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::number(caratteri)));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(senzaSpazi)));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(frasi)));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(paragrafi)));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::number(parole)));

    //creo il grafico a torta
    QPieSeries *series = new QPieSeries();
        series->append("Caratteri", caratteri);
        series->append("Caratteri senza spazi", senzaSpazi);
        series->append("Frasi", frasi);
        series->append("Paragrafi", paragrafi);
        series->append("Parole", parole);
    QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Grafico a torta");

    chart->legend()->show();
    ui->graphicsView->setChart(chart);
}

info::~info()
{
    delete ui;
}
