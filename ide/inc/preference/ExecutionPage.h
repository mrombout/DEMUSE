#ifndef DEMUSE_EXECUTIONPAGE_H
#define DEMUSE_EXECUTIONPAGE_H

#include <wx/preferences.h>

namespace dem {
    namespace ide {
        class ExecutionPage : public wxPreferencesPage {
        public:
            ExecutionPage();
            virtual wxWindow *CreateWindow(wxWindow *parent) override;

            virtual wxString GetName() const;
        };
    }
}

#endif //DEMUSE_EXECUTIONPAGE_H
