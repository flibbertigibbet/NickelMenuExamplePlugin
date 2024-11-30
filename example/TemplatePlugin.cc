#include <QDialogButtonBox>
#include <QLabel>
#include <QVBoxLayout>

#include "TemplatePlugin.h"

TemplatePlugin::TemplatePlugin() {
    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *lbl = new QLabel("This is a sample NickelPlugin");
    layout->addWidget(lbl);
    auto bb = new QDialogButtonBox(QDialogButtonBox::Close, &m_dlg);
    connect(bb, &QDialogButtonBox::rejected, &m_dlg, &QDialog::reject);
    layout->addWidget(bb);
    m_dlg.setLayout(layout);
}

void TemplatePlugin::showUi() {
    m_dlg.showDlg();
}
