#include <QDialogButtonBox>
#include <QLabel>
#include <QMovie>
#include <QVBoxLayout>

#include "TemplatePlugin.h"

TemplatePlugin::TemplatePlugin() {
    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *lbl = new QLabel("This is a sample NickelPlugin");
    QMovie *movie = new QMovie("/usr/local/Kobo/plugins/res/nyan-cat.gif");
    lbl->setMovie(movie);
    layout->addWidget(lbl);
    auto bb = new QDialogButtonBox(QDialogButtonBox::Close, &m_dlg);
    connect(bb, &QDialogButtonBox::rejected, &m_dlg, &QDialog::reject);
    layout->addWidget(bb);
    m_dlg.setLayout(layout);
    movie->start();
}

void TemplatePlugin::showUi() {
    m_dlg.showDlg();
}
