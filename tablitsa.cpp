#include "tablitsa.h"
#include "./ui_tablitsa.h"
#include "addpanel.h"
#include "QFile"

tablitsa::tablitsa(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tablitsa){
    ui->setupUi(this);
    setWindowTitle("Картотека пациентов");
    table = new QTableWidget(this);
    table->setColumnCount(6);
    QStringList headers;
    headers << "Фамилия" << "Имя" << "Отчество" << "Дата рождения" << "Рост" << "Вес";
    table->setHorizontalHeaderLabels(headers);
    setCentralWidget(table);
    loadFromFile();
}

tablitsa::~tablitsa(){
    delete ui;
}

void tablitsa::on_addButton_triggered(){
    addPanel panel;
    if (panel.exec() == QDialog::Accepted) {
        QString surname = panel.getSurname();
        QString name = panel.getName();
        QString lastName = panel.getLastName();
        QDate birthDate = panel.getBirthDate();
        QString height = panel.getHeight();
        QString weight = panel.getWeight();
        int row = table->rowCount();
        table->insertRow(row);
        QTableWidgetItem* itemSurname = new QTableWidgetItem(surname);
        table->setItem(row, 0, itemSurname);
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        table->setItem(row, 1, itemName);
        QTableWidgetItem* itemLastName = new QTableWidgetItem(lastName);
        table->setItem(row, 2, itemLastName);
        QTableWidgetItem* itemBirthDate = new QTableWidgetItem(birthDate.toString());
        table->setItem(row, 3, itemBirthDate);
        QTableWidgetItem* itemHeight = new QTableWidgetItem(height);
        table->setItem(row, 4, itemHeight);
        QTableWidgetItem* itemWeight = new QTableWidgetItem(weight);
        table->setItem(row, 5, itemWeight);
        saveToFile();
    }
}


void tablitsa::on_delButton_triggered(){
    QList<QTableWidgetItem*> selectedItems = table->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = table->row(selectedItems.first());
        table->removeRow(row);
        saveToFile();
    }
}

void tablitsa::saveToFile(){
    QFile file("database.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream save(&file);
        for (int row = 0; row < table->rowCount(); ++row) {
            QStringList values;
            for (int column = 0; column < 6; ++column) {
                QTableWidgetItem* item = table->item(row, column);
                if (item) {
                    values.append(item->text());
                } else {
                    values.append("");
                }
            }
            save << values.join(",") << "\n";
        }
        file.close();
    }
}

void tablitsa::loadFromFile(){
    QFile file("database.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream load(&file);
        while (!load.atEnd()) {
            QString line = load.readLine();
            QStringList values = line.split(",");
            if (values.size() == 6) {
                int row = table->rowCount();
                table->insertRow(row);
                for (int i = 0; i < 6; ++i) {
                    QTableWidgetItem* item = new QTableWidgetItem(values[i]);
                    table->setItem(row, i, item);
                }
            }
        }
        file.close();
    }
}
