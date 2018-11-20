#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "noteclass.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Buttons
    void on_buttonNewNote_clicked();
    void on_buttonNewTag_clicked();

    // Actions from mainToolBar
    void on_actionNewNote_triggered();
    void on_actionNewTag_triggered();
    void on_actionOpenArchive_triggered();

private:
    Ui::MainWindow *ui;

    // Stored values
    QVector<NoteClass*> notes;
    QVector<NoteClass*> archive;
    QStringList tags;
    QStringList tagsFilter;
    int MaxID;

    // Other methods
    void addNote();
    void addTag();

    // Methods to work with interface
    void updateView();
    void updateList();

    // Methods to work with JSON
    void readJSON(QString file);
    void writeJSON(QString file);
};

#endif // MAINWINDOW_H
