#ifndef ADDPANEL_H
#define ADDPANEL_H

#include <QDialog>
#include <QDate>

namespace Ui {
class addPanel;
}

class addPanel : public QDialog
{
    Q_OBJECT

public:
    explicit addPanel(QWidget *parent = nullptr);
    ~addPanel();
    QString getSurname() const;
    QString getName() const;
    QString getLastName() const;
    QDate getBirthDate() const;
    QString getHeight() const;
    QString getWeight() const;

private slots:
    void on_add_clicked();

    void on_exit_clicked();

private:
    Ui::addPanel *ui;
    QString surname, name, lastName, height, weight;
    QDate birthDate;
};

#endif // ADDPANEL_H
