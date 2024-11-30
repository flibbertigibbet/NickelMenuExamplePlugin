#ifndef TEMPLATE_PLUGIN_H
#define TEMPLATE_PLUGIN_H

#include <QObject>
#include "NPDialog.h"
#include "../NPGuiInterface.h"

class TemplatePlugin : public QObject, public NPGuiInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID NPGuiInterfaceIID FILE "TemplatePlugin.json")
    Q_INTERFACES(NPGuiInterface)

    public:
        TemplatePlugin();
        void showUi();

    private:
        NPDialog m_dlg;
};

#endif // TEMPLATE_PLUGIN_H
