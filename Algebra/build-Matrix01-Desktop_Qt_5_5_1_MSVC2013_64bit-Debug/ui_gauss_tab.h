/********************************************************************************
** Form generated from reading UI file 'gauss_tab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSS_TAB_H
#define UI_GAUSS_TAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GaussTab
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpinBox *m_spinBox;
    QLabel *label_7;
    QSpinBox *n_spinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *gen_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QLabel *label_3;
    QTableWidget *tableWidget_2;
    QLabel *label_2;
    QTableWidget *tableWidget_3;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget_4;
    QLabel *label_4;
    QTableWidget *tableWidget_6;
    QLabel *label_5;
    QTableWidget *tableWidget_5;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;

    void setupUi(QWidget *GaussTab)
    {
        if (GaussTab->objectName().isEmpty())
            GaussTab->setObjectName(QStringLiteral("GaussTab"));
        GaussTab->resize(400, 494);
        verticalLayout = new QVBoxLayout(GaussTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(GaussTab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(GaussTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        m_spinBox = new QSpinBox(groupBox);
        m_spinBox->setObjectName(QStringLiteral("m_spinBox"));

        horizontalLayout_3->addWidget(m_spinBox);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        n_spinBox = new QSpinBox(groupBox);
        n_spinBox->setObjectName(QStringLiteral("n_spinBox"));

        horizontalLayout_3->addWidget(n_spinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gen_pushButton = new QPushButton(groupBox);
        gen_pushButton->setObjectName(QStringLiteral("gen_pushButton"));

        horizontalLayout_4->addWidget(gen_pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(GaussTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(groupBox_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout->addWidget(tableWidget);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        tableWidget_2 = new QTableWidget(groupBox_2);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout->addWidget(tableWidget_2);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        tableWidget_3 = new QTableWidget(groupBox_2);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));

        horizontalLayout->addWidget(tableWidget_3);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(4, 1);

        verticalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(GaussTab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget_4 = new QTableWidget(groupBox_4);
        tableWidget_4->setObjectName(QStringLiteral("tableWidget_4"));

        horizontalLayout_2->addWidget(tableWidget_4);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        tableWidget_6 = new QTableWidget(groupBox_4);
        tableWidget_6->setObjectName(QStringLiteral("tableWidget_6"));
        tableWidget_6->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout_2->addWidget(tableWidget_6);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        tableWidget_5 = new QTableWidget(groupBox_4);
        tableWidget_5->setObjectName(QStringLiteral("tableWidget_5"));

        horizontalLayout_2->addWidget(tableWidget_5);

        horizontalLayout_2->setStretch(0, 10);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(4, 1);

        verticalLayout->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(GaussTab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listWidget = new QListWidget(groupBox_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(listWidget);


        verticalLayout->addWidget(groupBox_3);

        verticalLayout->setStretch(2, 10);
        verticalLayout->setStretch(3, 10);
        verticalLayout->setStretch(4, 1);

        retranslateUi(GaussTab);

        QMetaObject::connectSlotsByName(GaussTab);
    } // setupUi

    void retranslateUi(QWidget *GaussTab)
    {
        GaussTab->setWindowTitle(QApplication::translate("GaussTab", "Form", 0));
        label->setText(QApplication::translate("GaussTab", "Sistema com Elimina\303\247\303\243o de Gauss", 0));
        groupBox->setTitle(QApplication::translate("GaussTab", "Dimens\303\265es do Sistema", 0));
        label_6->setText(QApplication::translate("GaussTab", "m", 0));
        label_7->setText(QApplication::translate("GaussTab", "n", 0));
        gen_pushButton->setText(QApplication::translate("GaussTab", "Generate", 0));
        groupBox_2->setTitle(QApplication::translate("GaussTab", "Sistema", 0));
        label_3->setText(QApplication::translate("GaussTab", "x", 0));
        label_2->setText(QApplication::translate("GaussTab", "=", 0));
        groupBox_4->setTitle(QApplication::translate("GaussTab", "Elimina\303\247\303\243o", 0));
        label_4->setText(QApplication::translate("GaussTab", "x", 0));
        label_5->setText(QApplication::translate("GaussTab", "=", 0));
        groupBox_3->setTitle(QApplication::translate("GaussTab", "Solu\303\247\303\243o", 0));
    } // retranslateUi

};

namespace Ui {
    class GaussTab: public Ui_GaussTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSS_TAB_H
