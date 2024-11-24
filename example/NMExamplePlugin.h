#ifndef NM_EXAMPLE_PLUGIN_H
#define NM_EXAMPLE_PLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "../NMGuiInterface.h"

class NMExamplePlugin : public QObject, public NMGuiInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "NickelMenu.GuiInterface")
    Q_INTERFACES(NMGuiInterface)

    public:
        void runPlugin();
};

#endif // NM_EXAMPLE_PLUGIN_H
