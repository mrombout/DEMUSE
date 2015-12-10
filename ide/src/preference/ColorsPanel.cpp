#include <map>
#include <vector>
#include <MuseStyledTextEditor.h>
#include "App.h"
#include "preference/ColorsPanel.h"

namespace dem {
    namespace ide {
        const std::map<wxString, ColorDefaults> ColorsPanel::DEFAULTS = {
                {"Default",     {*wxBLACK,                *wxWHITE, false, false, false, wxSTC_STYLE_DEFAULT}},
                {"Boolean",     {wxColour(  0,   0, 128), *wxWHITE, true,  false, false, demSTC_DEMUSE_BOOL}},
                {"Text",        {wxColour(  0, 128,   0), *wxWHITE, false, false, false, demSTC_DEMUSE_TEXT}},
                {"Number",      {wxColour(  0,   0, 255), *wxWHITE, false, false, false, demSTC_DEMUSE_NUMBER}},
                {"Operator",    {wxColour(  0,   0,   0), *wxWHITE, false, false, false, demSTC_DEMUSE_OPERATOR}},
                {"Condition",   {wxColour(  0,   0,   0), *wxWHITE, false, false, false, demSTC_DEMUSE_CONDITION}},
                {"Unary",       {wxColour(  0,   0,   0), *wxWHITE, false, false, false, demSTC_DEMUSE_UNARY}},
                {"Keyword",     {wxColour(  0,   0, 128), *wxWHITE, true,  false, false, demSTC_DEMUSE_KEYWORD}},
                {"Track",       {wxColour(102,   0, 102), *wxWHITE, false, false, false, demSTC_DEMUSE_TRACK}},
                {"Note",        {wxColour(102,  14, 122), *wxWHITE, false, false, false, demSTC_DEMUSE_NOTE}},
                {"Accidental",  {wxColour(102,  14, 122), *wxWHITE, false, false, false, demSTC_DEMUSE_ACCIDENTAL}},
                {"Octave",      {wxColour(102,  14, 122), *wxWHITE, false, false, false, demSTC_DEMUSE_OCTAVE}},
                {"Chord",       {wxColour(102,  14, 122), *wxWHITE, false, false, false, demSTC_DEMUSE_CHORD}},
                {"Duration",    {wxColour(102,  14, 122), *wxWHITE, false, false, false, demSTC_DEMUSE_DURATION}},
                {"Block",       {wxColour(  0,   0,   0), *wxWHITE, false, false, false, demSTC_DEMUSE_BLOCK}},
                {"Parenthesis", {wxColour(  0,   0,   0), *wxWHITE, false, false, false, demSTC_DEMUSE_PARENTHESIS}},
                {"Brackets",    {wxColour(  0,   0,   0), *wxWHITE, false, false, false, demSTC_DEMUSE_BRACKET}},
                {"Play",        {wxColour(255,   0,   0), *wxWHITE, false, false, false, demSTC_DEMUSE_PLAY}},
                {"Function",    {wxColour(  0,   0, 128), *wxWHITE, true,  false, false, demSTC_DEMUSE_FUNCTION}},
                {"Var",         {wxColour(  0,   0, 128), *wxWHITE, true,  false, false, demSTC_DEMUSE_VAR}},
                {"Terminator",  {wxColour(  0,   0,   0), *wxWHITE, true,  false, false, demSTC_DEMUSE_TERMINATOR}},
                {"Identifier",  {wxColour(  0,   0,   0), *wxWHITE, false, true,  true,  demSTC_DEMUSE_IDENTIFIER}},
        };

        ColorsPanel::ColorsPanel(wxWindow *parent) : wxPanel(parent) {
            wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

            mPg = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_AUTO_SORT | wxPG_SPLITTER_AUTO_CENTER | wxPG_DEFAULT_STYLE);

            vbox->Add(mPg, 1, wxEXPAND | wxALL);

            SetSizerAndFit(vbox);
        }

        bool ColorsPanel::TransferDataToWindow() {
            wxFileConfig &config = wxGetApp().config();

            mPg->Clear();
            for(auto it = DEFAULTS.cbegin(); it != DEFAULTS.cend(); ++it) {
                wxString category = it->first.Lower();

                wxColour backgroundColor;
                backgroundColor.Set(config.Read("colors/" + category + "/background", it->second.background.GetAsString()));

                wxColour foregroundColor;
                foregroundColor.Set(config.Read("colors/" + category + "/foreground", it->second.foreground.GetAsString()));

                mPg->Append(new wxPropertyCategory(category.Capitalize()));
                mPg->Append(new wxColourProperty("Background", category + "/background", backgroundColor));
                mPg->Append(new wxColourProperty("Foreground", category + "/foreground", foregroundColor));
                mPg->Append(new wxBoolProperty("Bold", category + "/bold", config.ReadBool(category + "/bold", it->second.bold)));
                mPg->Append(new wxBoolProperty("Italic", category + "/italic", config.ReadBool(category + "/italic", it->second.italic)));
                mPg->Append(new wxBoolProperty("Underline", category + "/underline", config.ReadBool(category + "/underline", it->second.underline)));
            }

            return true;
        }

        bool ColorsPanel::TransferDataFromWindow() {
            wxFileConfig &config = wxGetApp().config();

            wxPropertyGridIterator it = mPg->GetIterator(wxPG_ITERATE_NORMAL);
            for(; !it.AtEnd(); ++it) {
                const wxPGProperty *p = *it;

                wxString key = "colors/" + p->GetName().Lower();
                wxString value = p->GetValueAsString(wxPG_FULL_VALUE);
                if(value.at(0) == '(') {
                    // TODO: Remove this cheap hack to fix the format of colours to be read by wxColour::Set
                    value = "rgba" + value;
                }
                std::cout << "Writing: " << key << " = " << value << std::endl;

                config.Write(key, value);
            }

            return true;
        }
    }
}
