#include "addpanel.h"
#include "ui_addpanel.h"
#include "QSpinBox"

addPanel::addPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPanel)
{
    ui->setupUi(this);
    setWindowTitle("Добавление пациентов");
    ui->dateBirth->setDate(QDate());
}

QString addPanel::getSurname() const {
    return surname;
}

QString addPanel::getName() const {
    return name;
}

QString addPanel::getLastName() const {
    return lastName;
}

QDate addPanel::getBirthDate() const {
    return birthDate;
}

QString addPanel::getHeight() const {
    return height;
}

QString addPanel::getWeight() const {
    return weight;
}

addPanel::~addPanel()
{
    delete ui;
}

void addPanel::on_add_clicked()
{
    surname = ui->surname->text();
    name = ui->name->text();
    lastName = ui->lastName->text();
    birthDate = ui->dateBirth->date();
    int intHeight = ui->height->value();
    height = QString::number(intHeight);
    int intWeight = ui->weight->value();
    weight = QString::number(intWeight);
    accept();
}


void addPanel::on_exit_clicked()
{
    reject();
}

