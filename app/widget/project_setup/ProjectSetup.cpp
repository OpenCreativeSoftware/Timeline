#include "ProjectSetup.h"

namespace OpenCreativeSoftware {
	ProjectSetupWidget::ProjectSetupWidget(QWidget* t_parent) : QDialog(t_parent) {
		m_mainLayout = new QVBoxLayout(this);

		m_projectDataLayout = new QFormLayout(this);
		m_projectDataLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);
		m_projectNameField = new QLineEdit(this);
		m_projectNameField->setFixedWidth(360);
		m_projectDataLayout->addRow(tr("Project name"), m_projectNameField);

		m_okButton = new QPushButton(tr("OK"), this);
		m_okButton->setDefault(true);
		m_okButton->setAutoDefault(true);
		m_okButton->setFixedSize(54, 24);
		m_okButton->setStyleSheet("border-radius: 12px");
		m_cancelButton = new QPushButton(tr("Cancel"), this);
		m_cancelButton->setFixedSize(54, 24);
		m_cancelButton->setStyleSheet("border-radius: 12px");

		m_dialogButtons = new QDialogButtonBox();
		m_dialogButtons->addButton(m_okButton, QDialogButtonBox::ButtonRole::AcceptRole);
		m_dialogButtons->addButton(m_cancelButton, QDialogButtonBox::ButtonRole::RejectRole);
		m_mainLayout->addLayout(m_projectDataLayout);
		m_mainLayout->addWidget(m_dialogButtons);

		connect(m_cancelButton, &QPushButton::clicked, this, &ProjectSetupWidget::OnCancelButtonClick);

		setLayout(m_mainLayout);
		setWindowTitle(tr("New Project"));
	}

	void ProjectSetupWidget::OnCancelButtonClick() {
		QDialog::reject();
	}
};