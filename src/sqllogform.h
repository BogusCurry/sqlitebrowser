#ifndef SQLLOGFORM_H
#define SQLLOGFORM_H

#include <qvariant.h>

/* QT_BEGIN_NAMESPACE and QT_END_NAMESPACE weren't introduced into QT right away... */
#ifndef QT_BEGIN_NAMESPACE
#define QT_BEGIN_NAMESPACE
#endif

#ifndef QT_END_NAMESPACE
#define QT_END_NAMESPACE
#endif


#include <QTextEdit>
#include <QStackedWidget>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sqlLogForm
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *textLabel1;
    QComboBox *comboBox3;
    QSpacerItem *spacer10;
    QPushButton *clearButton;
    QStackedWidget *logStack;
    QWidget *WStackPage;
    QGridLayout *gridLayout;
    QTextEdit *userLogText;
    QWidget *WStackPage1;
    QVBoxLayout *vboxLayout1;
    QTextEdit *appLogText;

    void setupUi(QDialog *sqlLogForm)
    {
        if (sqlLogForm->objectName().isEmpty())
            sqlLogForm->setObjectName(QString::fromUtf8("sqlLogForm"));
        sqlLogForm->resize(547, 203);
        vboxLayout = new QVBoxLayout(sqlLogForm);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabel1 = new QLabel(sqlLogForm);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        hboxLayout->addWidget(textLabel1);

        comboBox3 = new QComboBox(sqlLogForm);
        comboBox3->setObjectName(QString::fromUtf8("comboBox3"));

        hboxLayout->addWidget(comboBox3);

        spacer10 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer10);

        clearButton = new QPushButton(sqlLogForm);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        hboxLayout->addWidget(clearButton);


        vboxLayout->addLayout(hboxLayout);

        logStack = new QStackedWidget(sqlLogForm);
        logStack->setObjectName(QString::fromUtf8("logStack"));
        WStackPage = new QWidget(logStack);
        WStackPage->setObjectName(QString::fromUtf8("WStackPage"));
        gridLayout = new QGridLayout(WStackPage);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        userLogText = new QTextEdit(WStackPage);
        userLogText->setObjectName(QString::fromUtf8("userLogText"));
        userLogText->setReadOnly(true);

        gridLayout->addWidget(userLogText, 0, 0, 1, 1);

        logStack->insertWidget(0,  WStackPage);
        WStackPage1 = new QWidget(logStack);
        WStackPage1->setObjectName(QString::fromUtf8("WStackPage1"));
        vboxLayout1 = new QVBoxLayout(WStackPage1);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(11, 11, 11, 11);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        appLogText = new QTextEdit(WStackPage1);
        appLogText->setObjectName(QString::fromUtf8("appLogText"));
        appLogText->setReadOnly(true);

        vboxLayout1->addWidget(appLogText);

        logStack->insertWidget(1, WStackPage1);

        vboxLayout->addWidget(logStack);


        retranslateUi(sqlLogForm);
        QObject::connect(clearButton, SIGNAL(clicked()), sqlLogForm, SLOT(clearLog()));
        QObject::connect(comboBox3, SIGNAL(activated(int)), logStack, SLOT(setCurrentIndex(int)));

        QMetaObject::connectSlotsByName(sqlLogForm);
    } // setupUi

    void retranslateUi(QDialog *sqlLogForm)
    {
        sqlLogForm->setWindowTitle(QApplication::translate("sqlLogForm", "SQL Log", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("sqlLogForm", "Show SQL submitted by:", 0, QApplication::UnicodeUTF8));
        comboBox3->clear();
        comboBox3->insertItems(0, QStringList()
         << QApplication::translate("sqlLogForm", "User", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sqlLogForm", "Application", 0, QApplication::UnicodeUTF8)
        );
        clearButton->setText(QApplication::translate("sqlLogForm", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sqlLogForm: public Ui_sqlLogForm {};
} // namespace Ui

QT_END_NAMESPACE

class sqlLogForm : public QDialog, public Ui::sqlLogForm
{
    Q_OBJECT

public:
    sqlLogForm(QWidget* parent = 0, Qt::WindowFlags fl = Qt::Window);
    ~sqlLogForm();

public slots:
    virtual void closeEvent( QCloseEvent * );
    virtual void log( QString & statement, int msgtype );
    virtual void msgDBDirtyState( bool dirty );
    virtual void clearLog();

signals:
    void goingAway();
    void dbState(bool dirty);

protected slots:
    virtual void languageChange();

};

#endif // SQLLOGFORM_H