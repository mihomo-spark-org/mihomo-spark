#include "sparkmain.h"
#include "ui_sparkmain.h"

SparkMain::SparkMain(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::SparkMain)
{
    ui->setupUi(this);
    file_name = QApplication::applicationDirPath() + "/conf.ini";
    connect(ui->pushButton, &QPushButton::clicked, this, &SparkMain::save);
    settings = new QSettings(file_name, QSettings::Format::IniFormat);

    if (QFile::exists(file_name))
    {
        ui->plainTextEdit->setPlainText(settings->value("Spark/url").toString());
        ui->lineEdit_2->setText(settings->value("Spark/cmd").toString());
    }
    // connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, [&]()
    // {
    //     if (!ui->plainTextEdit->toPlainText().isEmpty())
    //     {
    //         auto cursor = ui->plainTextEdit->textCursor();
    //         auto pos = cursor.position();
    //         int count = 0;
    //         ui->plainTextEdit->blockSignals(true);
    //         while (ui->plainTextEdit->toPlainText().contains(re))
    //         {
    //             auto pos2 = ui->plainTextEdit->toPlainText().indexOf(re) + 1;
    //             if (pos > pos2)
    //             {
    //                 count++;
    //             }
    //             cursor.setPosition(pos2);
    //             cursor.deletePreviousChar();
    //         }
    //         cursor.setPosition(pos - count);
    //         ui->plainTextEdit->setTextCursor(cursor);
    //         ui->plainTextEdit->blockSignals(false);
    //     }
    // });
}

SparkMain::~SparkMain()
{
    delete ui;
}

void SparkMain::save()
{
    auto config_url = ui->plainTextEdit->toPlainText().remove(re);
    auto command_line = ui->lineEdit_2->text();
    settings->setValue("Spark/url", config_url);
    settings->setValue("Spark/cmd", command_line);
    settings->sync();
    ui->plainTextEdit->setPlainText(config_url);
}
