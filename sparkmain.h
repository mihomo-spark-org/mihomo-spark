#ifndef SPARKMAIN_H
#define SPARKMAIN_H

#include <QMainWindow>
#include <QSettings>
#include <QFile>
#include <QCoreApplication>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui
{
class SparkMain;
}
QT_END_NAMESPACE

class SparkMain : public QMainWindow
{
    Q_OBJECT

public:
    SparkMain(QWidget* parent = nullptr);
    ~SparkMain();

public slots:
    void save();

private:
    QRegularExpression re = QRegularExpression("\r|\n|\t");
    QString file_name;
    Ui::SparkMain* ui;
    QSettings* settings;
};
#endif // SPARKMAIN_H
