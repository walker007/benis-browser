#ifndef NAVEGADOR_H
#define NAVEGADOR_H

#include <QWidget>
#include <QTabWidget>
#include <QStatusBar>

namespace Ui {
class Navegador;
}

class Navegador : public QWidget
{
    Q_OBJECT

public:
    explicit Navegador(QWidget *parent = nullptr, QTabWidget *tab = NULL, int index = 0, QStatusBar *statusBar = NULL);
    ~Navegador();

private slots:
    void on_toolButton_clicked();

    void on_buttonGo_clicked();

    void on_inputUrl_editingFinished();

    void on_webView_urlChanged(const QUrl &arg1);

    void on_webView_titleChanged(const QString &title);

    void on_webView_loadStarted();

    void on_webView_loadProgress(int progress);

    void on_webView_statusBarMessage(const QString &text);

    void on_webView_loadFinished(bool arg1);


private:
    Ui::Navegador *ui;
    QTabWidget *tabs;
    QStatusBar *statusBar;
    int currentIndex;
};

#endif // NAVEGADOR_H
