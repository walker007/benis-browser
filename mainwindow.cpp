#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "navegador.h"

int tabIndex = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_addTab_clicked();
    ui->statusbar->addPermanentWidget(ui->addTab);
}

void MainWindow::on_abasBrowser_tabCloseRequested(int index)
{
    ui->abasBrowser->removeTab(index);
    tabIndex--;
}


void MainWindow::on_addTab_clicked()
{
    ui->abasBrowser->addTab(new Navegador(nullptr,ui->abasBrowser, tabIndex++,  ui->statusbar), "Nova Aba");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNova_Aba_triggered()
{
    on_addTab_clicked();
}

