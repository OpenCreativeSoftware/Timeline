#pragma once
#include <QWidget>
#include <QBoxLayout>
#include <QMouseEvent>

namespace OpenCreativeSoftware {
    class ClickableLayoutWidget : public QWidget {
        Q_OBJECT
    public:
        ClickableLayoutWidget(QBoxLayout* t_layout, QWidget* parent = nullptr) : QWidget(parent) {
            setLayout(t_layout);
        }

    protected:
        void mousePressEvent(QMouseEvent* event) override {
            if (event->button() == Qt::LeftButton) {
                emit OnClick();
            }
            QWidget::mousePressEvent(event);
        }

    signals:
        void OnClick();
    };
};