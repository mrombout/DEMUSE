#ifndef DEMUSE_EDITORPAGE_H
#define DEMUSE_EDITORPAGE_H

#include <wx/preferences.h>

namespace dem {
    namespace ide {
        class EditorPage : public wxPreferencesPage {
        public:
            EditorPage();
            virtual wxWindow *CreateWindow(wxWindow *parent) override;

            virtual wxString GetName() const;
        };
    }
}

#endif //DEMUSE_EDITORPAGE_H
