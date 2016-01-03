#ifndef DEMUSE_APP_H
#define DEMUSE_APP_H

#include <wx/app.h>
#include <wx/fileconf.h>

namespace dem {
    namespace ide {
        class App : public wxApp {
        public:
            virtual bool OnInit() override;
            virtual int OnExit() override;

            //wxFileConfig &config();

        //private:
            //wxFileConfig *mConfig;
        };
    }
}

wxDECLARE_APP(dem::ide::App);

#endif //DEMUSE_APP_H
