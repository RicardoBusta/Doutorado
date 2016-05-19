/********************************************************************************
** Form generated from reading UI file 'block_tab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCK_TAB_H
#define UI_BLOCK_TAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
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

class Ui_BlockTab
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_6;
    QSpinBox *n_spinBox;
    QLabel *label_3;
    QSpinBox *nb_spinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QSpinBox *m_spinBox;
    QSpinBox *mb_spinBox;
    QSpinBox *p_spinBox;
    QSpinBox *pb_spinBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *gen_pushButton;
    QPushButton *calc_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QTableWidget *C_tableWidget;
    QLabel *label_10;
    QLabel *label_9;
    QTableWidget *A_tableWidget;
    QTableWidget *B_tableWidget;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;

    void setupUi(QWidget *BlockTab)
    {
        if (BlockTab->objectName().isEmpty())
            BlockTab->setObjectName(QStringLiteral("BlockTab"));
        BlockTab->resize(400, 340);
        verticalLayout = new QVBoxLayout(BlockTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(BlockTab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(BlockTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 4, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 4, 1, 1);

        n_spinBox = new QSpinBox(groupBox);
        n_spinBox->setObjectName(QStringLiteral("n_spinBox"));
        n_spinBox->setMinimum(1);
        n_spinBox->setMaximum(9999);
        n_spinBox->setValue(2);

        gridLayout_2->addWidget(n_spinBox, 0, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 2, 1, 1);

        nb_spinBox = new QSpinBox(groupBox);
        nb_spinBox->setObjectName(QStringLiteral("nb_spinBox"));
        nb_spinBox->setMinimum(1);
        nb_spinBox->setMaximum(9999);
        nb_spinBox->setValue(3);

        gridLayout_2->addWidget(nb_spinBox, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 6, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        m_spinBox = new QSpinBox(groupBox);
        m_spinBox->setObjectName(QStringLiteral("m_spinBox"));
        m_spinBox->setMinimum(1);
        m_spinBox->setMaximum(9999);
        m_spinBox->setValue(2);

        gridLayout_2->addWidget(m_spinBox, 0, 1, 1, 1);

        mb_spinBox = new QSpinBox(groupBox);
        mb_spinBox->setObjectName(QStringLiteral("mb_spinBox"));
        mb_spinBox->setMinimum(1);
        mb_spinBox->setMaximum(9999);
        mb_spinBox->setValue(3);

        gridLayout_2->addWidget(mb_spinBox, 1, 1, 1, 1);

        p_spinBox = new QSpinBox(groupBox);
        p_spinBox->setObjectName(QStringLiteral("p_spinBox"));
        p_spinBox->setMinimum(1);
        p_spinBox->setMaximum(9999);
        p_spinBox->setValue(2);

        gridLayout_2->addWidget(p_spinBox, 0, 5, 1, 1);

        pb_spinBox = new QSpinBox(groupBox);
        pb_spinBox->setObjectName(QStringLiteral("pb_spinBox"));
        pb_spinBox->setMinimum(1);
        pb_spinBox->setMaximum(9999);
        pb_spinBox->setValue(3);

        gridLayout_2->addWidget(pb_spinBox, 1, 5, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gen_pushButton = new QPushButton(groupBox);
        gen_pushButton->setObjectName(QStringLiteral("gen_pushButton"));

        horizontalLayout->addWidget(gen_pushButton);

        calc_pushButton = new QPushButton(groupBox);
        calc_pushButton->setObjectName(QStringLiteral("calc_pushButton"));

        horizontalLayout->addWidget(calc_pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BlockTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        C_tableWidget = new QTableWidget(groupBox_2);
        C_tableWidget->setObjectName(QStringLiteral("C_tableWidget"));
        C_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        C_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        C_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        gridLayout->addWidget(C_tableWidget, 0, 4, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 3, 1, 1);

        A_tableWidget = new QTableWidget(groupBox_2);
        A_tableWidget->setObjectName(QStringLiteral("A_tableWidget"));
        A_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        A_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        A_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        gridLayout->addWidget(A_tableWidget, 0, 0, 1, 1);

        B_tableWidget = new QTableWidget(groupBox_2);
        B_tableWidget->setObjectName(QStringLiteral("B_tableWidget"));
        B_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        B_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        B_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        gridLayout->addWidget(B_tableWidget, 0, 2, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 1, 4, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 1, 2, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 2, 2, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 2, 4, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(BlockTab);

        QMetaObject::connectSlotsByName(BlockTab);
    } // setupUi

    void retranslateUi(QWidget *BlockTab)
    {
        BlockTab->setWindowTitle(QApplication::translate("BlockTab", "Form", 0));
        label->setText(QApplication::translate("BlockTab", "Multiplica\303\247\303\243o de Matrizes Bloco", 0));
        groupBox->setTitle(QApplication::translate("BlockTab", "Gera\303\247\303\243o de Matrizes", 0));
        label_4->setText(QApplication::translate("BlockTab", "t", 0));
        label_7->setText(QApplication::translate("BlockTab", "r", 0));
        label_2->setText(QApplication::translate("BlockTab", "m", 0));
        label_6->setText(QApplication::translate("BlockTab", "p", 0));
        label_3->setText(QApplication::translate("BlockTab", "s", 0));
        label_5->setText(QApplication::translate("BlockTab", "n", 0));
        gen_pushButton->setText(QApplication::translate("BlockTab", "Gerar", 0));
        calc_pushButton->setText(QApplication::translate("BlockTab", "Calcular", 0));
        groupBox_2->setTitle(QApplication::translate("BlockTab", "Multiplica\303\247\303\243o", 0));
        label_10->setText(QApplication::translate("BlockTab", "mxn", 0));
        label_9->setText(QApplication::translate("BlockTab", "=", 0));
        label_8->setText(QApplication::translate("BlockTab", "x", 0));
        label_12->setText(QApplication::translate("BlockTab", "mxp", 0));
        label_11->setText(QApplication::translate("BlockTab", "nxp", 0));
        label_13->setText(QApplication::translate("BlockTab", "[rxs]", 0));
        label_14->setText(QApplication::translate("BlockTab", "[sxt]", 0));
        label_15->setText(QApplication::translate("BlockTab", "[rxt]", 0));
    } // retranslateUi

};

namespace Ui {
    class BlockTab: public Ui_BlockTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCK_TAB_H
