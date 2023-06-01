#include "my_widget.h"

#include <QPainter>

MyWidget::MyWidget(QWidget *parent) //
    : QWidget(parent), timer(this) {
  timer.start(timer_interval);
  connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void MyWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);

  painter.translate(rect().width() / 2.0, rect().height() / 2.0);
  auto side = std::min(rect().width(), rect().height());
  painter.scale(side / 200.0, side / 200.0);
  painter.setPen(Qt::NoPen);
  for (int i = 0; i < num_disks; i++) {
    if (i != hidden) {
      QRadialGradient gradient(-5, 75, 15);
      gradient.setColorAt(0, QColor(Qt::GlobalColor::magenta));
      gradient.setColorAt(1, QColor(Qt::GlobalColor::lightGray));
      painter.setBrush(gradient);
      painter.drawEllipse(-20, 60, 30, 30);
    }
    painter.rotate(360.0 / num_disks);
  }
  painter.setBrush(QBrush(QColor(Qt::GlobalColor::black)));
  painter.scale(0.3, 0.3);
  int l = 20;
  int w = 2;
  painter.drawRect(-w / 2, -l / 2, w, l);
  painter.drawRect(-l / 2, -w / 2, l, w);
}

void MyWidget::on_timer() {
  hidden = (hidden + 1) % num_disks;
  update();
}

void MyWidget::toggle_animation() {
  if (timer.isActive()) {

    timer.stop();
  }

  else
    timer.start(timer_interval);
}
