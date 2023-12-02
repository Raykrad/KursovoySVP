#ifndef TABLITSA_H
#define TABLITSA_H

#include <QMainWindow>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class tablitsa; }
QT_END_NAMESPACE

class tablitsa : public QMainWindow
{
    Q_OBJECT

public:
    tablitsa(QWidget *parent = nullptr);
    ~tablitsa();

private slots:
    void on_addButton_triggered();
    void on_delButton_triggered();
    void loadFromFile();
    void saveToFile();

private:
    Ui::tablitsa *ui;
    QTableWidget* table;
};
#endif // TABLITSA_H
