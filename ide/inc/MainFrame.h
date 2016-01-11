#ifndef DEMUSE_MAINFRAME_H
#define DEMUSE_MAINFRAME_H

#include <memory>
#include <unordered_set>
#include <map>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/dataview.h>
#include <wx/process.h>
#include "AutocompleteVisitor.h"
#include "MuseStyledTextEditor.h"
#include "Parser.h"

namespace dem {
    namespace ide {
        enum {
            ID_NewFile = 1,
            ID_Build,
            ID_Run,
            ID_Stop
        };

        struct EditorInfo {
            size_t editorId;
            parser::ParseResults parseResults;
            std::unordered_set<std::string> autoCompleteWords;
        };

        class MainFrame : public wxFrame {
        public:
            MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
            ~MainFrame();

            wxAuiNotebook *mNotebook;
        private:
            void createMenu();
            void createStatusBar();
            void createCenterNotebook();
            void createEditor(const wxString &filePath = wxT(""));
            void createToolBar();
            void createBottomTools();

            MuseStyledTextEditor *activeEditor();

            void onExit(wxCommandEvent &event);
            void onAbout(wxCommandEvent &event);

            void onFileNew(wxCommandEvent &event);
            void onFileOpen(wxCommandEvent &event);
            void onFileSave(wxCommandEvent &event);
            void onFileSaveAs(wxCommandEvent &event);

            void onEditUndo(wxCommandEvent &event);
            void onEditRedo(wxCommandEvent &event);
            void onEditCut(wxCommandEvent &event);
            void onEditCopy(wxCommandEvent &event);
            void onEditPaste(wxCommandEvent &event);
            void onEditSelectAll(wxCommandEvent &event);
            void onEditPreferences(wxCommandEvent &event);

            void onRunBuild(wxCommandEvent &event);
            void onRunRun(wxCommandEvent &event);
            void onRunStop(wxCommandEvent &event);

            void onErrorListItemActivated(wxDataViewEvent &event);
            void onNotebookPageClose(wxAuiNotebookEvent &event);
            void onNotebookPageChanged(wxAuiNotebookEvent &event);
            void onEndProcess(wxProcessEvent &event);
            void onEditorModified(wxStyledTextEvent &event);

            wxString getOutputFileName(const wxString &fileName);

            void updateErrors();
            void updateAutocomplete(EditorInfo &info);

            std::map<wxString, EditorInfo> mFileEditors;
            AutocompleteVisitor mAutocompleteVisitor;

            wxAuiManager mMgr;

            wxMenu *mFileMenu;
            wxMenu *mRunMenu;
            wxMenu *mEditMenu;

            wxToolBar *mToolbar;
            wxDataViewListCtrl *mErrorList;
            wxTextCtrl *mOutput;

            wxProcess *mActiveProcess;

            std::streambuf *mOldSb;

            wxDECLARE_EVENT_TABLE();
        };
    }
}

#endif //DEMUSE_MAINFRAME_H
