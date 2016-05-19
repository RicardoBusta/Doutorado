/********************************************************************************
** Form generated from reading UI file 'lu_tab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LU_TAB_H
#define UI_LU_TAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LUTab
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *m_spinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *gen_pushButton;
    QPushButton *deco_pushButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QTableWidget *A_tableWidget;
    QLabel *label_5;
    QTableWidget *B_tableWidget;
    QLabel *label_3;
    QTableWidget *C_tableWidget;

    void setupUi(QWidget *LUTab)
    {
        if (LUTab->objectName().isEmpty())
            LUTab->setObjectName(QStringLiteral("LUTab"));
        LUTab->resize(400, 300);
        verticalLayout = new QVBoxLayout(LUTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(LUTab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(LUTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        m_spinBox = new QSpinBox(groupBox);
        m_spinBox->setObjectName(QStringLiteral("m_spinBox"));
        m_spinBox->setMinimum(1);
        m_spinBox->setMaximum(9999);
        m_spinBox->setValue(10);

        horizontalLayout->addWidget(m_spinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gen_pushButton = new QPushButton(groupBox);
        gen_pushButton->setObjectName(QStringLiteral("gen_pushButton"));

        horizontalLayout_3->addWidget(gen_pushButton);

        deco_pushButton = new QPushButton(groupBox);
        deco_pushButton->setObjectName(QStringLiteral("deco_pushButton"));

        horizontalLayout_3->addWidget(deco_pushButton);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(LUTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        A_tableWidget = new QTableWidget(groupBox_2);
        A_tableWidget->setObjectName(QStringLiteral("A_tableWidget"));
        A_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        A_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        A_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        horizontalLayout_2->addWidget(A_tableWidget);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        B_tableWidget = new QTableWidget(groupBox_2);
        B_tableWidget->setObjectName(QStringLiteral("B_tableWidget"));
        B_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        B_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        B_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        B_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        horizontalLayout_2->addWidget(B_tableWidget);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        C_tableWidget = new QTableWidget(groupBox_2);
        C_tableWidget->setObjectName(QStringLiteral("C_tableWidget"));
        C_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        C_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        C_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        C_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        horizontalLayout_2->addWidget(C_tableWidget);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(LUTab);

        QMetaObject::connectSlotsByName(LUTab);
    } // setupUi

    void retranslateUi(QWidget *LUTab)
    {
        LUTab->setWindowTitle(QApplication::translate("LUTab", "Form", 0));
        label->setText(QApplication::translate("LUTab", "Decomposi\303\247\303\243o LU", 0));
        groupBox->setTitle(QApplication::translate("LUTab", "Gera\303\247\303\243o de Matriz", 0));
        label_2->setText(QApplication::translate("LUTab", "m", 0));
        gen_pushButton->setText(QApplication::translate("LUTab", "Gerar", 0));
        deco_pushButton->setText(QApplication::translate("LUTab", "Decompor", 0));
        pushButton->setText(QApplication::translate("LUTab", "Carregar Matriz", 0));
        pushButton_2->setText(QApplication::translate("LUTab", "Exportar Matlab", 0));
        groupBox_2->setTitle(QApplication::translate("LUTab", "Decomposi\303\247\303\243o", 0));
        label_4->setText(QApplication::translate("LUTab", "LU(", 0));
        label_5->setText(QApplication::translate("LUTab", ") =", 0));
        label_3->setText(QApplication::translate("LUTab", "x", 0));
    } // retranslateUi

};

namespace Ui {
    class LUTab: public Ui_LUTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LU_TAB_H
