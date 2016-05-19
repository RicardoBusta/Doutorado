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
#include <QtWidgets/QCheckBox>
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
    QCheckBox *vert_checkBox;
    QCheckBox *horz_checkBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *gen_pushButton;
    QPushButton *eli_pushButton;
    QPushButton *sol_pushButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QTableWidget *A1_tableWidget;
    QLabel *label_3;
    QTableWidget *B1_tableWidget;
    QLabel *label_2;
    QTableWidget *C1_tableWidget;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *A2_tableWidget;
    QLabel *label_4;
    QTableWidget *B2_tableWidget;
    QLabel *label_5;
    QTableWidget *C2_tableWidget;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *sol_tableWidget;

    void setupUi(QWidget *GaussTab)
    {
        if (GaussTab->objectName().isEmpty())
            GaussTab->setObjectName(QStringLiteral("GaussTab"));
        GaussTab->resize(748, 494);
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
        m_spinBox->setMinimum(1);
        m_spinBox->setMaximum(9999);
        m_spinBox->setValue(5);

        horizontalLayout_3->addWidget(m_spinBox);

        vert_checkBox = new QCheckBox(groupBox);
        vert_checkBox->setObjectName(QStringLiteral("vert_checkBox"));

        horizontalLayout_3->addWidget(vert_checkBox);

        horz_checkBox = new QCheckBox(groupBox);
        horz_checkBox->setObjectName(QStringLiteral("horz_checkBox"));

        horizontalLayout_3->addWidget(horz_checkBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gen_pushButton = new QPushButton(groupBox);
        gen_pushButton->setObjectName(QStringLiteral("gen_pushButton"));

        horizontalLayout_4->addWidget(gen_pushButton);

        eli_pushButton = new QPushButton(groupBox);
        eli_pushButton->setObjectName(QStringLiteral("eli_pushButton"));

        horizontalLayout_4->addWidget(eli_pushButton);

        sol_pushButton = new QPushButton(groupBox);
        sol_pushButton->setObjectName(QStringLiteral("sol_pushButton"));

        horizontalLayout_4->addWidget(sol_pushButton);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(GaussTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        A1_tableWidget = new QTableWidget(groupBox_2);
        A1_tableWidget->setObjectName(QStringLiteral("A1_tableWidget"));

        horizontalLayout->addWidget(A1_tableWidget);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        B1_tableWidget = new QTableWidget(groupBox_2);
        B1_tableWidget->setObjectName(QStringLiteral("B1_tableWidget"));
        B1_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout->addWidget(B1_tableWidget);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        C1_tableWidget = new QTableWidget(groupBox_2);
        C1_tableWidget->setObjectName(QStringLiteral("C1_tableWidget"));

        horizontalLayout->addWidget(C1_tableWidget);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(4, 1);

        verticalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(GaussTab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        A2_tableWidget = new QTableWidget(groupBox_4);
        A2_tableWidget->setObjectName(QStringLiteral("A2_tableWidget"));

        horizontalLayout_2->addWidget(A2_tableWidget);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        B2_tableWidget = new QTableWidget(groupBox_4);
        B2_tableWidget->setObjectName(QStringLiteral("B2_tableWidget"));
        B2_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout_2->addWidget(B2_tableWidget);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        C2_tableWidget = new QTableWidget(groupBox_4);
        C2_tableWidget->setObjectName(QStringLiteral("C2_tableWidget"));

        horizontalLayout_2->addWidget(C2_tableWidget);

        horizontalLayout_2->setStretch(0, 10);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(4, 1);

        verticalLayout->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(GaussTab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        sol_tableWidget = new QTableWidget(groupBox_3);
        sol_tableWidget->setObjectName(QStringLiteral("sol_tableWidget"));

        verticalLayout_2->addWidget(sol_tableWidget);


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
        vert_checkBox->setText(QApplication::translate("GaussTab", "Pivota\303\247\303\243o Vertical", 0));
        horz_checkBox->setText(QApplication::translate("GaussTab", "Pivota\303\247\303\243o Horizontal", 0));
        gen_pushButton->setText(QApplication::translate("GaussTab", "Gerar", 0));
        eli_pushButton->setText(QApplication::translate("GaussTab", "Eliminar", 0));
        sol_pushButton->setText(QApplication::translate("GaussTab", "Resolver", 0));
        pushButton->setText(QApplication::translate("GaussTab", "Carregar Matriz", 0));
        pushButton_2->setText(QApplication::translate("GaussTab", "Exportar Matlab", 0));
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
