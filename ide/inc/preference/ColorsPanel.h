#ifndef DEMUSE_COLORSPANEL_H
#define DEMUSE_COLORSPANEL_H

#include <map>
#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>

namespace dem {
    namespace ide {
        struct ColorDefaults {
            wxColour foreground;
            wxColour background;
            bool bold;
            bool italic;
            bool underline;
            int styleType;
        };

        class ColorsPanel : public wxPanel {
        public:
            ColorsPanel(wxWindow *parent);

            virtual bool TransferDataToWindow() override;
            virtual bool TransferDataFromWindow() override;

        public:
            const static std::map<wxString, ColorDefaults> DEFAULTS;

        private:
            wxPropertyGrid *mPg;
        };
    }
}

#endif //DEMUSE_COLORSPANEL_H
