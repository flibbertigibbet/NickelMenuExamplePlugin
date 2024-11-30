#ifndef NP_DIALOG_HPP
#define NP_DIALOG_HPP

#include <QDialog>

class NPDialog : public QDialog
{
    Q_OBJECT
    public:
        NPDialog(QWidget* parent = nullptr);
        ~NPDialog() = default;
        void showDlg();

    protected:
        bool eventFilter(QObject *obj, QEvent *event) override;
    private:
        void installEvFilter(QWidget *w);
};

#endif // NP_DIALOG_HPP
