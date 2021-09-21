#include "navegador.h"
#include "ui_navegador.h"
#include <regex>
#include <iostream>
#include <QProgressBar>

Navegador::Navegador(QWidget *parent, QTabWidget *tab, int index, QStatusBar *status): QWidget(parent),
    ui(new Ui::Navegador)
{
    ui->setupUi(this);
    tabs = tab;
    currentIndex = index;
    statusBar = status;

}


Navegador::~Navegador()
{
    delete ui;
}

void Navegador::on_toolButton_clicked()
{
    QString url = "https://duckduckgo.com";
    ui->webView->load(url);
}

bool isValidUrl(QString url)
{

   const std::regex pattern("(^(http|https|ftp)://)?(www\\.|[a-zA-Z0-9]+\\.)?([a-zA-Z0-9]+\\.)([a-zA-Z0-9]+)(\\.[a-zA-Z0-9]+)?(/)?([-a-zA-Z0-9()!@:%_\\+.~#?&\\/\\/=]*)?");

   return std::regex_match(url.toStdString(), pattern,std::regex_constants::match_default);
}

bool notUsingProtocol (QString url)
{
    const std::regex pattern ("^((?!http://|https://|ftp://).)*$");
    return std::regex_match(url.toStdString(), pattern, std::regex_constants::match_default);
}

void Navegador::on_inputUrl_editingFinished()
{
    QString urlText = ui->inputUrl->text();

    if(isValidUrl(urlText))
    {
        if(notUsingProtocol(urlText))
        {
           ui->webView->load("https://" + urlText);
           return;
        }

        ui->webView->load(urlText);
        return;
    }


    ui->webView->load("https://duckduckgo.com/?q="+urlText);


}


void Navegador::on_buttonGo_clicked()
{
    on_inputUrl_editingFinished();

}

void Navegador::on_webView_urlChanged(const QUrl &arg1)
{
    ui->inputUrl->setText(arg1.toString());
}


void Navegador::on_webView_titleChanged(const QString &title)
{
    tabs->setTabText(currentIndex, title);
}

void Navegador::on_webView_loadStarted()
{
    statusBar->showMessage("Carregando...");
}


void Navegador::on_webView_loadProgress(int progress)
{
    statusBar->showMessage("Carregando ("+QString::number(progress)+"%)...");
}


void Navegador::on_webView_statusBarMessage(const QString &text)
{
    statusBar->showMessage(text);
}


void Navegador::on_webView_loadFinished(bool arg1)
{
    if(arg1)
    {
        statusBar->showMessage("Carregado com Sucesso!");
        return;
    }
        statusBar->showMessage("Falha ao Carregar");
}


