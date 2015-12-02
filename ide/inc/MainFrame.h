#ifndef DEMUSE_MAINFRAME_H
#define DEMUSE_MAINFRAME_H

#include <map>
#include <wx/frame.h>
#include <wx/event.h>
#include <wx/aui/aui.h>
#include <wx/dirctrl.h>
#include <wx/slider.h>
#include <wx/stc/stc.h>
#include "MuseStyledTextEditor.h"

namespace dem {
    namespace ide {
        enum {
            ID_NewFile = 1,
            ID_Run,
            ID_Stop
        };

        class MainFrame : public wxFrame {
        public:
            MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
            ~MainFrame();

        private:
            void createMenu();
            void createStatusBar();
            void createCenterNotebook();
            void createEditor(const wxString &filePath = wxT(""));
            void createToolBar();

            MuseStyledTextEditor *activeEditor();

            void onExit(wxCommandEvent &event);
            void onAbout(wxCommandEvent &event);

            void onFileNew(wxCommandEvent &event);
            void onFileOpen(wxCommandEvent &event);
            void onFileSave(wxCommandEvent &event);
            void onFileSaveAs(wxCommandEvent &event);
            void onFileClose(wxCommandEvent &event);

            void onEditUndo(wxCommandEvent &event);
            void onEditRedo(wxCommandEvent &event);
            void onEditCut(wxCommandEvent &event);
            void onEditCopy(wxCommandEvent &event);
            void onEditPaste(wxCommandEvent &event);
            void onEditSelectAll(wxCommandEvent &event);
            void onEditPreferences(wxCommandEvent &event);

            void onRunRun(wxCommandEvent &event);
            void onRunStop(wxCommandEvent &event);

            std::map<wxString, size_t> mFileEditors;

            wxAuiManager mMgr;

            wxMenu *mFileMenu;
            wxMenu *mRunMenu;
            wxMenu *mEditMenu;
            wxMenu *mHelpMenu;

            wxAuiNotebook *mNotebook;
            MuseStyledTextEditor *mEditor;

            wxSlider *mZoomSlider;

            wxProcess *mActiveProcess;

            wxDECLARE_EVENT_TABLE();
        };
    }
}

#endif //DEMUSE_MAINFRAME_H
