/********************************************************************************
** Form generated from reading UI file 'performance_tab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERFORMANCE_TAB_H
#define UI_PERFORMANCE_TAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_PerformanceTab
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *m_spinBox;
    QLabel *label_3;
    QSpinBox *n_spinBox;
    QLabel *label_4;
    QSpinBox *p_spinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *generate_pushButton;
    QPushButton *calculate_pushButton;
    QCheckBox *three_times_checkBox;
    QCheckBox *read_checkBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QTableWidget *A_tableWidget;
    QTableWidget *C_tableWidget;
    QLabel *label_6;
    QTableWidget *B_tableWidget;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *col_label;
    QLabel *label_7;
    QLabel *row_label;
    QLabel *row2_label;
    QLabel *row3_label;
    QLabel *col2_label;
    QLabel *col3_label;
    QLabel *label_14;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *PerformanceTab)
    {
        if (PerformanceTab->objectName().isEmpty())
            PerformanceTab->setObjectName(QStringLiteral("PerformanceTab"));
        PerformanceTab->resize(579, 488);
        verticalLayout = new QVBoxLayout(PerformanceTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(PerformanceTab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(PerformanceTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        m_spinBox = new QSpinBox(groupBox);
        m_spinBox->setObjectName(QStringLiteral("m_spinBox"));
        m_spinBox->setMinimum(1);
        m_spinBox->setMaximum(9999);
        m_spinBox->setValue(500);

        horizontalLayout_2->addWidget(m_spinBox);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        n_spinBox = new QSpinBox(groupBox);
        n_spinBox->setObjectName(QStringLiteral("n_spinBox"));
        n_spinBox->setMinimum(1);
        n_spinBox->setMaximum(9999);
        n_spinBox->setValue(500);

        horizontalLayout_2->addWidget(n_spinBox);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        p_spinBox = new QSpinBox(groupBox);
        p_spinBox->setObjectName(QStringLiteral("p_spinBox"));
        p_spinBox->setMinimum(1);
        p_spinBox->setMaximum(9999);
        p_spinBox->setValue(500);

        horizontalLayout_2->addWidget(p_spinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        generate_pushButton = new QPushButton(groupBox);
        generate_pushButton->setObjectName(QStringLiteral("generate_pushButton"));

        horizontalLayout->addWidget(generate_pushButton);

        calculate_pushButton = new QPushButton(groupBox);
        calculate_pushButton->setObjectName(QStringLiteral("calculate_pushButton"));

        horizontalLayout->addWidget(calculate_pushButton);

        three_times_checkBox = new QCheckBox(groupBox);
        three_times_checkBox->setObjectName(QStringLiteral("three_times_checkBox"));
        three_times_checkBox->setChecked(true);

        horizontalLayout->addWidget(three_times_checkBox);

        read_checkBox = new QCheckBox(groupBox);
        read_checkBox->setObjectName(QStringLiteral("read_checkBox"));

        horizontalLayout->addWidget(read_checkBox);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PerformanceTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        A_tableWidget = new QTableWidget(groupBox_2);
        A_tableWidget->setObjectName(QStringLiteral("A_tableWidget"));
        A_tableWidget->setRowCount(0);
        A_tableWidget->setColumnCount(0);
        A_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        A_tableWidget->horizontalHeader()->setHighlightSections(false);
        A_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        A_tableWidget->verticalHeader()->setDefaultSectionSize(30);
        A_tableWidget->verticalHeader()->setHighlightSections(false);
        A_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        gridLayout->addWidget(A_tableWidget, 0, 0, 1, 1);

        C_tableWidget = new QTableWidget(groupBox_2);
        C_tableWidget->setObjectName(QStringLiteral("C_tableWidget"));
        C_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        C_tableWidget->setRowCount(0);
        C_tableWidget->setColumnCount(0);
        C_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        C_tableWidget->horizontalHeader()->setHighlightSections(false);
        C_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        C_tableWidget->verticalHeader()->setDefaultSectionSize(30);
        C_tableWidget->verticalHeader()->setHighlightSections(false);
        C_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        gridLayout->addWidget(C_tableWidget, 0, 4, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        B_tableWidget = new QTableWidget(groupBox_2);
        B_tableWidget->setObjectName(QStringLiteral("B_tableWidget"));
        B_tableWidget->setRowCount(0);
        B_tableWidget->setColumnCount(0);
        B_tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        B_tableWidget->horizontalHeader()->setHighlightSections(false);
        B_tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        B_tableWidget->verticalHeader()->setDefaultSectionSize(30);
        B_tableWidget->verticalHeader()->setHighlightSections(false);
        B_tableWidget->verticalHeader()->setMinimumSectionSize(30);

        gridLayout->addWidget(B_tableWidget, 0, 2, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 1, 2, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 1, 4, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(PerformanceTab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        col_label = new QLabel(groupBox_3);
        col_label->setObjectName(QStringLiteral("col_label"));

        gridLayout_2->addWidget(col_label, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        row_label = new QLabel(groupBox_3);
        row_label->setObjectName(QStringLiteral("row_label"));

        gridLayout_2->addWidget(row_label, 1, 1, 1, 1);

        row2_label = new QLabel(groupBox_3);
        row2_label->setObjectName(QStringLiteral("row2_label"));

        gridLayout_2->addWidget(row2_label, 1, 2, 1, 1);

        row3_label = new QLabel(groupBox_3);
        row3_label->setObjectName(QStringLiteral("row3_label"));

        gridLayout_2->addWidget(row3_label, 1, 3, 1, 1);

        col2_label = new QLabel(groupBox_3);
        col2_label->setObjectName(QStringLiteral("col2_label"));

        gridLayout_2->addWidget(col2_label, 2, 2, 1, 1);

        col3_label = new QLabel(groupBox_3);
        col3_label->setObjectName(QStringLiteral("col3_label"));

        gridLayout_2->addWidget(col3_label, 2, 3, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 0, 3, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 0, 2, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 4, 1, 1);


        verticalLayout->addWidget(groupBox_3);


        retranslateUi(PerformanceTab);

        QMetaObject::connectSlotsByName(PerformanceTab);
    } // setupUi

    void retranslateUi(QWidget *PerformanceTab)
    {
        PerformanceTab->setWindowTitle(QApplication::translate("PerformanceTab", "Form", 0));
        label->setText(QApplication::translate("PerformanceTab", "Compara\303\247\303\243o de Performance", 0));
        groupBox->setTitle(QApplication::translate("PerformanceTab", "Gera\303\247\303\243o de Matrizes", 0));
        label_2->setText(QApplication::translate("PerformanceTab", "m", 0));
        label_3->setText(QApplication::translate("PerformanceTab", "n", 0));
        label_4->setText(QApplication::translate("PerformanceTab", "p", 0));
        generate_pushButton->setText(QApplication::translate("PerformanceTab", "Gerar", 0));
        calculate_pushButton->setText(QApplication::translate("PerformanceTab", "Calcular", 0));
        three_times_checkBox->setText(QApplication::translate("PerformanceTab", "Executar 3x", 0));
        read_checkBox->setText(QApplication::translate("PerformanceTab", "Ler Input", 0));
        pushButton->setText(QApplication::translate("PerformanceTab", "Carregar Matriz", 0));
        pushButton_2->setText(QApplication::translate("PerformanceTab", "Exportar Matlab", 0));
        groupBox_2->setTitle(QApplication::translate("PerformanceTab", "Multiplica\303\247\303\243o", 0));
        label_5->setText(QApplication::translate("PerformanceTab", "x", 0));
        label_6->setText(QApplication::translate("PerformanceTab", "=", 0));
        label_11->setText(QApplication::translate("PerformanceTab", "mxn", 0));
        label_12->setText(QApplication::translate("PerformanceTab", "nxp", 0));
        label_13->setText(QApplication::translate("PerformanceTab", "mxp", 0));
        groupBox_3->setTitle(QApplication::translate("PerformanceTab", "Desempenho", 0));
        col_label->setText(QApplication::translate("PerformanceTab", "(ms)", 0));
        label_7->setText(QApplication::translate("PerformanceTab", "Por Linha", 0));
        row_label->setText(QApplication::translate("PerformanceTab", "(ms)", 0));
        row2_label->setText(QApplication::translate("PerformanceTab", "(ms)", 0));
        row3_label->setText(QApplication::translate("PerformanceTab", "(ms)", 0));
        col2_label->setText(QApplication::translate("PerformanceTab", "(ms)", 0));
        col3_label->setText(QApplication::translate("PerformanceTab", "(ms)", 0));
        label_14->setText(QApplication::translate("PerformanceTab", "itera\303\247\303\243o 3", 0));
        label_9->setText(QApplication::translate("PerformanceTab", "itera\303\247\303\243o 1", 0));
        label_10->setText(QApplication::translate("PerformanceTab", "itera\303\247\303\243o 2", 0));
        label_8->setText(QApplication::translate("PerformanceTab", "Por Coluna", 0));
    } // retranslateUi

};

namespace Ui {
    class PerformanceTab: public Ui_PerformanceTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERFORMANCE_TAB_H
