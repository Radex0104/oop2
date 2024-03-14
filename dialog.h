#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSharedPointer>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void on_ButNewBook_clicked();

    void on_ButDel_clicked();

    void on_ButFind_clicked();

    void on_ButEdit_clicked();
private:
    void clients2grid(bool filtered=false) ;
    Ui::Dialog *ui;
};
#endif // DIALOG_H
