#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct person_t {QString first_name;
                 QString last_name;
                 QString  phone_number;};

QDataStream& operator <<(QDataStream& ostream, const person_t& c)
{
    ostream << c.first_name << c.last_name << c.phone_number;
    return ostream;
}

QDataStream& operator >> (QDataStream& istream, const person_t& c)
{
    istream >> c.first_name >> c.last_name >> c.phone_number;
    return istream;
}

bool is_phone_number_valid(QString phone_number)
{
    for (QChar i : phone_number)
        for(int j = 48; j < 58; j++)
            if(i != QChar(j))
                return false;
    return true;
}

void MainWindow::writeContact(const person_t &person)
{
    QString FirstName = person.first_name;
    QString SecondName = person.last_name;
    QString Number = person.phone_number;

    buffer.append(person);

}

void MainWindow::SaveContact()
{
    QFile file("db.txt");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << buffer;
    file.close();
    update();
}

void MainWindow::DisplayContact()
{
    QFile file("db.txt");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in>>buffer;
    update();
}
