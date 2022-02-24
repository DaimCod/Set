#include "counter.h"
#include "ui_counter.h"
#include <QFileDialog>
#include <QTextStream>

Counter::Counter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Counter)
{
    ui->setupUi(this);
}

Counter::~Counter()
{
    delete ui;
}



void Counter::on_buttonOpenFile_clicked()
{
    //azzero tutti i counter precedenti
    reset();
    //Apro una nuova dialog per scegliere il file da leggere
    QString file_path = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("*.txt"));
    QFile file(file_path);

    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);

        //mi salvo il nome del file che mi servirà nella save
        QFileInfo fileInfo(file_path);
        nomeFile = fileInfo.fileName().replace(".txt", "");

        //cancello l'eventuale testo nel plainText
        ui->plainTextEdit->clear();

        //scrivo nel plaintext il testo contenuto nel file
        while(!stream.atEnd()){
            ui->plainTextEdit->appendPlainText(stream.readLine());
        }
        file.close();
    }
    ui->buttonAnalize->setEnabled(true);
}


void Counter::on_buttonAnalize_clicked()
{
    //azzero tutti i counter nel caso l'utente voglia rivedere di nuovo i dati
    reset();

    //N.B. le variabili sono definite nel file .h

    //mi salvo il contenuto del plaintext
    QString testo = ui->plainTextEdit->toPlainText();

    //metodo che conta i caratteri
    for(int i=0; i<testo.size(); ++i){
        if(testo[i]!='\n')
            counterCaratteri++;
    }

    //metodo che conta i caratteri senza spazi
    for(int i=0; i<testo.size(); ++i){
        if(testo[i]!='\n' && testo[i]!=' ')
            counterSenzaSpazi++;
    }

    //metodo che conta le parole
    for(int i=0; i<testo.size(); ++i){
        if(testo[i] == ' ' || testo[i] == '\n')
            counterParole++;
    }

    //metodo che conta i paragrafi
    for(int i=0; i<testo.size(); ++i){
        if(testo[i] == '\n')
            counterParagrafi++;
    }

    //metodo che conta le frasi
    for(int i=0; i<testo.size(); ++i){
        if(testo[i] == '.' || testo[i] == '!' || testo[i] == '?')
            counterFrasi++;
    }

    //passo i counter alla nuova dialog che il compito di mostrarli a schermo
    i = new info(this, counterParole, counterCaratteri, counterFrasi, counterParagrafi, counterSenzaSpazi);
    i->open();

    ui->buttonSave->setEnabled(true);
}


void Counter::on_buttonSave_clicked()
{
    //creo la stringa da mandare nel file csv
    QString text = "\"parole\",\"caratteri\",\"frasi\",\"paragrafi\",\"caratteriSenzaSpazi\"";
    QString value = "\""+QString::number(counterParole)+"\",\""+QString::number(counterCaratteri)+"\",\""
            +QString::number(counterFrasi)+"\",\""+QString::number(counterParagrafi)+"\",\""+
            QString::number(counterSenzaSpazi)+"\"";


    //creo il file con lo stesso nome ma formato .csv
    QFile file(nomeFile.append(".csv"));
    //QFile file = QFileDialog::getSaveFileName(this, tr("Save as"), QDir::currentPath(), tr("*.csv"));
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream << text << "\n";
        stream << value << "\n";

        file.flush();
        file.close();
        //azzero tutti i counter nel caso l'utente voglia aprire un nuovo file da analizzare
        reset();
    }
}

void Counter::reset()
{
    counterParole = 0;
    counterCaratteri = 0;
    counterFrasi = 0;
    counterParagrafi = 1;
    counterSenzaSpazi = 0;
}

