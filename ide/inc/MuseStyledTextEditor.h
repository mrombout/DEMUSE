#ifndef DEMUSE_MUSESTYLEDTEXTEDITOR_H
#define DEMUSE_MUSESTYLEDTEXTEDITOR_H

#include <wx/stc/stc.h>

namespace dem {
    namespace ide {
        enum {
            MARGIN_LINE_NUMBERS,
            MARGIN_FOLD
        };

        class MuseStyledTextEditor : public wxStyledTextCtrl {
        public:
            MuseStyledTextEditor(wxWindow *parent);

            bool loadFile(const wxString &fileName);
            bool saveFile();

            wxString filePath() const;

        private:
            void onMarginClick(wxStyledTextEvent &event);

            wxString mFilePath;
        };
    }
}

#endif //DEMUSE_MUSESTYLEDTEXTEDITOR_H
