#include "dlgAbout.h"
#include "ui_dlgAbout.h"
#include "version.h"

#include <QDebug>
#include <QRegularExpression>

dlgAbout::dlgAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgAbout)
{
    ui->setupUi(this);
    QStringList msgList;
    msgList << "Application Name\t" PROJECT_NAME;
    msgList << "Release\t" PROJECT_VERSION;
    msgList << "Copyright\t" LEGAL_COPYRIGHT;
    msgList << "Created with\t" "www.qt.io " QT_VERSION_STR;
    msgList << "Iconset\t" "www.flaticon.com";
    msgList << "Iconset\t" "www.flaticon.com/authors/freepik";
    msgList << "Iconset\t" "www.icons8.it";

    QString msg;
    QRegularExpression reWebURL("(www|http:|https:)+[^\\s]+[\\w]");
    QRegularExpressionMatch match;
    for (auto row : msgList) {
        auto split = row.split("\t");
        // URL Expansion
        QString attribute = split.last().trimmed();
        match = reWebURL.match(attribute);
        if(match.hasMatch()) {
            QString urlExpansion =
                QString("<a href=\"https://%1\">%1</a>")
                    .arg(match.captured());
            attribute.replace(match.captured(), urlExpansion);
        }
        msg += QString("<p><b>%1</b>: %2</p>")
                   .arg(split.first()).arg(attribute);
    }
    ui->textBrowser->setOpenExternalLinks(true);
    ui->textBrowser->setHtml(msg);
}

dlgAbout::~dlgAbout()
{
    delete ui;
}
