#pragma once

#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>

namespace OpenCreativeSoftware {
	class ProjectSetupWidget : public QDialog {
		Q_OBJECT
	public:
		ProjectSetupWidget(QWidget* t_parent = nullptr);
	public slots:
		void OnCancelButtonClick();
	private:
		QVBoxLayout* m_mainLayout;
		QFormLayout* m_projectDataLayout;
		QLineEdit* m_projectNameField;
		QDialogButtonBox* m_dialogButtons;
		QPushButton* m_okButton;
		QPushButton* m_cancelButton;
	};
};