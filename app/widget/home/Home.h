#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QPushButton>
#include <QScrollArea>

namespace OpenCreativeSoftware {
	class HomeWidget : public QWidget {
		Q_OBJECT
	public:
		HomeWidget(QWidget* t_parent = nullptr);

	public slots:
		void OpenGithubPage();
	signals:
		void OnNewProjectButtonClicked();
	public:
		QVBoxLayout* mainLayout;

		QWidget* headerWidget;
		QHBoxLayout* headerLayout;
		QLabel* ocsIcon;
		QLineEdit* projectFilterLineEdit;

		QWidget* contentWidget;
		QHBoxLayout* contentHorizontalLayout;
		QVBoxLayout* projectButtonsLayout;
		QWidget* buttonsWidget;
		QWidget* homeLabelCompoundWidget;
		QHBoxLayout* homeLabelCompoundLayout;
		QLabel* homeIcon;
		QLabel* homeLabel;
		QPushButton* newProjectButton;
		QPushButton* openProjectButton;
		QPushButton* githubButton;

		QScrollArea* recentProjectsArea;
		QWidget* recentProjectsWidgetHolder;
		QVBoxLayout* recentProjectsLayout;
	};
};