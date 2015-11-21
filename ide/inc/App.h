#ifndef DEMUSE_APP_H
#define DEMUSE_APP_H

#include "wx/app.h"

namespace dem {
    namespace ide {
        class App : public wxApp {
        public:
            virtual bool OnInit() override;
        };
    }
}

#endif //DEMUSE_APP_H
