/********************************************************************************
** Form generated from reading UI file 'cholesky_tab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOLESKY_TAB_H
#define UI_CHOLESKY_TAB_H

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

class Ui_CholeskyTab
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpinBox *m_spinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *gen_pushButton;
    QPushButton *example_pushButton;
    QPushButton *deco_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTableWidget *A_tableWidget;
    QLabel *label_3;
    QTableWidget *B_tableWidget;
    QLabel *label_6;
    QTableWidget *C_tableWidget;

    void setupUi(QWidget *CholeskyTab)
    {
        if (CholeskyTab->objectName().isEmpty())
            CholeskyTab->setObjectName(QStringLiteral("CholeskyTab"));
        CholeskyTab->resize(400, 300);
        verticalLayout = new QVBoxLayout(CholeskyTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CholeskyTab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(CholeskyTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        m_spinBox = new QSpinBox(groupBox);
        m_spinBox->setObjectName(QStringLiteral("m_spinBox"));
        m_spinBox->setMinimum(1);
        m_spinBox->setMaximum(9999);
        m_spinBox->setValue(10);

        horizontalLayout_2->addWidget(m_spinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gen_pushButton = new QPushButton(groupBox);
        gen_pushButton->setObjectName(QStringLiteral("gen_pushButton"));

        horizontalLayout_3->addWidget(gen_pushButton);

        example_pushButton = new QPushButton(groupBox);
        example_pushButton->setObjectName(QStringLiteral("example_pushButton"));

        horizontalLayout_3->addWidget(example_pushButton);

        deco_pushButton = new QPushButton(groupBox);
        deco_pushButton->setObjectName(QStringLiteral("deco_pushButton"));

        horizontalLayout_3->addWidget(deco_pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(CholeskyTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        A_tableWidget = new QTableWidget(groupBox_2);
        A_tableWidget->setObjectName(QStringLiteral("A_tableWidget"));
        A_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        A_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        A_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        horizontalLayout->addWidget(A_tableWidget);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        B_tableWidget = new QTableWidget(groupBox_2);
        B_tableWidget->setObjectName(QStringLiteral("B_tableWidget"));
        B_tableWidget->setAutoScroll(false);
        B_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        B_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        B_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        horizontalLayout->addWidget(B_tableWidget);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        C_tableWidget = new QTableWidget(groupBox_2);
        C_tableWidget->setObjectName(QStringLiteral("C_tableWidget"));

        horizontalLayout->addWidget(C_tableWidget);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(CholeskyTab);

        QMetaObject::connectSlotsByName(CholeskyTab);
    } // setupUi

    void retranslateUi(QWidget *CholeskyTab)
    {
        CholeskyTab->setWindowTitle(QApplication::translate("CholeskyTab", "Form", 0));
        label->setText(QApplication::translate("CholeskyTab", "Decomposi\303\247\303\243o de Cholesky", 0));
        groupBox->setTitle(QApplication::translate("CholeskyTab", "Gera\303\247\303\243o de Matriz", 0));
        label_5->setText(QApplication::translate("CholeskyTab", "m", 0));
        gen_pushButton->setText(QApplication::translate("CholeskyTab", "Gerar", 0));
        example_pushButton->setText(QApplication::translate("CholeskyTab", "PushButton", 0));
        deco_pushButton->setText(QApplication::translate("CholeskyTab", "Decompor", 0));
        groupBox_2->setTitle(QApplication::translate("CholeskyTab", "Decomposi\303\247\303\243o", 0));
        label_2->setText(QApplication::translate("CholeskyTab", "Cho(", 0));
        label_3->setText(QApplication::translate("CholeskyTab", ") =", 0));
        label_6->setText(QApplication::translate("CholeskyTab", "x", 0));
    } // retranslateUi

};

namespace Ui {
    class CholeskyTab: public Ui_CholeskyTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOLESKY_TAB_H
