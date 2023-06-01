#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->przycisk->setIcon(QIcon(":/img/media-playback-pause.png"));
  connect(ui->action_Koniec, SIGNAL(triggered()), this,
          SLOT(koniec_programu()));
  connect(ui->przycisk, SIGNAL(clicked()), this, SLOT(switch_button()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::koniec_programu() {
  QMessageBox::StandardButton a =
      QMessageBox::question(this, "Zamknąć?", "Zamknąć");
  if (a == QMessageBox::Yes) {
    qApp->quit();
  }
}

void MainWindow::on_action_O_programie_triggered() {
  QMessageBox::aboutQt(this, "O wspaniałym programie");
}

void MainWindow::switch_button() {
  if (isPaused) {
    isPaused = false;
    ui->przycisk->setIcon(QIcon(":/img/media-playback-pause.png"));
  } else {
    isPaused = true;
    ui->przycisk->setIcon(QIcon(":/img/media-playback-start.png"));
  }
}
