#include <QDesktopServices>
#include "Home.h"
#include "FontAwesome.h"

#include "widget/clickable_layout/ClickableLayout.h"

namespace OpenCreativeSoftware {
	HomeWidget::HomeWidget(QWidget* t_parent) : QWidget(t_parent, Qt::Window) {
		headerWidget = new QWidget(this);

		headerLayout = new QHBoxLayout(this);
		headerLayout->setContentsMargins(30, 10, 30, 10);
		ocsIcon = new QLabel(this);
		ocsIcon->setPixmap(FontAwesome::s_instance->icon(fa_solid, fa_timeline).pixmap(40, 40));
		projectFilterLineEdit = new QLineEdit(this);
		auto searchIcon = new QAction(this);
		searchIcon->setIcon(FontAwesome::s_instance->icon(fa_solid, fa_magnifying_glass));
		projectFilterLineEdit->addAction(searchIcon, QLineEdit::ActionPosition::LeadingPosition);
		projectFilterLineEdit->setPlaceholderText(tr("Search Projects..."));
		projectFilterLineEdit->setStyleSheet("height: 20px;");
		headerLayout->addWidget(ocsIcon);
		headerLayout->addStretch();
		headerLayout->addWidget(projectFilterLineEdit);
		headerWidget->setLayout(headerLayout);
		headerWidget->setProperty("lightHeader", true);

		contentWidget = new QWidget(this);
		buttonsWidget = new QWidget(this);

		contentHorizontalLayout = new QHBoxLayout(this);
		projectButtonsLayout = new QVBoxLayout(this);
		homeLabelCompoundWidget = new QWidget(this);
		homeIcon = new QLabel(this);
		homeIcon->setPixmap(FontAwesome::s_instance->icon(fa_solid, fa_folder_open).pixmap(24, 24));
		homeIcon->setAlignment(Qt::AlignVCenter);
		homeIcon->setStyleSheet("color: white");
		homeLabel = new QLabel(tr("Recent projects"), this);
		homeLabel->setStyleSheet("color: white; font-size: 20px");
		homeLabel->setAlignment(Qt::AlignVCenter);
		homeLabelCompoundLayout = new QHBoxLayout(this);
		homeLabelCompoundLayout->addWidget(homeIcon);
		homeLabelCompoundLayout->addWidget(homeLabel);
		homeLabelCompoundWidget->setLayout(homeLabelCompoundLayout);
		newProjectButton = new QPushButton(tr("New Project"), this);
		openProjectButton = new QPushButton(tr("Open Project"), this);
		githubButton = new QPushButton(this);
		githubButton->setIcon(FontAwesome::s_instance->icon(fa_solid, fa_github).pixmap(32, 32));
		githubButton->setIconSize(QSize(32, 32));
		githubButton->setStyleSheet("border: 0px solid; border-radius: 16px");
		githubButton->setFlat(true);
		githubButton->setDefault(false);
		githubButton->setAutoDefault(false);
		newProjectButton->setProperty("default", true);
		newProjectButton->setFixedHeight(32);
		openProjectButton->setFixedHeight(32);
		newProjectButton->setStyleSheet("border: 0px solid; border-radius: 16px; color: rgb(227, 227, 227)");
		openProjectButton->setStyleSheet("border: 0px solid; border-radius: 16px; color: rgb(227, 227, 227)");
		newProjectButton->setDefault(true);
		newProjectButton->setAutoDefault(true);
		openProjectButton->setDefault(false);
		openProjectButton->setAutoDefault(false);
		projectButtonsLayout->addWidget(homeLabelCompoundWidget);
		projectButtonsLayout->addWidget(newProjectButton);
		projectButtonsLayout->addWidget(openProjectButton);
		projectButtonsLayout->addStretch();
		projectButtonsLayout->addWidget(githubButton, 0, Qt::AlignLeft);
		buttonsWidget->setLayout(projectButtonsLayout);
		buttonsWidget->setFixedWidth(200);

		recentProjectsArea = new QScrollArea(this);
		recentProjectsArea->setStyleSheet("border: 0px solid;");

		contentHorizontalLayout->setContentsMargins(15, 0, 15, 0);
		contentHorizontalLayout->addWidget(buttonsWidget);
		contentHorizontalLayout->addWidget(recentProjectsArea, 2);
		contentWidget->setLayout(contentHorizontalLayout);

		mainLayout = new QVBoxLayout(this);
		mainLayout->addWidget(headerWidget);
		mainLayout->addWidget(contentWidget);
		mainLayout->setContentsMargins(0, 0, 0, 0);
		setLayout(mainLayout);

		connect(githubButton, &QPushButton::clicked, this, &HomeWidget::OpenGithubPage);

		resize(800, 600);
		setWindowTitle(tr("Home"));
		setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint & ~Qt::WindowMinimizeButtonHint);
		setWindowIcon(FontAwesome::s_instance->icon(fa_solid, fa_home));
	}

	void HomeWidget::OpenGithubPage() {
		QDesktopServices::openUrl(QUrl("https://github.com/OpenCreativeSoftware/Timeline"));
	}

};